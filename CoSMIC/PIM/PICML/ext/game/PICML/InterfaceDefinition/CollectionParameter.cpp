// $Id$

#include "StdAfx.h"
#include "CollectionParameter.h"

#if !defined (__GAME_INLINE__)
#include "CollectionParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
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
    return ::GAME::Mga::create_object < CollectionParameter > (parent, CollectionParameter_Impl::metaname);
  }

  //
  // accept
  //
  void CollectionParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_CollectionParameter (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // NameParameter_is_nil
  //
  bool CollectionParameter_Impl::NameParameter_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_NameParameter
  //
  NameParameter CollectionParameter_Impl::get_NameParameter (void) const
  {
    return NameParameter::_narrow (this->refers_to ());
  }
}

