// $Id$

#include "StdAfx.h"
#include "ConnectedComponent.h"

#if !defined (__GAME_INLINE__)
#include "ConnectedComponent.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectedComponent_Impl::metaname ("ConnectedComponent");

  //
  // _create (const Path_in)
  //
  ConnectedComponent ConnectedComponent_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < ConnectedComponent > (parent, ConnectedComponent_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectedComponent_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ConnectedComponent (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_Ports
  //
  size_t ConnectedComponent_Impl::get_Ports (std::vector <Port> & items) const
  {
    return this->children (items);
  }

  //
  // get_Ports
  //
  ::GAME::Mga::Iterator <Port> ConnectedComponent_Impl::get_Ports (void) const
  {
    return this->children <Port> ();
  }

  //
  // get_DstEdges
  //
  size_t ConnectedComponent_Impl::get_DstEdges (std::vector <DstEdge> & items) const
  {
    return this->children (items);
  }

  //
  // get_DstEdges
  //
  ::GAME::Mga::Iterator <DstEdge> ConnectedComponent_Impl::get_DstEdges (void) const
  {
    return this->children <DstEdge> ();
  }
}

