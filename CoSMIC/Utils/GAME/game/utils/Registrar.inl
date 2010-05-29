// -*- C++ -*-
// $Id$

namespace GAME
{
namespace utils
{
//
// Registrar
//
GAME_INLINE
Registrar::Registrar (void)
{
  this->impl_.CoCreateInstance (L"Mga.MgaRegistrar");
}

//
// Registrar
//
GAME_INLINE
Registrar::Registrar (const Registrar & r)
: impl_ (r.impl_)
{

}

//
// ~Registrar
//
GAME_INLINE
Registrar::~Registrar (void)
{

}

}
}
