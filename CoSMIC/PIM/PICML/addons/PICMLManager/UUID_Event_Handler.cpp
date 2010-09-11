// $Id: UUID_Event_Handler.cpp 2455 2010-08-24 12:00:00Z alhad $

#include "StdAfx.h"
#include "UUID_Event_Handler.h"

#include "game/Connection.h"
#include "game/Model.h"
#include "game/MetaModel.h"
#include "game/Reference.h"
#include "game/Attribute.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/dialogs/Dialog_Display_Strategy.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

//
// UUID_Event_Handler
//
UUID_Event_Handler::UUID_Event_Handler ()
: GAME::Event_Handler_Impl (OBJEVENT_CREATED | OBJEVENT_ATTR)
{

}

//
// ~UUID_Event_Handler
//
UUID_Event_Handler::~UUID_Event_Handler (void)
{

}

//
// handle_object_created
//
int UUID_Event_Handler::
handle_object_created (GAME::Object obj)
{
  if (obj.is_lib_object ())
    return 0;

  // Locate the UUID attribute for the FCO.
  GAME::FCO fco = GAME::FCO::_narrow (obj);
  GAME::Attribute uuid_attr = fco.attribute ("UUID");

  // Get the current value of the attribute. Just because we
  // are creating the object does not mean that its value does
  // not already exist (e.g., importing an XME document).
  std::string uuid = uuid_attr.string_value ();
  const bool is_valid = uuid.empty () ? false : ::Utils::ValidUuid (uuid);

  if (!is_valid ||
     (!this->is_importing_ && (fco.is_instance () || fco.is_subtype ())))
  {
    // We need to generate a new UUID for the element.
    uuid = ::Utils::CreateUuid ();
    uuid_attr.string_value (uuid);
  }

  return 0;
}

//
// handle_object_attribute
//
int UUID_Event_Handler::
handle_object_attribute (GAME::Object obj)
{
  if (obj.is_lib_object ())
    return 0;

  // Get the UUID attribute for the FCO.
  GAME::FCO fco = GAME::FCO::_narrow (obj);
  GAME::Attribute uuid_attr = fco.attribute ("UUID");

  // Validate the current UUID string value.
  std::string uuid = uuid_attr.string_value ();

  if (::Utils::ValidUuid (uuid))
    return 0;

  // We need to create a new UUID for the object.
  uuid = ::Utils::CreateUuid ();
  uuid_attr.string_value (uuid);

  return 0;
}

}
}