// $Id$

#include "stdafx.h"
#include "PortType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PortType_Impl::metaname = "PortType";

  //
  // PortType_Impl
  //
  PortType_Impl::PortType_Impl (void)
  {
  }

  //
  // PortType_Impl
  //
  PortType_Impl::PortType_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PortType_Impl
  //
  PortType_Impl::~PortType_Impl (void)
  {
  }

  //
  // accept
  //
  void PortType_Impl::accept (Visitor * v)
  {
    v->visit_PortType (this);
  }

  //
  // get_ReadonlyAttributes
  //
  size_t PortType_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_ObjectPorts
  //
  size_t PortType_Impl::get_ObjectPorts (std::vector <ObjectPort> & items) const
  {
    return this->children (items);
  }
}

