// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // MetaFolder
  //
  GME_INLINE
  MetaFolder::MetaFolder (void)
  {

  }

  //
  // MetaFolder
  //
  GME_INLINE
  MetaFolder::MetaFolder (IMgaMetaFolder * meta)
  : MetaBase (meta)
  {

  }

  //
  // MetaFolder
  //
  GME_INLINE
  MetaFolder::MetaFolder (const MetaFolder & meta)
  : MetaBase (meta)
  {

  }

  //
  // ~MetaFolder
  //
  GME_INLINE
  MetaFolder::~MetaFolder (void)
  {

  }

  //
  // attach
  //
  GME_INLINE
  void MetaFolder::attach (IMgaMetaFolder * meta)
  {
    MetaBase::attach (meta);
  }

  //
  // operator IMgaMetaFolder *
  //
  GME_INLINE
  MetaFolder::operator IMgaMetaFolder * (void) const
  {
    return this->impl ();
  }
}
