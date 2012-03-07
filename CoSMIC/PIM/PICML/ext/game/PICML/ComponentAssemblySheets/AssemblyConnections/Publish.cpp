// $Id$

#include "StdAfx.h"
#include "Publish.h"

#if !defined (__GAME_INLINE__)
#include "Publish.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendPortEnd.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Publish_Impl::metaname ("Publish");

  //
  // _create (const ComponentAssembly_in)
  //
  Publish Publish_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < Publish > (parent, Publish_Impl::metaname);
  }

  //
  // accept
  //
  void Publish_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Publish (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // ExtendPortEnd
  //
  ExtendPortEnd Publish_Impl::src_ExtendPortEnd (void) const
  {
    return ExtendPortEnd::_narrow (this->src ());
  }

  //
  // ConnectorInstance
  //
  ConnectorInstance Publish_Impl::dst_ConnectorInstance (void) const
  {
    return ConnectorInstance::_narrow (this->dst ());
  }
}

