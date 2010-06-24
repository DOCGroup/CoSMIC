// $Id$

#include "functional.h"
#include "FCO.h"
#include "Registry.h"
#include "Utils/xercesc/XercesString.h"
#include <sstream>

namespace GAME
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
                   size_t & x,
                   size_t & y)
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

  char comma;
  istr >> x >> comma >> y;

  return true;
}

//
// set_position
//
void
set_position (FCO & fco, const ::Utils::XStr & aspect, size_t x, size_t y)
{
  std::ostringstream ostr;
  ostr << x << "," << y;

  Registry_Node node =
    fco.registry ().
      child (constant::PartRegs, true).
      child (aspect, true).
      child (constant::Position, true);

  node.value (ostr.str ());
}

}
}
