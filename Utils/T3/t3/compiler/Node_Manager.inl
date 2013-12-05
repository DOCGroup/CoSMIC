// -*- C++ -*-
// $Id$

//
// T3_Node_Manager
//
inline
T3_Node_Manager::T3_Node_Manager (void)
{

}

//
// rules
//
inline
const T3_Node_Manager::rule_map_type &
T3_Node_Manager::rules (void) const
{
  return this->rule_map_;
}
