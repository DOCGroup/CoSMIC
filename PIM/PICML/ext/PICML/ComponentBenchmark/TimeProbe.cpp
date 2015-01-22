// $Id$

#include "StdAfx.h"
#include "TimeProbe.h"

#if !defined (__GAME_INLINE__)
#include "TimeProbe.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TimeProbe_Impl::metaname ("TimeProbe");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  TimeProbe TimeProbe_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < TimeProbe > (parent, TimeProbe_Impl::metaname);
  }

  //
  // accept
  //
  void TimeProbe_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TimeProbe (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis TimeProbe_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // dst_of_TimerConnection
  //
  size_t TimeProbe_Impl::dst_of_TimerConnection (std::vector <TimerConnection> & items) const
  {
    return this->in_connections <TimerConnection> (items);
  }

  //
  // dst_of_TimerConnection
  //
  GAME::Mga::Collection_T <TimerConnection> TimeProbe_Impl::dst_of_TimerConnection (void) const
  {
    return this->in_connections <TimerConnection> ("dst");
  }

  //
  // dst_of_TimerEventSinkConn
  //
  size_t TimeProbe_Impl::dst_of_TimerEventSinkConn (std::vector <TimerEventSinkConn> & items) const
  {
    return this->in_connections <TimerEventSinkConn> (items);
  }

  //
  // dst_of_TimerEventSinkConn
  //
  GAME::Mga::Collection_T <TimerEventSinkConn> TimeProbe_Impl::dst_of_TimerEventSinkConn (void) const
  {
    return this->in_connections <TimerEventSinkConn> ("dst");
  }
}

