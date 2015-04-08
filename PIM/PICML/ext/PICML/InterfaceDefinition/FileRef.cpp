#include "StdAfx.h"
#include "FileRef.h"

#if !defined (__GAME_INLINE__)
#include "FileRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/ComponentBuild/StubProject.h"
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
  // is_abstract
  //
  const bool FileRef_Impl::is_abstract = false;

  //
  // _create (const File_in)
  //
  FileRef FileRef_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < FileRef > (parent, FileRef_Impl::metaname);
  }

  //
  // _create (const ServantProject_in)
  //
  FileRef FileRef_Impl::_create (const ServantProject_in parent)
  {
    return ::GAME::Mga::create < FileRef > (parent, FileRef_Impl::metaname);
  }

  //
  // _create (const StubProject_in)
  //
  FileRef FileRef_Impl::_create (const StubProject_in parent)
  {
    return ::GAME::Mga::create < FileRef > (parent, FileRef_Impl::metaname);
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
  // parent_File
  //
  File FileRef_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
  }

  //
  // parent_ServantProject
  //
  ServantProject FileRef_Impl::parent_ServantProject (void)
  {
    return ServantProject::_narrow (this->parent ());
  }

  //
  // parent_StubProject
  //
  StubProject FileRef_Impl::parent_StubProject (void)
  {
    return StubProject::_narrow (this->parent ());
  }

  //
  // File_is_nil
  //
  bool FileRef_Impl::File_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_File
  //
  void FileRef_Impl::refers_to_File (File_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_File
  //
  File FileRef_Impl::refers_to_File (void) const
  {
    return File::_narrow (this->refers_to ());
  }
}

