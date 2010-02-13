// -*- C++ -*-
// $Id$

//
// T3_Substitution_Node
//
inline
T3_Substitution_Node::T3_Substitution_Node (const T3_Rule_Node * rule)
: rule_ (rule)
{

}

//
// ~T3_Substitution_Node
//
inline
T3_Substitution_Node::~T3_Substitution_Node (void)
{

}

//
// target_rule
//
inline
const T3_Rule_Node * T3_Substitution_Node::target_rule (void) const
{
  return this->rule_;
}
