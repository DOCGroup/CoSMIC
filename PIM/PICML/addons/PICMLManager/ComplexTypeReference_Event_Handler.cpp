// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ComplexTypeReference_Event_Handler.h"

#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"

#include "boost/bind.hpp"

#include <functional>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_RELATION;

//
// ComplexTypeReference_Event_Handler
//
ComplexTypeReference_Event_Handler::ComplexTypeReference_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (mask)
{

}

//
// ~ComplexTypeReference_Event_Handler
//
ComplexTypeReference_Event_Handler::~ComplexTypeReference_Event_Handler (void)
{

}

//
// handle_object_created
//
int ComplexTypeReference_Event_Handler::
handle_object_relation (GAME::Mga::Object_in obj)
{
  // Get the complex types actual type.
  GAME::Mga::Model container = GAME::Mga::Model::_narrow (obj->parent ());
  GAME::Mga::Reference complex = GAME::Mga::Reference::_narrow (obj);
  GAME::Mga::FCO type = complex->refers_to ();

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  GAME::Mga::FCO real_type = type;
  GAME::Mga::Meta::FCO metafco = real_type->meta ();
  static const std::string meta_Alias ("Alias");

  while (metafco->name () == meta_Alias)
  {
    real_type = GAME::Mga::Reference::_narrow (real_type)->refers_to ();
    metafco = real_type->meta ();
  }

  static const std::string meta_Aggregate ("Aggregate");

  if (metafco->name () == meta_Aggregate)
  {
    GAME::Mga::Model aggregate = GAME::Mga::Model::_narrow (real_type);

    // Get all the members of the aggregate.
    std::vector <GAME::Mga::Reference> members;
    aggregate->children (members);

    std::for_each (members.begin (),
                   members.end (),
                   boost::bind (&ComplexTypeReference_Event_Handler::create_DataValue,
                                this,
                                container,
                                _1));
  }

  return 0;
}

//
// create_DataValue
//
void ComplexTypeReference_Event_Handler::
create_DataValue (GAME::Mga::Model_in container, const GAME::Mga::FCO_in fco)
{
  using GAME::Mga_t;

  GAME::Mga::Reference member = GAME::Mga::Reference::_narrow (fco);
  GAME::Mga::FCO type = member->refers_to ();

  if (type.is_nil ())
    return;

  GAME::Mga::FCO real_type = type;
  GAME::Mga::Meta::FCO metafco = type->meta ();
  const std::string name (fco->name ());

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  while (metafco->name () == "Alias")
  {
    GAME::Mga::Reference alias = GAME::Mga::Reference::_narrow (real_type);
    real_type = alias->refers_to ();

    if (real_type.is_nil ())
      return;

    metafco = real_type->meta ();
  }

  if (metafco->name () == "Aggregate" || metafco->name () == "Collection")
  {
    // Make sure the container contains the element that has the
    // same name as <fco> input parameter.
    GAME::Mga::Model child_container;

    if (GAME::create_if_not <Mga_t> (container, "DataValueContainer", child_container,
        GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                name,
                                boost::bind (&GAME::Mga::Model::impl_type::name,
                                             boost::bind (&GAME::Mga::Model::get, _1))))))
    {
      child_container->name (name);
    }

    // Set the child container's type. This will cause the add-on to
    // generate the container's elements.
    GAME::Mga::Reference complex_type;
    std::vector <GAME::Mga::Reference> complex_types;

    if (0 == child_container->children ("ComplexTypeReference", complex_types))
      complex_type = GAME::Mga::Reference_Impl::_create (child_container, "ComplexTypeReference");
    else
      complex_type = complex_types.front ();

    complex_type->refers_to (type);
    complex_type->name (type->name ());

    // Finally, set the position of the data value. We can do this by
    // just copying the current position of the type.
    GAME::Mga::Point pt;
    GAME::Mga::get_position ("InterfaceDefinition", fco, pt);
    GAME::Mga::set_position ("DataValueAspect", pt, child_container);
  }
  else
  {
    // Make sure the container contains the element that has the
    // same name as <fco> input parameter.
    GAME::Mga::Reference data_value;

    if (GAME::create_if_not <Mga_t> (container, "DataValue", data_value,
        GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                name,
                                boost::bind (&GAME::Mga::Reference::impl_type::name,
                                             boost::bind (&GAME::Mga::Reference::get, _1))))))
    {
      data_value->name (name);
    }

    // Set the data values type.
    data_value->refers_to (type);

    // Finally, set the position of the data value. We can do this by
    // just copying the current position of the type.
    GAME::Mga::Point pt;
    GAME::Mga::get_position ("InterfaceDefinition", fco, pt);
    GAME::Mga::set_position ("DataValueAspect", pt, data_value);
  }
}

}
}