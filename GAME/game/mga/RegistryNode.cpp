// $Id$

#include "stdafx.h"
#include "mga.h"

#include "RegistryNode.h"

#if !defined (__GAME_INLINE__)
#include "RegistryNode.inl"
#endif

#include "Exception.h"
#include "Collection_T.h"

namespace GAME
{
namespace Mga
{

//
// value
//
std::string RegistryNode_Impl::name (void) const
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
long RegistryNode_Impl::status (void) const
{
  long stat;
  VERIFY_HRESULT (this->node_->get_Status (&stat));

  return stat;
}

//
// value
//
void RegistryNode_Impl::value (const std::string & value)
{
  CComBSTR bstrval (value.size (), value.c_str ());
  VERIFY_HRESULT (this->node_->put_Value (bstrval));
}

//
// value
//
std::string RegistryNode_Impl::value (void) const
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
std::string RegistryNode_Impl::path (void) const
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
RegistryNode RegistryNode_Impl::parent (void) const
{
  CComPtr <IMgaRegNode> regnode;
  VERIFY_HRESULT (this->node_->get_ParentNode (&regnode));

  return regnode.p;
}

//
// child
//
RegistryNode RegistryNode_Impl::child (const std::string & name) const
{
  CComPtr <IMgaRegNode> regnode;
  CComBSTR bstrval (name.size (), name.c_str ());
  VERIFY_HRESULT (this->node_->get_SubNodeByName (bstrval, &regnode));

  return regnode.p;
}

//
// children
//
size_t RegistryNode_Impl::
children (std::vector <RegistryNode> & nodes, bool types) const
{
  // Get all the subnodes.
  CComPtr <IMgaRegNodes> rawnodes;
  VARIANT_BOOL vtypes = !types ? VARIANT_FALSE : VARIANT_TRUE;
  VERIFY_HRESULT (this->node_->get_SubNodes (vtypes, &rawnodes));

  return iter_to_collection (rawnodes.p, nodes);
}

//
// clear
//
void RegistryNode_Impl::clear (void)
{
  VERIFY_HRESULT (this->node_->Clear ());
}

//
// opacity
//
bool RegistryNode_Impl::opacity (void) const
{
  VARIANT_BOOL value;
  VERIFY_HRESULT (this->node_->get_Opacity (&value));

  return value == VARIANT_TRUE ? true : false;
}

//
// opacity
//
void RegistryNode_Impl::opacity (bool opacity)
{
  VARIANT_BOOL value = opacity ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->node_->put_Opacity (value));
}

//
// destroy
//
void RegistryNode_Impl::destroy (void)
{
  VERIFY_HRESULT (this->node_->RemoveTree ());
}

}
}
