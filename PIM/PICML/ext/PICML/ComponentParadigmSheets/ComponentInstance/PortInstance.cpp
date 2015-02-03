// $Id$

#include "StdAfx.h"
#include "PortInstance.h"

#if !defined (__GAME_INLINE__)
#include "PortInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PortInstance_Impl::metaname ("PortInstance");

  //
  // is_abstract
  //
  const bool PortInstance_Impl::is_abstract (1);

  //
  // parent_ComponentInstance
  //
  ComponentInstance PortInstance_Impl::parent_ComponentInstance (void)
  {
    return ComponentInstance::_narrow (this->parent ());
  }
}

