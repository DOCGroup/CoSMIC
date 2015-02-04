// $Id$

#include "StdAfx.h"
#include "Path.h"

#if !defined (__GAME_INLINE__)
#include "Path.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/PathDiagram/DisplayNode.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/PathDiagram/SrcEdge.h"
#include "PICML/PathDiagram/EdgeProperty.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/PathReference.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
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
  // is_abstract
  //
  const bool Path_Impl::is_abstract = false;

  //
  // _create (const Paths_in)
  //
  Path Path_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create < Path > (parent, Path_Impl::metaname);
  }

  //
  // accept
  //
  void Path_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Path (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Paths
  //
  Paths Path_Impl::parent_Paths (void)
  {
    return Paths::_narrow (this->parent ());
  }

  //
  // src_of_PathProperty
  //
  size_t Path_Impl::src_of_PathProperty (std::vector <PathProperty> & items) const
  {
    return this->in_connections <PathProperty> (items);
  }

  //
  // src_of_PathProperty
  //
  GAME::Mga::Collection_T <PathProperty> Path_Impl::src_of_PathProperty (void) const
  {
    return this->in_connections <PathProperty> ("src");
  }

  //
  // get_DisplayNodes
  //
  size_t Path_Impl::get_DisplayNodes (std::vector <DisplayNode> & items) const
  {
    return this->children (items);
  }

  //
  // get_DisplayNodes
  //
  ::GAME::Mga::Collection_T <DisplayNode> Path_Impl::get_DisplayNodes (void) const
  {
    return this->children <DisplayNode> ();
  }

  //
  // get_ConnectedComponents
  //
  size_t Path_Impl::get_ConnectedComponents (std::vector <ConnectedComponent> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectedComponents
  //
  ::GAME::Mga::Collection_T <ConnectedComponent> Path_Impl::get_ConnectedComponents (void) const
  {
    return this->children <ConnectedComponent> ();
  }

  //
  // get_RequiredRequestPorts
  //
  size_t Path_Impl::get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPorts
  //
  ::GAME::Mga::Collection_T <RequiredRequestPort> Path_Impl::get_RequiredRequestPorts (void) const
  {
    return this->children <RequiredRequestPort> ();
  }

  //
  // get_ProvidedRequestPorts
  //
  size_t Path_Impl::get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPorts
  //
  ::GAME::Mga::Collection_T <ProvidedRequestPort> Path_Impl::get_ProvidedRequestPorts (void) const
  {
    return this->children <ProvidedRequestPort> ();
  }

  //
  // get_OutEventPorts
  //
  size_t Path_Impl::get_OutEventPorts (std::vector <OutEventPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutEventPorts
  //
  ::GAME::Mga::Collection_T <OutEventPort> Path_Impl::get_OutEventPorts (void) const
  {
    return this->children <OutEventPort> ();
  }

  //
  // get_InEventPorts
  //
  size_t Path_Impl::get_InEventPorts (std::vector <InEventPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_InEventPorts
  //
  ::GAME::Mga::Collection_T <InEventPort> Path_Impl::get_InEventPorts (void) const
  {
    return this->children <InEventPort> ();
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
  ::GAME::Mga::Collection_T <Edge> Path_Impl::get_Edges (void) const
  {
    return this->children <Edge> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t Path_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> Path_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t Path_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> Path_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
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
  ::GAME::Mga::Collection_T <SrcEdge> Path_Impl::get_SrcEdges (void) const
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
  ::GAME::Mga::Collection_T <EdgeProperty> Path_Impl::get_EdgePropertys (void) const
  {
    return this->children <EdgeProperty> ();
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
  ::GAME::Mga::Collection_T <DstEdge> Path_Impl::get_DstEdges (void) const
  {
    return this->children <DstEdge> ();
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
  ::GAME::Mga::Collection_T <ComponentRef> Path_Impl::get_ComponentRefs (void) const
  {
    return this->children <ComponentRef> ();
  }
}

