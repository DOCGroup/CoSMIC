// $Id$

#include "stdafx.h"
#include "CriticalPath.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/PathDiagram/PathReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CriticalPath_Impl::metaname = "CriticalPath";

  //
  // CriticalPath_Impl
  //
  CriticalPath_Impl::CriticalPath_Impl (void)
  {
  }

  //
  // CriticalPath_Impl
  //
  CriticalPath_Impl::CriticalPath_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CriticalPath_Impl
  //
  CriticalPath_Impl::~CriticalPath_Impl (void)
  {
  }

  //
  // accept
  //
  void CriticalPath_Impl::accept (Visitor * v)
  {
    v->visit_CriticalPath (this);
  }

  //
  // _create
  //
  CriticalPath CriticalPath_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <CriticalPath> (parent, CriticalPath_Impl::metaname);
  }

  //
  // src_ComponentAssembly
  //
  ComponentAssembly CriticalPath_Impl::src_ComponentAssembly (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentAssembly::_narrow (target);
  }

  //
  // dst_PathReference
  //
  PathReference CriticalPath_Impl::dst_PathReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return PathReference::_narrow (target);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer CriticalPath_Impl::parent_ComponentImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentImplementationContainer> (this->object_.p);
  }
}

