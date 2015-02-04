// $Id$

#include "StdAfx.h"
#include "Edge.h"

#if !defined (__GAME_INLINE__)
#include "Edge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/PathDiagram/DstEdge.h"
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
  // src_of_SrcEdge
  //
  GAME::Mga::Collection_T <SrcEdge> Edge_Impl::src_of_SrcEdge (void) const
  {
    return this->in_connections <SrcEdge> ("src");
  }

  //
  // dst_of_EdgeProperty
  //
  size_t Edge_Impl::dst_of_EdgeProperty (std::vector <EdgeProperty> & items) const
  {
    return this->in_connections <EdgeProperty> (items);
  }

  //
  // dst_of_EdgeProperty
  //
  GAME::Mga::Collection_T <EdgeProperty> Edge_Impl::dst_of_EdgeProperty (void) const
  {
    return this->in_connections <EdgeProperty> ("dst");
  }

  //
  // dst_of_DstEdge
  //
  size_t Edge_Impl::dst_of_DstEdge (std::vector <DstEdge> & items) const
  {
    return this->in_connections <DstEdge> (items);
  }

  //
  // dst_of_DstEdge
  //
  GAME::Mga::Collection_T <DstEdge> Edge_Impl::dst_of_DstEdge (void) const
  {
    return this->in_connections <DstEdge> ("dst");
  }
}

