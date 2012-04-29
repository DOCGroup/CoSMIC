// $Id$

#include "StdAfx.h"
#include "ExecutorProject.h"

#if !defined (__GAME_INLINE__)
#include "ExecutorProject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExecutorProject_Impl::metaname ("ExecutorProject");

  //
  // _create (const Project_in)
  //
  ExecutorProject ExecutorProject_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ExecutorProject > (parent, ExecutorProject_Impl::metaname);
  }

  //
  // accept
  //
  void ExecutorProject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExecutorProject (this);
    else
      v->visit_Model (this);
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference ExecutorProject_Impl::get_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().item ();
  }
}

