// -*- C++ -*-

//=============================================================================
/**
 * @file          Association_Handler.h
 *
 * $Id: Association_Handler.h 2899 2012-05-01 20:01:10Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ASSOCIATION_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_ASSOCIATION_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

/**
 * @class Association_Handler
 *
 * Handler that is responsible for resolving
 * association type of relationship
 */
class Association_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_SELECT;

  /// Default constructor.
  Association_Handler (void);

  /// Destructor.
  virtual ~Association_Handler (void);

  virtual int handle_object_select (GAME::Mga::Object_in obj);
};

#endif  // !defined  _GAME_MODEL_INTELLIGENCE_ASSOCIATION_HANDLER_H_
