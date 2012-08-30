// -*- C++ -*-

//=============================================================================
/**
 * @file        Template_Engine_Impl.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTE_PLUGIN_IMPL_H_
#define _CUTE_PLUGIN_IMPL_H_

#include "game/mga/component/Plugin_Impl.h"
#include "ace/SString.h"
#include "ace/Unbounded_Set.h"
#include "Interpreter_List.h"

// Forward decl.
class Property_Map;

/**
 * @class GAME_Template_Engine
 *
 * Implementation of the CUTE plugin.
 */
class GAME_Template_Engine :
  public GAME::Mga::Plugin_Impl
{
public:
  /// Default constructor.
  GAME_Template_Engine (void);

  /// Destructor.
  virtual ~GAME_Template_Engine (void);

  /**
   * Handle the InvokeEx method.
   */
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in fco,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);

private:
  int handle_interpret (GAME::Mga::Project project,
                        GAME::Mga::FCO_in fco,
                        std::vector <GAME::Mga::FCO> & selected,
                        long flags,
                        const char * config_file,
                        const char * prog_id,
                        const char * parameters);

  int handle_generate (GAME::Mga::Project project,
                       GAME::Mga::FCO_in fco,
                       std::vector <GAME::Mga::FCO> & selected,
                       long flags,
                       const char * config_file);
};

#endif  // !defined _CUTE_PLUGIN_IMPL_H_
