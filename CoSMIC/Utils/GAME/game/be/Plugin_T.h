// -*- C++ -*-

//=============================================================================
/**
 * @class       Plugin_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_PLUGIN_T_H_
#define _GME_PLUGIN_T_H_

#include "Interpreter_T.h"

namespace GAME
{
  /**
   * @class Plugin_T
   */
  template <typename T, typename IMPL>
  class ATL_NO_VTABLE Plugin_T :
    public GAME::Interpreter_T <T, IMPL>
  {
  public:
    /// Default constructor
    Plugin_T (void);

    /// Destructor
    virtual ~Plugin_T (void);
  };
}

#if defined (__GAME_INLINE__)
#include "Plugin_T.inl"
#endif

#include "Plugin_T.cpp"

#endif  // !defined _GME_INTERPRETER_T_H_
