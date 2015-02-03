// $Id$

#include "StdAfx.h"
#include "InterfaceDefinitions.h"

#if !defined (__GAME_INLINE__)
#include "InterfaceDefinitions.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InterfaceDefinitions_Impl::metaname ("InterfaceDefinitions");

  //
  // is_abstract
  //
  const bool InterfaceDefinitions_Impl::is_abstract (0);

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  InterfaceDefinitions InterfaceDefinitions_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <InterfaceDefinitions> (parent, InterfaceDefinitions_Impl::metaname);
  }

  //
  // accept
  //
  void InterfaceDefinitions_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InterfaceDefinitions (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder InterfaceDefinitions_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_Files
  //
  size_t InterfaceDefinitions_Impl::get_Files (std::vector <File> & items) const
  {
    return this->children (items);
  }

  //
  // get_Files
  //
  ::GAME::Mga::Collection_T <File> InterfaceDefinitions_Impl::get_Files (void) const
  {
    return this->children <File> ();
  }
}

