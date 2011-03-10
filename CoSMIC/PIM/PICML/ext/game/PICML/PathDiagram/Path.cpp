// $Id$

#include "stdafx.h"
#include "Path.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/Common/Property.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/PathDiagram/PathReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Path_Impl::metaname = "Path";

  //
  // Path_Impl
  //
  Path_Impl::Path_Impl (void)
  {
  }

  //
  // Path_Impl
  //
  Path_Impl::Path_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Path_Impl
  //
  Path_Impl::~Path_Impl (void)
  {
  }

  //
  // accept
  //
  void Path_Impl::accept (Visitor * v)
  {
    v->visit_Path (this);
  }

  //
  // _create
  //
  Path Path_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create_object <Path> (parent, Path_Impl::metaname);
  }

  //
  // in_PathProperty_connections
  //
  size_t Path_Impl::in_PathProperty_connections (std::vector <PathProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // get_SrcEdges
  //
  size_t Path_Impl::get_SrcEdges (std::vector <SrcEdge> & items) const
  {
    return this->children (items);
  }

  //
  // get_Edges
  //
  size_t Path_Impl::get_Edges (std::vector <Edge> & items) const
  {
    return this->children (items);
  }

  //
  // get_EdgePropertys
  //
  size_t Path_Impl::get_EdgePropertys (std::vector <EdgeProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_GraphVertexs
  //
  size_t Path_Impl::get_GraphVertexs (std::vector <GraphVertex> & items) const
  {
    return this->children (items);
  }

  //
  // get_DstEdges
  //
  size_t Path_Impl::get_DstEdges (std::vector <DstEdge> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t Path_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  size_t Path_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // parent_Paths
  //
  Paths Path_Impl::parent_Paths (void) const
  {
    return ::GAME::Mga::get_parent <Paths> (this->object_.p);
  }
}

