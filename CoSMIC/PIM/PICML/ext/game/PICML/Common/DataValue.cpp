// $Id$

#include "StdAfx.h"
#include "DataValue.h"

#if !defined (__GAME_INLINE__)
#include "DataValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/DataValueContainer.h"
#include "PICML/Common/SimpleType.h"
#include "PICML/Common/ComplexProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DataValue_Impl::metaname ("DataValue");

  //
  // _create (const DataValueContainer_in)
  //
  DataValue DataValue_Impl::_create (const DataValueContainer_in parent)
  {
    return ::GAME::Mga::create_object < DataValue > (parent, DataValue_Impl::metaname);
  }

  //
  // _create (const ComplexProperty_in)
  //
  DataValue DataValue_Impl::_create (const ComplexProperty_in parent)
  {
    return ::GAME::Mga::create_object < DataValue > (parent, DataValue_Impl::metaname);
  }

  //
  // accept
  //
  void DataValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DataValue (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // SimpleType_is_nil
  //
  bool DataValue_Impl::SimpleType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_SimpleType
  //
  SimpleType DataValue_Impl::get_SimpleType (void) const
  {
    return SimpleType::_narrow (this->refers_to ());
  }
}

