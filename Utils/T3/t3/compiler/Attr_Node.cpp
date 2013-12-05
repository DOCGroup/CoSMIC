// $Id$

#include "Attr_Node.h"
#include "Node_Visitor.h"

///////////////////////////////////////////////////////////////////////////////
// T3_Boolean_Attr_Node

void T3_Boolean_Attr_Node::accept (T3_Node_Visitor & visitor)
{
  visitor.visit_Boolean_Attr_Node (*this);
}

int T3_Boolean_Attr_Node::true_value (const char * name)
{
  if (this->has_true_value ())
    return -1;

  ACE_CString * temp_str;
  ACE_NEW_RETURN (temp_str, ACE_CString (name), -1);
  this->true_value_.reset (temp_str);

  return 0;
}

int T3_Boolean_Attr_Node::false_value (const char * name)
{
  if (this->has_false_value ())
    return -1;

  ACE_CString * temp_str;
  ACE_NEW_RETURN (temp_str, ACE_CString (name), -1);
  this->false_value_.reset (temp_str);

  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// T3_Integer_Attr_Node

void T3_Integer_Attr_Node::accept (T3_Node_Visitor & visitor)
{
  visitor.visit_Integer_Attr_Node (*this);
}

///////////////////////////////////////////////////////////////////////////////
// T3_String_Attr_Node

void T3_String_Attr_Node::accept (T3_Node_Visitor & visitor)
{
  visitor.visit_String_Attr_Node (*this);
}

///////////////////////////////////////////////////////////////////////////////
// T3_Real_Attr_Node

void T3_Real_Attr_Node::accept (T3_Node_Visitor & visitor)
{
  visitor.visit_Real_Attr_Node (*this);
}

