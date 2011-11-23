// $Id$

#include "game/mga/plugins/Template_Engine/Configuration_File.h"

//
// test_single_configuration
//
bool test_single_configuration (void)
{
  std::cerr << "*** info: begin test_single_configuration" << std::endl;

  Property_Configuration_Map single;
  Configuration_File::read ("Single_Configuration.config", single);
  Property_Configuration_Map::iterator iter = single.find ("Single_Configuration");

  if (iter == single.end ())
  {
    std::cerr << "*** error: failed to locate Single_Configuration" << std::endl;
    return false;
  }

  return true;
}

//
// test_multiple_configuration
//
bool test_multiple_configuration (void)
{
  std::cerr << "*** info: begin test_multiple_configuration" << std::endl;

  Property_Configuration_Map multiple;
  if (!Configuration_File::read ("Multiple_Configuration.config", multiple))
  {
    std::cerr << "*** error: failed to read Multiple_Configuration.config" << std::endl;
    return false;
  }

  if (multiple.size () != 2)
  {
    std::cerr
      << "*** error: expected to read 2 configurations, but read "
      << multiple.size () << " configuration(s)" << std::endl;

    return false;
  }

  Property_Configuration_Map::iterator iter = multiple.find ("Config1");

  if (iter == multiple.end ())
  {
    std::cerr << "*** error: failed to locate Config1" << std::endl;
    return false;
  }

  iter = multiple.find ("Config2");
  if (iter == multiple.end ())
  {
    std::cerr << "*** error: failed to locate Config2" << std::endl;
    return false;
  }

  return true;
}


int main (int argc, char * argv [])
{
  if (!::test_single_configuration ())
    std::cerr << "*** error: single configuration test failed" << std::endl;

  if (!::test_multiple_configuration ())
    std::cerr << "*** error: multiple configuration test failed" << std::endl;

  return 0;
}
