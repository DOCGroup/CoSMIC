#include "StdAfx.h"
#include "Data_Type_Visitor.h"
#include "game/xml/Swap_Fragment.h"

#include "PICML/Common/DataType.h"

Data_Type_Visitor::Data_Type_Visitor (const GAME::Xml::Fragment & parent)
: fragment_ (parent)
{

}

Data_Type_Visitor::~Data_Type_Visitor (void)
{

}

void Data_Type_Visitor::visit_DataType (PICML::DataType_in dt)
{
  GAME::Xml::Swap_Fragment fragment (this->fragment_, this->fragment_.create_element ("type"));
  dt->refers_to ()->accept (this);
}

void Data_Type_Visitor::visit_Boolean (PICML::Boolean_in)
{
  this->fragment_.create_simple_content ("kind", "tk_boolean");
}

void Data_Type_Visitor::visit_Byte (PICML::Byte_in)
{
  this->fragment_.create_simple_content ("kind", "tk_octet");
}

void Data_Type_Visitor::visit_String (PICML::String_in)
{
  this->fragment_.create_simple_content ("kind", "tk_string");
}

void Data_Type_Visitor::visit_FloatNumber (PICML::FloatNumber_in)
{
  this->fragment_.create_simple_content ("kind", "tk_float");
}

void Data_Type_Visitor::visit_DoubleNumber (PICML::DoubleNumber_in)
{
  this->fragment_.create_simple_content ("kind", "tk_double");
}

void Data_Type_Visitor::visit_ShortInteger (PICML::ShortInteger_in)
{
  this->fragment_.create_simple_content ("kind", "tk_short");
}

void Data_Type_Visitor::visit_LongInteger (PICML::LongInteger_in)
{
  this->fragment_.create_simple_content ("kind", "tk_long");
}
