// -*- C++ -*-

//=============================================================================
/**
 * @file        stdafx.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _STDAFX_H_
#define _STDAFX_H_

#define STRICT
#ifndef _WIN32_WINNT
  #if _MSC_VER > 1400
    #define _WIN32_WINNT 0x0500
  #else
    #define _WIN32_WINNT 0x0400
  #endif
#endif

#include <afxwin.h>
#include <afxdisp.h>

#include <atlcomcli.h>

#include "game/Mga.h"

#endif  // !defined _STDAFX_H_
