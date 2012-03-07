// $Id$

#include "StdAfx.h"
#include "ExternalPort.h"

#if !defined (__GAME_INLINE__)
#include "ExternalPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExternalDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExternalPort_Impl::metaname ("ExternalPort");

  //
  // _create (const ComponentAssembly_in)
  //
  ExternalPort ExternalPort_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ExternalPort > (parent, ExternalPort_Impl::metaname);
  }

  //
  // accept
  //
  void ExternalPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ExternalPort (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // src_ExternalDelegate
  //
  size_t ExternalPort_Impl::src_ExternalDelegate (std::vector <ExternalDelegate> & items) const
  {
    return this->in_connections <ExternalDelegate> (items);
  }
}

