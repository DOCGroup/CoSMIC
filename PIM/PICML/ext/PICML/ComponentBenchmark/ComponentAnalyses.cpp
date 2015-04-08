#include "StdAfx.h"
#include "ComponentAnalyses.h"

#if !defined (__GAME_INLINE__)
#include "ComponentAnalyses.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentAnalyses_Impl::metaname ("ComponentAnalyses");

  //
  // is_abstract
  //
  const bool ComponentAnalyses_Impl::is_abstract = false;

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentAnalyses ComponentAnalyses_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <ComponentAnalyses> (parent, ComponentAnalyses_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentAnalyses_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentAnalyses (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder ComponentAnalyses_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_BenchmarkAnalysiss
  //
  size_t ComponentAnalyses_Impl::get_BenchmarkAnalysiss (std::vector <BenchmarkAnalysis> & items) const
  {
    return this->children (items);
  }

  //
  // get_BenchmarkAnalysiss
  //
  ::GAME::Mga::Collection_T <BenchmarkAnalysis> ComponentAnalyses_Impl::get_BenchmarkAnalysiss (void) const
  {
    return this->children <BenchmarkAnalysis> ();
  }
}

