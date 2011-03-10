// $Id$

#include "stdafx.h"
#include "PropertyMapping.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PropertyMapping_Impl::metaname = "PropertyMapping";

  //
  // PropertyMapping_Impl
  //
  PropertyMapping_Impl::PropertyMapping_Impl (void)
  {
  }

  //
  // PropertyMapping_Impl
  //
  PropertyMapping_Impl::PropertyMapping_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PropertyMapping_Impl
  //
  PropertyMapping_Impl::~PropertyMapping_Impl (void)
  {
  }

  //
  // accept
  //
  void PropertyMapping_Impl::accept (Visitor * v)
  {
    v->visit_PropertyMapping (this);
  }

  //
  // _create
  //
  PropertyMapping PropertyMapping_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object <PropertyMapping> (parent, PropertyMapping_Impl::metaname);
  }

  //
  // src_NodeReference
  //
  NodeReference PropertyMapping_Impl::src_NodeReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return NodeReference::_narrow (target);
  }

  //
  // dst_Property
  //
  Property PropertyMapping_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan PropertyMapping_Impl::parent_DeploymentPlan (void) const
  {
    return ::GAME::Mga::get_parent <DeploymentPlan> (this->object_.p);
  }
}

