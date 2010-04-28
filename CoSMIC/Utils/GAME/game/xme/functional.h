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
#include "Utils/xercesc/XercesString.h"
#include "Utils/Point.h"
#include "XME_export.h"

namespace GME
{
namespace XME
{
// Forward decl.
class FCO;

GAME_XME_Export
bool get_position (FCO & fco,
                   const ::Utils::XStr & aspect,
                   ::Utils::Point & pt);

GAME_XME_Export
void set_position (FCO & fco,
                   const ::Utils::XStr & name,
                   const ::Utils::Point & pt);

}
}

#endif  // !defined _GAME_XME_OBJECT_H_
