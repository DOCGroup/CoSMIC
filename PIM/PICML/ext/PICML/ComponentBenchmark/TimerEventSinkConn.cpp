// $Id$

#include "StdAfx.h"
#include "TimerEventSinkConn.h"

#if !defined (__GAME_INLINE__)
#include "TimerEventSinkConn.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/EventRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TimerEventSinkConn_Impl::metaname ("TimerEventSinkConn");

  //
  // _create (const BenchmarkAnalysis_in, EventRef_in src, TimeProbe_in dst)
  //
  TimerEventSinkConn TimerEventSinkConn_Impl::_create (const BenchmarkAnalysis_in parent, EventRef_in src, TimeProbe_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, TimerEventSinkConn_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void TimerEventSinkConn_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TimerEventSinkConn (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TimerEventSinkConn_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // EventRef
  //
  EventRef TimerEventSinkConn_Impl::src_EventRef (void) const
  {
    return EventRef::_narrow (this->src ());
  }

  //
  // TimeProbe
  //
  TimeProbe TimerEventSinkConn_Impl::dst_TimeProbe (void) const
  {
    return TimeProbe::_narrow (this->dst ());
  }
}

