// $Id$

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// EnumItem
//
GAME_INLINE
EnumItem::EnumItem (void)
{

}

//
// EnumItem
//
GAME_INLINE
EnumItem::EnumItem (IMgaMetaEnumItem * item)
: enum_item_ (item)
{

}

//
// EnumItem
//
GAME_INLINE
EnumItem::EnumItem (const EnumItem & item)
: enum_item_ (item.enum_item_)
{

}
//
// EnumItem
//
GAME_INLINE
EnumItem::~EnumItem (void)
{

}

//
// impl
//
GAME_INLINE
IMgaMetaEnumItem * EnumItem::impl (void) const
{
  return this->enum_item_.p;
}

//
// operator =
//
GAME_INLINE
const EnumItem & EnumItem::operator = (const EnumItem & item)
{
  this->enum_item_ = item.enum_item_;
  return *this;
}

}
}
}
