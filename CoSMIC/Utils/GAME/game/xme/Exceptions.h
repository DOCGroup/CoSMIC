// -*- C++ -*-

//=============================================================================
/**
 * @file      Exceptions.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_EXCEPTIONS_H_
#define _GAME_XME_EXCEPTIONS_H_

#include <stdexcept>
#include "XME_export.h"

namespace GME
{
namespace XME
{
/**
 * @class Invalid_Cast
 *
 * The cast operation failed.
 */
  class GAME_XME_Export Invalid_Cast : public std::runtime_error
{
public:
  /// Default constructor
  Invalid_Cast (void);

  /// Destructor
  ~Invalid_Cast (void);
};

/**
 * @class Not_Found
 *
 * The cast operation failed.
 */
class GAME_XME_Export Bad_Attribute : public std::runtime_error
{
public:
  /// Default constructor
  Bad_Attribute (void);

  /// Destructor
  ~Bad_Attribute (void);
};

/**
 * @class Not_Found
 *
 * The cast operation failed.
 */
class GAME_XME_Export Not_Found : public std::runtime_error
{
public:
  /// Default constructor
  Not_Found (void);

  /// Destructor
  ~Not_Found (void);
};

}
}

#if defined (__GME_INLINE__)
#include "Exceptions.inl"
#endif

#endif  // !defined _GAME_XME_ATOM_H_
