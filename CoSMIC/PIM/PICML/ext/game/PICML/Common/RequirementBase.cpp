// $Id$

#include "StdAfx.h"
#include "RequirementBase.h"

#if !defined (__GAME_INLINE__)
#include "RequirementBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequirementBase_Impl::metaname ("RequirementBase");

  //
  // get_Propertys
  //
  size_t RequirementBase_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> RequirementBase_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }
}

