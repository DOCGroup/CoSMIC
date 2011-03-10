// $Id$

#include "stdafx.h"
#include "ComponentInstanceRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/Deploys.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstanceRef_Impl::metaname = "ComponentInstanceRef";

  //
  // ComponentInstanceRef_Impl
  //
  ComponentInstanceRef_Impl::ComponentInstanceRef_Impl (void)
  {
  }

  //
  // ComponentInstanceRef_Impl
  //
  ComponentInstanceRef_Impl::ComponentInstanceRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInstanceRef_Impl
  //
  ComponentInstanceRef_Impl::~ComponentInstanceRef_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentInstanceRef_Impl::accept (Visitor * v)
  {
    v->visit_ComponentInstanceRef (this);
  }

  //
  // in_Deploys_connections
  //
  size_t ComponentInstanceRef_Impl::in_Deploys_connections (std::vector <Deploys> & conns) const
  {
    return this->in_connections (conns);
  }
}

