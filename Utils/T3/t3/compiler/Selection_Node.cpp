// $Id$

#include "Selection_Node.h"
#include "Node_Visitor.h"

//
// accept
//
void T3_Selection_Node::accept (T3_Node_Visitor & v)
{
  v.visit_Selection_Node (*this);
}
