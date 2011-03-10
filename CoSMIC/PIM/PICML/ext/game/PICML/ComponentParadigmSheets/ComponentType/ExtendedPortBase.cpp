// $Id$

#include "stdafx.h"
#include "ExtendedPortBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExtendedPortBase_Impl::metaname = "ExtendedPortBase";

  //
  // ExtendedPortBase_Impl
  //
  ExtendedPortBase_Impl::ExtendedPortBase_Impl (void)
  {
  }

  //
  // ExtendedPortBase_Impl
  //
  ExtendedPortBase_Impl::ExtendedPortBase_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExtendedPortBase_Impl
  //
  ExtendedPortBase_Impl::~ExtendedPortBase_Impl (void)
  {
  }

  //
  // parent_Component
  //
  Component ExtendedPortBase_Impl::parent_Component (void) const
  {
    return ::GAME::Mga::get_parent <Component> (this->object_.p);
  }

  //
  // refers_to_PortType
  //
  PortType ExtendedPortBase_Impl::refers_to_PortType (void) const
  {
    return ::GAME::Mga::get_refers_to <PortType> (this);
  }
}

