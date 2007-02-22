// $Id$

#include "CIAO_Retn_Type.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Retn_Type.inl"
#endif

//
// instance_
//
CUTS_CIAO_Retn_Type * CUTS_CIAO_Retn_Type::instance_ = 0;

//
// instance
//
CUTS_CIAO_Retn_Type * CUTS_CIAO_Retn_Type::instance (void)
{
  if (CUTS_CIAO_Retn_Type::instance_ == 0)
    CUTS_CIAO_Retn_Type::instance_ = new CUTS_CIAO_Retn_Type ();

  return CUTS_CIAO_Retn_Type::instance_;
}

//
// instance
//
void CUTS_CIAO_Retn_Type::close_singleton (void)
{
  if (CUTS_CIAO_Retn_Type::instance_)
  {
    delete CUTS_CIAO_Retn_Type::instance_;
    CUTS_CIAO_Retn_Type::instance_ = 0;
  }
}

//
// CUTS_CIAO_Retn_Type
//
CUTS_CIAO_Retn_Type::CUTS_CIAO_Retn_Type (void)
{
  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::String::meta, "char *"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::LongInteger::meta, "::CORBA::Long"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::ShortInteger::meta, "::CORBA::Short"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::Byte::meta, "::CORBA::Octet"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::Boolean::meta, "::CORBA::Octet"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::RealNumber::meta, "::CORBA::Double"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::GenericObject::meta, "::CORBA::Object_ptr"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::GenericValue::meta, "::CORBA::Any *"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::TypeKind::meta, "::CORBA::TCKind"));

  this->predefined_type_map_.insert (
    PredefinedType_Map::value_type (PICML::TypeEncoding::meta, "::CORBA::TypeCode_ptr"));
}
