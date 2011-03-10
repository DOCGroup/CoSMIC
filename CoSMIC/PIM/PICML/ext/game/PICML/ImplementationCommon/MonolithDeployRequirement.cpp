// $Id$

#include "stdafx.h"
#include "MonolithDeployRequirement.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/Common/ImplementationRequirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithDeployRequirement_Impl::metaname = "MonolithDeployRequirement";

  //
  // MonolithDeployRequirement_Impl
  //
  MonolithDeployRequirement_Impl::MonolithDeployRequirement_Impl (void)
  {
  }

  //
  // MonolithDeployRequirement_Impl
  //
  MonolithDeployRequirement_Impl::MonolithDeployRequirement_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MonolithDeployRequirement_Impl
  //
  MonolithDeployRequirement_Impl::~MonolithDeployRequirement_Impl (void)
  {
  }

  //
  // accept
  //
  void MonolithDeployRequirement_Impl::accept (Visitor * v)
  {
    v->visit_MonolithDeployRequirement (this);
  }

  //
  // _create
  //
  MonolithDeployRequirement MonolithDeployRequirement_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <MonolithDeployRequirement> (parent, MonolithDeployRequirement_Impl::metaname);
  }

  //
  // src_MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithDeployRequirement_Impl::src_MonolithicImplementationBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return MonolithicImplementationBase::_narrow (target);
  }

  //
  // dst_ImplementationRequirement
  //
  ImplementationRequirement MonolithDeployRequirement_Impl::dst_ImplementationRequirement (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ImplementationRequirement::_narrow (target);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer MonolithDeployRequirement_Impl::parent_ImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ImplementationContainer> (this->object_.p);
  }
}

