// $Id$

#include "StdAfx.h"
#include "RequirementBase.h"

#if !defined (__GAME_INLINE__)
#include "RequirementBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequirementBase_Impl::metaname ("RequirementBase");

  //
  // is_abstract
  //
  const bool RequirementBase_Impl::is_abstract (1);

  //
  // get_ComplexPropertys
  //
  size_t RequirementBase_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> RequirementBase_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t RequirementBase_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> RequirementBase_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }
}

