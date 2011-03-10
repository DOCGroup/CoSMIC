// $Id$

#include "stdafx.h"
#include "FileRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string FileRef_Impl::metaname = "FileRef";

  //
  // FileRef_Impl
  //
  FileRef_Impl::FileRef_Impl (void)
  {
  }

  //
  // FileRef_Impl
  //
  FileRef_Impl::FileRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FileRef_Impl
  //
  FileRef_Impl::~FileRef_Impl (void)
  {
  }

  //
  // accept
  //
  void FileRef_Impl::accept (Visitor * v)
  {
    v->visit_FileRef (this);
  }

  //
  // _create
  //
  FileRef FileRef_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object <FileRef> (parent, FileRef_Impl::metaname);
  }

  //
  // parent_File
  //
  File FileRef_Impl::parent_File (void) const
  {
    return ::GAME::Mga::get_parent <File> (this->object_.p);
  }

  //
  // refers_to_File
  //
  File FileRef_Impl::refers_to_File (void) const
  {
    return ::GAME::Mga::get_refers_to <File> (this);
  }
}

