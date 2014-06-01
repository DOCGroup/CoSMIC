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
// Visit_Char
//
void PICML_Data_Type_Visitor::Visit_Char (const PICML::Char & )
{
  this->create_simple_content ("kind", "tk_char");
}

//
// Visit_WideChar
//
void PICML_Data_Type_Visitor::Visit_WideChar (const PICML::WideChar & )
{
  this->create_simple_content ("kind", "tk_wchar");
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
// Visit_WideString
//
void PICML_Data_Type_Visitor::
Visit_WideString (const PICML::WideString & s)
{
  this->create_simple_content ("kind", "tk_wstring");
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
// Visit_LongDoubleNumber
//
void PICML_Data_Type_Visitor::
Visit_LongDoubleNumber (const PICML::LongDoubleNumber & dn)
{
  this->create_simple_content ("kind", "tk_longdouble");
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
// Visit_LongLongInteger
//
void PICML_Data_Type_Visitor::
Visit_LongLongInteger (const PICML::LongLongInteger & li)
{
  this->create_simple_content ("kind", "tk_longlong");
}

//
// Visit_UnsignedShortInteger
//
void PICML_Data_Type_Visitor::
Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & si)
{
  this->create_simple_content ("kind", "tk_ushort");
}

//
// Visit_UnsignedLongInteger
//
void PICML_Data_Type_Visitor::
Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & li)
{
  this->create_simple_content ("kind", "tk_ulong");
}

//
// Visit_UnsignedLongLongInteger
//
void PICML_Data_Type_Visitor::
Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & li)
{
  this->create_simple_content ("kind", "tk_ulonglong");
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
  typedef UDM_Position_Sort_T <PICML::EnumValue, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("InterfaceDefinition", PS_Top_To_Bottom ());
  std::set <PICML::EnumValue, sorter_t> sorted_values (sorter);
  sorted_values = e.EnumValue_kind_children_sorted (sorter);

  //typedef UDM_Position_Sort_T <PICML::EnumValue, PS_Top_To_Bottom> sort_type;
  //std::set <PICML::EnumValue, sort_type> values = e.EnumValue_children_sorted (sort_type ());

  std::swap (enum_element, this->curr_);
  for(auto sorted_value : sorted_values)
	  sorted_value.Accept(*this);

  std::swap (enum_element, this->curr_);
}

//
// Visit_EnumValue
//
void PICML_Data_Type_Visitor::Visit_EnumValue (const PICML::EnumValue & ev)
{
  this->create_simple_content ("member", ev.name ());
}

//
// Visit_Collection
//
void PICML_Data_Type_Visitor::Visit_Collection (const PICML::Collection & c)
{
  using namespace xercesc;

  this->create_simple_content ("kind", "tk_sequence");
  DOMElement * sequence = this->create_element ("sequence");

  // Make sure we account for the sequence's size.
  std::string bound = c.bound ();

  if (!bound.empty ())
    this->create_simple_content (sequence, "bound", bound);

  // Start the elementType for this part of the document.
  DOMElement * elementType = this->create_element (sequence, "elementType");
  std::swap (elementType, this->curr_);

  // Visit the member type. This will define the <kind> element
  // contained within the <elementType> element.
  PICML::MemberType mt = c.ref ();
  this->dispatcher_.dispatch (*this, mt);

  std::swap (elementType, this->curr_);
}

//
// Visit_Aggregate
//
void PICML_Data_Type_Visitor::Visit_Aggregate (const PICML::Aggregate & aggr)
{
  using namespace xercesc;

  this->create_simple_content ("kind", "tk_struct");
  DOMElement * aggregate = this->create_element ("struct");

  // Write the name and typeId to the document.
  this->create_simple_content (aggregate, "name", aggr.name ());
  this->create_simple_content (aggregate, "typeId", PICML::utils::repository_id (aggr));


  // Sort the elements by the position in the InterfaceDefinition aspect.
  typedef UDM_Position_Sort_T <PICML::Member, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("InterfaceDefinition", PS_Top_To_Bottom ());

  typedef std::set <PICML::Member, sorter_t> sorted_values_t;
  sorted_values_t sorted_values (sorter);

  std::vector <PICML::Member> members = aggr.Member_children ();
  for(auto & member : members)
	  sorted_values.insert(member);

  std::swap (aggregate, this->curr_);
  for(auto sorted_value : sorted_values)
	  sorted_value.Accept(*this);
  std::swap (aggregate, this->curr_);
}

//
// Visit_Member
//
void PICML_Data_Type_Visitor::Visit_Member (const PICML::Member & m)
{
  using namespace xercesc;

  DOMElement * member = this->create_element ("member");
  this->create_simple_content (member, "name", m.name ());

  // We need to create the "type" for this member. We can do so just
  // by reusing this class/visitor to handle the generation.
  PICML_Data_Type_Visitor v (member);
  this->dispatcher_.dispatch (v, m.ref ());
}
