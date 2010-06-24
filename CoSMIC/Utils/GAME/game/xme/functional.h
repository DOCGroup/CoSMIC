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

namespace Utils
{
class XStr;
}

namespace GAME
{
namespace XME
{
// Forward decl.
class FCO;

GAME_XME_Export
bool get_position (FCO & fco,
                   const ::Utils::XStr & aspect,
                   size_t & x,
                   size_t & y);

GAME_XME_Export
void set_position (FCO & fco,
                   const ::Utils::XStr & name,
                   size_t x,
                   size_t y);

}
}

#endif  // !defined _GAME_XME_OBJECT_H_
