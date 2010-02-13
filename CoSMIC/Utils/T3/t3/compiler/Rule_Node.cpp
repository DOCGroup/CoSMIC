// $Id$

#include "Rule_Node.h"
#include "Node_Visitor.h"

//
// accept
//
void T3_Rule_Node::accept (T3_Node_Visitor & v)
{
  v.visit_Rule_Node (*this);
}
