// $Id$

#include "Exception.h"

#if !defined (__GME_INLINE__)
#include "Exception.inl"
#endif

namespace GME
{
  //
  // Exception
  //
  Exception::Exception (void)
  {

  }

  //
  // ~Exception
  //
  Exception::~Exception (void)
  {

  }

  //
  // Failed_Result
  //
  Failed_Result::Failed_Result (HRESULT value)
    : value_ (value)
  {

  }

  //
  // ~Failed_Result
  //
  Failed_Result::~Failed_Result (void)
  {

  }
}
