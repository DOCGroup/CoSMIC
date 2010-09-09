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

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

namespace PICML
{
namespace MI
{

//
// UUID_Event_Handler_Base
//
UUID_Event_Handler_Base::UUID_Event_Handler_Base (objectevent_enum e)
: Event_Handler_Impl (e),
  config_ (ACE_Singleton <PICML::MI::Event_Handler_Config,
                          ACE_Null_Mutex>::instance ())
{
}

//
// ~UUID_Event_Handler_Base
//
UUID_Event_Handler_Base::~UUID_Event_Handler_Base (void)
{

}

//
// get_uuid_i
//
bool UUID_Event_Handler_Base::
get_uuid_i (const GAME::FCO & fco, GAME::Attribute & attr)
{
  typedef std::vector <GAME::Attribute> Attribute_Set;
  Attribute_Set attrs;

  // Get all the attributes of this FCO. It would be nice to query
  // the FCO for the attribute of interest, however, that capability
  // seems to be broken in the current MGA library.
  if (fco.attributes (attrs))
  {
    // We need to iterate over all the attribute until we find the
    // attribute with the name of UUID. That will be the attribute
    // we return to the caller.
    for (Attribute_Set::iterator iter = attrs.begin ();
         iter != attrs.end ();
         iter ++)
    {
      if (iter->meta ().name () == "UUID")
      {
        attr = *iter;
        return true;
      }
    }
  }

  return false;
}

//
// UUID_Create_Event_Handler
//
UUID_Create_Event_Handler::UUID_Create_Event_Handler (void)
: UUID_Event_Handler_Base (OBJEVENT_CREATED)
{
}

//
// ~UUID_Create_Event_Handler
//
UUID_Create_Event_Handler::~UUID_Create_Event_Handler (void)
{

}

//
// handle_object_created
//
int UUID_Create_Event_Handler::
handle_object_created (GAME::Object obj)
{
  GAME::FCO fco = GAME::FCO::_narrow (obj);
  GAME::Attribute uuid_attr;

  if (this->get_uuid_i (fco, uuid_attr))
  {
    long status = uuid_attr.status ();

    // This will force the generation of an UUID for any element
    // that requires an UUID, including instances and subtypes.
    try
    {
      uuid_attr.string_value (Utils::CreateUuid ());
    }
    catch (...)
    {
      //this->config_->pending_.push_back (fco);
    }
  }
  return 0;
}

//
// UUID_Verify_Event_Handler
//
UUID_Verify_Event_Handler::UUID_Verify_Event_Handler (void)
: UUID_Event_Handler_Base (OBJEVENT_ATTR)
{

}

//
// ~UUID_Verify_Event_Handler
//
UUID_Verify_Event_Handler::~UUID_Verify_Event_Handler (void)
{

}

//
// handle_object_attribute
//
int UUID_Verify_Event_Handler::
handle_object_attribute (GAME::Object obj)
{
  GAME::FCO fco = GAME::FCO::_narrow (obj);
  GAME::Attribute uuid_attr;

  if (this->get_uuid_i (fco, uuid_attr))
  {
    if (Utils::ValidUuid (uuid_attr.string_value ()))
      return 0;

    try
    {
      uuid_attr.string_value (Utils::CreateUuid ());
    }
    catch (GAME::Exception &)
    {
      //this->config_->pending_.push_back (fco);
    }
    catch (...)
    {

    }
  }
  return 0;
}

}
}