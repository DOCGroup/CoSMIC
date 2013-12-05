// -*- C++ -*-
// $Id$

//
// T3_Rule_Node
//
inline
T3_Rule_Node::T3_Rule_Node (const ACE_CString & name)
: name_ (name)
{

}

//
// ~T3_Rule_Node
//
inline
T3_Rule_Node::~T3_Rule_Node (void)
{

}

//
// name
//
inline
const ACE_CString & T3_Rule_Node::name (void) const
{
  return this->name_;
}

//
// length
//
inline
size_t T3_Rule_Node::length (void) const
{
  return this->is_end () ? 0 : T3_Node::length ();
}
