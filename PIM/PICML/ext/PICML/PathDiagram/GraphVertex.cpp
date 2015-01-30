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
  // parent_Path
  //
  Path GraphVertex_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
  }

  //
  // src_of_DstEdge
  //
  size_t GraphVertex_Impl::src_of_DstEdge (std::vector <DstEdge> & items) const
  {
    return this->in_connections <DstEdge> (items);
  }

  //
  // src_of_DstEdge
  //
  GAME::Mga::Collection_T <DstEdge> GraphVertex_Impl::src_of_DstEdge (void) const
  {
    return this->in_connections <DstEdge> ("src");
  }

  //
  // dst_of_SrcEdge
  //
  size_t GraphVertex_Impl::dst_of_SrcEdge (std::vector <SrcEdge> & items) const
  {
    return this->in_connections <SrcEdge> (items);
  }

  //
  // dst_of_SrcEdge
  //
  GAME::Mga::Collection_T <SrcEdge> GraphVertex_Impl::dst_of_SrcEdge (void) const
  {
    return this->in_connections <SrcEdge> ("dst");
  }
}

