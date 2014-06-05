// $Id$

#include "StdAfx.h"
#include "ComplexTypeReference.h"

#if !defined (__GAME_INLINE__)
#include "ComplexTypeReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/ComplexType.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/Common/DataValueContainer.h"
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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComplexTypeReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_DataValueContainer
  //
  DataValueContainer ComplexTypeReference_Impl::parent_DataValueContainer (void)
  {
    return DataValueContainer::_narrow (this->parent ());
  }

  //
  // parent_ComplexProperty
  //
  ComplexProperty ComplexTypeReference_Impl::parent_ComplexProperty (void)
  {
    return ComplexProperty::_narrow (this->parent ());
  }

  //
  // ComplexType_is_nil
  //
  bool ComplexTypeReference_Impl::ComplexType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ComplexType
  //
  void ComplexTypeReference_Impl::set_ComplexType (ComplexType_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ComplexType
  //
  ComplexType ComplexTypeReference_Impl::get_ComplexType (void) const
  {
    return ComplexType::_narrow (this->refers_to ());
  }
}

