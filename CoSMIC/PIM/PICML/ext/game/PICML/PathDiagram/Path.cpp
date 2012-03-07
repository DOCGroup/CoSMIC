// $Id$

#include "StdAfx.h"
#include "Path.h"

#if !defined (__GAME_INLINE__)
#include "Path.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/Common/Property.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Path_Impl::metaname ("Path");

  //
  // _create (const Paths_in)
  //
  Path Path_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create_object < Path > (parent, Path_Impl::metaname);
  }

  //
  // accept
  //
  void Path_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Path (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // src_PathProperty
  //
  size_t Path_Impl::src_PathProperty (std::vector <PathProperty> & items) const
  {
    return this->in_connections <PathProperty> (items);
  }

  //
  // get_ComponentRefs
  //
  size_t Path_Impl::get_ComponentRefs (std::vector <ComponentRef> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentRefs
  //
  ::GAME::Mga::Iterator <ComponentRef> Path_Impl::get_ComponentRefs (void) const
  {
    return this->children <ComponentRef> ();
  }

  //
  // get_Propertys
  //
  size_t Path_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> Path_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }

  //
  // get_DstEdges
  //
  size_t Path_Impl::get_DstEdges (std::vector <DstEdge> & items) const
  {
    return this->children (items);
  }

  //
  // get_DstEdges
  //
  ::GAME::Mga::Iterator <DstEdge> Path_Impl::get_DstEdges (void) const
  {
    return this->children <DstEdge> ();
  }

  //
  // get_GraphVertexs
  //
  size_t Path_Impl::get_GraphVertexs (std::vector <GraphVertex> & items) const
  {
    return this->children (items);
  }

  //
  // get_GraphVertexs
  //
  ::GAME::Mga::Iterator <GraphVertex> Path_Impl::get_GraphVertexs (void) const
  {
    return this->children <GraphVertex> ();
  }

  //
  // get_SrcEdges
  //
  size_t Path_Impl::get_SrcEdges (std::vector <SrcEdge> & items) const
  {
    return this->children (items);
  }

  //
  // get_SrcEdges
  //
  ::GAME::Mga::Iterator <SrcEdge> Path_Impl::get_SrcEdges (void) const
  {
    return this->children <SrcEdge> ();
  }

  //
  // get_EdgePropertys
  //
  size_t Path_Impl::get_EdgePropertys (std::vector <EdgeProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_EdgePropertys
  //
  ::GAME::Mga::Iterator <EdgeProperty> Path_Impl::get_EdgePropertys (void) const
  {
    return this->children <EdgeProperty> ();
  }

  //
  // get_Edges
  //
  size_t Path_Impl::get_Edges (std::vector <Edge> & items) const
  {
    return this->children (items);
  }

  //
  // get_Edges
  //
  ::GAME::Mga::Iterator <Edge> Path_Impl::get_Edges (void) const
  {
    return this->children <Edge> ();
  }
}

