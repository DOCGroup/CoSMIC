// $Id$

//=============================================================================
/**
 * @file      Test_Client.cpp
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#include "ace/DLL.h"
#include "ace/Log_Msg.h"
#include "Test_Suite.h"

#define CUTS_TEST_SYMBOL     "create_cuts_test_suite"

//
// main
//
int main (int argc, char * argv [])
{
  // This will automatically close the dll when the
  // object is destroyed.
  ACE_DLL test_dll;

  if (test_dll.open (argv[1], ACE_DEFAULT_SHLIB_MODE, 0) == 0)
  {
    // Load the export symbol to create the test_suite and create the
    // test_suite using the symbol.
    typedef CUTS_Test_Suite * (* CUTS_TEXT_EXPORT_SYMBOL)(void);

    CUTS_TEXT_EXPORT_SYMBOL create_cuts_test =
      (CUTS_TEXT_EXPORT_SYMBOL) test_dll.symbol (CUTS_TEST_SYMBOL);

    if (create_cuts_test == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "*** error: failed to load symbol %s\n",
                         CUTS_TEST_SYMBOL),
                         1);
    }

    // Create the test suite from the factory method.
    CUTS_Test_Suite * test_suite = create_cuts_test ();

    if (test_suite != 0)
    {
      // Run the test_suite.
      test_suite->run (argc, argv);

      ACE_ERROR ((LM_INFO,
                  "*** info: %u passed and %u failed\n",
                  test_suite->name (),
                  test_suite->passed (),
                  test_suite->failed ()));

      // Close the test_suite and the DLL module.
      test_suite->close ();
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error: failed to run test_suite in %s\n",
                  test_dll.dll_name_));
    }
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error: failed to load %s\n",
                argv[1]));
  }

  return 0;
}
