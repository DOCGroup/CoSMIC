// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaProject.h"

#if !defined (__GAME_INLINE__)
#include "MetaProject.inl"
#endif

#include "Exception.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

//
// root_folder
//
Folder Project::root_folder (void) const
{
  CComPtr <IMgaMetaFolder> folder;
  VERIFY_HRESULT (this->proj_->get_RootFolder (&folder));

  return folder.p;
}

}
}
}
