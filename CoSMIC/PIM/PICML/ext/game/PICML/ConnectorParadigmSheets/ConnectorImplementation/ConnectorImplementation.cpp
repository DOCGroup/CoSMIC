// $Id$

#include "StdAfx.h"
#include "ConnectorImplementation.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorImplementation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorImplementationType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementation_Impl::metaname ("ConnectorImplementation");

  //
  // _create (const ConnectorImplementationContainer_in)
  //
  ConnectorImplementation ConnectorImplementation_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ConnectorImplementation > (parent, ConnectorImplementation_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorImplementation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorImplementation (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ConnectorImplementationContainer
  //
  ConnectorImplementationContainer ConnectorImplementation_Impl::parent_ConnectorImplementationContainer (void)
  {
    return ConnectorImplementationContainer::_narrow (this->parent ());
  }

  //
  // src_ConnectorImplements
  //
  size_t ConnectorImplementation_Impl::src_ConnectorImplements (std::vector <ConnectorImplements> & items) const
  {
    return this->in_connections <ConnectorImplements> (items);
  }
}

