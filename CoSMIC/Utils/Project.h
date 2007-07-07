// -*- C++ -*-

//===========================================================================
/**
 * @file      Project.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//===========================================================================

#ifndef _UTILS_PROJECT_H_
#define _UTILS_PROJECT_H_

#include "Utils_Export.h"
#include <string>

// avoid conflicts (redefinitions) with ComponentLib.idl
#if !defined (__ComponentLib_h__)
#include "Mga.h"
#endif

namespace Utils
{
  //===========================================================================
  /**
   * @class Project
   *
   * Utility class for GME projects.
   */
  //===========================================================================

  class Utils_Export Project
  {
  public:
    /**
     * Get the global cached output directory.
     *
     * @param[in]       project     The target project.
     * @return          The global cached output directory,
     */
    static std::string get_global_default_output_dir (IMgaProject * project);

    /**
     * Set the global cached output directory.
     *
     * @param[in]       project     The target project.
     * @param[in]       outdir      The output directory to store.
     */
    static void set_global_default_output_dir (IMgaProject * project,
                                               const std::string & outdir);

    /**
     * Get the cached output directory. This will get the cached
     * output directory for a given \a uuid. It is advised that
     * the \a uuid not contain any spaces. If you want to global
     * cached output directory, use global_cached_outdir ().
     *
     * @param[in]       project     The target project.
     * @param[in]       uuid        Unique identifier
     * @return          The cached output directory.
     */
    static std::string get_default_output_dir (IMgaProject * project,
                                               const std::string & uuid);

    /**
     * Set the cached output directory. This will store the output
     * directory associated with \a uuid inside the model.
     *
     * @param[in]       project     The target project.
     * @param[in]       uuid        Unique identifier
     * @param[in]       outdir      The output directory to store.
     */
    static void set_default_output_dir (IMgaProject * project,
                                        const std::string & uuid,
                                        const std::string & outdir);
  };
}

#endif  // !defined _UTILS_PROJECT_H_
