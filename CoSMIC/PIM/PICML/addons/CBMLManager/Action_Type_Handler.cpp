// $Id$

#include "StdAfx.h"
#include "Action_Type_Handler.h"

#include "game/Reference.h"
#include "game/Model.h"
#include "game/MetaModel.h"
#include "game/MetaAspect.h"
#include "game/utils/Point.h"

#include "boost/bind.hpp"
#include <algorithm>
#include <functional>

namespace meta
{
  static const std::string Behavior ("Behavior");
  static const std::string ReturnType ("ReturnType");
  static const std::string WorkerBehavior ("WorkerBehavior");
  static const std::string SimpleProperty ("SimpleProperty");
}

//
// CBML_Action_Type_Handler
//
CBML_Action_Type_Handler::CBML_Action_Type_Handler (void)
: GAME::Event_Handler_Impl (eventmask)
{

}

//
// ~CBML_Action_Type_Handler
//
CBML_Action_Type_Handler::~CBML_Action_Type_Handler (void)
{

}


//
// handle_object_created
//
int CBML_Action_Type_Handler::handle_object_relation (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Reference action_type = GAME::Reference::_narrow (obj);
  GAME::FCO fco = action_type.refers_to ();
  GAME::Model action = action_type.parent_model ();

  if (fco.is_nil ())
  {
    // Locate all the parameters for this action.
    std::vector <GAME::FCO> parameters;
    GAME::Meta::Aspect behavior_aspect = action.meta ().aspect (meta::Behavior);
    action.children (behavior_aspect, parameters);

    // Remove all the parameters from the model.
    std::for_each (parameters.begin (),
                   parameters.end (),
                   boost::bind (&GAME::FCO::destroy, _1));
  }
  else
  {
    // Get the operation's parameters. If there are no parameters, then
    // there is no need continue.
    GAME::Model operation = GAME::Model::_narrow (fco);
    std::vector <GAME::Reference> parameters;

    if (0 == operation.children (parameters))
      return 0;

    // Remove all the ReturnType parameters.
    std::vector <GAME::Reference>::iterator iter_tail =
      std::remove_if (parameters.begin (),
                      parameters.end (),
                      boost::bind (std::equal_to <std::string> (),
                                   meta::ReturnType,
                                   boost::bind (&GAME::Meta::FCO::name,
                                                boost::bind (&GAME::FCO::meta, _1))));

    // Create a property for each parameter.
    std::for_each (parameters.begin (),
                   iter_tail,
                   boost::bind (&CBML_Action_Type_Handler::create_property,
                                this,
                                action,
                                _1));
  }

  return 0;
}

//
// create_property
//
void CBML_Action_Type_Handler::
create_property (GAME::Model action, const GAME::Reference & parameter)
{
  // Right now, we are only supporting simple property elements.
  try
  {
    GAME::Reference simple_property =
      GAME::Reference::_create (action, meta::SimpleProperty);

    // Set the property's reference to that of the parameter.
    simple_property.name (parameter.name ());
    simple_property.refers_to (parameter.refers_to ());

    // Update the property's location.
    GAME::utils::Point pos;
    GAME::utils::position (meta::WorkerBehavior, parameter, pos);
    GAME::utils::position (meta::Behavior, pos, simple_property);
  }
  catch (const GAME::Failed_Result & ex)
  {
    long hr = ex.value ();
  }
}
