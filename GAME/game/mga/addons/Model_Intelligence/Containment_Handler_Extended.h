// -*- C++ -*-

//=============================================================================
/**
 * @file         Containment_Handler_Extended.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONTAINMENT_HANDLER_EXTENDED_H_
#define _GAME_MODEL_INTELLIGENCE_CONTAINMENT_HANDLER_EXTENDED_H_

#include "game/mga/component/Event_Handler_Impl.h"

/**
 * @class Containment_Handler_Extended
 *
 * Handler that is responsible for controlling the
 * number of a particular FCO based on the constraint.
 */
class Containment_Handler_Extended :
  public GAME::Mga::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Containment_Handler_Extended (void);

  /// Destructor.
  virtual ~Containment_Handler_Extended (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_CONTAINMENT_HANDLER_EXTENDED_H_
