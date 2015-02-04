// $Id$

#include "StdAfx.h"
#include "OperationBase.h"

#if !defined (__GAME_INLINE__)
#include "OperationBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/OperationRef.h"
#include "PICML/OperationTypes/InParameter.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OperationBase_Impl::metaname ("OperationBase");

  //
  // is_abstract
  //
  const bool OperationBase_Impl::is_abstract = true;

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis OperationBase_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

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
  ::GAME::Mga::Collection_T <InParameter> OperationBase_Impl::get_InParameters (void) const
  {
    return this->children <InParameter> ();
  }
}

