// $Id$

#include "StdAfx.h"
#include "ExternalResources.h"

#if !defined (__GAME_INLINE__)
#include "ExternalResources.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/Project.h"
#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalResources_Impl::metaname ("ExternalResources");

  //
  // _create (const Project_in)
  //
  ExternalResources ExternalResources_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ExternalResources > (parent, ExternalResources_Impl::metaname);
  }

  //
  // accept
  //
  void ExternalResources_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ExternalResources (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // dst_ExtResourceConn
  //
  size_t ExternalResources_Impl::dst_ExtResourceConn (std::vector <ExtResourceConn> & items) const
  {
    return this->in_connections <ExtResourceConn> (items);
  }

  //
  // ImplementationArtifact_is_nil
  //
  bool ExternalResources_Impl::ImplementationArtifact_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ImplementationArtifact
  //
  ImplementationArtifact ExternalResources_Impl::get_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->refers_to ());
  }
}

