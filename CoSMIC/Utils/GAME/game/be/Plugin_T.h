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

#include "Interpreter_T.h"

namespace GAME
{
/**
 * @class Plugin_T
 */
template <typename T, const CLSID * pclsid = &CLSID_NULL>
class ATL_NO_VTABLE Plugin_T :
  public Interpreter_T < T , pclsid>
{
public:
  /// Default constructor
  Plugin_T (void);

  /// Destructor
  virtual ~Plugin_T (void);
};

}

#define DECLARE_GAME_PLUGIN(type, impl) \
  typedef GAME::Plugin_T <impl, &CLSID_##type> impl##_AutoImpl; \
  OBJECT_ENTRY_AUTO (__uuidof (type), impl##_AutoImpl)

#if defined (__GAME_INLINE__)
#include "Plugin_T.inl"
#endif

#include "Plugin_T.cpp"

#endif  // !defined _GME_INTERPRETER_T_H_
