// $Id$

#include "StdAfx.h"
#include "CollectionParameter.h"

#if !defined (__GAME_INLINE__)
#include "CollectionParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CollectionParameter_Impl::metaname ("CollectionParameter");

  //
  // _create (const Package_in)
  //
  CollectionParameter CollectionParameter_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < CollectionParameter > (parent, CollectionParameter_Impl::metaname);
  }

  //
  // accept
  //
  void CollectionParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_CollectionParameter (this);
    else
      v->visit_Reference (this);
  }

  //
  // NameParameter_is_nil
  //
  bool CollectionParameter_Impl::NameParameter_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_NameParameter
  //
  void CollectionParameter_Impl::refers_to_NameParameter (NameParameter_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_NameParameter
  //
  NameParameter CollectionParameter_Impl::refers_to_NameParameter (void) const
  {
    return NameParameter::_narrow (this->refers_to ());
  }
}

