// $Id$

#include "stdafx.h"
#include "Exception.h"

#if !defined (__GAME_INLINE__)
#include "Exception.inl"
#endif

#include "Errors.h"

namespace GAME
{
namespace Mga
{

//
// Failed_Result
//
Failed_Result::Failed_Result (HRESULT value)
: value_ (value)
{
  ERRORS::instance ()->lookup (value, this->msg_);
}

}
}
