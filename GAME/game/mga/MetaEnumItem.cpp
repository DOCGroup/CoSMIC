// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaEnumItem.h"

#if !defined (__GAME_INLINE__)
#include "MetaEnumItem.inl"
#endif

#include "Exception.h"
#include "MetaAttribute.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// value
//
std::string EnumItem::value (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->impl ()->get_Value (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// value
//
void EnumItem::value (const std::string & val)
{
  CComBSTR bstr (val.c_str ());
  VERIFY_HRESULT (this->impl ()->put_Value (bstr));
}

//
// display_name
//
std::string EnumItem::display_name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->impl ()->get_DisplayedName (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// display_name
//
void EnumItem::display_name (const std::string & name)
{
  CComBSTR bstr (name.c_str ());
  VERIFY_HRESULT (this->impl ()->put_DisplayedName (bstr));
}

//
// parent
//
Attribute EnumItem::parent (void) const
{
  CComPtr <IMgaMetaAttribute> attr;
  VERIFY_HRESULT (this->impl ()->get_Parent (&attr));

  return attr.p;
}

}
}
}
