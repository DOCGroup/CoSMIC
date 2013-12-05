// $Id$

#include "StdAfx.h"
#include "Action_Type_Handler.h"

#include "game/mga/Reference.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaAspect.h"
#include "game/mga/utils/Point.h"

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
: GAME::Mga::Object_Event_Handler (eventmask)
{

}

//
// ~CBML_Action_Type_Handler
//
CBML_Action_Type_Handler::~CBML_Action_Type_Handler (void)
{

}

/**
 * @struct metaname_equal_to
 */
struct metaname_equal_to
{
  metaname_equal_to (const std::string & metaname)
    : metaname_ (metaname)
  {

  }

  template <typename T>
  bool operator () (T t) const
  {
    return t->meta ()->name () == this->metaname_;
  }

private:
  const std::string & metaname_;
};

//
// handle_object_created
//
int CBML_Action_Type_Handler::handle_object_relation (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::Reference action_type = GAME::Mga::Reference::_narrow (obj);
  GAME::Mga::FCO fco = action_type->refers_to ();
  GAME::Mga::Model action = action_type->parent_model ();

  if (fco.is_nil ())
  {
    // Locate all the parameters for this action.
    std::vector <GAME::Mga::FCO> parameters;
    GAME::Mga::Meta::Aspect behavior_aspect = action->meta ()->aspect (meta::Behavior);
    action->children (behavior_aspect, parameters);

    // Remove all the parameters from the model.
    std::for_each (parameters.begin (),
                   parameters.end (),
                   boost::bind (&GAME::Mga::FCO_Impl::destroy,
                                boost::bind (&GAME::Mga::FCO::get, _1)));
  }
  else
  {
    // Get the operation's parameters. If there are no parameters, then
    // there is no need continue.
    GAME::Mga::Model operation = GAME::Mga::Model::_narrow (fco);
    std::vector <GAME::Mga::Reference> parameters;

    if (0 == operation->children (parameters))
      return 0;

    // Remove all the ReturnType parameters.
    std::vector <GAME::Mga::Reference>::iterator iter_tail =
      std::remove_if (parameters.begin (),
                      parameters.end (),
                      metaname_equal_to (meta::ReturnType));

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
create_property (GAME::Mga::Model_in action, const GAME::Mga::Reference_in parameter)
{
  try
  {
    // Right now, we are only supporting simple property elements.
    GAME::Mga::Reference simple_property =
      GAME::Mga::Reference_Impl::_create (action, meta::SimpleProperty);

    // Set the property's reference to that of the parameter.
    simple_property->name (parameter->name ());
    simple_property->refers_to (parameter->refers_to ());

    // Update the property's location.
    GAME::Mga::Point pos;
    GAME::Mga::get_position (meta::WorkerBehavior, parameter, pos);
    GAME::Mga::set_position (meta::Behavior, pos, simple_property);
  }
  catch (const GAME::Mga::Failed_Result & )
  {

  }
}
