// $Id$

#include "StdAfx.h"
#include "StringSeq.h"

#if !defined (__GAME_INLINE__)
#include "StringSeq.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/StringSeq_Item.h"
#include "DQML/Standard/QoSPolicies/SubscriptionKeyQosPolicy.h"
#include "DQML/Standard/QoSPolicies/PartitionQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string StringSeq_Impl::metaname ("StringSeq");

  //
  // _create (const SubscriptionKeyQosPolicy_in)
  //
  StringSeq StringSeq_Impl::_create (const SubscriptionKeyQosPolicy_in parent)
  {
    return ::GAME::Mga::create_object < StringSeq > (parent, StringSeq_Impl::metaname);
  }

  //
  // _create (const PartitionQosPolicy_in)
  //
  StringSeq StringSeq_Impl::_create (const PartitionQosPolicy_in parent)
  {
    return ::GAME::Mga::create_object < StringSeq > (parent, StringSeq_Impl::metaname);
  }

  //
  // accept
  //
  void StringSeq_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_StringSeq (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_SubscriptionKeyQosPolicy
  //
  SubscriptionKeyQosPolicy StringSeq_Impl::parent_SubscriptionKeyQosPolicy (void)
  {
    return SubscriptionKeyQosPolicy::_narrow (this->parent ());
  }

  //
  // parent_PartitionQosPolicy
  //
  PartitionQosPolicy StringSeq_Impl::parent_PartitionQosPolicy (void)
  {
    return PartitionQosPolicy::_narrow (this->parent ());
  }

  //
  // get_StringSeq_Items
  //
  size_t StringSeq_Impl::get_StringSeq_Items (std::vector <StringSeq_Item> & items) const
  {
    return this->children (items);
  }

  //
  // get_StringSeq_Items
  //
  ::GAME::Mga::Collection_T <StringSeq_Item> StringSeq_Impl::get_StringSeq_Items (void) const
  {
    return this->children <StringSeq_Item> ();
  }
}

