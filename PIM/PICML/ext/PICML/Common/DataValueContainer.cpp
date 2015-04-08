#include "StdAfx.h"
#include "DataValueContainer.h"

#if !defined (__GAME_INLINE__)
#include "DataValueContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/DataValueBase.h"
#include "PICML/Common/DataValue.h"
#include "PICML/Common/DataValueContainer.h"
#include "PICML/Common/ComplexTypeReference.h"
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
  // is_abstract
  //
  const bool DataValueContainer_Impl::is_abstract = false;

  //
  // _create (const ComplexProperty_in)
  //
  DataValueContainer DataValueContainer_Impl::_create (const ComplexProperty_in parent)
  {
    return ::GAME::Mga::create < DataValueContainer > (parent, DataValueContainer_Impl::metaname);
  }

  //
  // _create (const DataValueContainer_in)
  //
  DataValueContainer DataValueContainer_Impl::_create (const DataValueContainer_in parent)
  {
    return ::GAME::Mga::create < DataValueContainer > (parent, DataValueContainer_Impl::metaname);
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
  // has_ComplexTypeReference
  //
  bool DataValueContainer_Impl::has_ComplexTypeReference (void) const
  {
    return this->children <ComplexTypeReference> ().count () == 1;
  }

  //
  // get_ComplexTypeReference
  //
  ComplexTypeReference DataValueContainer_Impl::get_ComplexTypeReference (void) const
  {
    return this->children <ComplexTypeReference> ().first ();
  }

  //
  // get_DataValues
  //
  size_t DataValueContainer_Impl::get_DataValues (std::vector <DataValue> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataValues
  //
  ::GAME::Mga::Collection_T <DataValue> DataValueContainer_Impl::get_DataValues (void) const
  {
    return this->children <DataValue> ();
  }

  //
  // get_DataValueContainers
  //
  size_t DataValueContainer_Impl::get_DataValueContainers (std::vector <DataValueContainer> & items) const
  {
    return this->children (items);
  }

  //
  // get_DataValueContainers
  //
  ::GAME::Mga::Collection_T <DataValueContainer> DataValueContainer_Impl::get_DataValueContainers (void) const
  {
    return this->children <DataValueContainer> ();
  }
}

