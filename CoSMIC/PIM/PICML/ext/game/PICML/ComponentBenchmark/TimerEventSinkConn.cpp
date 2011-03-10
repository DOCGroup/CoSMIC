// $Id$

#include "stdafx.h"
#include "TimerEventSinkConn.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/EventRef.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TimerEventSinkConn_Impl::metaname = "TimerEventSinkConn";

  //
  // TimerEventSinkConn_Impl
  //
  TimerEventSinkConn_Impl::TimerEventSinkConn_Impl (void)
  {
  }

  //
  // TimerEventSinkConn_Impl
  //
  TimerEventSinkConn_Impl::TimerEventSinkConn_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TimerEventSinkConn_Impl
  //
  TimerEventSinkConn_Impl::~TimerEventSinkConn_Impl (void)
  {
  }

  //
  // accept
  //
  void TimerEventSinkConn_Impl::accept (Visitor * v)
  {
    v->visit_TimerEventSinkConn (this);
  }

  //
  // _create
  //
  TimerEventSinkConn TimerEventSinkConn_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <TimerEventSinkConn> (parent, TimerEventSinkConn_Impl::metaname);
  }

  //
  // src_EventRef
  //
  EventRef TimerEventSinkConn_Impl::src_EventRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return EventRef::_narrow (target);
  }

  //
  // dst_TimeProbe
  //
  TimeProbe TimerEventSinkConn_Impl::dst_TimeProbe (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return TimeProbe::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TimerEventSinkConn_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

