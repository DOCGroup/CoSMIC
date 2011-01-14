// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "AttributeMember_Event_Handler.h"

#include "game/Model.h"
#include "game/Connection.h"
#include "game/Reference.h"
#include "game/utils/Point.h"

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

//
// AttributeMember_Event_Handler
//
AttributeMember_Event_Handler::AttributeMember_Event_Handler (void)
: Event_Handler_Base (OBJEVENT_RELATION)
{

}

//
// ~AttributeMember_Event_Handler
//
AttributeMember_Event_Handler::~AttributeMember_Event_Handler (void)
{

}

//
// handle_object_created
//
int AttributeMember_Event_Handler::
handle_object_relation (GAME::Object_in obj)
{
  // The reference for the attribute changes. This is either
  // because the reference was cleared, or another data type
  // was referenced. Either way, we need to update all the
  // properties in component assemblies for this attribute.

  GAME::Reference member = GAME::Reference::_narrow (obj);
  GAME::FCO attr_type = member->refers_to ();

  if (!attr_type.is_nil ())
  {
    // Get the AttributeValue connection.
    GAME::Model attr = member->parent_model ();

    // Get all connection points that connect to this attribute.
    GAME::ConnectionPoints connpoints;
    attr->in_connection_points (connpoints);

    std::for_each (connpoints.begin (),
                   connpoints.end (),
                   boost::bind (&AttributeMember_Event_Handler::verify_property_datatype_entry,
                                this,
                                _1,
                                attr_type));
  }

return 0;
}

//
// verify_property_datatype_entry
//
void AttributeMember_Event_Handler::
verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
                                const GAME::FCO_in attr_type)
{
  this->verify_property_datatype (attr.item (), attr_type);
}

//
// verify_property_datatype
//
void AttributeMember_Event_Handler::
verify_property_datatype (GAME::ConnectionPoint & attr,
                          const GAME::FCO_in attr_type)
{
  // Get the own of this connection. If this is an AttributeValue
  // connection, then we should continue walking the connection
  // until we get to the prop.
  GAME::Connection attr_value = GAME::Connection::_narrow (attr->owner ());

  if (attr_value->meta ()->name () == "AttributeValue")
  {
    // We need to find the 'dst' connection point in this collection.
    // It will point to the target prop model.
    GAME::ConnectionPoints connpoints;
    attr_value->connection_points (connpoints);

    // Get the prop element from the connection. It will be
    // the 'dst' connection point.
    GAME::Model prop = GAME::Model::_narrow (connpoints["dst"]->target ());

    // Set the data type for the prop.
    this->set_property_type (prop, attr_type);
  }
}

}
}