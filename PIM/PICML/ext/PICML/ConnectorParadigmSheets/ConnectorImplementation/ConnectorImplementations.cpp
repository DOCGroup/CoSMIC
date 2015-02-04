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
  // is_abstract
  //
  const bool ConnectorImplementations_Impl::is_abstract = false;

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ConnectorImplementations ConnectorImplementations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <ConnectorImplementations> (parent, ConnectorImplementations_Impl::metaname);
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
  // parent_RootFolder (void)
  //
  RootFolder ConnectorImplementations_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_ConnectorImplementationContainers
  //
  size_t ConnectorImplementations_Impl::get_ConnectorImplementationContainers (std::vector <ConnectorImplementationContainer> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorImplementationContainers
  //
  ::GAME::Mga::Collection_T <ConnectorImplementationContainer> ConnectorImplementations_Impl::get_ConnectorImplementationContainers (void) const
  {
    return this->children <ConnectorImplementationContainer> ();
  }
}

