// $Id$

#include "stdafx.h"
#include "ExternalPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalPort_Impl::metaname = "ExternalPort";

  //
  // ExternalPort_Impl
  //
  ExternalPort_Impl::ExternalPort_Impl (void)
  {
  }

  //
  // ExternalPort_Impl
  //
  ExternalPort_Impl::ExternalPort_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExternalPort_Impl
  //
  ExternalPort_Impl::~ExternalPort_Impl (void)
  {
  }

  //
  // accept
  //
  void ExternalPort_Impl::accept (Visitor * v)
  {
    v->visit_ExternalPort (this);
  }

  //
  // _create
  //
  ExternalPort ExternalPort_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object <ExternalPort> (parent, ExternalPort_Impl::metaname);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ExternalPort_Impl::parent_ComponentAssembly (void) const
  {
    return ::GAME::Mga::get_parent <ComponentAssembly> (this->object_.p);
  }
}

