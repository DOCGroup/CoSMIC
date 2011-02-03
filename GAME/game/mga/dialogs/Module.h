// -*- C++ -*-

//=============================================================================
/**
 *  @file       Selection_List_Dialog.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_DIALOGS_MODULE_H_
#define _GAME_DIALOGS_MODULE_H_

#include "Dialogs_export.h"

namespace GAME
{
namespace Dialogs
{
/**
 * Initializing function that must be called each time this module
 * is used by a DLL. It will ensure the resources in this module
 * are available to the hosting DLL.
 */
GAME_DIALOGS_Export int initialize_module (void);

}
}

#endif  // !defined _GAME_DIALOGS_MODULE_H_
