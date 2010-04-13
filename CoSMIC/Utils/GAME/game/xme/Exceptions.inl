// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// Invalid_Cast
//
GME_INLINE
Invalid_Cast::Invalid_Cast (void)
: std::runtime_error ("invalid cast")
{

}

//
// Invalid_Cast
//
GME_INLINE
Invalid_Cast::~Invalid_Cast (void)
{

}

//
// Bad_Attribute
//
GME_INLINE
Bad_Attribute::Bad_Attribute (void)
: std::runtime_error ("bad attribute")
{

}

//
// Invalid_Cast
//
GME_INLINE
Bad_Attribute::~Bad_Attribute (void)
{

}

}
}
