#include <engine/constraint_engine.hpp>
#include <engine/definitions.hpp>
#include <engine/option_value.hpp>
#include <map>
#include <list>
#include <memory>
#include <ace/Log_Msg.h>
#include "option_value_test.hpp"

using OCML::Constraint_Value_Change_Listener;
using OCML::Option_Definition;
using OCML::Constraint_Engine;
using OCML::Option_Category;
using OCML::Option_Value;
using OCML::Option_Definition;

class Value_Change_Listener: public Constraint_Value_Change_Listener
{
public:
  Value_Change_Listener(Option_Definition* option)
    : option_(option)
  {
  }

  virtual void value_changed(bool flagged, Option_Value* value)
  {
    ACE_DEBUG((LM_TRACE, "ENTER: %s\n",
          "Value_Change_Listener::value_changed(bool, Option_Value*)"));
    std::cout << option_->name();
    if (flagged)
      std::cout << "*";
    if (value->is_null())
      std::cout << " = NULL\n";
    else
      std::cout  << " = " << value->str_value() << std::endl;
    ACE_DEBUG((LM_TRACE, "EXIT: %s\n",
          "Value_Change_Listener::value_changed(bool, Option_Value*)"));
  }

private:
  Option_Definition* option_;
};

typedef std::map<Option_Definition*, Value_Change_Listener*>
  listener_map;

listener_map*
create_listeners(Option_Category* category, Constraint_Engine& engine)
{
  ACE_DEBUG((LM_TRACE, "ENTER: %s\n",
        "create_listeners(Option_Category*, Constraint_Engine&)"));
  listener_map* result = new listener_map;
  for (Option_Category::option_iterator iter = category->begin_options();
       iter != category->end_options(); ++iter)
  {
    Value_Change_Listener* listener = new Value_Change_Listener(*iter);
    (*result)[*iter] = listener;
    engine.register_listener(*iter, listener);
  }
  ACE_DEBUG((LM_TRACE, "EXIT: %s\n",
        "create_listeners(Option_Category*, Constraint_Engine&)"));
  return result;
}

void delete_listeners(listener_map* listeners, Constraint_Engine& engine)
{
  ACE_DEBUG((LM_TRACE, "ENTER: %s\n",
        "delete_listeners(listener_map*, Constraint_Engine&)"));
  for (listener_map::iterator iter=listeners->begin();
       iter != listeners->end(); ++iter)
  {
    engine.unregister_listener(iter->first);
    delete iter->second;
  }
  ACE_DEBUG((LM_TRACE, "EXIT: %s\n",
        "delete_listeners(listener_map*, Constraint_Engine&)"));
}

void assign_values(Option_Category* category, Constraint_Engine& engine)
{
  ACE_DEBUG((LM_TRACE, "ENTER: %s\n",
        "assign_values(Option_Category*, Constraint_Engine&)"));
  std::list<Constraint_Engine::rule_index> indexes;
  std::auto_ptr<option_value_map> values(create_values(category));

  for (Option_Category::option_iterator iter = category->begin_options();
       iter != category->end_options(); ++iter)
  {
    Constraint_Engine::rule_index index =
      engine.define_equality_rule(*iter, (*values.get())[*iter]);
    engine.add_rule(index);
    indexes.push_back(index);
  }

  // validation check.
  if (engine.validate() == true)
  {
    std::cout << "Option selection succeeds" << std::endl;
  }
  else
  {
    std::cout << "Option selection doesn't succeed" << std::endl;
    for (std::list<Constraint_Engine::rule_index>::iterator
          iter = indexes.begin();
        iter != indexes.end(); ++iter)
    {
      engine.delete_rule(*iter);
    }
  }
  ACE_DEBUG((LM_TRACE, "EXIT: %s\n",
        "assign_values(Option_Category*, Constraint_Engine&)"));
}

