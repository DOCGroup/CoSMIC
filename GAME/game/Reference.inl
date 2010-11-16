// -*- C++ -*-
// $Id$

namespace GAME
{
//
// Reference
//
GAME_INLINE
Reference::Reference (void)
{

}

//
// Reference
//
GAME_INLINE
Reference::Reference (IMgaReference * ref)
  : FCO (ref)
{

}

//
// Reference
//
GAME_INLINE
Reference::Reference (const Reference & ref)
  : FCO (ref)
{

}

//
// ~Reference
//
GAME_INLINE
Reference::~Reference (void)
{

}

}
