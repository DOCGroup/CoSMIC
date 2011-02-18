// -*- C++ -*-

//=============================================================================
/**
 * @file        stlace.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_STLACE_H_
#define _GAME_STLACE_H_

#include <string>
#include "Mga_export.h"

#if defined (ACE_LACKS_STL_STRING_FUNCTORS)
// Forward decl.
template <typename T> class ACE_Hash;

/**
 * @class ACE_Hash <std::string>
 *
 * Specialization of the ACE_Hash for std::string objects
 */
template < >
class GAME_MGA_Export ACE_Hash <std::string>
{
public:
  unsigned long operator () (const std::string & lhs) const;
};

/**
 * @class ACE_Hash <std::wstring>
 *
 * Specialization of the ACE_Hash for std::string objects
 */
template < >
class GAME_MGA_Export ACE_Hash <std::wstring>
{
public:
  unsigned long operator () (const std::wstring & lhs) const;
};
#endif

#endif
