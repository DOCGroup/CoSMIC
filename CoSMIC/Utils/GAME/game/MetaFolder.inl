// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Meta
{
  //
  // Folder
  //
  GAME_INLINE
  Folder::Folder (void)
  {

  }

  //
  // Folder
  //
  GAME_INLINE
  Folder::Folder (IMgaMetaFolder * meta)
  : Base (meta)
  {

  }

  //
  // Folder
  //
  GAME_INLINE
  Folder::Folder (const Folder & meta)
  : Base (meta)
  {

  }

  //
  // ~Folder
  //
  GAME_INLINE
  Folder::~Folder (void)
  {

  }

  //
  // attach
  //
  GAME_INLINE
  void Folder::attach (IMgaMetaFolder * meta)
  {
    Base::attach (meta);
  }

  //
  // operator IMgaMetaFolder *
  //
  GAME_INLINE
  Folder::operator IMgaMetaFolder * (void) const
  {
    return this->impl ();
  }
}
}
