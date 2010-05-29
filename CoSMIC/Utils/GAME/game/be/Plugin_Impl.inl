// -*- C++ -*-
// $Id$

namespace GAME
{
//
// Plugin_Impl
//
GAME_INLINE
Plugin_Impl::Plugin_Impl (const std::string & name, const std::string & progid, bool managed)
  : GAME::Interpreter_Impl_Base (name, "*", progid, managed)
{

}

//
// ~Plugin_Impl
//
GAME_INLINE
Plugin_Impl::~Plugin_Impl (void)
{

}
}
