// -*- C++ -*-

//=============================================================================
/**
 *  @file       copy.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_MANIP_COPY_H_
#define _GAME_MANIP_COPY_H_

#include "game/Model.h"
#include "Manipulation_export.h"

namespace GAME
{
GAME_MANIPULATION_Export
FCO copy_attributes (const FCO & src, FCO dst);

GAME_MANIPULATION_Export
void copy_location (const FCO & src, FCO dst, const std::string & aspect = "");

GAME_MANIPULATION_Export
Model copy (const Model & src, Model dst, const std::string & aspect = "");
}

#endif  // !defined _GAME_MANIP_COPY_H_
