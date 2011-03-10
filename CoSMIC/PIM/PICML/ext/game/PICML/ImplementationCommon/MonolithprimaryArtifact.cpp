// $Id$

#include "stdafx.h"
#include "MonolithprimaryArtifact.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithprimaryArtifact_Impl::metaname = "MonolithprimaryArtifact";

  //
  // MonolithprimaryArtifact_Impl
  //
  MonolithprimaryArtifact_Impl::MonolithprimaryArtifact_Impl (void)
  {
  }

  //
  // MonolithprimaryArtifact_Impl
  //
  MonolithprimaryArtifact_Impl::MonolithprimaryArtifact_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MonolithprimaryArtifact_Impl
  //
  MonolithprimaryArtifact_Impl::~MonolithprimaryArtifact_Impl (void)
  {
  }

  //
  // accept
  //
  void MonolithprimaryArtifact_Impl::accept (Visitor * v)
  {
    v->visit_MonolithprimaryArtifact (this);
  }

  //
  // _create
  //
  MonolithprimaryArtifact MonolithprimaryArtifact_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <MonolithprimaryArtifact> (parent, MonolithprimaryArtifact_Impl::metaname);
  }

  //
  // src_MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithprimaryArtifact_Impl::src_MonolithicImplementationBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return MonolithicImplementationBase::_narrow (target);
  }

  //
  // dst_ImplementationArtifactReference
  //
  ImplementationArtifactReference MonolithprimaryArtifact_Impl::dst_ImplementationArtifactReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ImplementationArtifactReference::_narrow (target);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer MonolithprimaryArtifact_Impl::parent_ImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ImplementationContainer> (this->object_.p);
  }
}

