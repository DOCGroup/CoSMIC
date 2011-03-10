// $Id$

#include "stdafx.h"
#include "Port.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Port_Impl::metaname = "Port";

  //
  // Port_Impl
  //
  Port_Impl::Port_Impl (void)
  {
  }

  //
  // Port_Impl
  //
  Port_Impl::Port_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Port_Impl
  //
  Port_Impl::~Port_Impl (void)
  {
  }

  //
  // parent_Component
  //
  Component Port_Impl::parent_Component (void) const
  {
    return ::GAME::Mga::get_parent <Component> (this->object_.p);
  }
}

