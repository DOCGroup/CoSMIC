// $Id$

#include "stdafx.h"
#include "Model_Interpreter.h"

#if !defined (__GAME_INLINE__)
#include "Model_Interpreter.inl"
#endif

#include "game/mga/Transaction.h"

#include "parser/Property_Map.h"
#include "boost/bind.hpp"

#include "ace/Arg_Shifter.h"
#include "ace/ARGV.h"

//
// operator << (Property_Map &, const std::string & )
//
bool operator << (Property_Map & map, const std::string & params)
{
  // Convert the string into an argv list.
  ACE_ARGV_T <char> argv (params.c_str (), true);

  // Initialize the shifter with the argv list.
  int argc = argv.argc ();
  ACE_Arg_Shifter_T <char> shifter (argc, argv.argv ());

  // Parse the command-line arguments using the shifter.
  const char * option, * value;

  while (shifter.is_anything_left ())
  {
    // Get the next option in the argument vector.
    while (shifter.is_anything_left () && !shifter.is_option_next ())
      shifter.consume_arg ();

    if (shifter.is_anything_left ())
    {
      // Get the current option and its value.
      option = shifter.get_current ();
      value = shifter.get_the_parameter (option);

      // Insert the values into map.
      map[option] = 0 != value ? value : "";
    }
  }

  return true;
}


//
// Gme_Model_Interpreter
//
Gme_Model_Interpreter::
Gme_Model_Interpreter (const std::string & progid)
: interpreter_ (GAME::Mga::ComponentEx::impl_type::_load (progid))
{
  this->interpreter_->interactive (false);
}

//
// interpret
//
void Gme_Model_Interpreter::
interpret (GAME::Mga::Project project,
           GAME::Mga::FCO target,
           const std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  this->interpreter_->initialize (project);
  this->interpreter_->invoke (project, target, selected, flags);
}

//
// set_parameters
//
void Gme_Model_Interpreter::
set_parameters (const std::string & params)
{
  Property_Map prop_map;
  prop_map << params;

  Property_Map::iterator
    iter = prop_map.begin (),
    iter_end = prop_map.end ();

  for (; iter != iter_end; ++ iter)
    this->interpreter_->parameter (iter->key ().c_str (), iter->item ().c_str ());
}
