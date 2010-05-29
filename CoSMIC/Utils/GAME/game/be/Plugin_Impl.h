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

#ifndef _GME_PLUGIN_IMPL_H_
#define _GME_PLUGIN_IMPL_H_

#include "Interpreter_Impl_Base.h"

namespace GAME
{
  /**
   * @class Plugin_Impl_Base
   *
   * Base class for all plug-in implementations. The concrete plug-in
   * should derive from this class. The subclass should then be used
   * as the IMPL parameter in Plugin_T class.
   */
  class GAME_BE_Export Plugin_Impl :
    public GAME::Interpreter_Impl_Base
  {
  public:
    /**
     * Initializing constructor.
     */
    Plugin_Impl (const std::string & name,
                      const std::string & progid,
                      bool managed = true);

    /// Desturctor.
    virtual ~Plugin_Impl (void);
  };
}


#if defined (__GAME_INLINE__)
#include "Plugin_Impl.inl"
#endif

#endif  // !defined _GME_PLUGIN_IMPL_H_
