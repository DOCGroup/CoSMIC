// $Id$

#include "stdafx.h"
#include "ObjectPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ObjectPort_Impl::metaname = "ObjectPort";

  //
  // ObjectPort_Impl
  //
  ObjectPort_Impl::ObjectPort_Impl (void)
  {
  }

  //
  // ObjectPort_Impl
  //
  ObjectPort_Impl::ObjectPort_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ObjectPort_Impl
  //
  ObjectPort_Impl::~ObjectPort_Impl (void)
  {
  }

  //
  // parent_PortType
  //
  PortType ObjectPort_Impl::parent_PortType (void) const
  {
    return ::GAME::Mga::get_parent <PortType> (this->object_.p);
  }
}

