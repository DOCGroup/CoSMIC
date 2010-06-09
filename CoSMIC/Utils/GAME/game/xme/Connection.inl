// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
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
Connection::
Connection (xercesc::DOMElement * conn, bool validate)
: FCO (conn, false)
{
  if (validate && !(this->type_ & Object_Type::OT_CONNECTION))
    throw Invalid_Cast ();

  // need to finish initialization
}

//
// Connection
//
GAME_INLINE
Connection::~Connection (void)
{

}

//
// operator =
//
GAME_INLINE
const Connection & Connection::operator = (const Connection & conn)
{
  this->attach (conn.obj_);
  this->dst_ = conn.dst_;
  this->src_ = conn.src_;

  return *this;
}

//
// _narrow
//
GAME_INLINE
Connection Connection::_narrow (const Object & obj)
{
  if ((Object_Type::OT_CONNECTION & obj.type ()))
    return Connection (obj.ptr ());

  throw Invalid_Cast ();
}

}
}
