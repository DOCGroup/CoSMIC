// $Id$

namespace GAME
{
namespace Mga
{

//
// Attribute_Impl
//
GAME_INLINE
Attribute_Impl::Attribute_Impl (void)
{

}

//
// Attribute_Impl
//
GAME_INLINE
Attribute_Impl::Attribute_Impl (IMgaAttribute * attr)
: attr_ (attr)
{

}

//
// ~Attribute_Impl
//
GAME_INLINE
Attribute_Impl::~Attribute_Impl (void)
{

}

//
// attach
//
GAME_INLINE
void Attribute_Impl::attach (IMgaAttribute * attr)
{
  this->attr_.Attach (attr);
}

//
// impl
//
IMgaAttribute * Attribute_Impl::impl (void) const
{
  return this->attr_.p;
}

}
}
