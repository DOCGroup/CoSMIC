#include "StdAfx.h"
#include "MonolithprimaryArtifact.h"

#if !defined (__GAME_INLINE__)
#include "MonolithprimaryArtifact.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithprimaryArtifact_Impl::metaname ("MonolithprimaryArtifact");

  //
  // is_abstract
  //
  const bool MonolithprimaryArtifact_Impl::is_abstract = false;

  //
  // _create (const ImplementationContainer_in, MonolithicImplementationBase_in src, ImplementationArtifactReference_in dst)
  //
  MonolithprimaryArtifact MonolithprimaryArtifact_Impl::_create (const ImplementationContainer_in parent, MonolithicImplementationBase_in src, ImplementationArtifactReference_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, MonolithprimaryArtifact_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void MonolithprimaryArtifact_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MonolithprimaryArtifact (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer MonolithprimaryArtifact_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithprimaryArtifact_Impl::src_MonolithicImplementationBase (void) const
  {
    return MonolithicImplementationBase::_narrow (this->src ());
  }

  //
  // ImplementationArtifactReference
  //
  ImplementationArtifactReference MonolithprimaryArtifact_Impl::dst_ImplementationArtifactReference (void) const
  {
    return ImplementationArtifactReference::_narrow (this->dst ());
  }
}

