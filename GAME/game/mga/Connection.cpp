// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Connection.h"

#if !defined (__GAME_INLINE__)
#include "Connection.inl"
#endif

#include "Exception.h"
#include "Model.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "Visitor.h"

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoint_Impl

//
// owner
//
Connection ConnectionPoint_Impl::owner (void) const
{
  CComPtr <IMgaConnection> conn;
  VERIFY_HRESULT (this->impl ()->get_Owner (&conn));

  return conn.p;
}

//
// role
//
void ConnectionPoint_Impl::role (const std::string & name)
{
  CComBSTR bstr (name.c_str ());
  VERIFY_HRESULT (this->impl ()->put_ConnRole (bstr));
}

//
// role
//
std::string ConnectionPoint_Impl::role (void) const
{
  CComBSTR bstr ;
  VERIFY_HRESULT (this->impl ()->get_ConnRole (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// remove
//
void ConnectionPoint_Impl::remove (void)
{
  VERIFY_HRESULT (this->impl ()->Remove ());
}

//
// target
//
FCO ConnectionPoint_Impl::target (void) const
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->impl ()->get_Target (&fco));

  return fco.p;
}

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoints

ConnectionPoints::ConnectionPoints (IMgaConnPoints * points)
  : points_ (points)
{
  this->populate ();
}

//
// attach
//
void ConnectionPoints::attach (IMgaConnPoints * points)
{
  this->points_.Attach (points);
  this->populate ();
}

//
// populate
//
void ConnectionPoints::populate (void)
{
  if (this->points_mgr_.current_size () > 0)
    this->points_mgr_.unbind_all ();

  long count;
  VERIFY_HRESULT (this->points_->get_Count (&count));

  if (count > 0)
  {
    // Get the interface to all the members.
    CComPtr <IMgaConnPoint> * arr = new CComPtr <IMgaConnPoint> [count];
    VERIFY_HRESULT (this->points_->GetAll (count, &(*arr)));

    // Store the members in a collection.
    for (long i = 0; i < count; i ++)
    {
      ConnectionPoint point (arr[i]);
      this->points_mgr_.bind (point->role (), point);
    }

    // Release the temp storage.
    delete [] arr;
  }
}

//
// operator []
//
ConnectionPoint ConnectionPoints::
operator [] (const std::string & role) const
{
  ConnectionPoint point;
  this->points_mgr_.find (role, point);

  return point;
}

///////////////////////////////////////////////////////////////////////////////
// Connection_Impl


//
// _create
//
Connection Connection_Impl::_create (const Model_in parent,
                                     const std::string & name,
                                     const FCO_in src,
                                     const FCO_in dst)
{
  // Locate the role by name.
  Meta::Role role = parent->meta ()->role (name);

  // Create a new connection.
  CComPtr <IMgaFCO> fco;

  VERIFY_HRESULT (parent->impl ()->CreateSimpleConn (role->impl (),
                                                     src->impl (),
                                                     dst->impl (),
                                                     0,
                                                     0,
                                                     &fco));

  CComPtr <IMgaConnection> conn;
  fco.QueryInterface (&conn);

  return conn.p;
}

//
// impl
//
IMgaConnection * Connection_Impl::impl (void) const
{
  if (this->conn_.p == this->object_.p)
    return this->conn_.p;

  if (this->conn_.p)
    this->conn_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->conn_));
  return this->conn_.p;
}

//
// points
//
size_t Connection_Impl::connection_points (ConnectionPoints & points) const
{
  CComPtr <IMgaConnPoints> temp;
  VERIFY_HRESULT (this->impl ()->get_ConnPoints (&temp));

  points.attach (temp.Detach ());
  return points.size ();
}

//
// connection_point
//
ConnectionPoint Connection_Impl::
connection_point (const std::string & role) const
{
  ConnectionPoints points;
  ConnectionPoint point;

  if (this->connection_points (points))
    point = points[role];

  return point;
}

//
// accept
//
void Connection_Impl::accept (Visitor * v)
{
  v->visit_Connection (this);
}

}
}
