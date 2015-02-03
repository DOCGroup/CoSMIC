// $Id$

#include "StdAfx.h"
#include "PathDiagrams.h"

#if !defined (__GAME_INLINE__)
#include "PathDiagrams.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Paths.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PathDiagrams_Impl::metaname ("PathDiagrams");

  //
  // is_abstract
  //
  const bool PathDiagrams_Impl::is_abstract (0);

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  PathDiagrams PathDiagrams_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <PathDiagrams> (parent, PathDiagrams_Impl::metaname);
  }

  //
  // accept
  //
  void PathDiagrams_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PathDiagrams (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder PathDiagrams_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_Pathss
  //
  size_t PathDiagrams_Impl::get_Pathss (std::vector <Paths> & items) const
  {
    return this->children (items);
  }

  //
  // get_Pathss
  //
  ::GAME::Mga::Collection_T <Paths> PathDiagrams_Impl::get_Pathss (void) const
  {
    return this->children <Paths> ();
  }
}

