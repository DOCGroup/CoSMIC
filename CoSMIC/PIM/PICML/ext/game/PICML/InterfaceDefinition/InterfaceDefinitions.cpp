// $Id$

#include "stdafx.h"
#include "InterfaceDefinitions.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string InterfaceDefinitions_Impl::metaname = "InterfaceDefinitions";

  //
  // InterfaceDefinitions_Impl
  //
  InterfaceDefinitions_Impl::InterfaceDefinitions_Impl (void)
  {
  }

  //
  // InterfaceDefinitions_Impl
  //
  InterfaceDefinitions_Impl::InterfaceDefinitions_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~InterfaceDefinitions_Impl
  //
  InterfaceDefinitions_Impl::~InterfaceDefinitions_Impl (void)
  {
  }

  //
  // accept
  //
  void InterfaceDefinitions_Impl::accept (Visitor * v)
  {
    v->visit_InterfaceDefinitions (this);
  }

  //
  // _create
  //
  InterfaceDefinitions InterfaceDefinitions_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <InterfaceDefinitions> (parent, InterfaceDefinitions_Impl::metaname);
  }

  ::GAME::Mga::RootFolder InterfaceDefinitions_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

