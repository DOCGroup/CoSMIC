// $Id$

#include "StdAfx.h"
#include "ComponentImplementations.h"

#if !defined (__GAME_INLINE__)
#include "ComponentImplementations.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementations_Impl::metaname ("ComponentImplementations");

  //
  // is_abstract
  //
  const bool ComponentImplementations_Impl::is_abstract = false;

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentImplementations ComponentImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <ComponentImplementations> (parent, ComponentImplementations_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentImplementations_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentImplementations (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder ComponentImplementations_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_ComponentImplementationContainers
  //
  size_t ComponentImplementations_Impl::get_ComponentImplementationContainers (std::vector <ComponentImplementationContainer> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentImplementationContainers
  //
  ::GAME::Mga::Collection_T <ComponentImplementationContainer> ComponentImplementations_Impl::get_ComponentImplementationContainers (void) const
  {
    return this->children <ComponentImplementationContainer> ();
  }
}

