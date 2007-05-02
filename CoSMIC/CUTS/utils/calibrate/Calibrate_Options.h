// -*- C++ -*-

//=============================================================================
/**
 * @file      Calibrate_Options.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CALIBRATE_OPTIONS_H_
#define _CUTS_CALIBRATE_OPTIONS_H_

#include "ace/SString.h"

//=============================================================================
/**
 * @class CUTS_Calibrate_Options
 *
 * Collection of options for the calibration program.
 */
//=============================================================================

class CUTS_Calibrate_Options
{
public:
  CUTS_Calibrate_Options (void)
    : verbose_ (false)
  {

  }

  /// Path of the worker library to calibrate.
  ACE_CString worker_library_;

  /// Verbosity flags.
  bool verbose_;
};

#endif  // !defined _CUTS_CALIBRATE_OPTIONS_H_
