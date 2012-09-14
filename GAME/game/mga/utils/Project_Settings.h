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
 * @class Project_Settings
 *
 * Utility class for managing settings of a GME project.
 */
class GAME_UTILS_Export Project_Settings
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       project       Target project
   */
  Project_Settings (Project project);

  /**
   * Initializing constructor.
   *
   * @param[in]       project       Target project
   * @param[in]       cache_loc     Location for storing settings.
   */
  Project_Settings (Project project, const std::string & cache_loc);

  /// Destructor.
  ~Project_Settings (void);

  void global_default_output_directory (const std::string & dir);

  std::string global_default_output_directory (void) const;

  void default_output_directory (const std::string & uid, const std::string & dir);
  std::string default_output_directory (const std::string & uid) const;

  bool set_value (const std::string & path, bool value);
  bool set_value (const std::string & path, const std::string & value);

  template <typename T>
  bool set_value (const std::string & path, T value);

  bool get_value (const std::string & path, bool & value);
  bool get_value (const std::string & path, std::string & value);

  template <typename T>
  bool get_value (const std::string & patn, T & value);

private:
  /// Target GME project.
  Project project_;

  std::string default_cache_loc_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Project_Settings.inl"
#endif

#include "Project_Settings_T.cpp"

#endif  // !defined _GAME_MGA_UTILS_PROJECT_SETTINGS_
