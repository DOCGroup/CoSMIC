// -*- C++ -*-

//=============================================================================
/**
 * @file        Project_Settings.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_UTILS_PROJECT_SETTINGS_
#define _GAME_MGA_UTILS_PROJECT_SETTINGS_

#include "game/mga/Project.h"
#include "GAME_Utils_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Preferences
 *
 * Utility class to manipulate the preferences for a given FCO
 * object. The preferences are the FCO's attributes defined in
 * the metamodel, such as icon and color. Using this class, it
 is possible to get and set these values programmatically.
 *
 *
 */
class GAME_UTILS_Export Preferences
{
public:
  /// Get the FCO's icon name.
  static std::string icon_name (const FCO_in fco);
  static std::string icon_name (const Meta::FCO_in fco);

  /// Test if the FCO's name is enabled.
  static bool is_name_enabled (const FCO_in fco);
};

}
}

#if defined (__GAME_INLINE__)
#include "Preferences.inl"
#endif

#endif  // !defined _GAME_MGA_UTILS_PROJECT_SETTINGS_
