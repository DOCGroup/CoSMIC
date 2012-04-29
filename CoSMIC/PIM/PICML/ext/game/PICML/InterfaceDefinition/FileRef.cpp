// $Id$

#include "StdAfx.h"
#include "FileRef.h"

#if !defined (__GAME_INLINE__)
#include "FileRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/StubProject.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string FileRef_Impl::metaname ("FileRef");

  //
  // _create (const StubProject_in)
  //
  FileRef FileRef_Impl::_create (const StubProject_in parent)
  {
    return ::GAME::Mga::create_object < FileRef > (parent, FileRef_Impl::metaname);
  }

  //
  // _create (const ServantProject_in)
  //
  FileRef FileRef_Impl::_create (const ServantProject_in parent)
  {
    return ::GAME::Mga::create_object < FileRef > (parent, FileRef_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  FileRef FileRef_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < FileRef > (parent, FileRef_Impl::metaname);
  }

  //
  // accept
  //
  void FileRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_FileRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // File_is_nil
  //
  bool FileRef_Impl::File_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_File
  //
  File FileRef_Impl::get_File (void) const
  {
    return File::_narrow (this->refers_to ());
  }
}

