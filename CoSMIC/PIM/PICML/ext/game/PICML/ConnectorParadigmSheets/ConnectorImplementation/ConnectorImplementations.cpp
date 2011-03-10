// $Id$

#include "stdafx.h"
#include "ConnectorImplementations.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementations_Impl::metaname = "ConnectorImplementations";

  //
  // ConnectorImplementations_Impl
  //
  ConnectorImplementations_Impl::ConnectorImplementations_Impl (void)
  {
  }

  //
  // ConnectorImplementations_Impl
  //
  ConnectorImplementations_Impl::ConnectorImplementations_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorImplementations_Impl
  //
  ConnectorImplementations_Impl::~ConnectorImplementations_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorImplementations_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorImplementations (this);
  }

  //
  // _create
  //
  ConnectorImplementations ConnectorImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ConnectorImplementations> (parent, ConnectorImplementations_Impl::metaname);
  }

  ::GAME::Mga::RootFolder ConnectorImplementations_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

