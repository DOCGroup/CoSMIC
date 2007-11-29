// $Id$

#include "Connection.h"

#if !defined (__GME_INLINE__)
#include "Connection.inl"
#endif

#include "Model.h"
#include "MetaModel.h"
#include "MetaRole.h"

namespace GME
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
  // Connection

  //
  // _narrow
  //
  Connection Connection::_narrow (const Object & obj)
  {
    CComPtr <IMgaConnection> conn;
    VERIFY_HRESULT (obj.impl ()->QueryInterface (&conn));

    return conn.p;
  }

  //
  // _create
  //
  Connection Connection::_create (const std::string & name,
                                  const Model & parent,
                                  const FCO & src,
                                  const FCO & dst)
  {
    // Locate the role by name.
    Meta::Role role = parent.meta ().role (name);

    // Create a new connection.
    CComPtr <IMgaFCO> conn;
    parent.impl ()->CreateSimpleConn (role, src, dst, 0, 0, &conn);

    return Connection::_narrow (FCO (conn));
  }

  //
  // operator =
  //
  GME_INLINE
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
  size_t Connection::connection_points (Collection_T <ConnectionPoint> & points)
  {
    CComPtr <IMgaConnPoints> temp;
    VERIFY_HRESULT (this->impl ()->get_ConnPoints (&temp));

    points.attach (temp);
    return points.items ().size ();
  }
}
