// -*- C++ -*-

//=============================================================================
/**
 * @file    Exception.h
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_EXCEPTION_H_
#define _GAME_MGA_EXCEPTION_H_

#include <string>

#include "game/config.h"

#include "Mga_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Exception
 *
 * Base type of all exceptions.
 */
class GAME_MGA_Export Exception
{
public:
  /**
   * Constructor.
   *
   * @param[in]     error       The error code.
   */
  Exception (void);

  /**
   * Construct an exception with a message.
   *
   * @param[in]     msg         Exception message
   */
  Exception (const char * msg, const char * file = "", size_t line = 0);

  /// Destructor.
  virtual ~Exception (void);

  /// Get the exception message.
  const std::string & message (void) const;

protected:
  /// Exception specific message
  std::string msg_;

  std::string file_;

  size_t line_;
};

/**
 * @class Failed_Result
 *
 * Exception thrown when a COM method does not succeed. This is
 * usually realized when the return value for the method is not
 * S_OK. The value () method can be used to determine the return
 * code for the method that caused the error.
 */
class GAME_MGA_Export Failed_Result : public Exception
{
public:
  /**
   * Constructor. This is the only version of the constructor since
   * this exception is only valid when ther is a HRESULT value.
   * Otherwise, one of the other exceptions should be used.
   *
   * @param[in]     value     Value of the erro code.
   */
  Failed_Result (HRESULT value, const char * file = "", size_t line = 0);

  /// Destructor.
  virtual ~Failed_Result (void);

  /**
   * Get the error code.
   *
   * @return      Readonly version of the error code.
   */
  const HRESULT & value (void) const;

private:
  /// The resulting error code.
  const HRESULT value_;
};

/**
 * @class Invalid_Cast
 *
 * Exception thrown when casting between different model element
 * types fails.
 */
class GAME_MGA_Export Invalid_Cast : public Exception
{
public:
  /// Default constructor.
  Invalid_Cast (void);

  /// Destructor.
  virtual ~Invalid_Cast (void);
};

}
}

/// Macro for throwing an exception if the operation fails.
#define VERIFY_HRESULT(method) \
  { \
    HRESULT hr = method; \
    if (FAILED (hr)) \
      throw ::GAME::Mga::Failed_Result (hr, __FILE__, __LINE__); \
  }

#if defined (__GAME_INLINE__)
#include "Exception.inl"
#endif

#endif  // !defined _GAME_EXCEPTION_H_
