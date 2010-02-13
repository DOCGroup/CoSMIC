// -*- C++ -*-
// $Id$

///////////////////////////////////////////////////////////////////////////////
// T3_String_Literal_Node

//
// T3_String_Literal_Node
//
inline
T3_String_Literal_Node::T3_String_Literal_Node (const char * value)
: value_ (value)
{

}

//
// ~T3_String_Literal_Node
//
inline
T3_String_Literal_Node::~T3_String_Literal_Node (void)
{

}

//
// value
//
inline
const ACE_CString & T3_String_Literal_Node::value (void) const
{
  return this->value_;
}

///////////////////////////////////////////////////////////////////////////////
// T3_Keyword_Node

//
// T3_Keyword_Node
//
inline
T3_Keyword_Node::T3_Keyword_Node (const char * keyword, const char * type)
: T3_String_Literal_Node (keyword),
  element_type_ (type)
{

}

//
// ~T3_Keyword_Node
//
inline
T3_Keyword_Node::~T3_Keyword_Node (void)
{

}

//
// element_type
//
inline
const ACE_CString & T3_Keyword_Node::element_type (void) const
{
  return this->element_type_;
}
