// $Id$

#include "StdAfx.h"
#include "CriticalPath.h"

#if !defined (__GAME_INLINE__)
#include "CriticalPath.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/PathReference.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CriticalPath_Impl::metaname ("CriticalPath");

  //
  // _create (const ComponentImplementationContainer_in)
  //
  CriticalPath CriticalPath_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < CriticalPath > (parent, CriticalPath_Impl::metaname);
  }

  //
  // accept
  //
  void CriticalPath_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_CriticalPath (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer CriticalPath_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // ComponentAssembly
  //
  ComponentAssembly CriticalPath_Impl::src_ComponentAssembly (void) const
  {
    return ComponentAssembly::_narrow (this->src ());
  }

  //
  // PathReference
  //
  PathReference CriticalPath_Impl::dst_PathReference (void) const
  {
    return PathReference::_narrow (this->dst ());
  }
}
