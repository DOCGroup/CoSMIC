#include "StdAfx.h"
#include "ImplementationDependsOn.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationDependsOn.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/Common/ImplementationDependency.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
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
  // is_abstract
  //
  const bool ImplementationDependsOn_Impl::is_abstract = false;

  //
  // _create (const ComponentImplementationContainer_in, ComponentImplementation_in src, ImplementationDependency_in dst)
  //
  ImplementationDependsOn ImplementationDependsOn_Impl::_create (const ComponentImplementationContainer_in parent, ComponentImplementation_in src, ImplementationDependency_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ImplementationDependsOn_Impl::metaname, src, dst);
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

