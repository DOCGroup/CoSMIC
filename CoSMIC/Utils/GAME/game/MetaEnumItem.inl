// $Id$

namespace GME
{
namespace Meta
{
  //
  // EnumItem
  //
  GME_INLINE
  EnumItem::EnumItem (void)
  {

  }

  //
  // EnumItem
  //
  GME_INLINE
  EnumItem::EnumItem (IMgaMetaEnumItem * item)
  : enum_item_ (item)
  {

  }

  //
  // EnumItem
  //
  GME_INLINE
  EnumItem::EnumItem (const EnumItem & item)
  : enum_item_ (item.enum_item_)
  {

  }
  //
  // EnumItem
  //
  GME_INLINE
  EnumItem::~EnumItem (void)
  {

  }

  //
  // impl
  //
  GME_INLINE
  IMgaMetaEnumItem * EnumItem::impl (void) const
  {
    return this->enum_item_.p;
  }

  //
  // operator =
  //
  GME_INLINE
  const EnumItem & EnumItem::operator = (const EnumItem & item)
  {
    this->enum_item_ = item.enum_item_;
    return *this;
  }
}
}
