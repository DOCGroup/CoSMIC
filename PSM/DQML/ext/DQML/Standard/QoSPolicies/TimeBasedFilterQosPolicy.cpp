// $Id$

#include "StdAfx.h"
#include "TimeBasedFilterQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "TimeBasedFilterQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/TimeBasedFilterQosPolicy/dr_timebased_Connection.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TimeBasedFilterQosPolicy_Impl::metaname ("TimeBasedFilterQosPolicy");

  //
  // _create (const DataReaderQos_in)
  //
  TimeBasedFilterQosPolicy TimeBasedFilterQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < TimeBasedFilterQosPolicy > (parent, TimeBasedFilterQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  TimeBasedFilterQosPolicy TimeBasedFilterQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < TimeBasedFilterQosPolicy > (parent, TimeBasedFilterQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void TimeBasedFilterQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TimeBasedFilterQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dr_timebased_Connection
  //
  size_t TimeBasedFilterQosPolicy_Impl::dst_dr_timebased_Connection (std::vector <dr_timebased_Connection> & items) const
  {
    return this->in_connections <dr_timebased_Connection> (items);
  }
}

