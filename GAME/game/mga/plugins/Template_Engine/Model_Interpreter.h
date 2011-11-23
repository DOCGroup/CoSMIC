// -*- C++ -*-

//=============================================================================
/**
 * @file        Model_Interpreter.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CUTE_MODEL_INTERPRETER_H_
#define _CUTS_CUTE_MODEL_INTERPRETER_H_

#include "game/mga/ComponentEx.h"
#include "parser/Property_Map.h"

/**
 * @class Gme_Model_Interpreter
 *
 * Proxy class for a GME interpreter.
 */
class Gme_Model_Interpreter
{
public:
  /**
   * Initializing constructor.
   */
  Gme_Model_Interpreter (const std::string & progid);

  /// Destructor.
  ~Gme_Model_Interpreter (void);

  /**
   * Set the interpreter's parameters.
   */
  void set_parameters (const std::string & params);

  /**
   * Execute the interpreter.
   *
   * @param[in]       project         Target project
   * @param[in]       target          Active object
   * @param[in]       selected        List of selected FCOs
   * @param[in]       flags           Flags to pass to interpreter
   */
  void interpret (GAME::Mga::Project project,
                  GAME::Mga::FCO target,
                  const std::vector <GAME::Mga::FCO> & selected,
                  long flags);

private:
  /// Reference to the real interpreter.
  GAME::Mga::ComponentEx interpreter_;
};

#if defined (__GAME_INLINE__)
#include "Model_Interpreter.inl"
#endif

#endif  // !defined _CUTS_CUTE_MODEL_INTERPRETER_H_
