// -*- C++ -*-

//=============================================================================
/**
 * @file          Association_Handler.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ASSOCIATION_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_ASSOCIATION_HANDLER_H_

#include "game/mga/component/Event_Handler_Impl.h"

/**
 * @class Association_Handler
 *
 * Handler that is responsible for resolving
 * association type of relationship
 */
class Association_Handler :
  public GAME::Mga::Dynamic_Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  Association_Handler (void);

  /// Destructor.
  virtual ~Association_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_ASSOCIATION_HANDLER_H_
