// $Id$

#include "BE_Execution_Visitor_T.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// CUTS_BE_Env_Visitor_T
//
template <typename BE_STRATEGY>
CUTS_BE_Env_Visitor_T <BE_STRATEGY>::
CUTS_BE_Env_Visitor_T (BE_STRATEGY & traits)
: traits_ (traits)
{

}

//
// ~CUTS_BE_Env_Visitor_T
//
template <typename BE_STRATEGY>
CUTS_BE_Env_Visitor_T <BE_STRATEGY>::~CUTS_BE_Env_Visitor_T (void)
{

}

//
// Visit_Environment
//
template <typename BE_STRATEGY>
void CUTS_BE_Env_Visitor_T <BE_STRATEGY>::
Visit_Environment (const PICML::Environment & env)
{
  typedef std::set <PICML::MultiInput> MultiInput_Set;
  MultiInput_Set inputs = env.dstMultiInput ();

  std::for_each (inputs.begin (),
                 inputs.end (),
                 boost::bind (&MultiInput_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_MulitInput
//
template <typename BE_STRATEGY>
void CUTS_BE_Env_Visitor_T <BE_STRATEGY>::
Visit_MultiInput (const PICML::MultiInput & input)
{
  PICML::InputAction action =
    PICML::InputAction::Cast (input.dstMultiInput_end ());

  action.Accept (*this);
}

//
// Visit_InputAction
//
template <typename BE_STRATEGY>
void CUTS_BE_Env_Visitor_T <BE_STRATEGY>::
Visit_InputAction (const PICML::InputAction & action)
{
  this->traits_.write_environment_method_begin (action);

  CUTS_BE_Execution_Visitor_T <BE_STRATEGY> exec_visitor (this->traits_);
  PICML::InputAction (action).Accept (exec_visitor);

  this->traits_.write_environment_method_end (action);
}
