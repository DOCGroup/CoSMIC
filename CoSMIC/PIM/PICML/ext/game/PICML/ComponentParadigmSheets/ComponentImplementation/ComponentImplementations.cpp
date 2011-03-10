// $Id$

#include "stdafx.h"
#include "ComponentImplementations.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementations_Impl::metaname = "ComponentImplementations";

  //
  // ComponentImplementations_Impl
  //
  ComponentImplementations_Impl::ComponentImplementations_Impl (void)
  {
  }

  //
  // ComponentImplementations_Impl
  //
  ComponentImplementations_Impl::ComponentImplementations_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementations_Impl
  //
  ComponentImplementations_Impl::~ComponentImplementations_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentImplementations_Impl::accept (Visitor * v)
  {
    v->visit_ComponentImplementations (this);
  }

  //
  // _create
  //
  ComponentImplementations ComponentImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentImplementations> (parent, ComponentImplementations_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ComponentImplementations_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

