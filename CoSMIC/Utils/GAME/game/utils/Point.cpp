// $Id$

#include "game/StdAfx.h"
#include "Point.h"
#include <sstream>

namespace GME
{
//
// position
//
bool position (const std::string & aspect, const GME::FCO & fco, Utils::Point & pt)
{
  // Get the string version of the position
  std::ostringstream regval;
  regval << "PartRegs/" << aspect << "/Position";
  std::string position = fco.registry_value (regval.str ());

  // Extract the points from the position.
  std::istringstream istr (position);

  ACE_UINT32 value;

  // Read the x-coordinate
  istr >> value;
  pt.x_value (value);

  // Skip the comma in the string.
  istr.ignore (1);

  // Read the y-coordinate
  istr >> value;
  pt.y_value (value);

  return istr.good ();
}

//
// position
//
bool position (const std::string & aspect, const Utils::Point & pt, GME::FCO & fco)
{
  // Convert the point in a position value.
  std::ostringstream position;
  position << pt.x_value () << "," << pt.y_value ();

  if (!position.good ())
    return false;

  // Set the string version of the position
  std::ostringstream regval;
  regval << "PartRegs/" << aspect << "/Position";
  fco.registry_value (regval.str (), position.str ());

  return true;
}

}
