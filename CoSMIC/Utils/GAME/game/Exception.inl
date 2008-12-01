// $Id$

namespace GME
{
  //
  // Exception
  //
  GME_INLINE
  Exception::Exception (void)
  {

  }

  //
  // ~Exception
  //
  GME_INLINE
  Exception::~Exception (void)
  {

  }

  //
  // Failed_Result
  //
  GME_INLINE
  Failed_Result::Failed_Result (HRESULT value)
    : value_ (value)
  {

  }

  //
  // ~Failed_Result
  //
  GME_INLINE
  Failed_Result::~Failed_Result (void)
  {

  }

  //
  // error
  //
  GME_INLINE
  const HRESULT & Failed_Result::value (void) const
  {
    return this->value_;
  }

  //
  // Invalid_Cast
  //
  GME_INLINE
  Invalid_Cast::Invalid_Cast (void)
  {

  }

  //
  // Invalid_Cast
  //
  GME_INLINE
  Invalid_Cast::~Invalid_Cast (void)
  {

  }
}
