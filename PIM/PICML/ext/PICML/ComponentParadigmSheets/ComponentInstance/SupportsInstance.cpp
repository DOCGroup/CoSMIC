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
  // is_abstract
  //
  const bool SupportsInstance_Impl::is_abstract = false;

  //
  // _create (const ComponentInstance_in)
  //
  SupportsInstance SupportsInstance_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create < SupportsInstance > (parent, SupportsInstance_Impl::metaname);
  }

  //
  // accept
  //
  void SupportsInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SupportsInstance (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentInstance
  //
  ComponentInstance SupportsInstance_Impl::parent_ComponentInstance (void)
  {
    return ComponentInstance::_narrow (this->parent ());
  }

  //
  // Supports_is_nil
  //
  bool SupportsInstance_Impl::Supports_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_Supports
  //
  void SupportsInstance_Impl::refers_to_Supports (Supports_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Supports
  //
  Supports SupportsInstance_Impl::refers_to_Supports (void) const
  {
    return Supports::_narrow (this->refers_to ());
  }
}

