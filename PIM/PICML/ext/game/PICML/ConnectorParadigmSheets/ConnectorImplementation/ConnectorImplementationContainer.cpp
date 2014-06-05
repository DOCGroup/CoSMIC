// $Id$

#include "StdAfx.h"
#include "ConnectorImplementationContainer.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorImplementationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementations.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementationContainer_Impl::metaname ("ConnectorImplementationContainer");

  //
  // _create (const ConnectorImplementations_in)
  //
  ConnectorImplementationContainer ConnectorImplementationContainer_Impl::_create (const ConnectorImplementations_in parent)
  {
    return ::GAME::Mga::create_root_object < ConnectorImplementationContainer > (parent, ConnectorImplementationContainer_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorImplementationContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorImplementationContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ConnectorImplementations
  //
  ConnectorImplementations ConnectorImplementationContainer_Impl::parent_ConnectorImplementations (void)
  {
    return ConnectorImplementations::_narrow (this->parent ());
  }

  //
  // get_ConnectorImplementations
  //
  size_t ConnectorImplementationContainer_Impl::get_ConnectorImplementations (std::vector <ConnectorImplementation> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorImplementations
  //
  ::GAME::Mga::Collection_T <ConnectorImplementation> ConnectorImplementationContainer_Impl::get_ConnectorImplementations (void) const
  {
    return this->children <ConnectorImplementation> ();
  }

  //
  // get_ConnectorImplementss
  //
  size_t ConnectorImplementationContainer_Impl::get_ConnectorImplementss (std::vector <ConnectorImplements> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorImplementss
  //
  ::GAME::Mga::Collection_T <ConnectorImplements> ConnectorImplementationContainer_Impl::get_ConnectorImplementss (void) const
  {
    return this->children <ConnectorImplements> ();
  }

  //
  // get_ConnectorTypes
  //
  size_t ConnectorImplementationContainer_Impl::get_ConnectorTypes (std::vector <ConnectorType> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorTypes
  //
  ::GAME::Mga::Collection_T <ConnectorType> ConnectorImplementationContainer_Impl::get_ConnectorTypes (void) const
  {
    return this->children <ConnectorType> ();
  }
}

