// $Id$

#include "stdafx.h"
#include "AttributeMappingDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AttributeMapping.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMappingDelegate_Impl::metaname = "AttributeMappingDelegate";

  //
  // AttributeMappingDelegate_Impl
  //
  AttributeMappingDelegate_Impl::AttributeMappingDelegate_Impl (void)
  {
  }

  //
  // AttributeMappingDelegate_Impl
  //
  AttributeMappingDelegate_Impl::AttributeMappingDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeMappingDelegate_Impl
  //
  AttributeMappingDelegate_Impl::~AttributeMappingDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeMappingDelegate_Impl::accept (Visitor * v)
  {
    v->visit_AttributeMappingDelegate (this);
  }

  //
  // src_AttributeMapping
  //
  AttributeMapping AttributeMappingDelegate_Impl::src_AttributeMapping (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return AttributeMapping::_narrow (target);
  }

  //
  // dst_AttributeMapping
  //
  AttributeMapping AttributeMappingDelegate_Impl::dst_AttributeMapping (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return AttributeMapping::_narrow (target);
  }
}

