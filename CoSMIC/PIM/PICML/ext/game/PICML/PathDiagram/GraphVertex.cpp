// $Id$

#include "stdafx.h"
#include "GraphVertex.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/Path.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GraphVertex_Impl::metaname = "GraphVertex";

  //
  // GraphVertex_Impl
  //
  GraphVertex_Impl::GraphVertex_Impl (void)
  {
  }

  //
  // GraphVertex_Impl
  //
  GraphVertex_Impl::GraphVertex_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~GraphVertex_Impl
  //
  GraphVertex_Impl::~GraphVertex_Impl (void)
  {
  }

  //
  // in_DstEdge_connections
  //
  size_t GraphVertex_Impl::in_DstEdge_connections (std::vector <DstEdge> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_SrcEdge_connections
  //
  size_t GraphVertex_Impl::in_SrcEdge_connections (std::vector <SrcEdge> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Path
  //
  Path GraphVertex_Impl::parent_Path (void) const
  {
    return ::GAME::Mga::get_parent <Path> (this->object_.p);
  }
}

