// $Id$

#include "stdafx.h"
#include "ComponentTypes.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentTypes_Impl::metaname = "ComponentTypes";

  //
  // ComponentTypes_Impl
  //
  ComponentTypes_Impl::ComponentTypes_Impl (void)
  {
  }

  //
  // ComponentTypes_Impl
  //
  ComponentTypes_Impl::ComponentTypes_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentTypes_Impl
  //
  ComponentTypes_Impl::~ComponentTypes_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentTypes_Impl::accept (Visitor * v)
  {
    v->visit_ComponentTypes (this);
  }

  //
  // _create
  //
  ComponentTypes ComponentTypes_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentTypes> (parent, ComponentTypes_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ComponentTypes_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

