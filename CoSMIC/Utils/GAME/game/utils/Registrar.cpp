// $Id$

#include "Registrar.h"

#if !defined (__GAME_INLINE__)
#include "Registrar.inl"
#endif

#include "MgaUtil.h"
#include "game/Exception.h"

namespace GAME
{
namespace utils
{
//
// Registrar
//
Registrar::Registrar (void)
: impl_ (0)
{
  CComPtr <IMgaRegistrar> ptr;
  ptr.CoCreateInstance (L"Mga.MgaRegistrar");
  this->impl_ = ptr.Detach ();
}


//
// Registrar
//
GAME_INLINE
Registrar::Registrar (const Registrar & r)
: impl_ (0)
{
  r.impl_->AddRef ();
  this->impl_ = r.impl_;
}

//
// ~Registrar
//
Registrar::~Registrar (void)
{
  this->impl_->Release ();
}


//
// icon_path
//
std::string Registrar::icon_path (ACCESS_MODE mode)
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->impl_->get_IconPath ((regaccessmode_enum)mode, &bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// query_paradigm
//
std::string Registrar::
get_paradigm_connstr (const std::string & name, ACCESS_MODE mode)
{
  CComBSTR connstr;
  CComVariant guid;
  CComBSTR paradigm (name.length (), name.c_str ());

  VERIFY_HRESULT (this->impl_->QueryParadigm (paradigm,
                                              &connstr,
                                              &guid,
                                              (regaccessmode_enum)mode));

  CW2A tempstr (connstr);
  return tempstr.m_psz;
}

}
}
