// $Id$

#include "stdafx.h"
#include "Edge.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/Path.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Edge_Impl::metaname = "Edge";

  //
  // Edge_Impl
  //
  Edge_Impl::Edge_Impl (void)
  {
  }

  //
  // Edge_Impl
  //
  Edge_Impl::Edge_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Edge_Impl
  //
  Edge_Impl::~Edge_Impl (void)
  {
  }

  //
  // accept
  //
  void Edge_Impl::accept (Visitor * v)
  {
    v->visit_Edge (this);
  }

  //
  // _create
  //
  Edge Edge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object <Edge> (parent, Edge_Impl::metaname);
  }

  //
  // in_SrcEdge_connections
  //
  size_t Edge_Impl::in_SrcEdge_connections (std::vector <SrcEdge> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_EdgeProperty_connections
  //
  size_t Edge_Impl::in_EdgeProperty_connections (std::vector <EdgeProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_DstEdge_connections
  //
  size_t Edge_Impl::in_DstEdge_connections (std::vector <DstEdge> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Path
  //
  Path Edge_Impl::parent_Path (void) const
  {
    return ::GAME::Mga::get_parent <Path> (this->object_.p);
  }
}

