// $Id$

#include "StdAfx.h"
#include "Edge.h"

#if !defined (__GAME_INLINE__)
#include "Edge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
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
  // _create (const Path_in)
  //
  Edge Edge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < Edge > (parent, Edge_Impl::metaname);
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
  // src_SrcEdge
  //
  size_t Edge_Impl::src_SrcEdge (std::vector <SrcEdge> & items) const
  {
    return this->in_connections <SrcEdge> (items);
  }

  //
  // dst_DstEdge
  //
  size_t Edge_Impl::dst_DstEdge (std::vector <DstEdge> & items) const
  {
    return this->in_connections <DstEdge> (items);
  }

  //
  // dst_EdgeProperty
  //
  size_t Edge_Impl::dst_EdgeProperty (std::vector <EdgeProperty> & items) const
  {
    return this->in_connections <EdgeProperty> (items);
  }
}

