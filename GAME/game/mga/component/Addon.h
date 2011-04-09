// -*- C++ -*-

//=============================================================================
/**
 *  @file     Addon.h
 *
 *  $Id$
 *
 *  @author   James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_ADDON_H_
#define _GAME_MGA_ADDON_H_

#include "ComponentEx_T.h"
#include "Addon_Impl_T.h"

#define GAME_DECLARE_ADDON(type, impl, sink) \
  typedef GAME::Mga::ComponentEx_T < GAME::Mga::Addon_Impl_T <impl, sink> , &CLSID_##type> impl##_Interpreter; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_Interpreter)

#endif  // !defined _GAME_INTERPRETER_T_H_
