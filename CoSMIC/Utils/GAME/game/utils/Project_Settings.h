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

#ifndef _GAME_UTILS_PROJECT_SETTINGS_
#define _GAME_UTILS_PROJECT_SETTINGS_

#include <string>
#include "game/config.h"
#include "GAME_Utils_export.h"

namespace GAME
{
// Forward decl.
class Project;

namespace utils
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
     */
    Project_Settings (::GAME::Project & project);

    /// Destructor.
    ~Project_Settings (void);

    void global_default_output_directory (const std::string & dir);

    std::string global_default_output_directory (void) const;

    void default_output_directory (const std::string & uid,
                                   const std::string & dir);

    std::string default_output_directory (const std::string & uid) const;

  private:
    /// Target GME project.
    GAME::Project & project_;

    const std::string default_cache_loc_;
  };
}
}

#if defined (__GAME_INLINE__)
#include "Project_Settings.inl"
#endif

#endif  // !defined _GAME_UTILS_PROJECT_SETTINGS_
