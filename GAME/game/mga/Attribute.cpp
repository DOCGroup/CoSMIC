// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Attribute.h"

#if !defined (__GAME_INLINE__)
#include "Attribute.inl"
#endif

#include "FCO.h"
#include "MetaAttribute.h"
#include "Exception.h"

namespace GAME
{
namespace Mga
{

//
// status
//
long Attribute_Impl::status (void) const
{
  long result;
  VERIFY_HRESULT (this->attr_->get_Status (&result));

  return result;
}

//
// owner
//
FCO Attribute_Impl::owner (void) const
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->attr_->get_Owner (&fco));

  // TODO Use factory to create concrete implementation type.
  return fco.p;
}

//
// has_changed
//
bool Attribute_Impl::has_changed (void) const
{
  VARIANT_BOOL value;
  VERIFY_HRESULT (this->attr_->get_HasChanged (&value));

  return value == VARIANT_TRUE ? true : false;
}

//
// clear
//
void Attribute_Impl::clear (void)
{
  VERIFY_HRESULT (this->attr_->Clear ());
}

//
// string_value
//
std::string Attribute_Impl::string_value (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->attr_->get_StringValue (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// string_value
//
void Attribute_Impl::string_value (const std::string & val)
{
  CComBSTR bstr (val.c_str ());
  VERIFY_HRESULT (this->attr_->put_StringValue (bstr));
}

//
// int_value
//
long Attribute_Impl::int_value (void) const
{
  long val;
  VERIFY_HRESULT (this->attr_->get_IntValue (&val));

  return val;
}

//
// int_value
//
void Attribute_Impl::int_value (long val)
{
  VERIFY_HRESULT (this->attr_->put_IntValue (val));
}

//
// bool_value
//
bool Attribute_Impl::bool_value (void) const
{
  VARIANT_BOOL val;
  VERIFY_HRESULT (this->attr_->get_BoolValue (&val));

  return val == VARIANT_TRUE ? true : false;
}

//
// bool_value
//
void Attribute_Impl::bool_value (bool val)
{
  VARIANT_BOOL bval = val ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->attr_->put_BoolValue (bval));
}

//
// float_value
//
double Attribute_Impl::double_value (void) const
{
  double val;
  VERIFY_HRESULT (this->attr_->get_FloatValue (&val));

  return val;
}

//
// float_value
//
void Attribute_Impl::double_value (double val)
{
  VERIFY_HRESULT (this->attr_->put_FloatValue (val));
}

//
// meta
//
Meta::Attribute Attribute_Impl::meta (void) const
{
  CComPtr <IMgaMetaAttribute> attr;
  VERIFY_HRESULT (this->attr_->get_Meta (&attr));

  return attr.p;
}

}
}
