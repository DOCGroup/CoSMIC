// $Id$

#include "stdafx.h"
#include "TimeProbe.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TimeProbe_Impl::metaname = "TimeProbe";

  //
  // TimeProbe_Impl
  //
  TimeProbe_Impl::TimeProbe_Impl (void)
  {
  }

  //
  // TimeProbe_Impl
  //
  TimeProbe_Impl::TimeProbe_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TimeProbe_Impl
  //
  TimeProbe_Impl::~TimeProbe_Impl (void)
  {
  }

  //
  // accept
  //
  void TimeProbe_Impl::accept (Visitor * v)
  {
    v->visit_TimeProbe (this);
  }

  //
  // _create
  //
  TimeProbe TimeProbe_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <TimeProbe> (parent, TimeProbe_Impl::metaname);
  }

  //
  // in_TimerEventSinkConn_connections
  //
  size_t TimeProbe_Impl::in_TimerEventSinkConn_connections (std::vector <TimerEventSinkConn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_TimerConnection_connections
  //
  size_t TimeProbe_Impl::in_TimerConnection_connections (std::vector <TimerConnection> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TimeProbe_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

