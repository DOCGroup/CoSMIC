// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Options.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_OPTIONS_H_
#define _CUTS_BE_OPTIONS_H_

#include <string>
#include "BE_export.h"

//=============================================================================
/**
 * @class CUTS_BE_Options
 *
 * Collection of options for the backend generators. The class is
 * a singleton, which allows developers to access this information
 * as if it was global.
 */
//=============================================================================

struct CUTS_BE_Export CUTS_BE_Options
{
  /// Selected output directory for the backend.
  std::string output_directory_;

  /// Get a pointer to the singleton instance.
  static CUTS_BE_Options * instance (void);

  /// Close the singleton instance and release its resources.
  static void close_singleton (void);

private:
  /// Instance of the singleton.
  static CUTS_BE_Options * instance_;
};

/// Macro definition to simplify accessing backend options
#define CUTS_BE_OPTIONS() \
  CUTS_BE_Options::instance ()

#endif  // !defined _CUTS_BE_OPTIONS_H_