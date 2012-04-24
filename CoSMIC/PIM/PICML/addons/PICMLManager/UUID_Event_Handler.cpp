// $Id: UUID_Event_Handler.cpp 2455 2010-08-24 12:00:00Z alhad $

#include "StdAfx.h"
#include "UUID_Event_Handler.h"

#include "game/mga/Connection.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Reference.h"
#include "game/mga/Attribute.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include "game/mga/dialogs/Dialog_Display_Strategy.h"

#include "game/mga/Filter.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED |
                                  OBJEVENT_ATTR |
                                  OBJEVENT_DESTROYED;

namespace attr
{
  static const std::string UUID ("UUID");
}

//
// UUID_Event_Handler
//
UUID_Event_Handler::UUID_Event_Handler (UUID_MANAGER & uuids)
: GAME::Mga::Object_Event_Handler (mask),
  uuids_ (uuids)
{

}

//
// ~UUID_Event_Handler
//
UUID_Event_Handler::~UUID_Event_Handler (void)
{

}

//
// initialize
//
int UUID_Event_Handler::initialize (GAME::Mga::Project project)
{
  this->project_ = project;

  return 0;
}

//
// handle_project_open
//
int UUID_Event_Handler::handle_project_open (void)
{
  // Locate the following object types in the model.
  static
    const std::string filter_kind =
    "Component ConnectorObject ComponentInstance ConnectorInstance";

  std::vector <GAME::Mga::FCO> result_set;

  GAME::Mga::Filter filter (this->project_);
  filter.kind (filter_kind);
  if (0 == filter.apply (result_set))
    return 0;

  // Insert the UUID for each object in the UUID set.
  std::vector <GAME::Mga::FCO>::iterator
    iter = result_set.begin (), iter_end = result_set.end ();

  std::string uuid;

  for ( ; iter != iter_end; ++ iter)
  {
    uuid = (*iter)->attribute (attr::UUID)->string_value ();
    this->uuids_.bind (uuid, *iter);
  }

  return 0;
}

//
// handle_project_close
//
int UUID_Event_Handler::handle_project_close (void)
{
  this->uuids_.unbind_all ();
  this->project_ = 0;

  return 0;
}

//
// handle_object_created
//
int UUID_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  // Locate the UUID attribute for the FCO.
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);
  GAME::Mga::Attribute uuid_attr = fco->attribute (attr::UUID);
  std::string uuid = uuid_attr->string_value ();

  if (fco->is_lib_object ())
  {
    // Since it's a library object, we are just going to store
    // its reference.
    this->uuids_.bind (uuid, fco);
  }
  else
  {
    // Get the current value of the attribute. Just because we
    // are creating the object does not mean that its value does
    // not already exist (e.g., importing an XME document).
    const bool is_valid = uuid.empty () ? false : ::Utils::ValidUuid (uuid);
    const bool is_duplicate = !is_valid ? false : this->is_duplicate_uuid (fco, uuid);

    if (!is_valid || is_duplicate)
    {
      // We need to generate a new UUID for the element.
      uuid = ::Utils::CreateUuid ();
      bool is_readonly = obj->readonly_access ();

      // Remember the readonly access state since we need to restore
      // it after updated the UUID.
      if (is_readonly)
        obj->readonly_access (false, false);

      // Update the UUID attribute.
      uuid_attr->string_value (uuid);

      // Restore the readonly access flags.
      if (is_readonly)
        obj->readonly_access (true, false);
    }

    // Finally store the FCO's UUID. We do not care if it was already stored
    // in the mapping since we can safely assume that
    if (!is_duplicate)
      this->uuids_.bind (uuid, fco);
  }

  return 0;
}

//
// handle_object_destroyed
//
int UUID_Event_Handler::handle_object_destroyed (GAME::Mga::Object_in obj)
{
  // Locate the UUID attribute for the FCO.
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

  for (UUID_MANAGER::ITERATOR iter (this->uuids_); !iter.done (); ++ iter)
  {
    if (iter->item ()->is_equal_to (fco))
    {
      // We found the matching item. So, let's remove this item
      // from the UUID collection.
      this->uuids_.unbind (iter->key ());
      break;
    }
  }

  return 0;
}

//
// handle_object_attribute
//
int UUID_Event_Handler::
handle_object_attribute (GAME::Mga::Object_in obj)
{
  if (!obj->is_mutable ())
    return 0;

  // Get the UUID attribute for the FCO.
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);
  GAME::Mga::Attribute uuid_attr = fco->attribute (attr::UUID);

  // Validate the current UUID string value.
  std::string old_uuid = uuid_attr->string_value ();
  bool is_duplicate = this->is_duplicate_uuid (fco, old_uuid);

  if (::Utils::ValidUuid (old_uuid) && !is_duplicate)
    return 0;

  std::string new_uuid;

  do
  {
    // We need to create a new UUID for the object.
    new_uuid = ::Utils::CreateUuid ();
  } while (0 == this->uuids_.find (new_uuid));

  // We can now use and store the newly created UUID. Make sure we
  // remove the old UUID and replace it with the new UUID.
  uuid_attr->string_value (new_uuid);

  this->uuids_.bind (new_uuid, fco);

  if (!is_duplicate)
    this->uuids_.unbind (old_uuid);

  return 0;
}

//
// is_duplicate_uuid
//
bool UUID_Event_Handler::
is_duplicate_uuid (GAME::Mga::FCO_in fco, const std::string & uuid)
{
  // First, see if we can locate the UUID in the collection.
  GAME::Mga::FCO located_fco;
  if (0 != this->uuids_.find (uuid, located_fco))
    return false;

  // Since we are able to locate the UUID, lets see if this is the
  // same object. If it is, then it is not a duplicate. Otherwise,
  // we can assume the object is a duplicate.
  return !fco->is_equal_to (located_fco);
}

}
}
