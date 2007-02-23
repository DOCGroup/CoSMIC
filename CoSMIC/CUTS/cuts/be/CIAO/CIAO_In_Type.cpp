// $Id$

#include "CIAO_In_Type.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_In_Type.inl"
#endif

//
// instance_
//
CUTS_CIAO_In_Type * CUTS_CIAO_In_Type::instance_ = 0;

//
// instance
//
CUTS_CIAO_In_Type * CUTS_CIAO_In_Type::instance (void)
{
  if (CUTS_CIAO_In_Type::instance_ == 0)
    CUTS_CIAO_In_Type::instance_ = new CUTS_CIAO_In_Type ();

  return CUTS_CIAO_In_Type::instance_;
}

//
// close_singleton
//
void CUTS_CIAO_In_Type::close_singleton (void)
{
  if (CUTS_CIAO_In_Type::instance_)
  {
    delete CUTS_CIAO_In_Type::instance_;
    CUTS_CIAO_In_Type::instance_ = 0;
  }
}

//
// CUTS_CIAO_In_Type
//
CUTS_CIAO_In_Type::CUTS_CIAO_In_Type (void)
{
  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::String::meta, "const char *"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::LongInteger::meta, "::CORBA::Long"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::ShortInteger::meta, "::CORBA::Short"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::Boolean::meta, "::CORBA::Boolean"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::Byte::meta, "::CORBA::Octet"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::RealNumber::meta, "::CORBA::Double"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::GenericObject::meta, "::CORBA::Object_ptr"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::GenericValue::meta, "const ::CORBA::Any &"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::TypeKind::meta, "::CORBA::TCKind"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::TypeEncoding::meta, "::CORBA::TypeCode_ptr"));
}

//
// ~CUTS_CIAO_In_Type
//
CUTS_CIAO_In_Type::~CUTS_CIAO_In_Type (void)
{

}
