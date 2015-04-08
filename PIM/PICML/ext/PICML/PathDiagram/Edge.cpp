#include "StdAfx.h"
#include "Edge.h"

#if !defined (__GAME_INLINE__)
#include "Edge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/Path.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Edge_Impl::metaname ("Edge");

  //
  // is_abstract
  //
  const bool Edge_Impl::is_abstract = false;

  //
  // _create (const Path_in)
  //
  Edge Edge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create < Edge > (parent, Edge_Impl::metaname);
  }

  //
  // accept
  //
  void Edge_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Edge (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_Path
  //
  Path Edge_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
  }

  //
  // src_of_SrcEdge
  //
  size_t Edge_Impl::src_of_SrcEdge (std::vector <SrcEdge> & items) const
  {
    return this->in_connections <SrcEdge> (items);
  }

  //
  // has_src_of_SrcEdge
  //
  bool Edge_Impl::has_src_of_SrcEdge (void) const
  {
    return this->in_connections <SrcEdge> ("src").count () == 1;
  }

  //
  // src_of_SrcEdge
  //
  SrcEdge Edge_Impl::src_of_SrcEdge (void) const
  {
    return this->in_connections <SrcEdge> ("src").first ();
  }

  //
  // dst_of_DstEdge
  //
  size_t Edge_Impl::dst_of_DstEdge (std::vector <DstEdge> & items) const
  {
    return this->in_connections <DstEdge> (items);
  }

  //
  // has_dst_of_DstEdge
  //
  bool Edge_Impl::has_dst_of_DstEdge (void) const
  {
    return this->in_connections <DstEdge> ("dst").count () == 1;
  }

  //
  // dst_of_DstEdge
  //
  DstEdge Edge_Impl::dst_of_DstEdge (void) const
  {
    return this->in_connections <DstEdge> ("dst").first ();
  }

  //
  // dst_of_EdgeProperty
  //
  size_t Edge_Impl::dst_of_EdgeProperty (std::vector <EdgeProperty> & items) const
  {
    return this->in_connections <EdgeProperty> (items);
  }

  //
  // has_dst_of_EdgeProperty
  //
  bool Edge_Impl::has_dst_of_EdgeProperty (void) const
  {
    return this->in_connections <EdgeProperty> ("dst").count () == 1;
  }

  //
  // dst_of_EdgeProperty
  //
  EdgeProperty Edge_Impl::dst_of_EdgeProperty (void) const
  {
    return this->in_connections <EdgeProperty> ("dst").first ();
  }
}

