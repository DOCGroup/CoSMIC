// $Id$

#include "stdafx.h"
#include "PortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PortInstance_Impl::metaname = "PortInstance";

  //
  // PortInstance_Impl
  //
  PortInstance_Impl::PortInstance_Impl (void)
  {
  }

  //
  // PortInstance_Impl
  //
  PortInstance_Impl::PortInstance_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PortInstance_Impl
  //
  PortInstance_Impl::~PortInstance_Impl (void)
  {
  }

  //
  // parent_ComponentInstance
  //
  ComponentInstance PortInstance_Impl::parent_ComponentInstance (void) const
  {
    return ::GAME::Mga::get_parent <ComponentInstance> (this->object_.p);
  }
}

