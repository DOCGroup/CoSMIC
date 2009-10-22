// -*- C++ -*-

//=============================================================================
/**
 *  @file         Point.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _GAME_POINT_H_
#define _GAME_POINT_H_

#include "game/FCO.h"
#include "Utils/Point.h"

namespace GME
{
/**
 * Get the current position of the FCO.
 *
 * @param[in]     aspect        Aspect to retrieve position
 * @param[in]     fco           Source FCO
 * @param[out]    pt            The position of the \a fco
 * @retval        true          Succesfully retrieved position
 * @retval        false         Failed to retrieved position
 */
GME_Export
bool position (const std::string & aspect, const GME::FCO & fco, Utils::Point & pt);

/**
 * Set the current position of the FCO.
 *
 * @param[in]     aspect        Aspect to retrieve position
 * @param[out]    pt            The position of the \a fco
 * @param[in]     fco           Target FCO
 * @retval        true          Succesfully set position
 * @retval        false         Failed to set position
 */
GME_Export
bool position (const std::string & aspect, const Utils::Point & pt, GME::FCO & fco);
}

#endif  // !defined _GAME_POINT_H_
