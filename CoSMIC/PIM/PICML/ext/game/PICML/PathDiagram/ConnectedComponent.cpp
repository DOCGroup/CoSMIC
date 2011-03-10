// $Id$

#include "stdafx.h"
#include "ConnectedComponent.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/PathDiagram/DstEdge.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectedComponent_Impl::metaname = "ConnectedComponent";

  //
  // ConnectedComponent_Impl
  //
  ConnectedComponent_Impl::ConnectedComponent_Impl (void)
  {
  }

  //
  // ConnectedComponent_Impl
  //
  ConnectedComponent_Impl::ConnectedComponent_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectedComponent_Impl
  //
  ConnectedComponent_Impl::~ConnectedComponent_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectedComponent_Impl::accept (Visitor * v)
  {
    v->visit_ConnectedComponent (this);
  }

  //
  // get_Ports
  //
  size_t ConnectedComponent_Impl::get_Ports (std::vector <Port> & items) const
  {
    return this->children (items);
  }

  //
  // get_DstEdges
  //
  size_t ConnectedComponent_Impl::get_DstEdges (std::vector <DstEdge> & items) const
  {
    return this->children (items);
  }
}

