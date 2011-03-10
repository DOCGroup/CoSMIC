// $Id$

#include "stdafx.h"
#include "AttributeDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeDelegate_Impl::metaname = "AttributeDelegate";

  //
  // AttributeDelegate_Impl
  //
  AttributeDelegate_Impl::AttributeDelegate_Impl (void)
  {
  }

  //
  // AttributeDelegate_Impl
  //
  AttributeDelegate_Impl::AttributeDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeDelegate_Impl
  //
  AttributeDelegate_Impl::~AttributeDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeDelegate_Impl::accept (Visitor * v)
  {
    v->visit_AttributeDelegate (this);
  }

  //
  // src_AttributeMapping
  //
  AttributeMapping AttributeDelegate_Impl::src_AttributeMapping (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return AttributeMapping::_narrow (target);
  }

  //
  // dst_AttributeInstance
  //
  AttributeInstance AttributeDelegate_Impl::dst_AttributeInstance (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return AttributeInstance::_narrow (target);
  }
}

