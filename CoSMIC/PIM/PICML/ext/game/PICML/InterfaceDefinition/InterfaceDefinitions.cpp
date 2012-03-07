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
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  InterfaceDefinitions InterfaceDefinitions_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <InterfaceDefinitions> (parent, InterfaceDefinitions_Impl::metaname);
  }

  //
  // accept
  //
  void InterfaceDefinitions_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_InterfaceDefinitions (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_Files
  //
  size_t InterfaceDefinitions_Impl::get_Files (std::vector <File> & items) const
  {
    return this->children (items);
  }
}

