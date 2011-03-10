// $Id$

#include "stdafx.h"
#include "DataValueContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/DataValueBase.h"
#include "PICML/Common/ComplexTypeReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataValueContainer_Impl::metaname = "DataValueContainer";

  //
  // DataValueContainer_Impl
  //
  DataValueContainer_Impl::DataValueContainer_Impl (void)
  {
  }

  //
  // DataValueContainer_Impl
  //
  DataValueContainer_Impl::DataValueContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataValueContainer_Impl
  //
  DataValueContainer_Impl::~DataValueContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void DataValueContainer_Impl::accept (Visitor * v)
  {
    v->visit_DataValueContainer (this);
  }

  //
  // get_DataValueBases
  //
  size_t DataValueContainer_Impl::get_DataValueBases (std::vector <DataValueBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexTypeReference
  //
  ComplexTypeReference DataValueContainer_Impl::get_ComplexTypeReference (void) const
  {
    // Get the collection of children.
    std::vector <ComplexTypeReference> items;
    this->children (items);

    return !items.empty () ? items.front () : ComplexTypeReference ();
  }
}

