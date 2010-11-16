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

namespace GAME
{
namespace XME
{
/**
 * @class Exception
 *
 * Base class for all exceptions.
 */
class GAME_XME_Export Exception
{
public:
  /// Default constructor.
  Exception (void);
 
  Exception (const std::string & what);

  /// Destructor
  virtual ~Exception (void);

private:
  /// The exception string.
  std::string what_;
};

/**
 * @class Invalid_Cast
 *
 * The cast operation failed.
 */
class GAME_XME_Export Invalid_Cast : public Exception
{
public:
  /// Default constructor
  Invalid_Cast (void);

  /// Destructor
  virtual ~Invalid_Cast (void);
};

/**
 * @class Not_Found
 *
 * The cast operation failed.
 */
class GAME_XME_Export Bad_Attribute : public Exception
{
public:
  /// Default constructor
  Bad_Attribute (void);

  /// Destructor
  virtual ~Bad_Attribute (void);
};

/**
 * @class Not_Found
 *
 * The cast operation failed.
 */
class GAME_XME_Export Not_Found : public Exception
{
public:
  /// Default constructor
  Not_Found (void);

  /// Destructor
  virtual ~Not_Found (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Exceptions.inl"
#endif

#endif  // !defined _GAME_XME_ATOM_H_
