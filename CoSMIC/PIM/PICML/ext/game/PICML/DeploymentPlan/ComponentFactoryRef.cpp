// $Id$

#include "stdafx.h"
#include "ComponentFactoryRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryRef_Impl::metaname = "ComponentFactoryRef";

  //
  // ComponentFactoryRef_Impl
  //
  ComponentFactoryRef_Impl::ComponentFactoryRef_Impl (void)
  {
  }

  //
  // ComponentFactoryRef_Impl
  //
  ComponentFactoryRef_Impl::ComponentFactoryRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryRef_Impl
  //
  ComponentFactoryRef_Impl::~ComponentFactoryRef_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentFactoryRef_Impl::accept (Visitor * v)
  {
    v->visit_ComponentFactoryRef (this);
  }

  //
  // in_Deploys_connections
  //
  size_t ComponentFactoryRef_Impl::in_Deploys_connections (std::vector <Deploys> & conns) const
  {
    return this->in_connections (conns);
  }
}

