// $Id$

#include "StdAfx.h"
#include "DataType.h"

#if !defined (__GAME_INLINE__)
#include "DataType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentPropertyDescription.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/Common/SatisfierProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DataType_Impl::metaname ("DataType");

  //
  // _create (const ComponentPropertyDescription_in)
  //
  DataType DataType_Impl::_create (const ComponentPropertyDescription_in parent)
  {
    return ::GAME::Mga::create_object < DataType > (parent, DataType_Impl::metaname);
  }

  //
  // _create (const SatisfierProperty_in)
  //
  DataType DataType_Impl::_create (const SatisfierProperty_in parent)
  {
    return ::GAME::Mga::create_object < DataType > (parent, DataType_Impl::metaname);
  }

  //
  // accept
  //
  void DataType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DataType (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // MemberType_is_nil
  //
  bool DataType_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType DataType_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

