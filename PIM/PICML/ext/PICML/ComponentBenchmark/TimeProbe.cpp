// $Id$

#include "StdAfx.h"
#include "TimeProbe.h"

#if !defined (__GAME_INLINE__)
#include "TimeProbe.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimerConnection.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
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
  // is_abstract
  //
  const bool TimeProbe_Impl::is_abstract = false;

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
  // has_dst_of_TimerConnection
  //
  bool TimeProbe_Impl::has_dst_of_TimerConnection (void) const
  {
    return this->in_connections <TimerConnection> ("dst").count () == 1;
  }

  //
  // dst_of_TimerConnection
  //
  TimerConnection TimeProbe_Impl::dst_of_TimerConnection (void) const
  {
    return this->in_connections <TimerConnection> ("dst").first ();
  }

  //
  // dst_of_TimerEventSinkConn
  //
  size_t TimeProbe_Impl::dst_of_TimerEventSinkConn (std::vector <TimerEventSinkConn> & items) const
  {
    return this->in_connections <TimerEventSinkConn> (items);
  }

  //
  // has_dst_of_TimerEventSinkConn
  //
  bool TimeProbe_Impl::has_dst_of_TimerEventSinkConn (void) const
  {
    return this->in_connections <TimerEventSinkConn> ("dst").count () == 1;
  }

  //
  // dst_of_TimerEventSinkConn
  //
  TimerEventSinkConn TimeProbe_Impl::dst_of_TimerEventSinkConn (void) const
  {
    return this->in_connections <TimerEventSinkConn> ("dst").first ();
  }
}

