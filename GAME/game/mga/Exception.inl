// $Id$

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// class Exception

//
// Exception
//
GAME_INLINE
Exception::Exception (void)
: msg_ ("unknown exception"),
  line_ (0)
{

}

//
// Exception
//
GAME_INLINE
Exception::Exception (const char * msg, const char * file, size_t line)
: msg_ (msg),
  file_ (file),
  line_ (line)
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
// message
//
GAME_INLINE
const std::string & Exception::message (void) const
{
  return this->msg_;
}

///////////////////////////////////////////////////////////////////////////////
// class Failed_Result

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
: Exception ("invalid cast")
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
}
