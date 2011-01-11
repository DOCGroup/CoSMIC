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

#ifndef _GAME_EXCEPTION_H_
#define _GAME_EXCEPTION_H_

#include "GAME_export.h"
#include "game/config.h"
#include <atlbase.h>
#include <string>

/// Macro for throwing an exception if the operation fails.
#define VERIFY_HRESULT_THROW_EX(method, ex) \
  { \
    HRESULT hr = method; \
    if (FAILED (hr)) \
      throw ex; \
  }

/// Macro for verifying that a operation succeeded. If the operation
/// fails then GAME::Failed_Result exception is thrown.
#define VERIFY_HRESULT(method) \
  VERIFY_HRESULT_THROW_EX (method, GAME::Failed_Result (hr))

namespace GAME
{
/**
 * @class Exception
 *
 * Base type of all exceptions.
 */
class GAME_Export Exception
{
public:
  /**
   * Constructor.
   *
   * @param[in]     error       The error code.
   */
  Exception (void);

  /// Destructor.
  virtual ~Exception (void);
};

/**
 * @class Failed_Result
 *
 * Exception thrown when a COM method does not succeed. This is
 * usually realized when the return value for the method is not
 * S_OK. The value () method can be used to determine the return
 * code for the method that caused the error.
 */
class GAME_Export Failed_Result : public Exception
{
public:
  /**
   * Constructor. This is the only version of the constructor since
   * this exception is only valid when ther is a HRESULT value.
   * Otherwise, one of the other exceptions should be used.
   *
   * @param[in]     value     Value of the erro code.
   */
  Failed_Result (HRESULT value);

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
 */
class GAME_Export Invalid_Cast : public Exception
{
public:
  /// Default constructor.
  Invalid_Cast (void);

  /// Destructor.
  virtual ~Invalid_Cast (void);
};
}

#if defined (__GAME_INLINE__)
#include "Exception.inl"
#endif

#endif  // !defined _GAME_EXCEPTION_H_
