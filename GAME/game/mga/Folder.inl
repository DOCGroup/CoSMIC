// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Folder_Impl
//
GAME_INLINE
Folder_Impl::Folder_Impl (void)
{

}

//
// Folder_Impl
//
GAME_INLINE
Folder_Impl::Folder_Impl (IMgaFolder * folder)
//: Object_Impl (folder)
{
  this->object_ = folder;
}

//
// Folder_Impl
//
GAME_INLINE
Folder_Impl::~Folder_Impl (void)
{

}

}
}
