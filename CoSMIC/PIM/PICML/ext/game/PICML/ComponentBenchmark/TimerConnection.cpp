// $Id$

#include "StdAfx.h"
#include "TimerConnection.h"

#if !defined (__GAME_INLINE__)
#include "TimerConnection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimeProbe.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TimerConnection_Impl::metaname ("TimerConnection");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  TimerConnection TimerConnection_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < TimerConnection > (parent, TimerConnection_Impl::metaname);
  }

  //
  // accept
  //
  void TimerConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TimerConnection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // OperationRef
  //
  OperationRef TimerConnection_Impl::src_OperationRef (void) const
  {
    return OperationRef::_narrow (this->src ());
  }

  //
  // TimeProbe
  //
  TimeProbe TimerConnection_Impl::dst_TimeProbe (void) const
  {
    return TimeProbe::_narrow (this->dst ());
  }
}

