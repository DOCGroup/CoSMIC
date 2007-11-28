// $Id$

#include "Attribute.h"

#if !defined (__GME_INLINE__)
#include "Attribute.inl"
#endif

namespace GME
{
  //
  // status
  //
  long Attribute::status (void) const
  {
    long result;
    VERIFY_HRESULT (this->attr_->get_Status (&result));

    return result;
  }

  //
  // owner
  //
  FCO Attribute::owner (void) const
  {
    IMgaFCO * fco = 0;
    VERIFY_HRESULT (this->attr_->get_Owner (&fco));

    return FCO (fco);
  }

  //
  // has_changed
  //
  bool Attribute::has_changed (void) const
  {
    VARIANT_BOOL value;
    VERIFY_HRESULT (this->attr_->get_HasChanged (&value));

    return value == VARIANT_TRUE ? true : false;
  }

  //
  // clear
  //
  void Attribute::clear (void)
  {
    VERIFY_HRESULT (this->attr_->Clear ());
  }

  //
  // string_value
  //
  std::string Attribute::string_value (void) const
  {
    CComBSTR bstr;
    VERIFY_HRESULT (this->attr_->get_StringValue (&bstr));

    CW2A tempstr (bstr);
    return tempstr.m_psz;
  }

  //
  // string_value
  //
  void Attribute::string_value (const std::string & val)
  {
    CComBSTR bstr (val.c_str ());
    VERIFY_HRESULT (this->attr_->put_StringValue (bstr));
  }

  //
  // int_value
  //
  long Attribute::int_value (void) const
  {
    long val;
    VERIFY_HRESULT (this->attr_->get_IntValue (&val));

    return val;
  }

  //
  // int_value
  //
  void Attribute::int_value (long val)
  {
    VERIFY_HRESULT (this->attr_->put_IntValue (val));
  }

  //
  // bool_value
  //
  bool Attribute::bool_value (void) const
  {
    VARIANT_BOOL val;
    VERIFY_HRESULT (this->attr_->get_BoolValue (&val));

    return val == VARIANT_TRUE ? true : false;
  }

  //
  // bool_value
  //
  void Attribute::bool_value (bool val)
  {
    VERIFY_HRESULT (
      this->attr_->put_BoolValue (val ? VARIANT_TRUE : VARIANT_FALSE));
  }

  //
  // float_value
  //
  double Attribute::float_value (void) const
  {
    double val;
    VERIFY_HRESULT (this->attr_->get_FloatValue (&val));

    return val;
  }

  //
  // float_value
  //
  void Attribute::float_value (double val)
  {
    VERIFY_HRESULT (this->attr_->put_FloatValue (val));
  }

  //
  // meta
  //
  MetaAttribute Attribute::meta (void) const
  {
    IMgaMetaAttribute * attr = 0;
    VERIFY_HRESULT (this->attr_->get_Meta (&attr));

    return MetaAttribute (attr);
  }
}
