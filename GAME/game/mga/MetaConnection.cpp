// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaConnection.h"
#include "Collection_T.h"


#if !defined (__GAME_INLINE__)
#include "MetaConnection.inl"
#endif

#include "Exception.h"
#include "MetaRole.h"


namespace GAME
{
namespace Mga
{
namespace Meta
{

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoint_Impl

//
// parent
//
Connection ConnectionPoint_Impl::parent (void) const
{
  CComPtr <IMgaMetaConnection> conn;
  VERIFY_HRESULT (this->impl ()->get_Parent (&conn));

  return new Connection_Impl (conn.p);
}

///////////////////////////////////////////////////////////////////////////////
// Connection_Impl

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

//
// points
//
size_t Connection_Impl::connection_points (std::vector <ConnectionPoint> & points) const
{
  CComPtr <IMgaMetaConnJoints> temp;
  VERIFY_HRESULT (this->impl ()->get_Joints (&temp));

  return iter_to_collection (temp.p, points);
}

}
}
}
