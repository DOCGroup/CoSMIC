#include "StdAfx.h"
#include "Supports.h"

#if !defined (__GAME_INLINE__)
#include "Supports.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Supports_Impl::metaname ("Supports");

  //
  // is_abstract
  //
  const bool Supports_Impl::is_abstract = false;

  //
  // _create (const SupportsInterfaces_in)
  //
  Supports Supports_Impl::_create (const SupportsInterfaces_in parent)
  {
    return ::GAME::Mga::create < Supports > (parent, Supports_Impl::metaname);
  }

  //
  // accept
  //
  void Supports_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Supports (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_SupportsInterfaces
  //
  SupportsInterfaces Supports_Impl::parent_SupportsInterfaces (void)
  {
    return SupportsInterfaces::_narrow (this->parent ());
  }

  //
  // Object_is_nil
  //
  bool Supports_Impl::Object_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_Object
  //
  void Supports_Impl::refers_to_Object (Object_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Object
  //
  Object Supports_Impl::refers_to_Object (void) const
  {
    return Object::_narrow (this->refers_to ());
  }
}

