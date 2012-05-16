// -*- C++ -*-

//=============================================================================
/**
 * @file         Attributes_Handler.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================


#ifndef _GAME_MODEL_INTELLIGENCE_ATTRIBUTES_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_ATTRIBUTES_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

/**
 * @class Attributes_Handler
 *
 * Handler that is responsible for assigning attribute values
 * to objects.
 */
class Attributes_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Attributes_Handler (void);

  /// Destructor.
  virtual ~Attributes_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_ATTRIBUTE_HANDLER_H_
