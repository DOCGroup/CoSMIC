// $Id$

#include "stdafx.h"
#include "PathDiagrams.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Paths.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PathDiagrams_Impl::metaname = "PathDiagrams";

  //
  // PathDiagrams_Impl
  //
  PathDiagrams_Impl::PathDiagrams_Impl (void)
  {
  }

  //
  // PathDiagrams_Impl
  //
  PathDiagrams_Impl::PathDiagrams_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PathDiagrams_Impl
  //
  PathDiagrams_Impl::~PathDiagrams_Impl (void)
  {
  }

  //
  // accept
  //
  void PathDiagrams_Impl::accept (Visitor * v)
  {
    v->visit_PathDiagrams (this);
  }

  //
  // _create
  //
  PathDiagrams PathDiagrams_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <PathDiagrams> (parent, PathDiagrams_Impl::metaname);
  }

  ::GAME::Mga::RootFolder PathDiagrams_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

