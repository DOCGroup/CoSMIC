// $Id: Complex_Type_Visitor.cpp 2261 2010-06-16 16:47:55Z hillj $

#include "Complex_Type_Visitor.h"
#include "Utils/UDM/Position_Sort_T.h"
#include "PIM/PICML/utils/udm/functional.h"
#include "boost/bind.hpp"
#include <algorithm>

#include "Utils/xercesc/XercesString.h"

using Utils::XStr;

//
// PICML_Complex_Type_Visitor
//
PICML_Complex_Type_Visitor::
PICML_Complex_Type_Visitor (xercesc::DOMElement * parent)
: curr_ (parent)
{

}

//
// Visit_Boolean
//
void PICML_Complex_Type_Visitor::
Visit_Boolean (const PICML::Boolean & b)
{
  this->create_simple_content (curr_, "kind", "tk_boolean");
}

//
// Visit_Byte
//
void PICML_Complex_Type_Visitor::
Visit_Byte (const PICML::Byte & b)
{
  this->create_simple_content (curr_, "kind", "tk_octet");
}

//
// Visit_Char
//
void PICML_Complex_Type_Visitor::Visit_Char (const PICML::Char & )
{
  this->create_simple_content (curr_, "kind", "tk_char");
}

//
// Visit_WideChar
//
void PICML_Complex_Type_Visitor::Visit_WideChar (const PICML::WideChar & )
{
  this->create_simple_content (curr_, "kind", "tk_wchar");
}

//
// Visit_String
//
void PICML_Complex_Type_Visitor::
Visit_String (const PICML::String & s)
{
  this->create_simple_content (curr_, "kind", "tk_string");
}

//
// Visit_WideString
//
void PICML_Complex_Type_Visitor::
Visit_WideString (const PICML::WideString & s)
{
  this->create_simple_content (curr_, "kind", "tk_wstring");
}

//
// Visit_FloatNumber
//
void PICML_Complex_Type_Visitor::
Visit_FloatNumber (const PICML::FloatNumber & fn)
{
  this->create_simple_content (curr_, "kind", "tk_float");
}

//
// Visit_DoubleNumber
//
void PICML_Complex_Type_Visitor::
Visit_DoubleNumber (const PICML::DoubleNumber & dn)
{
  this->create_simple_content (curr_, "kind", "tk_double");
}

//
// Visit_LongDoubleNumber
//
void PICML_Complex_Type_Visitor::
Visit_LongDoubleNumber (const PICML::LongDoubleNumber & dn)
{
  this->create_simple_content (curr_, "kind", "tk_longdouble");
}

//
// Visit_ShortInteger
//
void PICML_Complex_Type_Visitor::
Visit_ShortInteger (const PICML::ShortInteger & si)
{
  this->create_simple_content (curr_, "kind", "tk_short");
}

//
// Visit_LongInteger
//
void PICML_Complex_Type_Visitor::
Visit_LongInteger (const PICML::LongInteger & li)
{
  this->create_simple_content (curr_, "kind", "tk_long");
}

//
// Visit_LongLongInteger
//
void PICML_Complex_Type_Visitor::
Visit_LongLongInteger (const PICML::LongLongInteger & li)
{
  this->create_simple_content (curr_, "kind", "tk_longlong");
}

//
// Visit_UnsignedShortInteger
//
void PICML_Complex_Type_Visitor::
Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & si)
{
  this->create_simple_content (curr_, "kind", "tk_ushort");
}

//
// Visit_UnsignedLongInteger
//
void PICML_Complex_Type_Visitor::
Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & li)
{
  this->create_simple_content (curr_, "kind", "tk_ulong");
}

//
// Visit_UnsignedLongLongInteger
//
void PICML_Complex_Type_Visitor::
Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & li)
{
  this->create_simple_content (curr_, "kind", "tk_ulonglong");
}

//
// Visit_Enum
//
void PICML_Complex_Type_Visitor::Visit_Enum (const PICML::Enum & e)
{
  using namespace xercesc;

  this->create_simple_content (curr_, "kind", "tk_enum");
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
void PICML_Complex_Type_Visitor::Visit_EnumValue (const PICML::EnumValue & ev)
{
  this->create_simple_content ("member", ev.name ());
}


//
// Visit_Aggregate
//
void PICML_Complex_Type_Visitor::Visit_Aggregate (const PICML::Aggregate & agg)
{
  this->create_simple_content (curr_, "kind", "tk_struct");
  this->process_aggregate_type (agg);
}


//
// process_aggregate_type
//
void  PICML_Complex_Type_Visitor::
process_aggregate_type (const PICML::Aggregate & agg)
{
  xercesc::DOMElement * root_struct = this->create_element (curr_, "struct");
  this->create_simple_content (root_struct, "name", agg.name ());
  this->create_simple_content (root_struct, "typeId", PICML::utils::repository_id (agg));

  std::set <PICML::Member> mems = agg.Member_children ();

  for ( set <PICML::Member>::iterator p = mems.begin( ); p != mems.end( ); ++p )
  {
    xercesc::DOMElement * member  = this->create_element (root_struct, "member");
    this->create_simple_content (member, "name", p->name ());

    xercesc::DOMElement * inner_type  = this->create_element (member, "type");
    PICML_Complex_Type_Visitor cctv (inner_type);
    PICML::MemberType mt = p->ref ();
    this->datatypes_.dispatch (cctv, p->ref ());
  }
}


//
// Visit_Collection
//
void PICML_Complex_Type_Visitor::Visit_Collection (const PICML::Collection & coll)
{
  this->create_simple_content (curr_, "kind", "tk_sequence");
  this->process_collection_type (coll);
}


//
// process_collection_type
//
void  PICML_Complex_Type_Visitor::
process_collection_type (const PICML::Collection & coll)
{
  xercesc::DOMElement * root_struct = this->create_element (curr_, "sequence");
  std::string temp (coll.bound ());
  if(temp.length () != 0)
  {
    this->create_simple_content (root_struct, "bound", temp);
  }
  xercesc::DOMElement * element_type = this->create_element (root_struct, "elementType");

  PICML_Complex_Type_Visitor ctv (element_type);
  PICML::MemberType mt = coll.ref ();
  this->datatypes_.dispatch (ctv, mt);
}
