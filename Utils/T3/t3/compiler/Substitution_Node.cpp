// $Id$

#include "Substitution_Node.h"
#include "Node_Visitor.h"

//
// accept
//
void T3_Substitution_Node::accept (T3_Node_Visitor & v)
{
  v.visit_Substitution_Node (*this);
}
