// -*- C++ -*-
// $Id$

//
// T3_Optional_Node
//
inline
T3_Optional_Node::T3_Optional_Node (T3_Node * definition)
: definition_ (definition)
{

}

//
// ~T3_Optional_Node
//
inline
T3_Optional_Node::~T3_Optional_Node (void)
{

}

//
// definition
//
inline
T3_Node * T3_Optional_Node::definition (void) const
{
  return this->definition_;
}
