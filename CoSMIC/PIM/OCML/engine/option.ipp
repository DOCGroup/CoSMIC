// $Id$

#include "constraint_engine.hpp"
#include <ace/Log_Msg.h>

namespace OCML
{
  inline
  Option::Option(Option_Definition* option_definition,
                 Constraint_Engine* constraint_manager)
    : definition_(option_definition),
      constraint_manager_(constraint_manager),
      assigned_(false)
  {
    ACE_DEBUG((LM_TRACE,
          "Option::Option(Option_Definition*, Constraint_Engine&)\n"));
  }

  inline bool
  Option::clear()
  {
    ACE_DEBUG((LM_TRACE, "ENTER: Option::clear()\n"));
    if (!assigned_)
    {
      ACE_DEBUG((LM_TRACE, "EXIT: Option::clear()\n"));
      return true;
    }

    constraint_manager_->delete_rule(equality_rule_);

    // If validated no more assigned, otherwise still assigned.
    assigned_ = !(constraint_manager_->validate());

    ACE_DEBUG((LM_TRACE, "EXIT: Option::clear()\n"));
    return !assigned_;
  }

  inline bool
  Option::value(const Option_Value* value)
  {
    ACE_DEBUG((LM_TRACE, "ENTER: Option::value(const Option_Value*)\n"));
    bool initially_assigned = assigned_;

    Constraint_Engine::rule_index tmp_equality_rule = equality_rule_;
   
    if (assigned_)
    {
      constraint_manager_->delete_rule(equality_rule_);
    }

    equality_rule_ =
      constraint_manager_->define_equality_rule(definition_, value);

    constraint_manager_->add_rule(equality_rule_);

    // If validated now assigned, otherwise not assigned.
    assigned_ = constraint_manager_->validate();

    if (!assigned_)
    {
      constraint_manager_->delete_rule_definition(equality_rule_);
      if (initially_assigned)
      {
        equality_rule_ = tmp_equality_rule;
        constraint_manager_->add_rule(equality_rule_);
        constraint_manager_->validate();
      }
    }

    ACE_DEBUG((LM_TRACE, "EXIT: Option::value(const Option_Value*)\n"));
    return assigned_;
  }

} // namespace OCML
