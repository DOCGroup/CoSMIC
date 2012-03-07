// $Id$

#include "StdAfx.h"
#include "SupportsInstance.h"

#if !defined (__GAME_INLINE__)
#include "SupportsInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/InheritableTypes/Supports.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SupportsInstance_Impl::metaname ("SupportsInstance");

  //
  // _create (const ComponentInstance_in)
  //
  SupportsInstance SupportsInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < SupportsInstance > (parent, SupportsInstance_Impl::metaname);
  }

  //
  // accept
  //
  void SupportsInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_SupportsInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // Supports_is_nil
  //
  bool SupportsInstance_Impl::Supports_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_Supports
  //
  Supports SupportsInstance_Impl::get_Supports (void) const
  {
    return Supports::_narrow (this->refers_to ());
  }
}

