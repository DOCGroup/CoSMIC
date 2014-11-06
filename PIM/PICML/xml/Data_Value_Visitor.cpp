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
Data_Value_Visitor (const GAME::Xml::Fragment & parent, const std::string & value)
: fragment_ (parent),
  value_ (value),
  container_ (NONE)
{

}

void Data_Value_Visitor::visit_DataType (PICML::DataType_in dt)
{
  GAME::Xml::Swap_Fragment fragment (this->fragment_, this->fragment_.create_element ("value"));
  dt->refers_to ()->accept (this);
}

//
// Visit_Boolean
//
void Data_Value_Visitor::
Visit_Boolean (PICML::Boolean_in )
{
  this->fragment_.create_simple_content ("boolean", this->value_);
}

//
// Visit_Byte
//
void Data_Value_Visitor::
Visit_Byte (PICML::Byte_in )
{
  this->fragment_.create_simple_content ("octet", this->value_);
}

//
// Visit_Char
//
void Data_Value_Visitor::Visit_Char (PICML::Char_in )
{
  this->fragment_.create_simple_content ("char", this->value_);
}

//
// Visit_WideChar
//
void Data_Value_Visitor::Visit_WideChar (PICML::WideChar_in )
{
  this->fragment_.create_simple_content ("wchar", this->value_);
}

//
// Visit_String
//
void Data_Value_Visitor::
Visit_String (PICML::String_in )
{
  this->fragment_.create_simple_content ("string", this->value_);
}

//
// Visit_WideString
//
void Data_Value_Visitor::
Visit_WideString (PICML::WideString_in )
{
  this->fragment_.create_simple_content ("wstring", this->value_);
}

//
// Visit_FloatNumber
//
void Data_Value_Visitor::
Visit_FloatNumber (PICML::FloatNumber_in )
{
  this->fragment_.create_simple_content ("float", this->value_);
}

//
// Visit_DoubleNumber
//
void Data_Value_Visitor::
Visit_DoubleNumber (PICML::DoubleNumber_in )
{
  this->fragment_.create_simple_content ("double", this->value_);
}

//
// Visit_LongDoubleNumber
//
void Data_Value_Visitor::
Visit_LongDoubleNumber (PICML::LongDoubleNumber_in )
{
  this->fragment_.create_simple_content ("longdouble", this->value_);
}

//
// Visit_UnsignedShortInteger
//
void Data_Value_Visitor::
Visit_UnsignedShortInteger (PICML::UnsignedShortInteger_in )
{
  this->fragment_.create_simple_content ("ushort", this->value_);
}

//
// Visit_UnsignedLongInteger
//
void Data_Value_Visitor::
Visit_UnsignedLongInteger (PICML::UnsignedLongInteger_in )
{
  this->fragment_.create_simple_content ("ulong", this->value_);
}

//
// Visit_UnsignedLongLongInteger
//
void Data_Value_Visitor::
Visit_UnsignedLongLongInteger (PICML::UnsignedLongLongInteger_in )
{
  this->fragment_.create_simple_content ("ulonglong", this->value_);
}

//
// Visit_ShortInteger
//
void Data_Value_Visitor::
Visit_ShortInteger (PICML::ShortInteger_in )
{
  this->fragment_.create_simple_content ("short", this->value_);
}

//
// Visit_LongInteger
//
void Data_Value_Visitor::
Visit_LongInteger (PICML::LongInteger_in )
{
  this->fragment_.create_simple_content ("long", this->value_);
}

//
// Visit_LongLongInteger
//
void Data_Value_Visitor::
Visit_LongLongInteger (PICML::LongLongInteger_in )
{
  this->fragment_.create_simple_content ("longlong", this->value_);
}

//
// Visit_Enum
//
void Data_Value_Visitor::
Visit_Enum (PICML::Enum_in )
{
  this->fragment_.create_simple_content ("enum", this->value_);
}

//
// Visit_DataValue
//
void Data_Value_Visitor::
Visit_DataValue (PICML::DataValue_in value)
{
  switch (this->container_)
  {
  case AGGREGATE:
    {
      GAME::Xml::Fragment member = this->fragment_.create_element ("member");
      member.create_simple_content ("name", value->name ());

      // We can now visit the value using this visitor.
      Data_Value_Visitor dvv (member, this->value_);
      value->accept (&dvv);
    }
    break;

  case SEQUENCE:
    {
      GAME::Xml::Swap_Fragment element (this->fragment_, this->fragment_.create_element ("element"));

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
Visit_DataValueContainer (PICML::DataValueContainer_in c)
{
  if (this->container_ == AGGREGATE)
  {
    // We are dealing with a struct parent container.
    GAME::Xml::Fragment member = this->fragment_.create_element ("member");
    member.create_simple_content ("name", c->name ());

    // We can now visit the value using this visitor.
    Data_Value_Visitor dvv (member, this->value_);
    c->accept (&dvv);
  }
  else if (this->container_ == SEQUENCE)
  {
    // We are dealing with a sequence parent container.
    GAME::Xml::Swap_Fragment member (this->fragment_, this->fragment_.create_element ("member"));
    container_t old = NONE;

    c->accept (this);
  }
  else /* container_ == NONE */
  {
    // Determine the container class.
    PICML::ComplexTypeReference complex = c->get_ComplexTypeReference ();
    PICML::ComplexType t = complex->get_ComplexType ();
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

//
// Visit_SimpleProperty
//
void Data_Value_Visitor::Visit_SimpleProperty (PICML::SimpleProperty_in prop)
{
  this->value_ = prop->Value ();
  prop->refers_to ()->accept (this);
}

//
// Visit_ComlexProperty
//
void Data_Value_Visitor::Visit_ComplexProperty (PICML::ComplexProperty_in prop)
{
  PICML::ComplexTypeReference complex = prop->get_ComplexTypeReference ();
  PICML::ComplexType t = complex->get_ComplexType ();

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
