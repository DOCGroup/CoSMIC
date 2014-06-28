// $Id$

#include "StdAfx.h"
#include "ComponentTypes.h"

#if !defined (__GAME_INLINE__)
#include "ComponentTypes.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentTypes_Impl::metaname ("ComponentTypes");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentTypes ComponentTypes_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <ComponentTypes> (parent, ComponentTypes_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentTypes_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentTypes (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder ComponentTypes_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_ComponentContainers
  //
  size_t ComponentTypes_Impl::get_ComponentContainers (std::vector <ComponentContainer> & items) const
  {
    return this->children (items);
  }
}

