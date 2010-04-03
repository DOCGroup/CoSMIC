// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
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
GME_INLINE
Connection::~Connection (void)
{

}

//
// operator =
//
GME_INLINE
const Connection & Connection::operator = (const Connection & conn)
{
  this->attach (conn.obj_);
  return *this;
}

}
}
