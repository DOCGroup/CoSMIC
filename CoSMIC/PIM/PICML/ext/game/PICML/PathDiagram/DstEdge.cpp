// $Id$

#include "StdAfx.h"
#include "DstEdge.h"

#if !defined (__GAME_INLINE__)
#include "DstEdge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
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
  const std::string DstEdge_Impl::metaname ("DstEdge");

  //
  // _create (const ConnectedComponent_in)
  //
  DstEdge DstEdge_Impl::_create (const ConnectedComponent_in parent)
  {
    return ::GAME::Mga::create_object < DstEdge > (parent, DstEdge_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  DstEdge DstEdge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < DstEdge > (parent, DstEdge_Impl::metaname);
  }

  //
  // accept
  //
  void DstEdge_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DstEdge (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // GraphVertex
  //
  GraphVertex DstEdge_Impl::src_GraphVertex (void) const
  {
    return GraphVertex::_narrow (this->src ());
  }

  //
  // Edge
  //
  Edge DstEdge_Impl::dst_Edge (void) const
  {
    return Edge::_narrow (this->dst ());
  }
}

