// $Id$

#include "StdAfx.h"
#include "DataValueContainer.h"

#if !defined (__GAME_INLINE__)
#include "DataValueContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/ComplexTypeReference.h"
#include "PICML/Common/DataValueBase.h"
#include "PICML/Common/ComplexProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DataValueContainer_Impl::metaname ("DataValueContainer");

  //
  // _create (const ComplexProperty_in)
  //
  DataValueContainer DataValueContainer_Impl::_create (const ComplexProperty_in parent)
  {
    return ::GAME::Mga::create_object < DataValueContainer > (parent, DataValueContainer_Impl::metaname);
  }

  //
  // accept
  //
  void DataValueContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DataValueContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // get_ComplexTypeReference
  //
  ComplexTypeReference DataValueContainer_Impl::get_ComplexTypeReference (void) const
  {
    return this->children <ComplexTypeReference> ().item ();
  }

  //
  // get_DataValueBases
  //
  size_t DataValueContainer_Impl::get_DataValueBases (std::vector <DataValueBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataValueBases
  //
  ::GAME::Mga::Iterator <DataValueBase> DataValueContainer_Impl::get_DataValueBases (void) const
  {
    return this->children <DataValueBase> ();
  }
}

