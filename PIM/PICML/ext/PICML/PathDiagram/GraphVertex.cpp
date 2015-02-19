// $Id$

#include "StdAfx.h"
#include "GraphVertex.h"

#if !defined (__GAME_INLINE__)
#include "GraphVertex.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/Path.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string GraphVertex_Impl::metaname ("GraphVertex");

  //
  // is_abstract
  //
  const bool GraphVertex_Impl::is_abstract = true;

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
  // has_src_of_DstEdge
  //
  bool GraphVertex_Impl::has_src_of_DstEdge (void) const
  {
    return this->in_connections <DstEdge> ("src").count () == 1;
  }

  //
  // src_of_DstEdge
  //
  DstEdge GraphVertex_Impl::src_of_DstEdge (void) const
  {
    return this->in_connections <DstEdge> ("src").first ();
  }

  //
  // dst_of_SrcEdge
  //
  size_t GraphVertex_Impl::dst_of_SrcEdge (std::vector <SrcEdge> & items) const
  {
    return this->in_connections <SrcEdge> (items);
  }

  //
  // has_dst_of_SrcEdge
  //
  bool GraphVertex_Impl::has_dst_of_SrcEdge (void) const
  {
    return this->in_connections <SrcEdge> ("dst").count () == 1;
  }

  //
  // dst_of_SrcEdge
  //
  SrcEdge GraphVertex_Impl::dst_of_SrcEdge (void) const
  {
    return this->in_connections <SrcEdge> ("dst").first ();
  }
}

