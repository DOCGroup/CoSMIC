// $Id$

#include "Optional_Node.h"
#include "Node_Visitor.h"

//
// accept
//
void T3_Optional_Node::accept (T3_Node_Visitor & visitor)
{
  visitor.visit_Optional_Node (*this);
}
