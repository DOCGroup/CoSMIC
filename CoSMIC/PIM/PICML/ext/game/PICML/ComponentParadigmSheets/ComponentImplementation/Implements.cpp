// $Id$

#include "StdAfx.h"
#include "Implements.h"

#if !defined (__GAME_INLINE__)
#include "Implements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Implements_Impl::metaname ("Implements");

  //
  // _create (const ComponentImplementationContainer_in)
  //
  Implements Implements_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < Implements > (parent, Implements_Impl::metaname);
  }

  //
  // accept
  //
  void Implements_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Implements (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // ComponentImplementation
  //
  ComponentImplementation Implements_Impl::src_ComponentImplementation (void) const
  {
    return ComponentImplementation::_narrow (this->src ());
  }

  //
  // ComponentRef
  //
  ComponentRef Implements_Impl::dst_ComponentRef (void) const
  {
    return ComponentRef::_narrow (this->dst ());
  }
}

