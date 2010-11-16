// $Id$

namespace GAME
{
  //
  // Attribute
  //
  GAME_INLINE
  Attribute::Attribute (void)
  {

  }

  //
  // Attribute
  //
  GAME_INLINE
  Attribute::Attribute (IMgaAttribute * attr)
  : attr_ (attr)
  {

  }

  //
  // Attribute
  //
  GAME_INLINE
  Attribute::Attribute (const Attribute & attr)
  : attr_ (attr.attr_)
  {

  }

  //
  // ~Attribute
  //
  GAME_INLINE
  Attribute::~Attribute (void)
  {

  }

  //
  // attach
  //
  GAME_INLINE
  void Attribute::attach (IMgaAttribute * attr)
  {
    this->attr_.Attach (attr);
  }

  //
  // operator =
  //
  GAME_INLINE
  const Attribute & Attribute::operator = (const Attribute & attr)
  {
    this->attr_ = attr.attr_;
    return *this;
  }

  //
  // impl
  //
  IMgaAttribute * Attribute::impl (void)
  {
    return this->attr_.p;
  }
}
