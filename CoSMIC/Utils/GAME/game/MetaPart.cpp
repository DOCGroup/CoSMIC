// $Id$

#include "MetaPart.h"

#if !defined (__GAME_INLINE__)
#include "MetaPart.inl"
#endif

namespace GAME
{
namespace Meta
{
//
// kind
//
std::string Part::kind (void) const
{
  CComBSTR kind;
  VERIFY_HRESULT (this->impl ()->get_KindAspect (&kind));

  CW2A tempstr (kind);
  return tempstr.m_psz;
}

//
// is_linked
//
bool Part::is_linked (void) const
{
  VARIANT_BOOL retval;
  VERIFY_HRESULT (this->impl ()->get_IsLinked (&retval));

  return retval == VARIANT_TRUE ? true : false;
}

//
// is_primary
//
bool Part::is_primary (void) const
{
  VARIANT_BOOL retval;
  VERIFY_HRESULT (this->impl ()->get_IsPrimary (&retval));

  return retval == VARIANT_TRUE ? true : false;
}

//
// role
// 
Role Part::role (void) const
{
  CComPtr <IMgaMetaRole> role;
  VERIFY_HRESULT (this->impl ()->get_Role (&role));

  return role.Detach ();
}

}
}
