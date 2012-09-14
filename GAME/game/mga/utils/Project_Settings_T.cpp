// $Id$

#include <sstream>

namespace GAME
{
namespace Mga
{

//
// get_value
//
template <typename T>
bool Project_Settings::get_value (const std::string & name, T & value)
{
  std::string str_value;
  if (!this->get_value (name, str_value))
    return false;

  std::istringstream istr (str_value);
  istr >> value;
  return !istr.fail ();
}

//
// set_value
//
template <typename T>
bool Project_Settings::set_value (const std::string & name, T value)
{
  std::ostringstream ostr;
  ostr << value;

  return this->set_value (name, ostr.str ());
}

}
}
