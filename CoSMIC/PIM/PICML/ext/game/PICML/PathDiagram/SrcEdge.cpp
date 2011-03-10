// $Id$

#include "stdafx.h"
#include "SrcEdge.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/GraphVertex.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SrcEdge_Impl::metaname = "SrcEdge";

  //
  // SrcEdge_Impl
  //
  SrcEdge_Impl::SrcEdge_Impl (void)
  {
  }

  //
  // SrcEdge_Impl
  //
  SrcEdge_Impl::SrcEdge_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SrcEdge_Impl
  //
  SrcEdge_Impl::~SrcEdge_Impl (void)
  {
  }

  //
  // accept
  //
  void SrcEdge_Impl::accept (Visitor * v)
  {
    v->visit_SrcEdge (this);
  }

  //
  // _create
  //
  SrcEdge SrcEdge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object <SrcEdge> (parent, SrcEdge_Impl::metaname);
  }

  //
  // src_Edge
  //
  Edge SrcEdge_Impl::src_Edge (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Edge::_narrow (target);
  }

  //
  // dst_GraphVertex
  //
  GraphVertex SrcEdge_Impl::dst_GraphVertex (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return GraphVertex::_narrow (target);
  }

  //
  // parent_Path
  //
  Path SrcEdge_Impl::parent_Path (void) const
  {
    return ::GAME::Mga::get_parent <Path> (this->object_.p);
  }
}

