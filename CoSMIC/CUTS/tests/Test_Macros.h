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

#include <sstream>

#define CUTS_TEST_SUITE_EXPORT(suite) \
  extern "C" CUTS_TEST_Export \
  CUTS_Test_Suite * create_cuts_test_suite (void) \
  { \
    return new suite (); \
  }

#define CUTS_TEST_SUITE_BEGIN(suite, cls) \
  class suite : public CUTS_Test_Suite \
  { \
  public: \
    inline suite (void) \
      : CUTS_Test_Suite (#cls) \
    {

#define CUTS_TEST_SUITE_END(suite) \
    } \
    virtual ~suite (void) { } \
  }; \
  CUTS_TEST_SUITE_EXPORT (suite)

#define CUTS_ADD_UNIT_TEST(name, unit_test) \
  this->add_unit_test (name, &unit_test);

#define CUTS_UNIT_TEST(test) \
  static int test (void)

#define CUTS_VERIFY_TEST(cond, errmsg) \
  if (cond) \
  { \
    std::ostringstream message; \
    message << __FILE__ << ":" << __LINE__ << " " \
            << errmsg << std::ends; \
    return 1; \
  }

#define CUTS_VERIFY_TEST_STR(cond, errmsg) \
  if (cond) \
  { \
    return 1; \
  }

#endif  // !defined _CUTS_TEST_MACROS_H_
