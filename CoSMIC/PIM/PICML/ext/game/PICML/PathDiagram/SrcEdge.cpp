// $Id$

#include "StdAfx.h"
#include "SrcEdge.h"

#if !defined (__GAME_INLINE__)
#include "SrcEdge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/PathDiagram/Edge.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SrcEdge_Impl::metaname ("SrcEdge");

  //
  // _create (const Path_in)
  //
  SrcEdge SrcEdge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < SrcEdge > (parent, SrcEdge_Impl::metaname);
  }

  //
  // accept
  //
  void SrcEdge_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_SrcEdge (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Edge
  //
  Edge SrcEdge_Impl::src_Edge (void) const
  {
    return Edge::_narrow (this->src ());
  }

  //
  // GraphVertex
  //
  GraphVertex SrcEdge_Impl::dst_GraphVertex (void) const
  {
    return GraphVertex::_narrow (this->dst ());
  }
}

