// $Id$

#include "StdAfx.h"
#include "dr_readerdatalifecycle_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dr_readerdatalifecycle_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/ReaderDataLifecycleQosPolicy.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dr_readerdatalifecycle_Connection_Impl::metaname ("dr_readerdatalifecycle_Connection");

  //
  // _create (const DDSQoS_in, DataReader_in src, ReaderDataLifecycleQosPolicy_in dst)
  //
  dr_readerdatalifecycle_Connection dr_readerdatalifecycle_Connection_Impl::_create (const DDSQoS_in parent, DataReader_in src, ReaderDataLifecycleQosPolicy_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dr_readerdatalifecycle_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dr_readerdatalifecycle_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dr_readerdatalifecycle_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dr_readerdatalifecycle_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataReader
  //
  DataReader dr_readerdatalifecycle_Connection_Impl::src_DataReader (void) const
  {
    return DataReader::_narrow (this->src ());
  }

  //
  // ReaderDataLifecycleQosPolicy
  //
  ReaderDataLifecycleQosPolicy dr_readerdatalifecycle_Connection_Impl::dst_ReaderDataLifecycleQosPolicy (void) const
  {
    return ReaderDataLifecycleQosPolicy::_narrow (this->dst ());
  }
}

