// -*- C++ -*-
// $Id$

#include "Definition.h"

//
// T3_Selection_Node
//
inline
T3_Selection_Node::T3_Selection_Node (void)
{

}

//
// ~T3_Selection_Node
//
inline
T3_Selection_Node::~T3_Selection_Node (void)
{

}

//
// insert_option
//
inline
int T3_Selection_Node::insert_option (const T3_Definition & option)
{
  return this->options_.insert (option.start ());
}

//
// remove_option
//
inline
int T3_Selection_Node::remove_option (const T3_Definition & option)
{
  return this->options_.remove (option.start ());
}

//
// options
//
inline
const T3_Selection_Node::options_type &
T3_Selection_Node::options (void) const
{
  return this->options_;
}

//
// operator +=
inline
void operator += (T3_Selection_Node * selection, const T3_Definition & option)
{
  if (selection)
    selection->insert_option (option);
}
