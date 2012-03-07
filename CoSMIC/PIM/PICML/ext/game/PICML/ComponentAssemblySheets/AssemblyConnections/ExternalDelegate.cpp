// $Id$

#include "StdAfx.h"
#include "ExternalDelegate.h"

#if !defined (__GAME_INLINE__)
#include "ExternalDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalPortEnd.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ExternalPort.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalDelegate_Impl::metaname ("ExternalDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  ExternalDelegate ExternalDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ExternalDelegate > (parent, ExternalDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void ExternalDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ExternalDelegate (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // ExternalPort
  //
  ExternalPort ExternalDelegate_Impl::src_ExternalPort (void) const
  {
    return ExternalPort::_narrow (this->src ());
  }

  //
  // ExternalPortEnd
  //
  ExternalPortEnd ExternalDelegate_Impl::dst_ExternalPortEnd (void) const
  {
    return ExternalPortEnd::_narrow (this->dst ());
  }
}

