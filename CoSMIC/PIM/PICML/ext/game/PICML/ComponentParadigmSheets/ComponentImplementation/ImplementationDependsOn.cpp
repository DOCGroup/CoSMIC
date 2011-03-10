// $Id$

#include "stdafx.h"
#include "ImplementationDependsOn.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/Common/ImplementationDependency.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationDependsOn_Impl::metaname = "ImplementationDependsOn";

  //
  // ImplementationDependsOn_Impl
  //
  ImplementationDependsOn_Impl::ImplementationDependsOn_Impl (void)
  {
  }

  //
  // ImplementationDependsOn_Impl
  //
  ImplementationDependsOn_Impl::ImplementationDependsOn_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationDependsOn_Impl
  //
  ImplementationDependsOn_Impl::~ImplementationDependsOn_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationDependsOn_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationDependsOn (this);
  }

  //
  // _create
  //
  ImplementationDependsOn ImplementationDependsOn_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ImplementationDependsOn> (parent, ImplementationDependsOn_Impl::metaname);
  }

  //
  // src_ComponentImplementation
  //
  ComponentImplementation ImplementationDependsOn_Impl::src_ComponentImplementation (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentImplementation::_narrow (target);
  }

  //
  // dst_ImplementationDependency
  //
  ImplementationDependency ImplementationDependsOn_Impl::dst_ImplementationDependency (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ImplementationDependency::_narrow (target);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ImplementationDependsOn_Impl::parent_ComponentImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentImplementationContainer> (this->object_.p);
  }
}

