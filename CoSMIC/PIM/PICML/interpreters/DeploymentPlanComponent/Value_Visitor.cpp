// $Id: Value_Visitor.cpp 2261 2010-06-16 16:47:55Z hillj $

#include "Value_Visitor.h"

//
// PICML_Value_Visitor
//
PICML_Value_Visitor::
PICML_Value_Visitor (xercesc::DOMElement * parent, const std::string value)
: curr (parent), datavalue_ (value)
{

}

//
// Visit_Boolean
//
void PICML_Value_Visitor::
Visit_Boolean (const PICML::Boolean & )
{
  this->create_simple_content (curr, "boolean", this->datavalue_);
}

//
// Visit_Byte
//
void PICML_Value_Visitor::
Visit_Byte (const PICML::Byte & )
{
  this->create_simple_content (curr, "octet", this->datavalue_);
}

//
// Visit_Char
//
void PICML_Value_Visitor::Visit_Char (const PICML::Char & )
{
  this->create_simple_content (curr, "char", this->datavalue_);
}

//
// Visit_WideChar
//
void PICML_Value_Visitor::Visit_WideChar (const PICML::WideChar & )
{
  this->create_simple_content (curr, "wchar", this->datavalue_);
}

//
// Visit_String
//
void PICML_Value_Visitor::
Visit_String (const PICML::String & )
{
  this->create_simple_content (curr, "string", this->datavalue_);
}

//
// Visit_WideString
//
void PICML_Value_Visitor::
Visit_WideString (const PICML::WideString & )
{
  this->create_simple_content (curr, "wstring", this->datavalue_);
}

//
// Visit_FloatNumber
//
void PICML_Value_Visitor::
Visit_FloatNumber (const PICML::FloatNumber & )
{
  this->create_simple_content (curr, "float", this->datavalue_);
}

//
// Visit_DoubleNumber
//
void PICML_Value_Visitor::
Visit_DoubleNumber (const PICML::DoubleNumber & )
{
  this->create_simple_content (curr, "double", this->datavalue_);
}

//
// Visit_LongDoubleNumber
//
void PICML_Value_Visitor::
Visit_LongDoubleNumber (const PICML::LongDoubleNumber & )
{
  this->create_simple_content (curr, "longdouble", this->datavalue_);
}

//
// Visit_UnsignedShortInteger
//
void PICML_Value_Visitor::
Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & )
{
  this->create_simple_content (curr, "ushort", this->datavalue_);
}

//
// Visit_UnsignedLongInteger
//
void PICML_Value_Visitor::
Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & )
{
  this->create_simple_content (curr, "ulong", this->datavalue_);
}

//
// Visit_UnsignedLongLongInteger
//
void PICML_Value_Visitor::
Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & )
{
  this->create_simple_content (curr, "ulonglong", this->datavalue_);
}

//
// Visit_ShortInteger
//
void PICML_Value_Visitor::
Visit_ShortInteger (const PICML::ShortInteger & )
{
  this->create_simple_content (curr, "short", this->datavalue_);
}

//
// Visit_LongInteger
//
void PICML_Value_Visitor::
Visit_LongInteger (const PICML::LongInteger & )
{
  this->create_simple_content (curr, "long", this->datavalue_);
}

//
// Visit_LongLongInteger
//
void PICML_Value_Visitor::
Visit_LongLongInteger (const PICML::LongLongInteger & )
{
  this->create_simple_content (curr, "longlong", this->datavalue_);
}

//
// Visit_Enum
//
void PICML_Value_Visitor::
Visit_Enum (const PICML::Enum & )
{
  this->create_simple_content (curr, "enum", this->datavalue_);
}