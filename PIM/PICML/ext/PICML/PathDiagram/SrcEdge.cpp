// $Id$

#include "StdAfx.h"
#include "SrcEdge.h"

#if !defined (__GAME_INLINE__)
#include "SrcEdge.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Edge.h"
#include "PICML/PathDiagram/GraphVertex.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/PathDiagram/DisplayNode.h"
#include "PICML/PathDiagram/Path.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SrcEdge_Impl::metaname ("SrcEdge");

  //
  // _create (const Path_in)
  //
  SrcEdge SrcEdge_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < SrcEdge > (parent, SrcEdge_Impl::metaname);
  }

  //
  // accept
  //
  void SrcEdge_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SrcEdge (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Path
  //
  Path SrcEdge_Impl::parent_Path (void)
  {
    return Path::_narrow (this->parent ());
  }

  //
  // Edge
  //
  Edge SrcEdge_Impl::src_Edge (void) const
  {
    return Edge::_narrow (this->src ());
  }

  //
  // GraphVertex
  //
  GraphVertex SrcEdge_Impl::dst_GraphVertex (void) const
  {
    return GraphVertex::_narrow (this->dst ());
  }
}

