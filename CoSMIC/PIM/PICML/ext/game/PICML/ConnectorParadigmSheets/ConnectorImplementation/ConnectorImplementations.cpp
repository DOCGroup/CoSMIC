// $Id$

#include "StdAfx.h"
#include "ConnectorImplementations.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorImplementations.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementations_Impl::metaname ("ConnectorImplementations");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ConnectorImplementations ConnectorImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <ConnectorImplementations> (parent, ConnectorImplementations_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorImplementations_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorImplementations (this);
    else
      v->visit_Folder (this);
  }

  //
  // get_ConnectorImplementationContainers
  //
  size_t ConnectorImplementations_Impl::get_ConnectorImplementationContainers (std::vector <ConnectorImplementationContainer> & items) const
  {
    return this->children (items);
  }
}

