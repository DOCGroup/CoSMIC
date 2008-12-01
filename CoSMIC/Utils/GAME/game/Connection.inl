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
  // ConnectionPoint

  GME_INLINE
  ConnectionPoints::ConnectionPoints (void)
  {

  }

  //
  // find
  //
  GME_INLINE
  bool ConnectionPoints::find (const std::string & role)
  {
    return this->points_mgr_.find (role) == 0 ? true : false;
  }

  //
  // find
  //
  GME_INLINE
  bool ConnectionPoints::
  find (const std::string & role, ConnectionPoint & point)
  {
    return this->points_mgr_.find (role, point) == 0 ? true : false;
  }

  //
  // size
  //
  GME_INLINE
  size_t ConnectionPoints::size (void) const
  {
    return this->points_mgr_.current_size ();
  }

  //
  // begin
  //
  GME_INLINE
  ConnectionPoints::iterator ConnectionPoints::begin (void)
  {
    return this->points_mgr_.begin ();
  }

  //
  // begin
  //
  GME_INLINE
  ConnectionPoints::const_iterator ConnectionPoints::begin (void) const
  {
    return this->points_mgr_.begin ();
  }

  //
  // end
  //
  GME_INLINE
  ConnectionPoints::iterator ConnectionPoints::end (void)
  {
    return this->points_mgr_.end ();
  }

  //
  // end
  //
  GME_INLINE
  ConnectionPoints::const_iterator ConnectionPoints::end (void) const
  {
    return this->points_mgr_.end ();
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
