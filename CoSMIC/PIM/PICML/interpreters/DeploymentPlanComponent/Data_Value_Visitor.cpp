// $Id$

#include "Data_Value_Visitor.h"

//
// PICML_Data_Value_Visitor
//
PICML_Data_Value_Visitor::
PICML_Data_Value_Visitor (xercesc::DOMElement * curr, const PICML::Property & prop)
: XML_Document (this->create_element (curr, "value")),
  prop_ (prop)
{

}

//
// Visit_Boolean
//
void PICML_Data_Value_Visitor::
Visit_Boolean (const PICML::Boolean & )
{
  this->create_simple_content ("boolean", this->prop_.DataValue ());
}

//
// Visit_Byte
//
void PICML_Data_Value_Visitor::
Visit_Byte (const PICML::Byte & )
{
  this->create_simple_content ("octet", this->prop_.DataValue ());
}

//
// Visit_String
//
void PICML_Data_Value_Visitor::
Visit_String (const PICML::String & )
{
  this->create_simple_content ("string", this->prop_.DataValue ());
}

//
// Visit_FloatNumber
//
void PICML_Data_Value_Visitor::
Visit_FloatNumber (const PICML::FloatNumber & )
{
  this->create_simple_content ("float", this->prop_.DataValue ());
}

//
// Visit_DoubleNumber
//
void PICML_Data_Value_Visitor::
Visit_DoubleNumber (const PICML::DoubleNumber & )
{
  this->create_simple_content ("double", this->prop_.DataValue ());
}

//
// Visit_ShortInteger
//
void PICML_Data_Value_Visitor::
Visit_ShortInteger (const PICML::ShortInteger & )
{
  this->create_simple_content ("short", this->prop_.DataValue ());
}

//
// Visit_LongInteger
//
void PICML_Data_Value_Visitor::
Visit_LongInteger (const PICML::LongInteger & )
{
  this->create_simple_content ("long", this->prop_.DataValue ());
}

//
// Visit_LongInteger
//
void PICML_Data_Value_Visitor::
Visit_Enum (const PICML::Enum & )
{
  this->create_simple_content ("enum", this->prop_.DataValue ());
}
