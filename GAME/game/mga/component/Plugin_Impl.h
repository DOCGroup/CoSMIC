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

#include "ComponentEx_Impl_Base.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Plugin_Impl_Base
 *
 * Base class for all plug-in implementations. The concrete plug-in
 * should derive from this class. The subclass should then be used
 * as the IMPL parameter in Plugin_T class.
 */
class GAME_MGA_COMPONENT_Export Plugin_Impl : public ComponentEx_Impl_Base
{
public:
  /**
   * Initializing constructor.
   */
  Plugin_Impl (const std::string & name,
               const std::string & progid);

  /// Desturctor.
  virtual ~Plugin_Impl (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Plugin_Impl.inl"
#endif

#endif  // !defined _GME_PLUGIN_IMPL_H_
