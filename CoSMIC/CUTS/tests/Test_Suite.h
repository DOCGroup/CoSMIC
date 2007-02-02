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
#include <list>
#include <string>
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
  /**
   * Run the test. This involves running all the unit test.
   *
   * @param     argc      The number of command line arguments.
   * @param     arvg      The command-line arguments for the test.
   */
  virtual void run (int argc, char * argv []);

  /**
   * Get the name of the test.
   *
   * @return    NULL-terminated string.
   */
  virtual const char * name (void) const;

  /// Close the test and release all its resources.
  virtual void close (void);

  virtual size_t passed (void) const;

  virtual size_t failed (void) const;

protected:
  typedef int (* unit_test_ptr) (void);

  /**
   * Add a unit test to the test.
   *
   * @param[in]     unit_test       Pointer to the unit test.
   */
  void add_unit_test (const std::string & name,
                      unit_test_ptr unit_test);

  /// Initializing constructor.
  CUTS_Test_Suite (const char *);

  /// Destructor.
  virtual ~CUTS_Test_Suite (void);

private:
  // Type definition for a collection of unit tests.
  typedef std::list <std::pair <std::string,
                                unit_test_ptr> > Unit_Test_List;

  /// Name of the test suite.
  std::string name_;

  /// Collection of unit test.
  Unit_Test_List unit_test_;

  /// Number of passed test.
  size_t passed_;

  /// Number of failed test.
  size_t failed_;
};

#endif  // !defined _CUTS_TEST_SUITE_H_
