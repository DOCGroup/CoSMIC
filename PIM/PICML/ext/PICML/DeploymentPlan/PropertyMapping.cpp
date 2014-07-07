// $Id$

#include "StdAfx.h"
#include "PropertyMapping.h"

#if !defined (__GAME_INLINE__)
#include "PropertyMapping.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PropertyMapping_Impl::metaname ("PropertyMapping");

  //
  // _create (const DeploymentPlan_in)
  //
  PropertyMapping PropertyMapping_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create_object < PropertyMapping > (parent, PropertyMapping_Impl::metaname);
  }

  //
  // accept
  //
  void PropertyMapping_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PropertyMapping (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan PropertyMapping_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // NodeReference
  //
  NodeReference PropertyMapping_Impl::src_NodeReference (void) const
  {
    return NodeReference::_narrow (this->src ());
  }

  //
  // Property
  //
  Property PropertyMapping_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

