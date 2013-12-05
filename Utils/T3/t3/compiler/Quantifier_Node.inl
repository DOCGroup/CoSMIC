// -*- C++ -*-
// $Id$

//
// T3_Quantifier_Node
//
inline
T3_Quantifier_Node::T3_Quantifier_Node (void)
: quantifier_ (Q_NONE)
{

}

//
// ~T3_Quantifier_Node
//
inline
T3_Quantifier_Node::~T3_Quantifier_Node (void)
{

}

//
// quantifier_value
//
inline
T3_Quantifier_Node::type_t
T3_Quantifier_Node::quantifier_value (void) const
{
  return this->quantifier_;
}

//
// quantifier_value
//
inline
void T3_Quantifier_Node::quantifier_value (type_t type)
{
  this->quantifier_ = type;
}
