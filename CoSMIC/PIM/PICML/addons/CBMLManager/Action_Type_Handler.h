// -*- C++ -*-

//=============================================================================
/**
 * @file        Action_Type_Handler.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CBML_ACTION_TYPE_HANDLER_H_
#define _CBML_ACTION_TYPE_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"
#include "game/Model.h"
#include "game/Reference.h"

/**
 * @class CBML_Action_Type_Handler
 *
 * Handler that is responsible for generating connections that
 * connect with the State element.
 */
class CBML_Action_Type_Handler :
  public GAME::Event_Handler_Impl
{
public:
  static const unsigned long eventmask = OBJEVENT_RELATION;

  /// Default constructor.
  CBML_Action_Type_Handler (void);

  /// Destructor.
  virtual ~CBML_Action_Type_Handler (void);

  virtual int handle_object_relation (GAME::Object_in obj);

private:
  void create_property (GAME::Model_in action,
                        const GAME::Reference_in parameter);
};

#endif  // !defined _CBML_CONNECTION_GENERATION_HANDLER_H_