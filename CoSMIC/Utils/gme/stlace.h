// -*- C++ -*-

//=============================================================================
/**
 * @file        stlace.h
 *
 * Template specializations for enabling STL to work with ACE
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _STLACE_H_
#define _STLACE_H_

#include <string>
#include "GME_export.h"

// Forward decl.
template <typename T>
class ACE_Hash;

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
class GME_Export ACE_Hash <std::string>
{
public:
  unsigned long operator () (const std::string & lhs) const;
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
class GME_Export ACE_Hash <std::wstring>
{
public:
  unsigned long operator () (const std::wstring & lhs) const;
};

#endif
