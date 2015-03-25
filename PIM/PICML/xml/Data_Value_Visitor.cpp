#include "StdAfx.h"

#include "Data_Value_Visitor.h"
#include "PIM/PICML/ext/PICML/PICML.h"
#include "game/mga/utils/Position_Sort_T.h"
#include "game/xml/Swap_Fragment.h"

#include <set>

namespace PICML
{
namespace Xml
{

Data_Value_Visitor::
Data_Value_Visitor (GAME::Xml::Fragment parent)
: fragment_ (parent.append_element ("value")),
  container_ (NONE)
{

}

Data_Value_Visitor::
Data_Value_Visitor (GAME::Xml::Fragment parent, const std::string & value)
: fragment_ (parent.append_element ("value")),
  value_ (value),
  container_ (NONE)
{

}

void Data_Value_Visitor::visit_DataType (PICML::DataType_in dt)
{
  dt->refers_to ()->accept (this);
}

void Data_Value_Visitor::
visit_Boolean (PICML::Boolean_in )
{
  this->fragment_.append_simple_content ("boolean", this->value_);
}

void Data_Value_Visitor::
visit_Byte (PICML::Byte_in )
{
  this->fragment_.append_simple_content ("octet", this->value_);
}

void Data_Value_Visitor::visit_Char (PICML::Char_in )
{
  this->fragment_.append_simple_content ("char", this->value_);
}

void Data_Value_Visitor::visit_WideChar (PICML::WideChar_in )
{
  this->fragment_.append_simple_content ("wchar", this->value_);
}

void Data_Value_Visitor::
visit_String (PICML::String_in )
{
  this->fragment_.append_simple_content ("string", this->value_);
}

void Data_Value_Visitor::
visit_WideString (PICML::WideString_in )
{
  this->fragment_.append_simple_content ("wstring", this->value_);
}

void Data_Value_Visitor::
visit_FloatNumber (PICML::FloatNumber_in )
{
  this->fragment_.append_simple_content ("float", this->value_);
}

void Data_Value_Visitor::
visit_DoubleNumber (PICML::DoubleNumber_in )
{
  this->fragment_.append_simple_content ("double", this->value_);
}

void Data_Value_Visitor::
visit_LongDoubleNumber (PICML::LongDoubleNumber_in )
{
  this->fragment_.append_simple_content ("longdouble", this->value_);
}

void Data_Value_Visitor::
visit_UnsignedShortInteger (PICML::UnsignedShortInteger_in )
{
  this->fragment_.append_simple_content ("ushort", this->value_);
}

void Data_Value_Visitor::
visit_UnsignedLongInteger (PICML::UnsignedLongInteger_in )
{
  this->fragment_.append_simple_content ("ulong", this->value_);
}

void Data_Value_Visitor::
visit_UnsignedLongLongInteger (PICML::UnsignedLongLongInteger_in )
{
  this->fragment_.append_simple_content ("ulonglong", this->value_);
}

void Data_Value_Visitor::
visit_ShortInteger (PICML::ShortInteger_in )
{
  this->fragment_.append_simple_content ("short", this->value_);
}

void Data_Value_Visitor::
visit_LongInteger (PICML::LongInteger_in )
{
  this->fragment_.append_simple_content ("long", this->value_);
}

void Data_Value_Visitor::
visit_LongLongInteger (PICML::LongLongInteger_in )
{
  this->fragment_.append_simple_content ("longlong", this->value_);
}

void Data_Value_Visitor::
visit_Enum (PICML::Enum_in )
{
  this->fragment_.append_simple_content ("enum", this->value_);
}

void Data_Value_Visitor::
visit_DataValue (PICML::DataValue_in value)
{
  switch (this->container_)
  {
  case AGGREGATE:
    {
      GAME::Xml::Fragment member = this->fragment_.append_element ("member");
      member.append_simple_content ("name", value->name ());

      // We can now visit the value using this visitor.
      Data_Value_Visitor dvv (member, this->value_);
      value->accept (&dvv);
    }
    break;

  case SEQUENCE:
    {
      GAME::Xml::Swap_Fragment element (this->fragment_, this->fragment_.append_element ("element"));

      container_t old = NONE;

      std::swap (old, this->container_);
      value->accept (this);
      std::swap (old, this->container_);
    }
    break;

  case NONE:
    // Store the value for later usage.
    this->value_ = value->Value ();

    // Visit the value's type. This will generate the correct value
    // element for this data value.
    value->refers_to ()->accept (this);
  };
}

Data_Value_Visitor::
Container_Setter::Container_Setter (container_t & container)
: container_ (container)
{

}

void Data_Value_Visitor::
Container_Setter::visit_Collection (PICML::Collection_in coll)
{
  this->container_ = SEQUENCE;
}

void Data_Value_Visitor::
Container_Setter::visit_Aggregate (PICML::Aggregate_in aggr)
{
  this->container_ = AGGREGATE;
}

void Data_Value_Visitor::
visit_DataValueContainer (PICML::DataValueContainer_in c)
{
  if (this->container_ == AGGREGATE)
  {
    // We are dealing with a struct parent container.
    GAME::Xml::Fragment member = this->fragment_.append_element ("member");
    member.append_simple_content ("name", c->name ());

    // We can now visit the value using this visitor.
    Data_Value_Visitor dvv (member, this->value_);
    c->accept (&dvv);
  }
  else if (this->container_ == SEQUENCE)
  {
    // We are dealing with a sequence parent container.
    GAME::Xml::Swap_Fragment member (this->fragment_, this->fragment_.append_element ("member"));
    container_t old = NONE;

    c->accept (this);
  }
  else /* container_ == NONE */
  {
    // Determine the container class.
    PICML::ComplexTypeReference complex = c->get_ComplexTypeReference ();
    PICML::ComplexType t = complex->refers_to_ComplexType ();
    Container_Setter setter (this->container_);
    t->accept (&setter);

    // Select the DataValueBase elements from top to bottom. This has
    // to be done in two phases since UDM does not allow you to initialize
    // the collection with the sort function.
    typedef GAME::Mga::Position_Sort_T <PICML::DataValueBase, GAME::Mga::PS_Top_To_Bottom> Sorter;
    Sorter sorter ("DataValueAspect", GAME::Mga::PS_Top_To_Bottom ());

    typedef std::set <PICML::DataValueBase, Sorter> sorted_values_t;
    sorted_values_t sorted_values (sorter);

    for (PICML::DataValueBase dvb : c->get_DataValues ())
      sorted_values.insert (dvb);

    // Visit each member of the container.
    for (PICML::DataValueBase dvb : sorted_values)
      dvb->accept (this);
  }
}

void Data_Value_Visitor::visit_SimpleProperty (PICML::SimpleProperty_in prop)
{
  this->value_ = prop->Value ();
  prop->refers_to_MemberType ()->accept (this);
}

void Data_Value_Visitor::visit_ComplexProperty (PICML::ComplexProperty_in prop)
{
  PICML::ComplexTypeReference complex = prop->get_ComplexTypeReference ();
  PICML::ComplexType t = complex->refers_to_ComplexType ();

  // Store the container's type for later usage.
  Container_Setter setter (this->container_);
  t->accept (&setter);

  // Select the DataValueBase elements from top to bottom. This has
  // to be done in two phases since UDM does not allow you to initialize
  // the collection with the sort function.
  typedef GAME::Mga::Position_Sort_T <PICML::DataValueBase, GAME::Mga::PS_Top_To_Bottom> Sorter;
  Sorter sorter ("DataValueAspect", GAME::Mga::PS_Top_To_Bottom ());

  typedef std::set <PICML::DataValueBase, Sorter> sorted_values_t;
  sorted_values_t sorted_values (sorter);

  for (PICML::DataValueBase base : prop->get_DataValues ())
	  sorted_values.insert (base);

  // Visit each member of the container.
  for (PICML::DataValueBase base : sorted_values)
    base->accept (this);
}

}
}
