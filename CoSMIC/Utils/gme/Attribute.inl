// $Id$

namespace GME
{
  //
  // Attribute
  //
  GME_INLINE
  Attribute::Attribute (void)
  {

  }

  //
  // Attribute
  //
  GME_INLINE
  Attribute::Attribute (IMgaAttribute * attr)
  : attr_ (attr)
  {

  }

  //
  // Attribute
  //
  GME_INLINE
  Attribute::Attribute (const Attribute & attr)
  : attr_ (attr.attr_)
  {

  }

  //
  // ~Attribute
  //
  GME_INLINE
  Attribute::~Attribute (void)
  {

  }

  //
  // attach
  //
  GME_INLINE
  void Attribute::attach (IMgaAttribute * attr)
  {
    this->attr_.Attach (attr);
  }

  //
  // operator =
  //
  GME_INLINE
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
