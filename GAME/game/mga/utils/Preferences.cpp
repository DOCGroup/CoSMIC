// $Id$

#include "stdafx.h"
#include "Preferences.h"

#if !defined (__GAME_INLINE__)
#include "Preferences.inl"
#endif

#include "game/mga/MetaFCO.h"

namespace GAME
{
namespace Mga
{

//
// icon_name
//
std::string Preferences::icon_name (const FCO_in fco)
{
  static const std::string icon ("icon");
  return fco->registry_value (icon);
}

//
// icon_name
//
std::string Preferences::icon_name (const Meta::FCO_in fco)
{
  static const std::string icon ("icon");
  return fco->registry_value (icon);
}

//
// is_name_enabled
//
bool Preferences::is_name_enabled (const FCO_in fco)
{
  static const std::string isNameEnabled ("isNameEnabled");
  const std::string val = fco->registry_value (isNameEnabled);

  return !val.empty () && val == "true";
}

}
}
