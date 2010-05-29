// $Id$

namespace GAME
{
  //
  // Exception
  //
  GAME_INLINE
  Exception::Exception (void)
  {

  }

  //
  // ~Exception
  //
  GAME_INLINE
  Exception::~Exception (void)
  {

  }

  //
  // Failed_Result
  //
  GAME_INLINE
  Failed_Result::Failed_Result (HRESULT value)
    : value_ (value)
  {

  }

  //
  // ~Failed_Result
  //
  GAME_INLINE
  Failed_Result::~Failed_Result (void)
  {

  }

  //
  // error
  //
  GAME_INLINE
  const HRESULT & Failed_Result::value (void) const
  {
    return this->value_;
  }

  //
  // Invalid_Cast
  //
  GAME_INLINE
  Invalid_Cast::Invalid_Cast (void)
  {

  }

  //
  // Invalid_Cast
  //
  GAME_INLINE
  Invalid_Cast::~Invalid_Cast (void)
  {

  }
}
