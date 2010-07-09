// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaPart.h"

#if !defined (__GAME_INLINE__)
#include "MetaPart.inl"
#endif

#include "Exception.h"

namespace GAME
{
namespace Meta
{
//
// impl
//
IMgaMetaPart * Part::impl (void) const
{
  if (this->part_.p == this->metabase_.p)
    return this->part_.p;

  if (this->part_.p != 0)
    this->part_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->part_));
  return this->part_;
} 

//
// kind
//
std::string Part::kind_aspect (void) const
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

//
// role
// 
Aspect Part::parent_aspect (void) const
{
  CComPtr <IMgaMetaAspect> aspect;
  VERIFY_HRESULT (this->impl ()->get_ParentAspect (&aspect));

  return Aspect (aspect);
}

}
}
