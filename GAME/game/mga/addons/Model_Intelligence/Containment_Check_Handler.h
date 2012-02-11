// -*- C++ -*-

//=============================================================================
/**
 * @file         Containment_Check_Handler.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONTAINMENT_CHECK_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_CONTAINMENT_CHECK_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"

/**
 * @class Containment_Check_Handler
 *
 * Handler that is responsible for controlling the
 * number of a particular FCO based on the constraint.
 */
class Containment_Check_Handler :
  public GAME::Mga::Dynamic_Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Containment_Check_Handler (void);

  /// Destructor.
  virtual ~Containment_Check_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_CONTAINMENT_CHECK_HANDLER_H_
