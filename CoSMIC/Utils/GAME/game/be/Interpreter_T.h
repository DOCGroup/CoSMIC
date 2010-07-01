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

#ifndef _GME_INTERPRETER_T_H_
#define _GME_INTERPRETER_T_H_

#include "ComponentEx_T.h"
#include "ComponentEx_Impl_Base.h"

namespace GAME
{

};

}

#define DECLARE_GAME_INTERPRETER(type, impl) \
  typedef GAME::Interpreter_T <impl, &CLSID_##type> impl##_AutoImpl; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_AutoImpl)

#if defined (__GAME_INLINE__)
#include "Interpreter_T.inl"
#endif

#include "Interpreter_T.cpp"

#endif  // !defined _GME_INTERPRETER_T_H_
