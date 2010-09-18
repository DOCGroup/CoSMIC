// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ComplexTypeReference_Event_Handler.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"

#include "Utils/Utils.h"

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
: GAME::Event_Handler_Impl (mask)
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
handle_object_relation (GAME::Object obj)
{
  // Get the complex types actual type.
  GAME::Model container = GAME::Model::_narrow (obj.parent ());
  GAME::Reference complex = GAME::Reference::_narrow (obj);
  GAME::FCO type = complex.refers_to ();

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  GAME::FCO real_type = type;
  GAME::Meta::FCO metafco = real_type.meta ();

  while (metafco == "Alias")
  {
    GAME::Reference alias = GAME::Reference::_narrow (real_type);
    real_type = alias.refers_to ();
    metafco = real_type.meta ();
  }

  if (metafco == "Aggregate")
  {
    GAME::Model aggregate = GAME::Model::_narrow (real_type);

    // Get all the members of the aggregate.
    std::vector <GAME::FCO> members;
    aggregate.children (members);

    std::for_each (members.begin (),
                   members.end (),
                   boost::bind (&ComplexTypeReference_Event_Handler::create_DataValue,
                                this,
                                container,
                                _1));
  }
  else if (metafco == "Collection")
  {

  }

  return 0;
}

//
// create_DataValue
//
void ComplexTypeReference_Event_Handler::
create_DataValue (GAME::Model container, const GAME::FCO & fco)
{
  GAME::Reference member = GAME::Reference::_narrow (fco);
  GAME::FCO type = member.refers_to ();

  if (type.is_nil ())
    return;

  GAME::FCO real_type = type;
  GAME::Meta::FCO metafco = type.meta ();
  const std::string name (fco.name ());

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  while (metafco == "Alias")
  {
    GAME::Reference alias = GAME::Reference::_narrow (real_type);
    real_type = alias.refers_to ();

    if (real_type.is_nil ())
      return;

    metafco = real_type.meta ();
  }

  if (metafco == "Aggregate" || metafco == "Collection")
  {
    // Make sure the container contains the element that has the
    // same name as <fco> input parameter.
    GAME::Model child_container;

    if (GAME::create_if_not (container, "DataValueContainer", child_container,
        GAME::contains (boost::bind (std::equal_to <std::string> (),
                        name,
                        boost::bind (&GAME::Model::name, _1)))))
    {
      child_container.name (name);
    }

    // Set the child container's type. This will cause the add-on to
    // generate the container's elements.
    GAME::Reference complex_type;
    std::vector <GAME::Reference> complex_types;

    if (0 == child_container.children ("ComplexTypeReference", complex_types))
      complex_type = GAME::Reference::_create (child_container, "ComplexTypeReference");
    else
      complex_type = complex_types.front ();

    complex_type.refers_to (type);
    complex_type.name (type.name ());

    // Finally, set the position of the data value. We can do this by
    // just copying the current position of the type.
    GAME::utils::Point pt;
    GAME::utils::position ("InterfaceDefinition", fco, pt);
    GAME::utils::position ("DataValueAspect", pt, child_container);
  }
  else
  {
    // Make sure the container contains the element that has the
    // same name as <fco> input parameter.
    GAME::Reference data_value;

    if (GAME::create_if_not (container, "DataValue", data_value,
        GAME::contains (boost::bind (std::equal_to <std::string> (),
                        name,
                        boost::bind (&GAME::Reference::name, _1)))))
    {
      data_value.name (name);
    }

    // Set the data values type.
    data_value.refers_to (type);

    // Finally, set the position of the data value. We can do this by
    // just copying the current position of the type.
    GAME::utils::Point pt;
    GAME::utils::position ("InterfaceDefinition", fco, pt);
    GAME::utils::position ("DataValueAspect", pt, data_value);
  }
}

}
}