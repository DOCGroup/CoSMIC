// $Id$

#include "StdAfx.h"
#include "LookupKey.h"

#if !defined (__GAME_INLINE__)
#include "LookupKey.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/LookupKeyType.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string LookupKey_Impl::metaname ("LookupKey");

  //
  // _create (const ComponentFactory_in)
  //
  LookupKey LookupKey_Impl::_create (const ComponentFactory_in parent)
  {
    return ::GAME::Mga::create_object < LookupKey > (parent, LookupKey_Impl::metaname);
  }

  //
  // accept
  //
  void LookupKey_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LookupKey (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentFactory
  //
  ComponentFactory LookupKey_Impl::parent_ComponentFactory (void)
  {
    return ComponentFactory::_narrow (this->parent ());
  }

  //
  // LookupKeyType_is_nil
  //
  bool LookupKey_Impl::LookupKeyType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_LookupKeyType
  //
  void LookupKey_Impl::set_LookupKeyType (LookupKeyType_in item)
  {
    this->refers_to (item);
  }

  //
  // get_LookupKeyType
  //
  LookupKeyType LookupKey_Impl::get_LookupKeyType (void) const
  {
    return LookupKeyType::_narrow (this->refers_to ());
  }
}

