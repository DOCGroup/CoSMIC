// $Id$

#include "StdAfx.h"
#include "HasExceptions.h"

#if !defined (__GAME_INLINE__)
#include "HasExceptions.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/ExceptionRef.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string HasExceptions_Impl::metaname ("HasExceptions");

  //
  // is_abstract
  //
  const bool HasExceptions_Impl::is_abstract = true;

  //
  // get_ExceptionRefs
  //
  size_t HasExceptions_Impl::get_ExceptionRefs (std::vector <ExceptionRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExceptionRefs
  //
  ::GAME::Mga::Collection_T <ExceptionRef> HasExceptions_Impl::get_ExceptionRefs (void) const
  {
    return this->children <ExceptionRef> ();
  }
}

