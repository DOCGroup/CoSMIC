// -*- C++ -*-

//=============================================================================
/**
 *  @file     Interpreter_T
 *
 *  $Id$
 *
 *  @author   James H. Hill
 */
//=============================================================================

#ifndef _GAME_INTERPRETER_T_H_
#define _GAME_INTERPRETER_T_H_

#include "ComponentEx_T.h"
#include "ComponentEx_Impl_T.h"

#define GAME_DECLARE_INTERPRETER(type, impl) \
  typedef GAME::Mga::ComponentEx_T < GAME::Mga::ComponentEx_Impl_T <impl> , &CLSID_##type> impl##_Interpreter; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_Interpreter)

#endif  // !defined _GAME_INTERPRETER_T_H_
