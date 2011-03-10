// $Id$

#include "stdafx.h"
#include "TimerConnection.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TimerConnection_Impl::metaname = "TimerConnection";

  //
  // TimerConnection_Impl
  //
  TimerConnection_Impl::TimerConnection_Impl (void)
  {
  }

  //
  // TimerConnection_Impl
  //
  TimerConnection_Impl::TimerConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TimerConnection_Impl
  //
  TimerConnection_Impl::~TimerConnection_Impl (void)
  {
  }

  //
  // accept
  //
  void TimerConnection_Impl::accept (Visitor * v)
  {
    v->visit_TimerConnection (this);
  }

  //
  // _create
  //
  TimerConnection TimerConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <TimerConnection> (parent, TimerConnection_Impl::metaname);
  }

  //
  // src_OperationRef
  //
  OperationRef TimerConnection_Impl::src_OperationRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return OperationRef::_narrow (target);
  }

  //
  // dst_TimeProbe
  //
  TimeProbe TimerConnection_Impl::dst_TimeProbe (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return TimeProbe::_narrow (target);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TimerConnection_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

