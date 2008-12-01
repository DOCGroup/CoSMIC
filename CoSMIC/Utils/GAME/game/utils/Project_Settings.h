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

#include "game/Project.h"

namespace GME
{
namespace Utils
{
  /**
   * @class Project_Settings
   *
   * Utility class for managing settings of a GME project.
   */
  class GME_Export Project_Settings
  {
  public:
    /**
     * Initializing constructor.
     */
    Project_Settings (const GME::Project & project);

    /// Destructor.
    ~Project_Settings (void);

    void global_default_output_directory (const std::string & dir);
    std::string global_default_output_directory (void) const;

    void default_output_directory (const std::string & uid,
                                   const std::string & dir);

    std::string default_output_directory (const std::string & uid) const;

  private:
    /// Target GME project.
    GME::Project project_;

    const std::string default_cache_loc_;
  };
}
}

#if defined (__GME_INLINE__)
#include "Project_Settings.inl"
#endif

#endif  // !defined _GAME_UTILS_PROJECT_SETTINGS_
