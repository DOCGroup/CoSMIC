// $Id$

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoint_Impl

//
// ConnectionPoint_Impl
//
GAME_INLINE
ConnectionPoint_Impl::ConnectionPoint_Impl (void)
{

}

//
// ConnectionPoint_Impl
//
GAME_INLINE
ConnectionPoint_Impl::ConnectionPoint_Impl (IMgaConnPoint * point)
: point_ (point)
{

}

//
// ~ConnectionPoint_Impl
//
GAME_INLINE
ConnectionPoint_Impl::~ConnectionPoint_Impl (void)
{

}

//
// impl
//
GAME_INLINE
IMgaConnPoint * ConnectionPoint_Impl::impl (void) const
{
  return this->point_.p;
}

//
// attach
//
GAME_INLINE
void ConnectionPoint_Impl::attach (IMgaConnPoint * point)
{
  this->point_.Attach (point);
}

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoints

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
// Connection_Impl

//
// Connection_Impl
//
GAME_INLINE
Connection_Impl::Connection_Impl (void)
{

}

//
// Connection_Impl
//
GAME_INLINE
Connection_Impl::Connection_Impl (IMgaConnection * conn)
//: FCO_Impl (conn)
{
  this->object_ = conn;
}

//
// ~Connection_Impl
//
GAME_INLINE
Connection_Impl::~Connection_Impl (void)
{

}

//
// operator []
//
GAME_INLINE
ConnectionPoint Connection_Impl::operator [] (const std::string & role)
{
  return this->connection_point (role);
}

//
// operator []
//
GAME_INLINE
ConnectionPoint Connection_Impl::operator [] (const char * role)
{
  return this->connection_point (role);
}

//
// connection_point
//
GAME_INLINE
ConnectionPoint Connection_Impl::connection_point (const char * role) const
{
  const std::string str_role (role);
  return this->connection_point (str_role);
}

//
// src
//
GAME_INLINE
FCO Connection_Impl::src (void) const
{
  return this->connection_point ("src")->target ();
}

//
// dst
//
GAME_INLINE
FCO Connection_Impl::dst (void) const
{
  return this->connection_point ("dst")->target ();
}

}
}
