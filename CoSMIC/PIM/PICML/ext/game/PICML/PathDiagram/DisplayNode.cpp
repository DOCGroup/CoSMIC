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
  // _create (const Path_in)
  //
  DisplayNode DisplayNode_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < DisplayNode > (parent, DisplayNode_Impl::metaname);
  }

  //
  // accept
  //
  void DisplayNode_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DisplayNode (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

