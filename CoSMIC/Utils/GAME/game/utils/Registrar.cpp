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
// icon_path
//
std::string Registrar::icon_path (int mode)
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->impl_->get_IconPath ((regaccessmode_enum)mode, &bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

}
}
