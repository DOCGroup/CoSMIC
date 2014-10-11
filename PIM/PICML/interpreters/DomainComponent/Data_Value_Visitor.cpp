#include "StdAfx.h"
#include "Data_Value_Visitor.h"
#include "game/xml/Swap_Fragment.h"

#include "PICML/Common/DataType.h"

Data_Value_Visitor::
Data_Value_Visitor (const GAME::Xml::Fragment & parent, const std::string & value)
: fragment_ (parent),
  value_ (value)
{

}

Data_Value_Visitor::~Data_Value_Visitor (void)
{

}

void Data_Value_Visitor::visit_DataType (PICML::DataType_in dt)
{
  GAME::Xml::Swap_Fragment fragment (this->fragment_, this->fragment_.create_element ("value"));
  dt->refers_to ()->accept (this);
}

void Data_Value_Visitor::visit_Boolean (PICML::Boolean_in)
{
  this->fragment_.create_simple_content ("boolean", this->value_);
}

void Data_Value_Visitor::visit_Byte (PICML::Byte_in)
{
  this->fragment_.create_simple_content ("octet", this->value_);
}

void Data_Value_Visitor::visit_String (PICML::String_in)
{
  this->fragment_.create_simple_content ("string", this->value_);
}

void Data_Value_Visitor::visit_FloatNumber (PICML::FloatNumber_in)
{
  this->fragment_.create_simple_content ("float", this->value_);
}

void Data_Value_Visitor::visit_DoubleNumber (PICML::DoubleNumber_in)
{
  this->fragment_.create_simple_content ("double", this->value_);
}

void Data_Value_Visitor::visit_ShortInteger (PICML::ShortInteger_in)
{
  this->fragment_.create_simple_content ("short", this->value_);
}

void Data_Value_Visitor::visit_LongInteger (PICML::LongInteger_in)
{
  this->fragment_.create_simple_content ("long", this->value_);
}
