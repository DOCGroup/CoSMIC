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
#include "ace/Functor_T.h"
#include "ace/ACE.h"
#include "GME_export.h"

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

#if defined (__GME_INLINE__)
#include "stlace.inl"
#endif

#endif
