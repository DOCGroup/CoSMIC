// -*- C++ -*-

//=============================================================================
/**
 * @file      calibration.cpp
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#include "Calibrate_Options.h"
#include "cuts/Worker.h"
#include "ace/DLL.h"
#include "ace/Get_Opt.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"

/// Helper for using the options as a singleton.
#define CALIBRATE_OPTIONS() \
  ACE_Singleton <CUTS_Calibrate_Options, ACE_Null_Mutex>::instance ()

// Helper macro for generating verbose messages.
#define VERBOSE_MESSAGE(msg) \
  if (CALIBRATE_OPTIONS ()->verbose_) \
  { \
    ACE_DEBUG (msg); \
  }

//
// parse_args
//
int parse_args (int argc, char * argv [])
{
  const char * opts = ACE_TEXT ("vf:");
  ACE_Get_Opt get_opt (argc, argv, opts, 1);

  int option;

  while ((option = get_opt ()) != EOF)
  {
    switch (option)
    {
    case 'f':
      CALIBRATE_OPTIONS ()->worker_library_ = get_opt.opt_arg ();
      break;

    case 'v':
      CALIBRATE_OPTIONS ()->verbose_ = true;
      break;

    case '?':
      ACE_ERROR ((LM_ERROR,
                  "*** warning [calibrate]: -%c is an unknown option\n",
                  get_opt.opt_opt ()));
      break;

    case ':':
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error [calibrate]: -%c is missing an argument\n",
                         get_opt.opt_opt ()),
                         -1);
      break;

    default:
      /* do nothing */;
    }
  }
  return 0;
}

//
// main
//
int main (int argc, char * argv [])
{
  if (parse_args (argc, argv) != 0)
    return 1;

  // This will automatically close the dll when the
  // object is destroyed.
  ACE_DLL test_dll;

  VERBOSE_MESSAGE ((LM_INFO,
                    "*** info (%s): opening %s for calibration\n",
                    argv[0],
                    CALIBRATE_OPTIONS ()->worker_library_.c_str ()));

  if (test_dll.open (CALIBRATE_OPTIONS ()->worker_library_.c_str (),
                     ACE_DEFAULT_SHLIB_MODE, 0) == 0)
  {
    // Load the export symbol that will allow use to create
    // the worker to be calibrated.

    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info (%s): extacting worker factory method\n",
                      argv[0]));

    void * symbol = test_dll.symbol (CUTS_WORKER_FACTORY_SYMBOL_NAME);

    if (symbol == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error: failed to load symbol '%s'\n",
                         CUTS_WORKER_FACTORY_SYMBOL_NAME),
                         1);
    }

    // Create the worker from the factory method.
    VERBOSE_MESSAGE ((LM_INFO,
                      "*** info (%s): creating worker via factory\n",
                      argv[0]));

    typedef CUTS_Worker * (* CUTS_WORKER_EXPORT_SYMBOL) (void);

    CUTS_WORKER_EXPORT_SYMBOL worker_factory =
      (CUTS_WORKER_EXPORT_SYMBOL) symbol;

    CUTS_Worker * worker = worker_factory ();

    if (worker != 0)
    {
      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info (%s): invoking calibrate on worker "
                        "located in '%s'\n",
                        argv[0],
                        CALIBRATE_OPTIONS ()->worker_library_.c_str ()));

      // Invoke the calibration method.
      bool retval = worker->calibrate ();

      VERBOSE_MESSAGE ((LM_INFO,
                        "*** info (%s): calibration %s\n",
                        argv[0],
                        (retval ? "succeeded" : "failed")));

      // Close the test_suite and the DLL module.
      worker->release ();
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: failed to run calibration in '%s'\n",
                  test_dll.dll_name_));
    }
  }

  return 1;
}
