// -*- C++ -*-

//=============================================================================
/**
 * @file      Test_Macros.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TEST_MACROS_H_
#define _CUTS_TEST_MACROS_H_

//=============================================================================
/**
 * Exports the factory method for creating the test \a suite. The
 * \a suite is the same as the one used in CUTS_TEST_SUITE_BEGIN
 * and CUTS_TEST_SUITE_END.
 */
//=============================================================================

#define CUTS_TEST_SUITE_EXPORT(suite) \
  extern "C" CUTS_TEST_Export \
  CUTS_Test_Suite * create_cuts_test_suite (void) \
  { \
    return new suite (); \
  }

//=============================================================================
/**
 * Defines the beginning of a test suite. This will create a
 * test suite of type \a suite for the class \cls.
 */
//=============================================================================

#define CUTS_TEST_SUITE_BEGIN(suite, cls) \
  class suite : public CUTS_Test_Suite \
  { \
  public: \
    inline suite (void) \
      : CUTS_Test_Suite (#cls) \
    {

//=============================================================================
/**
 * Defines the end of a test suite for \a suite.
 */
//=============================================================================

#define CUTS_TEST_SUITE_END(suite) \
    } \
    virtual ~suite (void) { } \
  }; \
  CUTS_TEST_SUITE_EXPORT (suite)

//=============================================================================
/**
 * Addes a new \a unit_test to the test suite that has the
 * specified \a name.
 */
//=============================================================================

#define CUTS_ADD_UNIT_TEST(name, unit_test) \
  this->add_unit_test (name, &unit_test);

//=============================================================================
/**
 * Declares a unit unit test. This maps to a function with the
 * declaration name of \a test.
 */
//=============================================================================

#define CUTS_UNIT_TEST(test) \
  static int test (void)

//=============================================================================
/**
 * Verify the success of a particular test. If the \cond is false,
 * then it will log the \errmsg to the message log as an error and
 * return 1.
 */
//=============================================================================

#define CUTS_VERIFY_TEST(cond, errmsg) \
  if (cond) \
  { \
    std::ostringstream msg; \
    msg << __FILE__ << ":" << __LINE__ << " " \
            << errmsg << std::ends; \
    CUTS_Msg_Log::instance ()->error_message (msg.str ()); \
    return 1; \
  }

//=============================================================================
/**
 * Verify the success of a particular test. If the \cond is false,
 * then it will log the \errmsg to the message log as an error and
 * continue.
 */
//=============================================================================

#define CUTS_VERIFY_TEST_CONTINUE(cond, errmsg) \
  if (cond) \
  { \
    std::ostringstream msg; \
    msg << __FILE__ << ":" << __LINE__ << " " \
            << errmsg << std::ends; \
    CUTS_Msg_Log::instance ()->error_message (msg.str ()); \
  }

#endif  // !defined _CUTS_TEST_MACROS_H_
