// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "MetaConnection.h"

#if !defined (__GAME_INLINE__)
#include "MetaConnection.inl"
#endif

#include "Exception.h"

namespace GAME
{
namespace Meta
{
//
// impl
//
IMgaMetaConnection * Connection_Impl::impl (void) const
{
  // Optimize for the quick path.
  if (this->conn_.p == this->metabase_.p)
    return this->conn_;

  // So, we have to actually initalize the <meta_fco_>.
  if (this->conn_)
    this->conn_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->conn_));
  return this->conn_;
}

}
}
