// $Id$

#include "stdafx.h"
#include "ConnectorImplementationContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementations.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementationContainer_Impl::metaname = "ConnectorImplementationContainer";

  //
  // ConnectorImplementationContainer_Impl
  //
  ConnectorImplementationContainer_Impl::ConnectorImplementationContainer_Impl (void)
  {
  }

  //
  // ConnectorImplementationContainer_Impl
  //
  ConnectorImplementationContainer_Impl::ConnectorImplementationContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorImplementationContainer_Impl
  //
  ConnectorImplementationContainer_Impl::~ConnectorImplementationContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorImplementationContainer_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorImplementationContainer (this);
  }

  //
  // _create
  //
  ConnectorImplementationContainer ConnectorImplementationContainer_Impl::_create (const ConnectorImplementations_in parent)
  {
    return ::GAME::Mga::create_root_object <ConnectorImplementationContainer> (parent, ConnectorImplementationContainer_Impl::metaname);
  }

  //
  // get_ConnectorTypes
  //
  size_t ConnectorImplementationContainer_Impl::get_ConnectorTypes (std::vector <ConnectorType> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorImplementss
  //
  size_t ConnectorImplementationContainer_Impl::get_ConnectorImplementss (std::vector <ConnectorImplements> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConnectorImplementations
  //
  size_t ConnectorImplementationContainer_Impl::get_ConnectorImplementations (std::vector <ConnectorImplementation> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ConnectorImplementations
  //
  ConnectorImplementations ConnectorImplementationContainer_Impl::parent_ConnectorImplementations (void) const
  {
    return ::GAME::Mga::get_parent <ConnectorImplementations> (this->object_.p);
  }
}

