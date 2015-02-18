#include "StdAfx.h"
#include "Data_Type_Visitor.h"

#include "game/mga/utils/Position_Sort_T.h"
#include "game/xml/Swap_Fragment.h"

#include "PIM/PICML/ext/PICML/PICML.h"
#include "PIM/PICML/utils/game/Utility.h"

#include <set>

namespace PICML
{
namespace Xml
{

Data_Type_Visitor::
Data_Type_Visitor (GAME::Xml::Fragment parent)
: fragment_ (parent.create_element ("type"))
{

}

void Data_Type_Visitor::Visit_SimpleProperty (PICML::SimpleProperty_in prop)
{
  prop->refers_to_MemberType ()->accept (this);
}

void Data_Type_Visitor::Visit_ComplexProperty (PICML::ComplexProperty_in prop)
{
  prop->get_ComplexTypeReference ()->accept (this);
}

void Data_Type_Visitor::
visit_Boolean (PICML::Boolean_in b)
{
  this->fragment_.create_simple_content ("kind", "tk_boolean");
}

void Data_Type_Visitor::
visit_Byte (PICML::Byte_in b)
{
  this->fragment_.create_simple_content ("kind", "tk_octet");
}

//
// visit_Char
//
void Data_Type_Visitor::visit_Char (PICML::Char_in )
{
  this->fragment_.create_simple_content ("kind", "tk_char");
}

void Data_Type_Visitor::visit_WideChar (PICML::WideChar_in )
{
  this->fragment_.create_simple_content ("kind", "tk_wchar");
}

void Data_Type_Visitor::
visit_String (PICML::String_in s)
{
  this->fragment_.create_simple_content ("kind", "tk_string");
}

void Data_Type_Visitor::
visit_WideString (PICML::WideString_in s)
{
  this->fragment_.create_simple_content ("kind", "tk_wstring");
}

void Data_Type_Visitor::
visit_FloatNumber (PICML::FloatNumber_in fn)
{
  this->fragment_.create_simple_content ("kind", "tk_float");
}

void Data_Type_Visitor::
visit_DoubleNumber (PICML::DoubleNumber_in dn)
{
  this->fragment_.create_simple_content ("kind", "tk_double");
}

void Data_Type_Visitor::
visit_LongDoubleNumber (PICML::LongDoubleNumber_in dn)
{
  this->fragment_.create_simple_content ("kind", "tk_longdouble");
}

void Data_Type_Visitor::
visit_ShortInteger (PICML::ShortInteger_in si)
{
  this->fragment_.create_simple_content ("kind", "tk_short");
}

void Data_Type_Visitor::
visit_LongInteger (PICML::LongInteger_in li)
{
  this->fragment_.create_simple_content ("kind", "tk_long");
}

void Data_Type_Visitor::
visit_LongLongInteger (PICML::LongLongInteger_in li)
{
  this->fragment_.create_simple_content ("kind", "tk_longlong");
}

void Data_Type_Visitor::
visit_UnsignedShortInteger (PICML::UnsignedShortInteger_in si)
{
  this->fragment_.create_simple_content ("kind", "tk_ushort");
}

//
// visit_UnsignedLongInteger
//
void Data_Type_Visitor::
visit_UnsignedLongInteger (PICML::UnsignedLongInteger_in li)
{
  this->fragment_.create_simple_content ("kind", "tk_ulong");
}

void Data_Type_Visitor::
visit_UnsignedLongLongInteger (PICML::UnsignedLongLongInteger_in li)
{
  this->fragment_.create_simple_content ("kind", "tk_ulonglong");
}

void Data_Type_Visitor::visit_Enum (PICML::Enum_in e)
{
  this->fragment_.create_simple_content ("kind", "tk_enum");
  GAME::Xml::Fragment enum_element = this->fragment_.create_element ("enum");

  // Write the name and typeId to the document.
  enum_element.create_simple_content ("name", e->name ());
  enum_element.create_simple_content ("typeId", PICML::repository_id (e));

  // Write the members of the enumeration.
  typedef GAME::Mga::Position_Sort_T <PICML::EnumValue, GAME::Mga::PS_Top_To_Bottom> Sorter;
  Sorter sorter ("InterfaceDefinition", GAME::Mga::PS_Top_To_Bottom ());
  std::set <PICML::EnumValue, Sorter> sorted_values (sorter);

  for (PICML::EnumValue enum_value : e->get_EnumValues ())
    sorted_values.insert (enum_value);

  for (PICML::EnumValue enum_value : sorted_values)
    enum_value->accept (this);
}

void Data_Type_Visitor::visit_EnumValue (PICML::EnumValue_in ev)
{
  this->fragment_.create_simple_content ("member", ev->name ());
}

//
// visit_Collection
//
void Data_Type_Visitor::visit_Collection (PICML::Collection_in c)
{
  this->fragment_.create_simple_content ("kind", "tk_sequence");
  GAME::Xml::Swap_Fragment sequence (this->fragment_, this->fragment_.create_element ("sequence"));

  // Make sure we account for the sequence's size.
  std::string bound = c->bound ();

  if (!bound.empty ())
    this->fragment_.create_simple_content ("bound", bound);

  // Start the elementType for this part of the document.
  GAME::Xml::Swap_Fragment elementType (this->fragment_, this->fragment_.create_element ("elementType"));

  // Visit the member type. This will define the <kind> element
  // contained within the <elementType> element.
  c->refers_to ()->accept (this);
}

//
// visit_Aggregate
//
void Data_Type_Visitor::visit_Aggregate (PICML::Aggregate_in aggr)
{
  this->fragment_.create_simple_content ("kind", "tk_struct");
  GAME::Xml::Swap_Fragment aggregate (this->fragment_, this->fragment_.create_element ("struct"));

  // Write the name and typeId to the document.
  aggregate.create_simple_content ("name", aggr->name ());
  aggregate.create_simple_content ("typeId", PICML::repository_id (aggr));

  // Sort the elements by the position in the InterfaceDefinition aspect.
  typedef GAME::Mga::Position_Sort_T <PICML::Member, GAME::Mga::PS_Top_To_Bottom> Sorter;
  Sorter sorter ("InterfaceDefinition", GAME::Mga::PS_Top_To_Bottom ());

  typedef std::set <PICML::Member, Sorter> sorted_values_t;
  sorted_values_t sorted_values (sorter);

  for (PICML::Member member : aggr->get_Members ())
	  sorted_values.insert (member);

  for (PICML::Member member : sorted_values)
    member->accept (this);
}

void Data_Type_Visitor::visit_Member (PICML::Member_in m)
{
  GAME::Xml::Fragment member = this->fragment_.create_element ("member");
  member.create_simple_content ("name", m->name ());

  // We need to create the "type" for this member. We can do so just
  // by reusing this class/visitor to handle the generation.
  Data_Type_Visitor v (member);
  m->refers_to ()->accept (&v);
}

}
}
