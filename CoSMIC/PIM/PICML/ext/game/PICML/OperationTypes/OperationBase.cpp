// $Id$

#include "StdAfx.h"
#include "OperationBase.h"

#if !defined (__GAME_INLINE__)
#include "OperationBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/InParameter.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OperationBase_Impl::metaname ("OperationBase");

  //
  // get_InParameters
  //
  size_t OperationBase_Impl::get_InParameters (std::vector <InParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_InParameters
  //
  ::GAME::Mga::Iterator <InParameter> OperationBase_Impl::get_InParameters (void) const
  {
    return this->children <InParameter> ();
  }
}

