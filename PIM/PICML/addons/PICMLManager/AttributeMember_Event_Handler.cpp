// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "AttributeMember_Event_Handler.h"

#include "game/mga/Model.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/utils/Point.h"

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
handle_object_relation (GAME::Mga::Object_in obj)
{
  // The reference for the attribute changes. This is either
  // because the reference was cleared, or another data type
  // was referenced. Either way, we need to update all the
  // properties in component assemblies for this attribute.

  GAME::Mga::Reference member = GAME::Mga::Reference::_narrow (obj);
  GAME::Mga::FCO attr_type = member->refers_to ();

  if (!attr_type.is_nil ())
  {
    // Get the AttributeValue connection.
    GAME::Mga::Model attr = member->parent_model ();

    // Get all connection points that connect to this attribute.
    GAME::Mga::ConnectionPoints connpoints;
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
verify_property_datatype_entry (GAME::Mga::ConnectionPoints::value_type & attr,
                                const GAME::Mga::FCO_in attr_type)
{
  this->verify_property_datatype (attr.item (), attr_type);
}

//
// verify_property_datatype
//
void AttributeMember_Event_Handler::
verify_property_datatype (GAME::Mga::ConnectionPoint & attr,
                          const GAME::Mga::FCO_in attr_type)
{
  // Get the own of this connection. If this is an AttributeValue
  // connection, then we should continue walking the connection
  // until we get to the prop.
  GAME::Mga::Connection attr_value = GAME::Mga::Connection::_narrow (attr->owner ());

  if (attr_value->meta ()->name () == "AttributeValue")
  {
    // We need to find the 'dst' connection point in this collection.
    // It will point to the target prop model.
    GAME::Mga::ConnectionPoints connpoints;
    attr_value->connection_points (connpoints);

    // Get the prop element from the connection. It will be
    // the 'dst' connection point.
    GAME::Mga::Model prop = GAME::Mga::Model::_narrow (connpoints["dst"]->target ());

    // Set the data type for the prop.
    this->set_property_type (prop, attr_type);
  }
}

}
}