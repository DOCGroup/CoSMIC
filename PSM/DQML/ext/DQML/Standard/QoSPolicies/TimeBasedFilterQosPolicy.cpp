// $Id$

#include "StdAfx.h"
#include "TimeBasedFilterQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "TimeBasedFilterQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/TimeBasedFilterQosPolicy/dr_timebased_Connection.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool TimeBasedFilterQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataReaderQos_in)
  //
  TimeBasedFilterQosPolicy TimeBasedFilterQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < TimeBasedFilterQosPolicy > (parent, TimeBasedFilterQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  TimeBasedFilterQosPolicy TimeBasedFilterQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < TimeBasedFilterQosPolicy > (parent, TimeBasedFilterQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void TimeBasedFilterQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TimeBasedFilterQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos TimeBasedFilterQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // dst_of_dr_timebased_Connection
  //
  size_t TimeBasedFilterQosPolicy_Impl::dst_of_dr_timebased_Connection (std::vector <dr_timebased_Connection> & items) const
  {
    return this->in_connections <dr_timebased_Connection> (items);
  }

  //
  // dst_of_dr_timebased_Connection
  //
  GAME::Mga::Collection_T <dr_timebased_Connection> TimeBasedFilterQosPolicy_Impl::dst_of_dr_timebased_Connection (void) const
  {
    return this->in_connections <dr_timebased_Connection> ("dst");
  }
}

