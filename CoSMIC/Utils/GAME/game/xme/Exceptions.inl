// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Exception
//
GAME_INLINE
Exception::Exception (void)
{
}

//
// Exception
//
GAME_INLINE
Exception::Exception (const std::string & what)
: what_ (what)
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

//
// Bad_Attribute
//
GAME_INLINE
Bad_Attribute::Bad_Attribute (void)
: Exception ("bad attribute")
{

}

//
// Invalid_Cast
//
GAME_INLINE
Bad_Attribute::~Bad_Attribute (void)
{

}

//
// Not_Found
//
GAME_INLINE
Not_Found::Not_Found (void)
: Exception("not found")
{

}

//
// Not_Found
//
GAME_INLINE
Not_Found::~Not_Found (void)
{

}

}
}
