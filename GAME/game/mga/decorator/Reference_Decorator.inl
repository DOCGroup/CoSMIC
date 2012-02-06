// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Reference_Decorator
//
GAME_INLINE
Reference_Decorator::Reference_Decorator (void)
{

}

//
// Reference_Decorator
//
GAME_INLINE
Reference_Decorator::
Reference_Decorator (bool use_default_bitmap, bool show_refers_to)
: FCO_Decorator (use_default_bitmap),
  show_refers_to_ (show_refers_to)
{

}

//
// ~Reference_Decorator
//
GAME_INLINE
Reference_Decorator::~Reference_Decorator (void)
{

}

}
}
