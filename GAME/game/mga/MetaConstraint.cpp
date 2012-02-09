// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaConstraint.h"

#if !defined (__GAME_INLINE__)
#include "MetaConstraint.inl"
#endif

#include "MetaProject.h"
#include "Exception.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// name
//
std::string Constraint_Impl::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->metaconst_->get_Name (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// expression
//
std::string Constraint_Impl::expression (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->metaconst_->get_Expression (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}


}
}
}
