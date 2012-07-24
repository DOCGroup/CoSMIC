// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__C4EFDDFC_C095_4509_B571_632F0986D162__INCLUDED_)
#define AFX_STDAFX_H__C4EFDDFC_C095_4509_B571_632F0986D162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
  #if _MSC_VER > 1400
    #define _WIN32_WINNT 0x0500
  #else
    #define _WIN32_WINNT 0x0400
  #endif
#endif
#define _ATL_APARTMENT_THREADED

#include <afxwin.h>
#include <afxdisp.h>
#include <atlbase.h>

#include <atlcom.h>
#include <atlcoll.h>

#include "Model_Intelligence.h"

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C4EFDDFC_C095_4509_B571_632F0986D162__INCLUDED)
