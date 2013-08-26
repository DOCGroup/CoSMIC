// -*- C++ -*-

//==============================================================================
/**
 *  @file        MultiInput_Handler.h
 *
 *  $Id: generate_cpp_class.py 3685 2012-09-26 14:45:04Z dfeiock $
 *
 *  @author      Dennis Feiock
 */
//==============================================================================

#ifndef _CBML_MULTIINPUT_HANDLER_H_
#define _CBML_MULTIINPUT_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

/**
 * @class MultiInput_Handler
 *
 * Handler for managing MultiInput/Facet behavior
 */
class CBML_MultiInput_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  static const unsigned long eventmask = OBJEVENT_CONNECTED | OBJEVENT_CREATED;

  /// Default constructor.
  CBML_MultiInput_Handler (void);

  /// Destructor.
  ~CBML_MultiInput_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);

private:
  // Helper method for collecting operations attached to an object
  void get_operations (GAME::Mga::Model_in object, std::vector <GAME::Mga::Object> & ops);

  // Helper method for collecting MultiInputActions attached to a facet
  void get_actions (GAME::Mga::FCO_in facet, std::vector <GAME::Mga::Object> & actions);

  // Helper method to identify potential target Operations
  void narrow_targets (const std::vector <GAME::Mga::Object> & ops,
                       const std::vector <GAME::Mga::Object> & actions,
                       std::vector <GAME::Mga::Object> & targets);
};


#if defined (__GAME_INLINE__)
#include "MultiInput_Handler.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _CBML_MULTIINPUT_HANDLER_H_
