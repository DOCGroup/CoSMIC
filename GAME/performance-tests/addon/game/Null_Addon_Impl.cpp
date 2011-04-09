// $Id$

#include "StdAfx.h"
#include "Null_Addon_Impl.h"

#include "game/mga/component/Addon.h"

GAME_DEFAULT_ADDON_IMPL (Null_Addon, "GAME Null Addon", "Library", "GAME.AddOn.Null");
GAME_DECLARE_ADDON (Null_Addon, Null_Addon, GAME::Null_Addon_Sink);

namespace GAME
{

//
// Null_Addon_Sink
//
Null_Addon_Sink::Null_Addon_Sink (void)
: GAME::Mga::Event_Handler_Impl (0xFFFFFFFF, false)
{

}

//
// ~Null_Addon_Sink
//
Null_Addon_Sink::~Null_Addon_Sink (void)
{

}

}
