// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Invalid_Cast
//
GAME_INLINE
Invalid_Cast::Invalid_Cast (void)
: std::runtime_error ("invalid cast")
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
: std::runtime_error ("bad attribute")
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
: std::runtime_error ("not found")
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
