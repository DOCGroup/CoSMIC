// $Id$

#include "StdAfx.h"
#include "CompRef.h"

#if !defined (__GAME_INLINE__)
#include "CompRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/ComponentOperation.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CompRef_Impl::metaname ("CompRef");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  CompRef CompRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < CompRef > (parent, CompRef_Impl::metaname);
  }

  //
  // accept
  //
  void CompRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_CompRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis CompRef_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // dst_ComponentOperation
  //
  size_t CompRef_Impl::dst_ComponentOperation (std::vector <ComponentOperation> & items) const
  {
    return this->in_connections <ComponentOperation> (items);
  }

  //
  // Component_is_nil
  //
  bool CompRef_Impl::Component_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_Component
  //
  void CompRef_Impl::set_Component (Component_in item)
  {
    this->refers_to (item);
  }

  //
  // get_Component
  //
  Component CompRef_Impl::get_Component (void) const
  {
    return Component::_narrow (this->refers_to ());
  }
}
