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

  ACE_DEBUG ((LM_INFO,
              "*** info (%s): opening %s for calibration\n",
              argv[0],
              argv[1]));

  if (test_dll.open (argv[1], ACE_DEFAULT_SHLIB_MODE, 0) == 0)
  {
    // Load the export symbol to create the test_suite and create the
    // test_suite using the symbol.

    ACE_DEBUG ((LM_DEBUG,
                "*** info (%s): extacting worker factory method\n",
                argv[0]));
 
    void * symbol = test_dll.symbol (CUTS_WORKER_SYMBOL);

    if (symbol == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error: failed to load symbol %s\n",
                         CUTS_WORKER_SYMBOL),
                         1);
    }

    // Create the worker from the factory method.
    ACE_DEBUG ((LM_DEBUG,
                "*** info (%s): creating worker via factory\n",
                argv[0]));

    typedef CUTS_Worker * (* CUTS_WORKER_EXPORT_SYMBOL) (void);

    CUTS_WORKER_EXPORT_SYMBOL worker_factory = 
      reinterpret_cast <CUTS_WORKER_EXPORT_SYMBOL> (symbol);

    CUTS_Worker * worker = worker_factory ();

    if (worker != 0)
    {
      ACE_DEBUG ((LM_INFO,
                  "*** info (%s): invoking calibrate on worker "
                  "located in %s\n",
                  argv[0],
                  argv[1]));

      // Invoke the calibration method.
      bool retval = worker->calibrate ();

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
