// $Id$

#include "StdAfx.h"
#include "MonolithDeployRequirement.h"

#if !defined (__GAME_INLINE__)
#include "MonolithDeployRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithDeployRequirement_Impl::metaname ("MonolithDeployRequirement");

  //
  // is_abstract
  //
  const bool MonolithDeployRequirement_Impl::is_abstract (0);

  //
  // _create (const ImplementationContainer_in, MonolithicImplementationBase_in src, ImplementationRequirement_in dst)
  //
  MonolithDeployRequirement MonolithDeployRequirement_Impl::_create (const ImplementationContainer_in parent, MonolithicImplementationBase_in src, ImplementationRequirement_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, MonolithDeployRequirement_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void MonolithDeployRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MonolithDeployRequirement (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer MonolithDeployRequirement_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithDeployRequirement_Impl::src_MonolithicImplementationBase (void) const
  {
    return MonolithicImplementationBase::_narrow (this->src ());
  }

  //
  // ImplementationRequirement
  //
  ImplementationRequirement MonolithDeployRequirement_Impl::dst_ImplementationRequirement (void) const
  {
    return ImplementationRequirement::_narrow (this->dst ());
  }
}

