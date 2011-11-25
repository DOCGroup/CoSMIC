// -*- C++ -*-

//=============================================================================
/**
 * @file        Boost_JUnit_Formatter.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BOOST_JUNIT_FORMATTER_H_
#define _CUTS_BOOST_JUNIT_FORMATTER_H_

#include "boost/test/unit_test.hpp"
#include "boost/test/unit_test_log_formatter.hpp"
#include <fstream>

#define XSTR(X) STR(X)
#define STR(X) #X

/**
 * @def DEFINE_BOOST_TEST_CONFIG
 *
 * Macro for defining the Boost test configuration.
 */
#define DECLARE_BOOST_TEST_CONFIG(LOGDIR) \
  class Boost_Junit_Log_Format : public boost::unit_test::unit_test_log_formatter \
  { \
  public: \
    Boost_Junit_Log_Format (void) { } \
    Boost_Junit_Log_Format (const std::string & package) \
      : package_ (package_) { } \
    virtual ~Boost_Junit_Log_Format (void) { } \
    void log_start (std::ostream & output, boost::unit_test::counter_t test_cases_amount) { \
      output << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>" << std::endl; \
    } \
    void log_build_info (std::ostream & output) { } \
    void log_finish (std::ostream & output) { } \
    void test_unit_start (std::ostream & output, const boost::unit_test::test_unit & tu ) { \
      switch (tu.p_type) { \
      case boost::unit_test::tut_any: \
      case boost::unit_test::tut_case: \
        output << "<testcase"; \
        break; \
      case boost::unit_test::tut_suite: \
        output << "<testsuite package=\"" << this->package_ << "\""; \
        break; \
      }\
      output << " name=\"" << tu.p_name << "\">" << std::endl; \
    } \
    void test_unit_skipped (std::ostream & output, const::boost::unit_test::test_unit & tu) { } \
    void test_unit_finish (std::ostream & output, const boost::unit_test::test_unit & tu, unsigned long elapsed) { \
      output << "</test" << tu.p_type_name << ">" << std::endl; \
    } \
    void log_exception (std::ostream & output, const boost::unit_test::log_checkpoint_data & lcd, boost::unit_test::const_string explanation) { \
      output << "<error>" << explanation << "</error>" << std::endl; \
    } \
    void log_entry_start (std::ostream & output, const boost::unit_test::log_entry_data & led, boost::unit_test::unit_test_log_formatter::log_entry_types let) { \
      switch (let) { \
      case BOOST_UTL_ET_INFO: \
      case BOOST_UTL_ET_MESSAGE: \
        this->closing_tag_.clear (); \
        break;\
      case BOOST_UTL_ET_WARNING: \
        output << "<failure>"; \
        this->closing_tag_ = "</failure>"; \
        break; \
      case BOOST_UTL_ET_ERROR: \
      case BOOST_UTL_ET_FATAL_ERROR: \
        output << "<error>"; \
        this->closing_tag_ = "</error>"; \
        break; \
      default: \
        this->closing_tag_.clear (); \
      } \
    } \
    void log_entry_value (std::ostream & output, boost::unit_test::const_string value) { \
      if (!this->closing_tag_.empty ()) \
        output << value; \
    } \
    void log_entry_finish (std::ostream & output) { \
      if (this->closing_tag_.empty ()) return; \
      output << this->closing_tag_ << std::endl; \
      this->closing_tag_.clear (); \
    } \
  private: \
    std::string package_; \
    std::string closing_tag_; \
  }; \
  struct Boost_Test_Config_Fixture { \
    Boost_Test_Config_Fixture (void) \
    : log_ (LOGDIR "/" XSTR(BOOST_TEST_MODULE) ".log") { \
      using boost::unit_test::unit_test_log; \
      unit_test_log.set_stream (this->log_); \
      unit_test_log.set_threshold_level (boost::unit_test::log_successful_tests); \
      unit_test_log.set_formatter (new Boost_Junit_Log_Format ()); \
    } \
    ~Boost_Test_Config_Fixture (void) { \
      using boost::unit_test::unit_test_log; \
      unit_test_log.set_stream (std::cout); \
    } \
  private: \
    std::ofstream log_; \
  }; \
  BOOST_GLOBAL_FIXTURE (Boost_Test_Config_Fixture)

#endif  // !defined _CUTS_BOOST_JUNIT_FORMATTER_H_
