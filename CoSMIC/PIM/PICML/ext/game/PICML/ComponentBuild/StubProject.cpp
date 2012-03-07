// $Id$

#include "StdAfx.h"
#include "StubProject.h"

#if !defined (__GAME_INLINE__)
#include "StubProject.inl"
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
  const std::string StubProject_Impl::metaname ("StubProject");

  //
  // _create (const Project_in)
  //
  StubProject StubProject_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < StubProject > (parent, StubProject_Impl::metaname);
  }

  //
  // accept
  //
  void StubProject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_StubProject (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_FileRef
  //
  FileRef StubProject_Impl::get_FileRef (void) const
  {
    return this->children <FileRef> ().item ();
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference StubProject_Impl::get_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().item ();
  }
}

