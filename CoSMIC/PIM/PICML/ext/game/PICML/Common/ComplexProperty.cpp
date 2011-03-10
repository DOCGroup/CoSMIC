// $Id$

#include "stdafx.h"
#include "ComplexProperty.h"

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
  const std::string ComplexProperty_Impl::metaname = "ComplexProperty";

  //
  // ComplexProperty_Impl
  //
  ComplexProperty_Impl::ComplexProperty_Impl (void)
  {
  }

  //
  // ComplexProperty_Impl
  //
  ComplexProperty_Impl::ComplexProperty_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComplexProperty_Impl
  //
  ComplexProperty_Impl::~ComplexProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void ComplexProperty_Impl::accept (Visitor * v)
  {
    v->visit_ComplexProperty (this);
  }

  //
  // get_DataValueBases
  //
  size_t ComplexProperty_Impl::get_DataValueBases (std::vector <DataValueBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexTypeReference
  //
  ComplexTypeReference ComplexProperty_Impl::get_ComplexTypeReference (void) const
  {
    // Get the collection of children.
    std::vector <ComplexTypeReference> items;
    this->children (items);

    return !items.empty () ? items.front () : ComplexTypeReference ();
  }
}

