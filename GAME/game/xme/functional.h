// -*- C++ -*-

//=============================================================================
/**
 * @file      functional.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_FUNCTIONAL_H_
#define _GAME_XME_FUNCTIONAL_H_

#include <string>
#include <vector>
#include "XME_export.h"

namespace GAME
{
namespace Xml
{
// Forward decl.
class String;
}
}

namespace GAME
{
namespace XME
{
// Forward decl.
class FCO;

GAME_XME_Export
bool get_position (FCO fco,
                   const GAME::Xml::String & aspect,
                   size_t & x,
                   size_t & y);

GAME_XME_Export
void set_position (FCO fco,
                   const GAME::Xml::String & aspect,
                   size_t x,
                   size_t y);

GAME_XME_Export
bool is_in_aspect (FCO fco,
                   const GAME::Xml::String & aspect);

}
}

#endif  // !defined _GAME_XME_OBJECT_H_
