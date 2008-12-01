// -*- C++ -*-
// $Id$

namespace GME
{
namespace Meta
{
  //
  // Folder
  //
  GME_INLINE
  Folder::Folder (void)
  {

  }

  //
  // Folder
  //
  GME_INLINE
  Folder::Folder (IMgaMetaFolder * meta)
  : Base (meta)
  {

  }

  //
  // Folder
  //
  GME_INLINE
  Folder::Folder (const Folder & meta)
  : Base (meta)
  {

  }

  //
  // ~Folder
  //
  GME_INLINE
  Folder::~Folder (void)
  {

  }

  //
  // attach
  //
  GME_INLINE
  void Folder::attach (IMgaMetaFolder * meta)
  {
    Base::attach (meta);
  }

  //
  // operator IMgaMetaFolder *
  //
  GME_INLINE
  Folder::operator IMgaMetaFolder * (void) const
  {
    return this->impl ();
  }
}
}
