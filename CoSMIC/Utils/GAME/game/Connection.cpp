// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Connection.h"

#if !defined (__GAME_INLINE__)
#include "Connection.inl"
#endif

#include "Model.h"
#include "MetaModel.h"
#include "MetaRole.h"

namespace GAME
{
  //===========================================================================
  // ConnectionPoint

  //
  // owner
  //
  Connection ConnectionPoint::owner (void) const
  {
    CComPtr <IMgaConnection> conn;
    VERIFY_HRESULT (this->impl ()->get_Owner (&conn));

    return conn.p;
  }

  //
  // role
  //
  void ConnectionPoint::role (const std::string & name)
  {
    CComBSTR bstr (name.c_str ());
    VERIFY_HRESULT (this->impl ()->put_ConnRole (bstr));
  }

  //
  // role
  //
  std::string ConnectionPoint::role (void) const
  {
    CComBSTR bstr ;
    VERIFY_HRESULT (this->impl ()->get_ConnRole (&bstr));

    CW2A tempstr (bstr);
    return tempstr.m_psz;
  }

  //
  // remove
  //
  void ConnectionPoint::remove (void)
  {
    VERIFY_HRESULT (this->impl ()->Remove ());
  }

  //
  // target
  //
  FCO ConnectionPoint::target (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_Target (&fco));

    return fco.p;
  }

  //===========================================================================
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
      CComPtr <IMgaConnPoint> * array =
        new CComPtr <IMgaConnPoint> [count];

      VERIFY_HRESULT (this->points_->GetAll (count, &(*array)));

      // Store the members in a collection.
      for (long i = 0; i < count; i ++)
      {
        ConnectionPoint point (array[i]);
        this->points_mgr_.bind (point.role (), point);
      }

      // Release the temp storage.
      delete [] array;
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

  //===========================================================================
  // Connection

  //
  // _narrow
  //
  Connection Connection::_narrow (const Object & obj)
  {
    CComPtr <IMgaConnection> conn;

    VERIFY_HRESULT_THROW_EX (obj.impl ()->QueryInterface (&conn),
                             GAME::Invalid_Cast ());

    return conn.p;
  }

  //
  // _create
  //
  Connection Connection::_create (const Model & parent,
                                  const std::string & name,
                                  const FCO & src,
                                  const FCO & dst)
  {
    // Locate the role by name.
    Meta::Role role = parent.meta ().role (name);

    // Create a new connection.
    CComPtr <IMgaFCO> conn;

    VERIFY_HRESULT (parent.impl ()->CreateSimpleConn (role,
                                                      src.impl (),
                                                      dst.impl (),
                                                      0,
                                                      0,
                                                      &conn));

    return Connection::_narrow (FCO (conn));
  }

  //
  // operator =
  //
  GAME_INLINE
  const Connection & Connection::operator = (const Connection & conn)
  {
    if (this != &conn)
      this->object_ = conn.object_;

    return *this;
  }

  //
  // impl
  //
  IMgaConnection * Connection::impl (void) const
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
  size_t Connection::connection_points (ConnectionPoints & points)
  {
    CComPtr <IMgaConnPoints> temp;
    VERIFY_HRESULT (this->impl ()->get_ConnPoints (&temp));

    points.attach (temp.Detach ());
    return points.size ();
  }

  //
  // operator []
  //
  GAME::ConnectionPoint Connection:: operator [] (const std::string & role)
  {
    GAME::ConnectionPoint point;
    GAME::ConnectionPoints points;

    if (this->connection_points (points))
      point = points[role];

    return point;
  }
}
