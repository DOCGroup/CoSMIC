// $Id$

namespace GAME
{
///////////////////////////////////////////////////////////////////////////////
// ConnectoinPoint

//
// ConnectionPoint
//
GAME_INLINE
ConnectionPoint::ConnectionPoint (void)
{

}

//
// ConnectionPoint
//
GAME_INLINE
ConnectionPoint::ConnectionPoint (IMgaConnPoint * point)
  : point_ (point)
{

}

//
// ConnectionPoint
//
GAME_INLINE
ConnectionPoint::ConnectionPoint (const ConnectionPoint & point)
  : point_ (point.point_)
{

}

//
// ~ConnectionPoint
//
GAME_INLINE
ConnectionPoint::~ConnectionPoint (void)
{

}

//
// impl
//
GAME_INLINE
IMgaConnPoint * ConnectionPoint::impl (void) const
{
  return this->point_.p;
}

//
// operator =
//
GAME_INLINE
const ConnectionPoint & ConnectionPoint::
operator = (const ConnectionPoint & point)
{
  this->point_ = point.point_;
  return *this;
}

//
// attach
//
GAME_INLINE
void ConnectionPoint::attach (IMgaConnPoint * point)
{
  this->point_.Attach (point);
}

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoint

GAME_INLINE
ConnectionPoints::ConnectionPoints (void)
{

}

//
// find
//
GAME_INLINE
bool ConnectionPoints::find (const std::string & role)
{
  return this->points_mgr_.find (role) == 0 ? true : false;
}

//
// find
//
GAME_INLINE
bool ConnectionPoints::
find (const std::string & role, ConnectionPoint & point)
{
  return this->points_mgr_.find (role, point) == 0 ? true : false;
}

//
// size
//
GAME_INLINE
size_t ConnectionPoints::size (void) const
{
  return this->points_mgr_.current_size ();
}

//
// begin
//
GAME_INLINE
ConnectionPoints::iterator ConnectionPoints::begin (void)
{
  return this->points_mgr_.begin ();
}

//
// begin
//
GAME_INLINE
ConnectionPoints::const_iterator ConnectionPoints::begin (void) const
{
  return this->points_mgr_.begin ();
}

//
// end
//
GAME_INLINE
ConnectionPoints::iterator ConnectionPoints::end (void)
{
  return this->points_mgr_.end ();
}

//
// end
//
GAME_INLINE
ConnectionPoints::const_iterator ConnectionPoints::end (void) const
{
  return this->points_mgr_.end ();
}

///////////////////////////////////////////////////////////////////////////////
// Connection

//
// Connection
//
GAME_INLINE
Connection::Connection (void)
{

}

//
// Connection
//
GAME_INLINE
Connection::Connection (const Connection & conn)
: FCO (conn)
{

}

//
// Connection
//
GAME_INLINE
Connection::Connection (IMgaConnection * conn)
: FCO (conn)
{

}

//
// ~Connection
//
GAME_INLINE
Connection::~Connection (void)
{

}

//
// operator []
//
GAME_INLINE
GAME::ConnectionPoint Connection::operator [] (const std::string & role)
{
  return this->connection_point (role);
}

//
// operator []
//
GAME_INLINE
GAME::ConnectionPoint Connection::operator [] (const char * role)
{
  return this->connection_point (role);
}

//
// connection_point
//
GAME_INLINE
ConnectionPoint Connection::
connection_point (const char * role) const
{
  const std::string str_role (role);
  return this->connection_point (str_role);
}

//
// src
//
GAME_INLINE
FCO Connection::src (void) const
{
  return this->connection_point ("src").target ();
}

//
// dst
//
GAME_INLINE
FCO Connection::dst (void) const
{
  return this->connection_point ("dst").target ();
}

}
