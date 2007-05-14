// -*- C++ -*-

//=============================================================================
/**
 * @file    Test.h
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TEST_SUITE_H_
#define _CUTS_TEST_SUITE_H_

#include "CUTS_Test_export.h"
#include "Test_Macros.h"
#include "Msg_Log.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include "ace/SString.h"

#include <list>
#include <utility>

//=============================================================================
/**
 * @class CUTS_Test_Suite
 *
 * Base class for all test run by the testing client. This class defines
 * the necessary data/methods to provide meaningful information to the
 * testing client for executing the test and reporting messages.
 */
//=============================================================================

class CUTS_TEST_Export CUTS_Test_Suite
{
public:
  typedef int (* _unit_test) (void);

  /// Initializing constructor.
  CUTS_Test_Suite (void);

  CUTS_Test_Suite (const ACE_CString & name);

  /// Destructor.
  ~CUTS_Test_Suite (void);

  /**
   * Get the name of the test.
   *
   * @return    NULL-terminated string.
   */
  const ACE_CString & name (void) const;

  void name (const ACE_CString & name);

  size_t passed (void) const;

  size_t failed (void) const;

  /**
   * Add a unit test to the test.
   *
   * @param[in]     unit_test       Pointer to the unit test.
   */
  int add_unit_test (const ACE_CString & name,
                     _unit_test unit_test);

  int run_all_unit_test (int argc, char * argv []);

private:
  // Type definition for a collection of unit tests.
  typedef std::list <std::pair <ACE_CString,
                                _unit_test> > Unit_Test_List;

  /// Name of the test suite.
  ACE_CString name_;

  /// Collection of unit test.
  Unit_Test_List unit_test_;

  /// Number of passed test.
  size_t passed_;

  /// Number of failed test.
  size_t failed_;
};

CUTS_TEST_SINGLETON_DECLARE (ACE_Singleton,
                             CUTS_Test_Suite,
                             ACE_Null_Mutex);

#define CUTS_TEST_SUITE() \
  ACE_Singleton <CUTS_Test_Suite, ACE_Null_Mutex>::instance ()

#endif  // !defined _CUTS_TEST_SUITE_H_
