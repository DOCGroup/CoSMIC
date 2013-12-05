// $Id$

#include "Data_Value_Visitor.h"
#include "Utils/UDM/Position_Sort_T.h"
#include <algorithm>
#include "boost/bind.hpp"

//
// PICML_Data_Value_Visitor
//
PICML_Data_Value_Visitor::
PICML_Data_Value_Visitor (xercesc::DOMElement * curr)
: XML_Document (this->create_element (curr, "value")),
  container_ (NONE)
{

}

//
// Visit_Boolean
//
void PICML_Data_Value_Visitor::
Visit_Boolean (const PICML::Boolean & )
{
  this->create_simple_content ("boolean", this->value_);
}

//
// Visit_Byte
//
void PICML_Data_Value_Visitor::
Visit_Byte (const PICML::Byte & )
{
  this->create_simple_content ("octet", this->value_);
}

//
// Visit_Char
//
void PICML_Data_Value_Visitor::Visit_Char (const PICML::Char & )
{
  this->create_simple_content ("char", this->value_);
}

//
// Visit_WideChar
//
void PICML_Data_Value_Visitor::Visit_WideChar (const PICML::WideChar & )
{
  this->create_simple_content ("wchar", this->value_);
}

//
// Visit_String
//
void PICML_Data_Value_Visitor::
Visit_String (const PICML::String & )
{
  this->create_simple_content ("string", this->value_);
}

//
// Visit_WideString
//
void PICML_Data_Value_Visitor::
Visit_WideString (const PICML::WideString & )
{
  this->create_simple_content ("wstring", this->value_);
}

//
// Visit_FloatNumber
//
void PICML_Data_Value_Visitor::
Visit_FloatNumber (const PICML::FloatNumber & )
{
  this->create_simple_content ("float", this->value_);
}

//
// Visit_DoubleNumber
//
void PICML_Data_Value_Visitor::
Visit_DoubleNumber (const PICML::DoubleNumber & )
{
  this->create_simple_content ("double", this->value_);
}

//
// Visit_LongDoubleNumber
//
void PICML_Data_Value_Visitor::
Visit_LongDoubleNumber (const PICML::LongDoubleNumber & )
{
  this->create_simple_content ("longdouble", this->value_);
}

//
// Visit_UnsignedShortInteger
//
void PICML_Data_Value_Visitor::
Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & )
{
  this->create_simple_content ("ushort", this->value_);
}

//
// Visit_UnsignedLongInteger
//
void PICML_Data_Value_Visitor::
Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & )
{
  this->create_simple_content ("ulong", this->value_);
}

//
// Visit_UnsignedLongLongInteger
//
void PICML_Data_Value_Visitor::
Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & )
{
  this->create_simple_content ("ulonglong", this->value_);
}

//
// Visit_ShortInteger
//
void PICML_Data_Value_Visitor::
Visit_ShortInteger (const PICML::ShortInteger & )
{
  this->create_simple_content ("short", this->value_);
}

//
// Visit_LongInteger
//
void PICML_Data_Value_Visitor::
Visit_LongInteger (const PICML::LongInteger & )
{
  this->create_simple_content ("long", this->value_);
}

//
// Visit_LongLongInteger
//
void PICML_Data_Value_Visitor::
Visit_LongLongInteger (const PICML::LongLongInteger & )
{
  this->create_simple_content ("longlong", this->value_);
}

//
// Visit_Enum
//
void PICML_Data_Value_Visitor::
Visit_Enum (const PICML::Enum & )
{
  this->create_simple_content ("enum", this->value_);
}

//
// Visit_DataValue
//
void PICML_Data_Value_Visitor::
Visit_DataValue (const PICML::DataValue & value)
{
  switch (this->container_)
  {
  case AGGREGATE:
    {
      xercesc::DOMElement * member = this->create_element ("member");
      this->create_simple_content (member, "name", value.name ());

      // We can now visit the value using this visitor.
      PICML_Data_Value_Visitor dvv (member);
      PICML::DataValue (value).Accept (dvv);
    }
    break;

  case SEQUENCE:
    {
      xercesc::DOMElement * element = this->create_element ("element");

      container_t old = NONE;

      std::swap (old, this->container_);
      std::swap (element, this->curr_);

      PICML::DataValue (value).Accept (*this);

      std::swap (element, this->curr_);
      std::swap (old, this->container_);
    }
    break;

  case NONE:
    // Store the value for later usage.
    this->value_ = value.Value ();

    // Visit the value's type. This will generate the correct value
    // element for this data value.
    this->dt_dispatcher_.dispatch (*this, value.ref ());
  };
}

