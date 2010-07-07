// $Id$

//=============================================================================
/**
 * @file        Automation_App_Options.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_AUTOMATION_APP_OPTIONS_H_
#define _GAME_AUTOMATION_APP_OPTIONS_H_

#include <string>
#include <map>
#include "game/config.h"

/**
 * @class GAME_Automation_App_Options
 *
 * Options abstraction for the GAME automation application.
 */
struct GAME_Automation_App_Options
{
  /// Default constructor. This will set the default options
  /// for this class, and the application.
  GAME_Automation_App_Options (void);

  std::string project_;

  std::string interpreter_;

  typedef std::map <std::string, std::string> param_t;

  param_t params_;

  bool enable_auto_addons_;

  bool interactive_;
};

#if defined (__GAME_INLINE__)
#include "Automation_App_Options.inl"
#endif

#endif
