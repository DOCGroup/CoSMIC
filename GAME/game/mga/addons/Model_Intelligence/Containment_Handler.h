// -*- C++ -*-

//=============================================================================
/**
 * @file         Containment_Handler.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONTAINMENT_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_CONTAINMENT_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"

/**
 * @class Containment_Handler
 *
 * Handler that is responsible for generating FCO's
 * contained within an object.
 */
class Containment_Handler :
  public GAME::Mga::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Containment_Handler (void);

  /// Destructor.
  virtual ~Containment_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_CONTAINMENT_HANDLER_H_
