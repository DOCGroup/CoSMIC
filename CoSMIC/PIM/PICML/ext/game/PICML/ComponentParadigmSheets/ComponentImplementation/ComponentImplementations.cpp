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
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentImplementations ComponentImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentImplementations> (parent, ComponentImplementations_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentImplementations_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentImplementations (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_ComponentImplementationContainers
  //
  size_t ComponentImplementations_Impl::get_ComponentImplementationContainers (std::vector <ComponentImplementationContainer> & items) const
  {
    return this->children (items);
  }
}

