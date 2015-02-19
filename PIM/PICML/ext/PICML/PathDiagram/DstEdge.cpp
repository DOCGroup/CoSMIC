// $Id$

#include "StdAfx.h"
#include "DstEdge.h"

#if !defined (__GAME_INLINE__)
#include "DstEdge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/PathDiagram/DisplayNode.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/Path.h"
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
  // is_abstract
  //
  const bool DstEdge_Impl::is_abstract = false;

  //
  // _create (const Path_in, GraphVertex_in src, Edge_in dst)
  //
  DstEdge DstEdge_Impl::_create (const Path_in parent, GraphVertex_in src, Edge_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, DstEdge_Impl::metaname, src, dst);
  }

  //
  // _create (const ConnectedComponent_in, GraphVertex_in src, Edge_in dst)
  //
  DstEdge DstEdge_Impl::_create (const ConnectedComponent_in parent, GraphVertex_in src, Edge_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, DstEdge_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void DstEdge_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DstEdge (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Path
  //
  Path DstEdge_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
  }

  //
  // parent_ConnectedComponent
  //
  ConnectedComponent DstEdge_Impl::parent_ConnectedComponent (void)
  {
    return ConnectedComponent::_narrow (this->parent ());
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

