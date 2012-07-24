// -*- C++ -*-

//=============================================================================
/**
 * @file         Containment_Check_Handler.h
 *
 * $Id: Containment_Check_Handler.h 2884 2012-04-24 04:36:05Z hillj $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONTAINMENT_CHECK_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_CONTAINMENT_CHECK_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

/**
 * @class Containment_Check_Handler
 *
 * Handler that is responsible for controlling the
 * number of a particular FCO based on the constraint.
 */
class Containment_Check_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_SELECT;

  /// Default constructor.
  Containment_Check_Handler (void);

  /// Destructor.
  virtual ~Containment_Check_Handler (void);

  virtual int handle_object_select (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_CONTAINMENT_CHECK_HANDLER_H_
