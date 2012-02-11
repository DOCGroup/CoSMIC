// -*- C++ -*-

//=============================================================================
/**
 * @file         Reference_Handler.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================


#ifndef _GAME_MODEL_INTELLIGENCE_REFERENCE_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_REFERENCE_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"

/**
 * @class Reference_Handler
 *
 * Handler that is responsible for creating references
 * to objects.
 */
class Reference_Handler :
  public GAME::Mga::Dynamic_Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Reference_Handler (void);

  /// Destructor.
  virtual ~Reference_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_REFERENCE_HANDLER_H_
