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

#ifndef _GME_EXCEPTION_H_
#define _GME_EXCEPTION_H_

#include "GME_export.h"
#include <atlbase.h>
#include <string>

#define VERIFY_HRESULT_THROW_EX(method, ex) \
  { \
    HRESULT hr = method; \
    if (FAILED (hr)) \
      throw ex; \
  }

#define VERIFY_HRESULT(method) \
  VERIFY_HRESULT_THROW_EX (method, GME::Failed_Result (hr))

namespace GME
{
  //===========================================================================
  /**
   * @class Exception
   *
   * Base type of all exceptions.
   */
  //===========================================================================

  class GME_Export Exception
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

  //===========================================================================
  /**
   * @class Failed_Result
   *
   * Exception thrown when a COM method does not succeed. This is
   * usually realized when the return value for the method is not
   * S_OK. The value () method can be used to determine the return
   * code for the method that caused the error.
   */
  //===========================================================================

  class GME_Export Failed_Result
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

  class GME_Export Invalid_Cast
  {
  public:
    /// Default constructor.
    Invalid_Cast (void);

    /// Destructor.
    virtual ~Invalid_Cast (void);
  };
}

#if defined (__GME_INLINE__)
#include "Exception.inl"
#endif

#endif  // !defined _GME_EXCEPTION_H_
