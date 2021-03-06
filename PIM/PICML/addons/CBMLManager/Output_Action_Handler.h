// -*- C++ -*-

//=============================================================================
/**
 * @file        Output_Action_Handler.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CBML_OUTPUT_ACTION_HANDLER_H_
#define _CBML_OUTPUT_ACTION_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

/**
 * @class CBML_Output_Action_Handler
 *
 * Handler that is responsible for generating connections that
 * connect with the State element.
 */
class CBML_Output_Action_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_CREATED;

  /// Default constructor.
  CBML_Output_Action_Handler (void);

  /// Destructor.
  virtual ~CBML_Output_Action_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);
};

#endif  // !defined _CBML_CONNECTION_GENERATION_HANDLER_H_