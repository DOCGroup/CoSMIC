// $Id$

#include "functional.h"
#include "FCO.h"
#include "Registry.h"
#include <sstream>

namespace GME
{
namespace XME
{
namespace constant
{
  static const ::Utils::XStr PartRegs ("PartRegs");
  static const ::Utils::XStr Position ("Position");
}

//
// get_position
//
bool get_position (FCO & fco,
                   const ::Utils::XStr & aspect,
                   ::Utils::Point & pt)
{
  Registry_Node node =
    fco.registry ().
      child (constant::PartRegs, true).
      child (aspect, true).
      child (constant::Position, true);

  // There has to be some way to stream in the values as a
  // XMLCh instead of converting the value to a C string.
  ::Utils::XStr tempstr (node.value (), false);
  std::istringstream istr (tempstr.to_string ());

  int x_value, y_value;
  char comma;

  istr >> x_value >> comma >> y_value;
  pt.set (x_value, y_value);

  return true;
}

//
// set_position
//
void
set_position (FCO & fco, const ::Utils::XStr & aspect, const ::Utils::Point & pt)
{
  std::ostringstream ostr;
  ostr << pt.x_value () << "," << pt.y_value ();

  Registry_Node node =
    fco.registry ().
      child (constant::PartRegs, true).
      child (aspect, true).
      child (constant::Position, true);

  node.value (ostr.str ());
}

}
}
