// $Id$

#include "CIAO_Out_Type.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Out_Type.inl"
#endif

//
// instance_
//
CUTS_CIAO_Out_Type * CUTS_CIAO_Out_Type::instance_ = 0;

//
// instance
//
CUTS_CIAO_Out_Type * CUTS_CIAO_Out_Type::instance (void)
{
  if (CUTS_CIAO_Out_Type::instance_ == 0)
    CUTS_CIAO_Out_Type::instance_ = new CUTS_CIAO_Out_Type ();

  return CUTS_CIAO_Out_Type::instance_;
}

//
// close_singleton
//
void CUTS_CIAO_Out_Type::close_singleton (void)
{
  if (CUTS_CIAO_Out_Type::instance_)
  {
    delete CUTS_CIAO_Out_Type::instance_;
    CUTS_CIAO_Out_Type::instance_ = 0;
  }
}

//
// CUTS_CIAO_Out_Type
//
CUTS_CIAO_Out_Type::CUTS_CIAO_Out_Type (void)
{
  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::String::meta, "::CORBA::String_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::Boolean::meta, "::CORBA::Boolean_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::LongInteger::meta, "::CORBA::Long_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::ShortInteger::meta, "::CORBA::Short_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::Byte::meta, "::CORBA::Octet_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::RealNumber::meta, "::CORBA::Double_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::GenericObject::meta, "::CORBA::Object_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::GenericValue::meta, "const ::CORBA::Any_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::TypeKind::meta, "::CORBA::TCKind_out"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::TypeEncoding::meta, "::CORBA::TypeCode_out"));
}
