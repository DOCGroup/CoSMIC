// $Id$

#include "StdAfx.h"
#include "ServantProject.h"

#if !defined (__GAME_INLINE__)
#include "ServantProject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ServantProject_Impl::metaname ("ServantProject");

  //
  // _create (const Project_in)
  //
  ServantProject ServantProject_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ServantProject > (parent, ServantProject_Impl::metaname);
  }

  //
  // accept
  //
  void ServantProject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ServantProject (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference ServantProject_Impl::get_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().item ();
  }

  //
  // has_FileRef
  //
  bool ServantProject_Impl::has_FileRef (void) const
  {
    return this->children <FileRef> ().count () == 1;
  }

  //
  // get_FileRef
  //
  FileRef ServantProject_Impl::get_FileRef (void) const
  {
    return this->children <FileRef> ().item ();
  }
}

