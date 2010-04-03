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

}
}

#if defined (__GME_INLINE__)
#include "Exceptions.inl"
#endif

#endif  // !defined _GAME_XME_ATOM_H_
