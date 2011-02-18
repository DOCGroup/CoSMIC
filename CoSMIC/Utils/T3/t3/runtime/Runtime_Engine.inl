// -*- C++ -*-
// $Id$

#include "game/mga/Attribute.h"

//
// T3_Runtime_Engine
//
inline
T3_Runtime_Engine::T3_Runtime_Engine (void)
{

}

//
// ~T3_Runtime_Engine
//
inline
T3_Runtime_Engine::~T3_Runtime_Engine (void)
{

}

//
// set_attribute
//
inline
void T3_Runtime_Engine::
set_attribute (GAME::Mga::FCO_in fco, const std::string & name, bool value)
{
  fco->attribute (name)->bool_value (value);
}

//
// set_attribute
//
inline
void T3_Runtime_Engine::
set_attribute (GAME::Mga::FCO_in fco, const std::string & name, long value)
{
  fco->attribute (name)->int_value (value);
}

//
// set_attribute
//
inline
void T3_Runtime_Engine::
set_attribute (GAME::Mga::FCO_in fco, const std::string & name, double value)
{
  fco->attribute (name)->double_value (value);
}

//
// store_flag
//
inline
bool T3_Runtime_Engine::store_attribute (const std::string & name, bool value)
{
  return
    this->stored_flags_.bind (name.c_str (), value) == 0 ?
    true : false;
}

//
// store_attribute
//
inline
bool T3_Runtime_Engine::store_attribute (const std::string & name, double value)
{
  return
    this->stored_doubles_.bind (name.c_str (), value) == 0 ?
    true : false;
}

//
// store_attribute
//
inline
bool T3_Runtime_Engine::store_attribute (const std::string & name, int value)
{
  return
    this->stored_ints_.bind (name.c_str (), value) == 0 ?
    true : false;
}

//
// store_attribute
//
inline
bool T3_Runtime_Engine::
store_attribute (const std::string & name, const std::string & value)
{
  return
    this->stored_strings_.bind (name.c_str (), value) == 0 ?
    true : false;
}

//
// symbols
//
inline
const T3_Runtime_Engine::SYMBOL_TABLE &
T3_Runtime_Engine::symbols (void) const
{
  return this->sym_table_;
}

//
// symbols
//
inline
T3_Runtime_Engine::SYMBOL_TABLE & T3_Runtime_Engine::symbols (void)
{
  return this->sym_table_;
}

inline
T3_Event_Listener * T3_Runtime_Engine::event_listener (void)
{
  return this->listener_;
}

inline
void T3_Runtime_Engine::event_listener (T3_Event_Listener * listener)
{
  this->listener_ = listener;
}
