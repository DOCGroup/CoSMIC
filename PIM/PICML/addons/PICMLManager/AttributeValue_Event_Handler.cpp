// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "AttributeValue_Event_Handler.h"
#include "game/mga/Connection.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"

#include "boost/bind.hpp"
#include <set>

namespace PICML
{
namespace MI
{

//
// AttributeValue_Event_Handler
//
AttributeValue_Event_Handler::AttributeValue_Event_Handler (void)
: Event_Handler_Base (OBJEVENT_CREATED)
{

}

//
// ~AttributeValue_Event_Handler
//
AttributeValue_Event_Handler::~AttributeValue_Event_Handler (void)
{

}

//
// handle_object_created
//
int AttributeValue_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  // Extract the connection from the object and get its endpoints.
  GAME::Mga::Connection attr_value = GAME::Mga::Connection::_narrow (obj);
  GAME::Mga::FCO dst = attr_value->dst ();
  GAME::Mga::FCO src = attr_value->src ();
  GAME::Mga::Reference attr_inst = GAME::Mga::Reference::_narrow (src);

  // Set the name of the Property. We want to ensure the name to
  // the prop matches the name of the attribute.
  if (dst->name () != attr_inst->name ())
    dst->name (attr_inst->name ());

  // Get the target attribute so we know what we are working with.
  GAME::Mga::FCO fco = attr_inst->refers_to ();

  if (fco.is_nil ())
    return 0;

  GAME::Mga::Model attr = GAME::Mga::Model::_narrow (fco);

  // Let's get the data type of the attribute. Since there is only
  // 1 attribute member, we can just get the front element in the
  // container.
  std::vector <GAME::Mga::Reference> attr_members;
  GAME::Mga::FCO member_type;

  if (1 == attr->children ("AttributeMember", attr_members))
    member_type = attr_members.front ()->refers_to ();

  if (member_type.is_nil ())
    return 0;

  if (dst->meta ()->name () == "SimpleProperty")
  {
    GAME::Mga::Reference simple = GAME::Mga::Reference::_narrow (dst);
    simple->refers_to (member_type);
  }
  else
  {
    GAME::Mga::Model complex = GAME::Mga::Model::_narrow (dst);
    this->set_property_type (complex, member_type);
  }

  return 0;
}

}
}