// $Id$

#include "Data_Type_Visitor.h"
#include "Utils/UDM/Position_Sort_T.h"
#include "PIM/PICML/utils/udm/functional.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// PICML_Data_Type_Visitor
//
PICML_Data_Type_Visitor::
PICML_Data_Type_Visitor (xercesc::DOMElement * curr)
: XML_Document (this->create_element (curr, "type"))
{

}

//
// Visit_Boolean
//
void PICML_Data_Type_Visitor::
Visit_Boolean (const PICML::Boolean & b)
{
  this->create_simple_content ("kind", "tk_boolean");
}

//
// Visit_Byte
//
void PICML_Data_Type_Visitor::
Visit_Byte (const PICML::Byte & b)
{
  this->create_simple_content ("kind", "tk_octet");
}

//
// Visit_String
//
void PICML_Data_Type_Visitor::
Visit_String (const PICML::String & s)
{
  this->create_simple_content ("kind", "tk_string");
}

//
// Visit_FloatNumber
//
void PICML_Data_Type_Visitor::
Visit_FloatNumber (const PICML::FloatNumber & fn)
{
  this->create_simple_content ("kind", "tk_float");
}

//
// Visit_DoubleNumber
//
void PICML_Data_Type_Visitor::
Visit_DoubleNumber (const PICML::DoubleNumber & dn)
{
  this->create_simple_content ("kind", "tk_double");
}

//
// Visit_ShortInteger
//
void PICML_Data_Type_Visitor::
Visit_ShortInteger (const PICML::ShortInteger & si)
{
  this->create_simple_content ("kind", "tk_short");
}

//
// Visit_LongInteger
//
void PICML_Data_Type_Visitor::
Visit_LongInteger (const PICML::LongInteger & li)
{
  this->create_simple_content ("kind", "tk_long");
}

//
// Visit_Enum
//
void PICML_Data_Type_Visitor::Visit_Enum (const PICML::Enum & e)
{
  using namespace xercesc;

  this->create_simple_content ("kind", "tk_enum");
  DOMElement * enum_element = this->create_element ("enum");

  // Write the name and typeId to the document.
  this->create_simple_content (enum_element, "name", e.name ());
  this->create_simple_content (enum_element, "typeId", PICML::utils::repository_id (e));

  // Write the members of the enumeration.
  typedef UDM_Position_Sort_T <PICML::EnumValue, PS_Top_To_Bottom> sort_type;
  std::set <PICML::EnumValue, sort_type> values = e.EnumValue_children_sorted (sort_type ());

  std::swap (enum_element, this->curr_);
  std::for_each (values.begin (),
                 values.end (),
                 boost::bind (&PICML::EnumValue::Accept,
                              _1,
                              boost::ref (*this)));

  std::swap (enum_element, this->curr_);
}

//
// Visit_EnumValue
//
void PICML_Data_Type_Visitor::Visit_EnumValue (const PICML::EnumValue & ev)
{
  this->create_simple_content ("member", ev.name ());
}
