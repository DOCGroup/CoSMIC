// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__8B8917B1_B409_43D6_9604_73055641403B__INCLUDED_)
#define AFX_STDAFX_H__8B8917B1_B409_43D6_9604_73055641403B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
	#if _MSC_VER > 1400
		#define _WIN32_WINNT 0x0501
	#else
		#define _WIN32_WINNT 0x0400
	#endif 
#endif

#include <afxwin.h>
#include <Gdiplus.h>

#include "game/Mga.h"

#endif // !defined(AFX_STDAFX_H__8B8917B1_B409_43D6_9604_73055641403B__INCLUDED)