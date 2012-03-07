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
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  PathDiagrams PathDiagrams_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <PathDiagrams> (parent, PathDiagrams_Impl::metaname);
  }

  //
  // accept
  //
  void PathDiagrams_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PathDiagrams (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_Pathss
  //
  size_t PathDiagrams_Impl::get_Pathss (std::vector <Paths> & items) const
  {
    return this->children (items);
  }
}

