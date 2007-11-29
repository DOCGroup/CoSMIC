// $Id$

namespace GME
{
  //===========================================================================
  // ConnectoinPoint

  //
  // ConnectionPoint
  //
  GME_INLINE
  ConnectionPoint::ConnectionPoint (void)
  {

  }

  //
  // ConnectionPoint
  //
  GME_INLINE
  ConnectionPoint::ConnectionPoint (IMgaConnPoint * point)
    : point_ (point)
  {

  }

  //
  // ConnectionPoint
  //
  GME_INLINE
  ConnectionPoint::ConnectionPoint (const ConnectionPoint & point)
    : point_ (point.point_)
  {

  }

  //
  // ~ConnectionPoint
  //
  GME_INLINE
  ConnectionPoint::~ConnectionPoint (void)
  {

  }

  //
  // impl
  //
  GME_INLINE
  IMgaConnPoint * ConnectionPoint::impl (void) const
  {
    return this->point_.p;
  }

  //
  // operator =
  //
  GME_INLINE
  const ConnectionPoint & ConnectionPoint::
  operator = (const ConnectionPoint & point)
  {
    this->point_ = point.point_;
    return *this;
  }

  //
  // attach
  //
  GME_INLINE
  void ConnectionPoint::attach (IMgaConnPoint * point)
  {
    this->point_.Attach (point);
  }

  //===========================================================================
  // Connection

  //
  // Connection
  //
  GME_INLINE
  Connection::Connection (void)
  {

  }

  //
  // Connection
  //
  GME_INLINE
  Connection::Connection (const Connection & conn)
  : FCO (conn)
  {

  }

  //
  // Connection
  //
  GME_INLINE
  Connection::Connection (IMgaConnection * conn)
  : FCO (conn)
  {

  }

  //
  // ~Connection
  //
  GME_INLINE
  Connection::~Connection (void)
  {

  }
}
