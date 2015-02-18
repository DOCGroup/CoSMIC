// $Id$

#include "StdAfx.h"
#include "ImplementationDependency.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationDependency.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationDependency_Impl::metaname ("ImplementationDependency");

  //
  // is_abstract
  //
  const bool ImplementationDependency_Impl::is_abstract = false;

  //
  // _create (const ComponentImplementationContainer_in)
  //
  ImplementationDependency ImplementationDependency_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < ImplementationDependency > (parent, ImplementationDependency_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationDependency_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ImplementationDependency (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ImplementationDependency_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // dst_of_ImplementationDependsOn
  //
  size_t ImplementationDependency_Impl::dst_of_ImplementationDependsOn (std::vector <ImplementationDependsOn> & items) const
  {
    return this->in_connections <ImplementationDependsOn> (items);
  }

  //
  // dst_of_ImplementationDependsOn
  //
  GAME::Mga::Collection_T <ImplementationDependsOn> ImplementationDependency_Impl::dst_of_ImplementationDependsOn (void) const
  {
    return this->in_connections <ImplementationDependsOn> ("dst");
  }
}

