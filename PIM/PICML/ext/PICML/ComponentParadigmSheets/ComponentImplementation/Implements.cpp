// $Id$

#include "StdAfx.h"
#include "Implements.h"

#if !defined (__GAME_INLINE__)
#include "Implements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
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
  // _create (const ComponentImplementationContainer_in)
  //
  Implements Implements_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < Implements > (parent, Implements_Impl::metaname);
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

