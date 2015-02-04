// $Id$

#include "StdAfx.h"
#include "Implements.h"

#if !defined (__GAME_INLINE__)
#include "Implements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Implements_Impl::metaname ("Implements");

  //
  // is_abstract
  //
  const bool Implements_Impl::is_abstract = false;

  //
  // _create (const ComponentImplementationContainer_in, ComponentImplementation_in src, ComponentRef_in dst)
  //
  Implements Implements_Impl::_create (const ComponentImplementationContainer_in parent, ComponentImplementation_in src, ComponentRef_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Implements_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Implements_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Implements (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer Implements_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // ComponentImplementation
  //
  ComponentImplementation Implements_Impl::src_ComponentImplementation (void) const
  {
    return ComponentImplementation::_narrow (this->src ());
  }

  //
  // ComponentRef
  //
  ComponentRef Implements_Impl::dst_ComponentRef (void) const
  {
    return ComponentRef::_narrow (this->dst ());
  }
}

