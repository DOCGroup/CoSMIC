// -*- C++ -*-
// $Id$

///////////////////////////////////////////////////////////////////////////////
// T3_Attr_Node

//
// T3_Attr_Node
//
inline
T3_Attr_Node::T3_Attr_Node (void)
{

}

//
// ~T3_Attr_Node
//
inline
T3_Attr_Node::~T3_Attr_Node (void)
{

}

inline
void T3_Attr_Node::name (const ACE_CString & name)
{
  this->name_ = name;
}

inline
const ACE_CString & T3_Attr_Node::name (void) const
{
  return this->name_;
}

//
// is_anonymous
//
inline
bool T3_Attr_Node::is_anonymous (void) const
{
  return this->name_.empty ();
}

///////////////////////////////////////////////////////////////////////////////
// T3_Boolean_Attr_Node

inline
T3_Boolean_Attr_Node::T3_Boolean_Attr_Node (void)
{

}

inline
T3_Boolean_Attr_Node::~T3_Boolean_Attr_Node (void)
{

}

inline
const ACE_CString * T3_Boolean_Attr_Node::true_value (void) const
{
  return this->true_value_.get ();
}

inline
bool T3_Boolean_Attr_Node::has_true_value (void) const
{
  return this->true_value_.get () != 0;
}

inline
const ACE_CString * T3_Boolean_Attr_Node::false_value (void) const
{
  return this->false_value_.get ();
}

inline
bool T3_Boolean_Attr_Node::has_false_value (void) const
{
  return this->false_value_.get () != 0;
}

///////////////////////////////////////////////////////////////////////////////
// T3_String_Attr_Node

inline
T3_String_Attr_Node::T3_String_Attr_Node (void)
{

}

inline
T3_String_Attr_Node::~T3_String_Attr_Node (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// T3_Integer_Attr_Node

inline
T3_Integer_Attr_Node::T3_Integer_Attr_Node (void)
{

}

inline
T3_Integer_Attr_Node::~T3_Integer_Attr_Node (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// T3_Real_Attr_Node

inline
T3_Real_Attr_Node::T3_Real_Attr_Node (void)
{

}

inline
T3_Real_Attr_Node::~T3_Real_Attr_Node (void)
{

}
