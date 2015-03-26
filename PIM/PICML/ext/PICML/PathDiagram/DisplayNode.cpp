// $Id$

#include "StdAfx.h"
#include "DisplayNode.h"

#if !defined (__GAME_INLINE__)
#include "DisplayNode.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DisplayNode_Impl::metaname ("DisplayNode");

  //
  // is_abstract
  //
  const bool DisplayNode_Impl::is_abstract = false;

  //
  // _create (const Path_in)
  //
  DisplayNode DisplayNode_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create < DisplayNode > (parent, DisplayNode_Impl::metaname);
  }

  //
  // accept
  //
  void DisplayNode_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DisplayNode (this);
    else
      v->visit_Atom (this);
  }
}

