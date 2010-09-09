// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "AttributeValue_Event_Handler.h"

#include "game/GAME.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

//
// AttributeValue_Create_Event_Handler
//
AttributeValue_Create_Event_Handler::AttributeValue_Create_Event_Handler (void)
: Event_Handler_Base (OBJEVENT_CREATED)
{

}

//
// ~AttributeValue_Create_Event_Handler
//
AttributeValue_Create_Event_Handler::~AttributeValue_Create_Event_Handler (void)
{

}

//
// handle_object_created
//
int AttributeValue_Create_Event_Handler::
handle_object_created (GAME::Object obj)
{
  // Extract the connection from the object and get its endpoints.
  GAME::Connection attr_value = GAME::Connection::_narrow (obj);
  GAME::Reference attr_inst = GAME::Reference::_narrow (attr_value[std::string ("src")].target ());
  GAME::Model prop = GAME::Model::_narrow (attr_value[std::string ("dst")].target ());

  // Get the target attribute.
  GAME::Model attr = GAME::Model::_narrow (attr_inst.refers_to ());

  if (attr.is_nil ())
    return 0;

  // Set the name of the Property. We want to ensure the name to
  // the prop matches the name of the attribute.
  if (prop.name () != attr.name ())
    prop.name (attr.name ());

  GAME::FCO member_type;
  Reference_Set attr_members;

  // Let's get the data type of the attribute. Since there is only
  // 1 attribute member, we can just get the front element in the
  // container.
  if (1 == attr.children ("AttributeMember", attr_members))
    member_type = attr_members.front ().refers_to ();

  if (!member_type.is_nil ())
    this->set_property_type (prop, member_type);

  return 0;
}

}
}