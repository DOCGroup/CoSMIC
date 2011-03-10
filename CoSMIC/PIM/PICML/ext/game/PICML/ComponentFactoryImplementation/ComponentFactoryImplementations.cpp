// $Id$

#include "stdafx.h"
#include "ComponentFactoryImplementations.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryImplementations_Impl::metaname = "ComponentFactoryImplementations";

  //
  // ComponentFactoryImplementations_Impl
  //
  ComponentFactoryImplementations_Impl::ComponentFactoryImplementations_Impl (void)
  {
  }

  //
  // ComponentFactoryImplementations_Impl
  //
  ComponentFactoryImplementations_Impl::ComponentFactoryImplementations_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryImplementations_Impl
  //
  ComponentFactoryImplementations_Impl::~ComponentFactoryImplementations_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentFactoryImplementations_Impl::accept (Visitor * v)
  {
    v->visit_ComponentFactoryImplementations (this);
  }

  //
  // _create
  //
  ComponentFactoryImplementations ComponentFactoryImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentFactoryImplementations> (parent, ComponentFactoryImplementations_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ComponentFactoryImplementations_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

