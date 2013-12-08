// $Id$

#include "StdAfx.h"
#include "ReaderDataLifecycleQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ReaderDataLifecycleQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/ReaderDataLifecycleQosPolicy/dr_readerdatalifecycle_Connection.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string ReaderDataLifecycleQosPolicy_Impl::metaname ("ReaderDataLifecycleQosPolicy");

  //
  // _create (const DataReaderQos_in)
  //
  ReaderDataLifecycleQosPolicy ReaderDataLifecycleQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < ReaderDataLifecycleQosPolicy > (parent, ReaderDataLifecycleQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  ReaderDataLifecycleQosPolicy ReaderDataLifecycleQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < ReaderDataLifecycleQosPolicy > (parent, ReaderDataLifecycleQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void ReaderDataLifecycleQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ReaderDataLifecycleQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dr_readerdatalifecycle_Connection
  //
  size_t ReaderDataLifecycleQosPolicy_Impl::dst_dr_readerdatalifecycle_Connection (std::vector <dr_readerdatalifecycle_Connection> & items) const
  {
    return this->in_connections <dr_readerdatalifecycle_Connection> (items);
  }
}
