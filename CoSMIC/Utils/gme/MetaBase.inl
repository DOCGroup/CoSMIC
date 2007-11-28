// $Id$

namespace GME
{
namespace Meta
{
  //
  // Base
  //
  GME_INLINE
  Base::Base (void)
  {

  }

  //
  // Base
  //
  GME_INLINE
  Base::Base (IMgaMetaBase * meta)
  : metabase_ (meta)
  {

  }

  //
  // Base
  //
  GME_INLINE
  Base::Base (const Base & meta)
    : metabase_ (meta.metabase_)
  {

  }

  //
  // ~Base
  //
  GME_INLINE
  Base::~Base (void)
  {

  }

  //
  // attach
  //
  GME_INLINE
  void Base::attach (IMgaMetaBase * metabase)
  {
    this->metabase_.Attach (metabase);
  }

  //
  // operator IMgaMetaBase *
  //
  GME_INLINE
  Base::operator IMgaMetaBase * (void) const
  {
    return this->metabase_.p;
  }

  //
  // operator ==
  //
  GME_INLINE
  bool Base::operator == (const std::string & name) const
  {
    return this->name () == name;
  }

  //
  // operator ==
  //
  GME_INLINE
  bool Base::operator == (const Base & meta) const
  {
    return this->metabase_ == meta.metabase_;
  }

  //
  // impl
  //
  GME_INLINE
  IMgaMetaBase * Base::impl (void) const
  {
    return this->metabase_;
  }

  //
  // operator bool
  //
  GME_INLINE
  Base::operator bool (void) const
  {
    return this->metabase_.p != 0;
  }
}
}
