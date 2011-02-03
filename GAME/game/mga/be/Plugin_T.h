// -*- C++ -*-

//=============================================================================
/**
 * @class       Plugin_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_PLUGIN_T_H_
#define _GME_PLUGIN_T_H_

#include "ComponentEx_T.h"
#include "ComponentEx_Impl_T.h"

#define GAME_DECLARE_PLUGIN(type, impl) \
  typedef GAME::Mga::ComponentEx_T < GAME::Mga::ComponentEx_Impl_T <impl>, &CLSID_##type>  impl##_PluginImpl; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_PluginImpl)

#if defined (__GAME_INLINE__)
#include "Plugin_T.inl"
#endif

#include "Plugin_T.cpp"

#endif  // !defined _GME_INTERPRETER_T_H_
