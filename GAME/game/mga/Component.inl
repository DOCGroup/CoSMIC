// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Component_Impl
//
GAME_INLINE
Component_Impl::Component_Impl (void)
{

}

//
// Component_Impl
//
GAME_INLINE
Component_Impl::Component_Impl (IMgaComponent * c)
: component_ (c)
{

}

//
// ~Component_Impl
//
GAME_INLINE
Component_Impl::~Component_Impl (void)
{

}

//
// operator ->
//
GAME_INLINE
IMgaComponent * Component_Impl::impl (void) const
{
  return this->component_.p;
}

//
// release
//
GAME_INLINE
void Component_Impl::release (void)
{
  this->component_.Release ();
}

//
// attach
//
GAME_INLINE
void Component_Impl::attach (IMgaComponent * c)
{
  this->component_.Attach (c);
}

}
}
