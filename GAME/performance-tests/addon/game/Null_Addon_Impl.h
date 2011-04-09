/* -*- C++ -*- */

//=============================================================================
/**
 * @file      Null_Addon_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_NULL_ADDON_IMPL_H_
#define _GAME_NULL_ADDON_IMPL_H_

#include "game/mga/component/Event_Handler_Impl.h"

namespace GAME
{
/**
 * @class Null_Addon_Sink
 *
 * Implementation of a null (i.e., no-op) addon. This add-on can receive
 * every type of event, but does not process any of the events. It is
 * primarily used for functional and performance testing purposes.
 */
class Null_Addon_Sink : public GAME::Mga::Event_Handler_Impl
{
public:
  /// Constructor.
  Null_Addon_Sink (void);

  /// Destructor.
  virtual ~Null_Addon_Sink (void);
};

}

#endif // _GAME_NULL_ADDON_IMPL_H_
