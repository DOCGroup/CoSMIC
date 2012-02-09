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
namespace Mga
{
namespace Meta
{

//
// impl
//
IMgaMetaPart * Part_Impl::impl (void) const
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
std::string Part_Impl::kind_aspect (void) const
{
  CComBSTR kind;
  VERIFY_HRESULT (this->impl ()->get_KindAspect (&kind));

  CW2A tempstr (kind);
  return tempstr.m_psz;
}

//
// is_linked
//
bool Part_Impl::is_linked (void) const
{
  VARIANT_BOOL retval;
  VERIFY_HRESULT (this->impl ()->get_IsLinked (&retval));

  return retval == VARIANT_TRUE ? true : false;
}

//
// is_primary
//
bool Part_Impl::is_primary (void) const
{
  VARIANT_BOOL retval;
  VERIFY_HRESULT (this->impl ()->get_IsPrimary (&retval));

  return retval == VARIANT_TRUE ? true : false;
}

//
// role
//
Role Part_Impl::role (void) const
{
  CComPtr <IMgaMetaRole> role;
  VERIFY_HRESULT (this->impl ()->get_Role (&role));

  return role.p;
}

//
// count
//
long Part_Impl::count (void) const
{
  long count;
  VERIFY_HRESULT (this->parts_->get_Count (&count));

  return count;
}

//
// in_aspect
//
Aspect Part_Impl::in_aspect (void) const
{
  CComPtr <IMgaMetaAspect> aspect;
  VERIFY_HRESULT (this->impl ()->get_ParentAspect (&aspect));

  return aspect.p;
}

}
}
}
