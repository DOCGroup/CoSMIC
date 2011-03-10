// $Id$

#include "stdafx.h"
#include "DstEdge.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/PathDiagram/Edge.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DstEdge_Impl::metaname = "DstEdge";

  //
  // DstEdge_Impl
  //
  DstEdge_Impl::DstEdge_Impl (void)
  {
  }

  //
  // DstEdge_Impl
  //
  DstEdge_Impl::DstEdge_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DstEdge_Impl
  //
  DstEdge_Impl::~DstEdge_Impl (void)
  {
  }

  //
  // accept
  //
  void DstEdge_Impl::accept (Visitor * v)
  {
    v->visit_DstEdge (this);
  }

  //
  // _create
  //
  DstEdge DstEdge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object <DstEdge> (parent, DstEdge_Impl::metaname);
  }

  //
  // _create
  //
  DstEdge DstEdge_Impl::_create (const ConnectedComponent_in parent)
  {
    return ::GAME::Mga::create_object <DstEdge> (parent, DstEdge_Impl::metaname);
  }

  //
  // src_GraphVertex
  //
  GraphVertex DstEdge_Impl::src_GraphVertex (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return GraphVertex::_narrow (target);
  }

  //
  // dst_Edge
  //
  Edge DstEdge_Impl::dst_Edge (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Edge::_narrow (target);
  }

  //
  // parent_Path
  //
  Path DstEdge_Impl::parent_Path (void) const
  {
    return ::GAME::Mga::get_parent <Path> (this->object_.p);
  }

  //
  // parent_ConnectedComponent
  //
  ConnectedComponent DstEdge_Impl::parent_ConnectedComponent (void) const
  {
    return ::GAME::Mga::get_parent <ConnectedComponent> (this->object_.p);
  }
}