//
// Visit_DataValueContainer
//
void PICML_Data_Value_Visitor::
Visit_DataValueContainer (const PICML::DataValueContainer & c)
{
  if (this->container_ == AGGREGATE)
  {
    // We are dealing with a struct parent container.
    xercesc::DOMElement * member = this->create_element ("member");
    this->create_simple_content (member, "name", c.name ());

    // We can now visit the value using this visitor.
    PICML_Data_Value_Visitor dvv (member);
    PICML::DataValueContainer (c).Accept (dvv);
  }
  else if (this->container_ == SEQUENCE)
  {
    // We are dealing with a sequence parent container.
    xercesc::DOMElement * element = this->create_element ("element");

    container_t old = NONE;

    std::swap (element, this->curr_);
    std::swap (old, this->container_);

    PICML::DataValueContainer (c).Accept (*this);

    std::swap (old, this->container_);
    std::swap (element, this->curr_);
  }
  else /* container_ == NONE */
  {
    // Determine the container class.
    PICML::ComplexTypeReference complex = c.ComplexTypeReference_child ();
    PICML::ComplexType t = complex.ref ();
    const Uml::Class & cls = t.type ();

    if (cls == PICML::Aggregate::meta)
      this->container_ = AGGREGATE;
    else if (cls == PICML::Collection::meta)
      this->container_ = SEQUENCE;

    // Select the DataValueBase elements from top to bottom. This has
    // to be done in two phases since UDM does not allow you to initialize
    // the collection with the sort function.
    typedef UDM_Position_Sort_T <PICML::DataValueBase, PS_Top_To_Bottom> sorter_t;
    sorter_t sorter ("DataValueAspect", PS_Top_To_Bottom ());

    typedef std::set <PICML::DataValueBase, sorter_t> sorted_values_t;
    sorted_values_t sorted_values (sorter);

    std::vector <PICML::DataValueBase> values = c.DataValueBase_kind_children ();
    std::for_each (values.begin (),
                   values.end (),
                   boost::bind (&sorted_values_t::insert,
                                boost::ref (sorted_values),
                                _1));

    // Visit each member of the container.
    std::for_each (sorted_values.begin (),
                   sorted_values.end (),
                   boost::bind (&DataValueBase_Dispatcher::dispatch,
                                boost::ref (this->dvb_dispatcher_),
                                boost::ref (*this),
                                _1));
  }
}

//
// Visit_SimpleProperty
//
void PICML_Data_Value_Visitor::Visit_SimpleProperty (const PICML::SimpleProperty & prop)
{
  this->value_ = prop.Value ();
  this->dt_dispatcher_.dispatch (*this, prop.ref ());
}

//
// Visit_ComlexProperty
//
void PICML_Data_Value_Visitor::Visit_ComplexProperty (const PICML::ComplexProperty & prop)
{
  PICML::ComplexTypeReference complex = prop.ComplexTypeReference_child ();

  PICML::ComplexType t = complex.ref ();
  const Uml::Class & cls = t.type ();

  // Store the container's type for later usage.
  if (cls == PICML::Collection::meta)
    this->container_ = SEQUENCE;
  else if (cls == PICML::Aggregate::meta)
    this->container_ = AGGREGATE;

  // Select the DataValueBase elements from top to bottom. This has
  // to be done in two phases since UDM does not allow you to initialize
  // the collection with the sort function.
  typedef UDM_Position_Sort_T <PICML::DataValueBase, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("DataValueAspect", PS_Top_To_Bottom ());

  typedef std::set <PICML::DataValueBase, sorter_t> sorted_values_t;
  sorted_values_t sorted_values (sorter);

  std::vector <PICML::DataValueBase> values = prop.DataValueBase_kind_children ();
  std::for_each (values.begin (),
                 values.end (),
                 boost::bind (&sorted_values_t::insert,
                              boost::ref (sorted_values),
                              _1));

  // Visit each member of the container.
  std::for_each (sorted_values.begin (),
                 sorted_values.end (),
                 boost::bind (&DataValueBase_Dispatcher::dispatch,
                              boost::ref (this->dvb_dispatcher_),
                              boost::ref (*this),
                              _1));
}