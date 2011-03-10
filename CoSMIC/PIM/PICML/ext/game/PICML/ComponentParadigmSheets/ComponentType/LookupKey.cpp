// $Id$

#include "stdafx.h"
#include "LookupKey.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/ComponentParadigmSheets/ComponentType/LookupKeyType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LookupKey_Impl::metaname = "LookupKey";

  //
  // LookupKey_Impl
  //
  LookupKey_Impl::LookupKey_Impl (void)
  {
  }

  //
  // LookupKey_Impl
  //
  LookupKey_Impl::LookupKey_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LookupKey_Impl
  //
  LookupKey_Impl::~LookupKey_Impl (void)
  {
  }

  //
  // accept
  //
  void LookupKey_Impl::accept (Visitor * v)
  {
    v->visit_LookupKey (this);
  }

  //
  // _create
  //
  LookupKey LookupKey_Impl::_create (const ComponentFactory_in parent)
  {
    return ::GAME::Mga::create_object <LookupKey> (parent, LookupKey_Impl::metaname);
  }

  //
  // parent_ComponentFactory
  //
  ComponentFactory LookupKey_Impl::parent_ComponentFactory (void) const
  {
    return ::GAME::Mga::get_parent <ComponentFactory> (this->object_.p);
  }

  //
  // refers_to_LookupKeyType
  //
  LookupKeyType LookupKey_Impl::refers_to_LookupKeyType (void) const
  {
    return ::GAME::Mga::get_refers_to <LookupKeyType> (this);
  }
}

