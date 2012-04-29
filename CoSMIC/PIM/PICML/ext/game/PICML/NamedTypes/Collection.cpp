// $Id$

#include "StdAfx.h"
#include "Collection.h"

#if !defined (__GAME_INLINE__)
#include "Collection.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Collection_Impl::metaname ("Collection");

  //
  // _create (const ConnectorObject_in)
  //
  Collection Collection_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < Collection > (parent, Collection_Impl::metaname);
  }

  //
  // _create (const HasOperations_in)
  //
  Collection Collection_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < Collection > (parent, Collection_Impl::metaname);
  }

  //
  // accept
  //
  void Collection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Collection (this);
    else
      v->visit_Reference (this);
  }

  //
  // MemberType_is_nil
  //
  bool Collection_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType Collection_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

