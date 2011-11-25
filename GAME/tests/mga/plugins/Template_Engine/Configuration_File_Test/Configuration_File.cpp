// $Id$

#include "game/mga/plugins/Template_Engine/Configuration_File.h"

#define BOOST_TEST_MODULE Template_Engine_Configuration_File

#include "Test_Configuration.hpp"
DECLARE_BOOST_TEST_CONFIG ("../../../../logs");

//
// single_configuration
//
BOOST_AUTO_TEST_CASE (single_configuration)
{
  Property_Configuration_Map configs;
  BOOST_REQUIRE (Configuration_File::read ("Single_Configuration.config", configs));

  BOOST_CHECK_EQUAL (configs.size (), 1);
  BOOST_CHECK (configs.find ("Single_Configuration") != configs.end ());
}

//
// multiple_configurations
//
BOOST_AUTO_TEST_CASE (multiple_configurations)
{
  Property_Configuration_Map configs;
  BOOST_REQUIRE (Configuration_File::read ("Multiple_Configuration.config", configs));

  BOOST_CHECK_EQUAL (configs.size (), 2);
  BOOST_CHECK (configs.find ("Config1") != configs.end ());
  BOOST_CHECK (configs.find ("Config2") != configs.end ());
}
