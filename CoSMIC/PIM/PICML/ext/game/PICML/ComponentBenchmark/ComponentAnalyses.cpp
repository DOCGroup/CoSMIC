// $Id$

#include "stdafx.h"
#include "ComponentAnalyses.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentAnalyses_Impl::metaname = "ComponentAnalyses";

  //
  // ComponentAnalyses_Impl
  //
  ComponentAnalyses_Impl::ComponentAnalyses_Impl (void)
  {
  }

  //
  // ComponentAnalyses_Impl
  //
  ComponentAnalyses_Impl::ComponentAnalyses_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentAnalyses_Impl
  //
  ComponentAnalyses_Impl::~ComponentAnalyses_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentAnalyses_Impl::accept (Visitor * v)
  {
    v->visit_ComponentAnalyses (this);
  }

  //
  // _create
  //
  ComponentAnalyses ComponentAnalyses_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentAnalyses> (parent, ComponentAnalyses_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ComponentAnalyses_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

