// -*- C++ -*
// $Id$

namespace GAME
{
namespace Mga
{
namespace Meta
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
ConnectionPoint_Impl::ConnectionPoint_Impl (IMgaMetaConnJoint * point)
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
IMgaMetaConnJoint * ConnectionPoint_Impl::impl (void) const
{
  return this->point_.p;
}

//
// attach
//
GAME_INLINE
void ConnectionPoint_Impl::attach (IMgaMetaConnJoint * point)
{
  this->point_.Attach (point);
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
Connection_Impl::Connection_Impl (IMgaMetaConnection * aspect)
: FCO_Impl (aspect)
{

}

//
// ~Connection_Impl
//
GAME_INLINE
Connection_Impl::~Connection_Impl (void)
{

}

}
}
}
