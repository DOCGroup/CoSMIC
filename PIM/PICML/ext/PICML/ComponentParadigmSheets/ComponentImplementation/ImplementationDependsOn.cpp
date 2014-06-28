// $Id$

#include "StdAfx.h"
#include "ImplementationDependsOn.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationDependsOn.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/Common/ImplementationDependency.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationDependsOn_Impl::metaname ("ImplementationDependsOn");

  //
  // _create (const ComponentImplementationContainer_in)
  //
  ImplementationDependsOn ImplementationDependsOn_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationDependsOn > (parent, ImplementationDependsOn_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationDependsOn_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ImplementationDependsOn (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ImplementationDependsOn_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // ComponentImplementation
  //
  ComponentImplementation ImplementationDependsOn_Impl::src_ComponentImplementation (void) const
  {
    return ComponentImplementation::_narrow (this->src ());
  }

  //
  // ImplementationDependency
  //
  ImplementationDependency ImplementationDependsOn_Impl::dst_ImplementationDependency (void) const
  {
    return ImplementationDependency::_narrow (this->dst ());
  }
}

