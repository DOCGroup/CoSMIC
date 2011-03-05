// -*- C++ -*-

//=============================================================================
/**
 * @file      config.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_CONFIG_H_
#define _GAME_CONFIG_H_

// Definition for inlining source code in GAME. We should move the
// GAME_INLINE definition to its own header file.
#if defined (__GAME_INLINE__)
# define GAME_INLINE inline
#else
# define GAME_INLINE
#endif

// Make sure we use the #pragma once statement correctly.
#if _MSC_VER > 1000
# pragma once
#endif

// Enforce strict type checking in Windows headers.
#if !defined (STRICT)
# define STRICT
#endif

// Exclude APIs such as Cryptography, DDE, RPC, Shell, and Windows Sockets.
#if !defined (WIN32_LEAN_AND_MEAN)
# define WIN32_LEAN_AND_MEAN
#endif

// GAME is targeting Windows XP right now. In the near future, GAME
// will be able to target other version of Windows.
#if !defined (_WIN32_WINNT)
# define _WIN32_WINNT 0x0501
#endif

#if !defined (WINVER)
# define WINVER 0x0501
#endif

#if !defined (GDIPVER)
#define GDIPVER 0x0110
#endif

#endif
