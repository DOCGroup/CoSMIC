// $Id$

#include "stdafx.h"
#include "RegistryNode.h"

#if !defined (__GME_INLINE__)
#include "RegistryNode.inl"
#endif

namespace GME
{
  //
  // value
  //
  std::string RegistryNode::name (void) const
  {
    CComBSTR bstrval;

    VERIFY_HRESULT (this->node_->get_Name (&bstrval));

    // Convert the wide-string to a C-string
    CW2A convert (bstrval);
    return convert.m_psz;
  }

  //
  // status
  //
  long RegistryNode::status (void) const
  {
    long stat;
    VERIFY_HRESULT (this->node_->get_Status (&stat));

    return stat;
  }

  //
  // value
  //
  void RegistryNode::value (const std::string & value)
  {
    CComBSTR bstrval (value.size (), value.c_str ());

    VERIFY_HRESULT (this->node_->put_Value (bstrval));
  }

  //
  // value
  //
  std::string RegistryNode::value (void) const
  {
    CComBSTR bstrval;

    VERIFY_HRESULT (this->node_->get_Value (&bstrval));

    // Convert the wide-string to a C-string
    CW2A convert (bstrval);
    return convert.m_psz ? convert.m_psz : "";
  }

  //
  // path
  //
  std::string RegistryNode::path (void) const
  {
    CComBSTR bstrval;

    VERIFY_HRESULT (this->node_->get_Path (&bstrval));

    // Convert the wide-string to a C-string
    CW2A convert (bstrval);
    return convert.m_psz;
  }

  //
  // parent
  //
  RegistryNode RegistryNode::parent (void) const
  {
    RegistryNode node;
    VERIFY_HRESULT (this->node_->get_ParentNode (&node.node_));

    return node;
  }

  //
  // child
  //
  RegistryNode RegistryNode::child (const std::string & name) const
  {
    RegistryNode node;
    CComBSTR bstrval (name.size (), name.c_str ());

    VERIFY_HRESULT (this->node_->get_SubNodeByName (bstrval, &node.node_));

    return node;
  }

  //
  // children
  //
  size_t RegistryNode::children (GME::Collection_T <GME::RegistryNode> & nodes, 
                                 bool virtualinterface_types) const
  {
    // Get all the subnodes.
    CComPtr <IMgaRegNodes> rawnodes;
    VARIANT_BOOL vtypes = !virtualinterface_types ? VARIANT_FALSE : VARIANT_TRUE;
    VERIFY_HRESULT (this->node_->get_SubNodes (vtypes, &rawnodes));

    // Get the count and resize the nodes.
    nodes.attach (rawnodes.Detach ());
    return nodes.size ();
  }

  //
  // clear
  //
  void RegistryNode::clear (void)
  {
    VERIFY_HRESULT (this->node_->Clear ());
  }

  //
  // opacity
  //
  bool RegistryNode::opacity (void) const
  {
    VARIANT_BOOL value;
    VERIFY_HRESULT (this->node_->get_Opacity (&value));

    return value == VARIANT_TRUE ? true : false;
  }

  //
  // opacity
  //
  void RegistryNode::opacity (bool opacity)
  {
    VARIANT_BOOL value = opacity ? VARIANT_TRUE : VARIANT_FALSE;
    VERIFY_HRESULT (this->node_->put_Opacity (value));
  }

  //
  // destroy
  //
  void RegistryNode::destroy (void)
  {
    VERIFY_HRESULT (this->node_->RemoveTree ());
  }
}
