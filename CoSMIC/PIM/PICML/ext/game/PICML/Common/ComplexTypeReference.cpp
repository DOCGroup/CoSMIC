// $Id$

#include "StdAfx.h"
#include "ComplexTypeReference.h"

#if !defined (__GAME_INLINE__)
#include "ComplexTypeReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/DataValueContainer.h"
#include "PICML/Common/ComplexType.h"
#include "PICML/Common/ComplexProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComplexTypeReference_Impl::metaname ("ComplexTypeReference");

  //
  // _create (const DataValueContainer_in)
  //
  ComplexTypeReference ComplexTypeReference_Impl::_create (const DataValueContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComplexTypeReference > (parent, ComplexTypeReference_Impl::metaname);
  }

  //
  // _create (const ComplexProperty_in)
  //
  ComplexTypeReference ComplexTypeReference_Impl::_create (const ComplexProperty_in parent)
  {
    return ::GAME::Mga::create_object < ComplexTypeReference > (parent, ComplexTypeReference_Impl::metaname);
  }

  //
  // accept
  //
  void ComplexTypeReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComplexTypeReference (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // ComplexType_is_nil
  //
  bool ComplexTypeReference_Impl::ComplexType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ComplexType
  //
  ComplexType ComplexTypeReference_Impl::get_ComplexType (void) const
  {
    return ComplexType::_narrow (this->refers_to ());
  }
}

