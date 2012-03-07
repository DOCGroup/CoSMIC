// $Id$

#include "StdAfx.h"
#include "ImplementationDependency.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationDependency.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationDependsOn.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationDependency_Impl::metaname ("ImplementationDependency");

  //
  // _create (const ComponentImplementationContainer_in)
  //
  ImplementationDependency ImplementationDependency_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationDependency > (parent, ImplementationDependency_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationDependency_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ImplementationDependency (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_ImplementationDependsOn
  //
  size_t ImplementationDependency_Impl::dst_ImplementationDependsOn (std::vector <ImplementationDependsOn> & items) const
  {
    return this->in_connections <ImplementationDependsOn> (items);
  }
}

