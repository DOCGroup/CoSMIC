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

#include "cuts/Worker.h"
#include "ace/DLL.h"
#include "ace/Log_Msg.h"

#define CUTS_WORKER_SYMBOL     "create_cuts_worker"

//
// main
//
int main (int argc, char * argv [])
{
  if (argc == 1)
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                      "*** error (calibration): missing worker "
                      "library parameter\n"),
                      1);
  }

  // This will automatically close the dll when the
  // object is destroyed.
  ACE_DLL test_dll;

  if (test_dll.open (argv[1], ACE_DEFAULT_SHLIB_MODE, 0) == 0)
  {
    // Load the export symbol to create the test_suite and create the
    // test_suite using the symbol.
    typedef CUTS_Worker * (* CUTS_WORKER_EXPORT_SYMBOL)(void);

    CUTS_WORKER_EXPORT_SYMBOL create_cuts_worker =
      (CUTS_WORKER_EXPORT_SYMBOL) test_dll.symbol (CUTS_WORKER_SYMBOL);

    if (create_cuts_worker == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error: failed to load symbol %s\n",
                         CUTS_WORKER_SYMBOL),
                         1);
    }

    // Create the test suite from the factory method.
    CUTS_Worker * worker = create_cuts_worker ();

    if (worker != 0)
    {
      ACE_DEBUG ((LM_INFO,
                  "*** info (%s): invoking calibrate on worker "
                  "located in %s\n",
                  argv[0],
                  argv[1]));

      // Invoke the calibration method.
      bool retval = worker->calibrate ();

      ACE_DEBUG ((LM_DEBUG, "..."));

      ACE_DEBUG ((LM_INFO,
                  "*** info (%s): calibration %s\n",
                  argv[0],
                  (retval ? "succeeded" : "failed")));

      // Close the test_suite and the DLL module.
      worker->release ();
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: failed to run calibration in %s\n",
                  test_dll.dll_name_));
    }
  }

  return 1;
}
