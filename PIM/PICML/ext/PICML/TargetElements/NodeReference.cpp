#include "StdAfx.h"
#include "NodeReference.h"

#if !defined (__GAME_INLINE__)
#include "NodeReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/DeploymentPlan/DeploymentPlan.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/DeploymentPlan/PropertyMapping.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string NodeReference_Impl::metaname ("NodeReference");

  //
  // is_abstract
  //
  const bool NodeReference_Impl::is_abstract = false;

  //
  // _create (const DeploymentPlan_in)
  //
  NodeReference NodeReference_Impl::_create (const DeploymentPlan_in parent)
  {
    return ::GAME::Mga::create < NodeReference > (parent, NodeReference_Impl::metaname);
  }

  //
  // accept
  //
  void NodeReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_NodeReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_DeploymentPlan
  //
  DeploymentPlan NodeReference_Impl::parent_DeploymentPlan (void)
  {
    return DeploymentPlan::_narrow (this->parent ());
  }

  //
  // src_of_PropertyMapping
  //
  size_t NodeReference_Impl::src_of_PropertyMapping (std::vector <PropertyMapping> & items) const
  {
    return this->in_connections <PropertyMapping> (items);
  }

  //
  // src_of_PropertyMapping
  //
  GAME::Mga::Collection_T <PropertyMapping> NodeReference_Impl::src_of_PropertyMapping (void) const
  {
    return this->in_connections <PropertyMapping> ("src");
  }

  //
  // dst_of_InstanceMapping
  //
  size_t NodeReference_Impl::dst_of_InstanceMapping (std::vector <InstanceMapping> & items) const
  {
    return this->in_connections <InstanceMapping> (items);
  }

  //
  // dst_of_InstanceMapping
  //
  GAME::Mga::Collection_T <InstanceMapping> NodeReference_Impl::dst_of_InstanceMapping (void) const
  {
    return this->in_connections <InstanceMapping> ("dst");
  }

  //
  // Node_is_nil
  //
  bool NodeReference_Impl::Node_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_Node
  //
  void NodeReference_Impl::refers_to_Node (Node_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Node
  //
  Node NodeReference_Impl::refers_to_Node (void) const
  {
    return Node::_narrow (this->refers_to ());
  }
}

