// $Id$

#include "StdAfx.h"
#include "ConnectedComponent.h"

#if !defined (__GAME_INLINE__)
#include "ConnectedComponent.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/PathDiagram/DstEdge.h"
#include "PICML/PathDiagram/Path.h"
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
    return ::GAME::Mga::create < ConnectedComponent > (parent, ConnectedComponent_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectedComponent_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectedComponent (this);
    else
      v->visit_Model (this);
  }

  //
  // get_RequiredRequestPorts
  //
  size_t ConnectedComponent_Impl::get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPorts
  //
  ::GAME::Mga::Collection_T <RequiredRequestPort> ConnectedComponent_Impl::get_RequiredRequestPorts (void) const
  {
    return this->children <RequiredRequestPort> ();
  }

  //
  // get_ProvidedRequestPorts
  //
  size_t ConnectedComponent_Impl::get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPorts
  //
  ::GAME::Mga::Collection_T <ProvidedRequestPort> ConnectedComponent_Impl::get_ProvidedRequestPorts (void) const
  {
    return this->children <ProvidedRequestPort> ();
  }

  //
  // get_InEventPorts
  //
  size_t ConnectedComponent_Impl::get_InEventPorts (std::vector <InEventPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_InEventPorts
  //
  ::GAME::Mga::Collection_T <InEventPort> ConnectedComponent_Impl::get_InEventPorts (void) const
  {
    return this->children <InEventPort> ();
  }

  //
  // get_OutEventPorts
  //
  size_t ConnectedComponent_Impl::get_OutEventPorts (std::vector <OutEventPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutEventPorts
  //
  ::GAME::Mga::Collection_T <OutEventPort> ConnectedComponent_Impl::get_OutEventPorts (void) const
  {
    return this->children <OutEventPort> ();
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
  ::GAME::Mga::Collection_T <DstEdge> ConnectedComponent_Impl::get_DstEdges (void) const
  {
    return this->children <DstEdge> ();
  }
}

