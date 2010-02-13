// $Id$

#include "String_Literal_Node.h"
#include "Node_Visitor.h"

//
// accept
//
void T3_String_Literal_Node::accept (T3_Node_Visitor & v)
{
  v.visit_String_Literal_Node (*this);
}

//
// accept
//
void T3_Keyword_Node::accept (T3_Node_Visitor & v)
{
  v.visit_Keyword_Node (*this);
}
