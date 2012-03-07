// $Id$

#include "StdAfx.h"
#include "ConnectorType.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplements.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorType_Impl::metaname ("ConnectorType");

  //
  // _create (const ConnectorImplementationContainer_in)
  //
  ConnectorType ConnectorType_Impl::_create (const ConnectorImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ConnectorType > (parent, ConnectorType_Impl::metaname);
  }

  //
  // accept
  //
  void ConnectorType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ConnectorType (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // dst_ConnectorImplements
  //
  size_t ConnectorType_Impl::dst_ConnectorImplements (std::vector <ConnectorImplements> & items) const
  {
    return this->in_connections <ConnectorImplements> (items);
  }

  //
  // ConnectorObject_is_nil
  //
  bool ConnectorType_Impl::ConnectorObject_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ConnectorObject
  //
  ConnectorObject ConnectorType_Impl::get_ConnectorObject (void) const
  {
    return ConnectorObject::_narrow (this->refers_to ());
  }
}

