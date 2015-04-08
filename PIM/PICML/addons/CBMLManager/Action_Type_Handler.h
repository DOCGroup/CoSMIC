// -*- C++ -*-

//=============================================================================
/**
 * @file        Action_Type_Handler.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CBML_ACTION_TYPE_HANDLER_H_
#define _CBML_ACTION_TYPE_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"

/**
 * @class CBML_Action_Type_Handler
 *
 * Handler that is responsible for generating connections that
 * connect with the State element.
 */
class CBML_Action_Type_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_RELATION;

  /// Default constructor.
  CBML_Action_Type_Handler (void);

  /// Destructor.
  virtual ~CBML_Action_Type_Handler (void);

  virtual int handle_object_relation (GAME::Mga::Object_in obj);

private:
  void create_property (GAME::Mga::Model_in action,
                        const GAME::Mga::Reference_in parameter);
};

#endif  // !defined _CBML_CONNECTION_GENERATION_HANDLER_H_