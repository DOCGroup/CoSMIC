// $Id$

#include "StdAfx.h"
#include "sub_groupdata_Connection.h"

#if !defined (__GAME_INLINE__)
#include "sub_groupdata_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "DQML/Standard/QoSPolicies/GroupDataQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string sub_groupdata_Connection_Impl::metaname ("sub_groupdata_Connection");

  //
  // _create (const DDSQoS_in)
  //
  sub_groupdata_Connection sub_groupdata_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < sub_groupdata_Connection > (parent, sub_groupdata_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void sub_groupdata_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_sub_groupdata_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Subscriber
  //
  Subscriber sub_groupdata_Connection_Impl::src_Subscriber (void) const
  {
    return Subscriber::_narrow (this->src ());
  }

  //
  // GroupDataQosPolicy
  //
  GroupDataQosPolicy sub_groupdata_Connection_Impl::dst_GroupDataQosPolicy (void) const
  {
    return GroupDataQosPolicy::_narrow (this->dst ());
  }
}

