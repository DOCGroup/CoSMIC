#include "StdAfx.h"
#include "ConnectorImplementationType.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorImplementationType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementationType_Impl::metaname ("ConnectorImplementationType");

  //
  // is_abstract
  //
  const bool ConnectorImplementationType_Impl::is_abstract = false;

  //
  // _create (const ConnectorInstance_in)
  //
  ConnectorImplementationType ConnectorImplementationType_Impl::_create (const ConnectorInstance_in parent)
  {
    return ::GAME::Mga::create < ConnectorImplementationType > (parent, ConnectorImplementationType_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorImplementationType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorImplementationType (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ConnectorInstance
  //
  ConnectorInstance ConnectorImplementationType_Impl::parent_ConnectorInstance (void)
  {
    return ConnectorInstance::_narrow (this->parent ());
  }

  //
  // ConnectorImplementation_is_nil
  //
  bool ConnectorImplementationType_Impl::ConnectorImplementation_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_ConnectorImplementation
  //
  void ConnectorImplementationType_Impl::refers_to_ConnectorImplementation (ConnectorImplementation_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ConnectorImplementation
  //
  ConnectorImplementation ConnectorImplementationType_Impl::refers_to_ConnectorImplementation (void) const
  {
    return ConnectorImplementation::_narrow (this->refers_to ());
  }
}

