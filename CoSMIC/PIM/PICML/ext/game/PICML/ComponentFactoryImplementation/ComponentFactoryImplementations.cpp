// $Id$

#include "StdAfx.h"
#include "ComponentFactoryImplementations.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactoryImplementations.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryImplementations_Impl::metaname ("ComponentFactoryImplementations");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentFactoryImplementations ComponentFactoryImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentFactoryImplementations> (parent, ComponentFactoryImplementations_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactoryImplementations_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentFactoryImplementations (this);
    else
      v->visit_Folder (this);
  }

  //
  // get_ComponentFactoryImplementationContainers
  //
  size_t ComponentFactoryImplementations_Impl::get_ComponentFactoryImplementationContainers (std::vector <ComponentFactoryImplementationContainer> & items) const
  {
    return this->children (items);
  }
}

