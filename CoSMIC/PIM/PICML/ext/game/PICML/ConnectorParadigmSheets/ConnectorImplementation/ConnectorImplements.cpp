// $Id$

#include "StdAfx.h"
#include "ConnectorImplements.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorImplements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplements_Impl::metaname ("ConnectorImplements");

  //
  // _create (const ConnectorImplementationContainer_in)
  //
  ConnectorImplements ConnectorImplements_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ConnectorImplements > (parent, ConnectorImplements_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorImplements_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ConnectorImplements (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // ConnectorImplementation
  //
  ConnectorImplementation ConnectorImplements_Impl::src_ConnectorImplementation (void) const
  {
    return ConnectorImplementation::_narrow (this->src ());
  }

  //
  // ConnectorType
  //
  ConnectorType ConnectorImplements_Impl::dst_ConnectorType (void) const
  {
    return ConnectorType::_narrow (this->dst ());
  }
}

