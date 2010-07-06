// -*- C++ -*-
// $Id$

namespace GAME
{
//
// Component
//
GAME_INLINE
Component::Component (void)
{

}

//
// Component
//
GAME_INLINE
Component::Component (const Component & c)
: component_ (c.component_)
{

}

//
// Component
//
GAME_INLINE
Component::Component (IMgaComponent * c)
: component_ (c)
{

}

//
// ~Component
//
GAME_INLINE
Component::~Component (void)
{

}

//
// operator ->
//
GAME_INLINE
IMgaComponent * Component::operator -> (void) const
{
  return this->component_.p;
}

//
// release
//
GAME_INLINE
void Component::release (void)
{
  this->component_.Release ();
}

//
// attach
//
GAME_INLINE
void Component::attach (IMgaComponent * c)
{
  this->component_.Attach (c);  
}

}
