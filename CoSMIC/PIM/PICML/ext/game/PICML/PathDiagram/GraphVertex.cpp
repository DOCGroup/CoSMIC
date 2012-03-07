// $Id$

#include "StdAfx.h"
#include "GraphVertex.h"

#if !defined (__GAME_INLINE__)
#include "GraphVertex.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/SrcEdge.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GraphVertex_Impl::metaname ("GraphVertex");

  //
  // src_DstEdge
  //
  size_t GraphVertex_Impl::src_DstEdge (std::vector <DstEdge> & items) const
  {
    return this->in_connections <DstEdge> (items);
  }

  //
  // dst_SrcEdge
  //
  size_t GraphVertex_Impl::dst_SrcEdge (std::vector <SrcEdge> & items) const
  {
    return this->in_connections <SrcEdge> (items);
  }
}

