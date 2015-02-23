// $Id$

#include "StdAfx.h"
#include "Implemenation.h"

#if !defined (__GAME_INLINE__)
#include "Implemenation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/ImplementationCommon/InfoProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Implemenation_Impl::metaname ("Implemenation");

  //
  // is_abstract
  //
  const bool Implemenation_Impl::is_abstract = true;

  //
  // src_of_ConfigProperty
  //
  size_t Implemenation_Impl::src_of_ConfigProperty (std::vector <ConfigProperty> & items) const
  {
    return this->in_connections <ConfigProperty> (items);
  }

  //
  // src_of_ConfigProperty
  //
  GAME::Mga::Collection_T <ConfigProperty> Implemenation_Impl::src_of_ConfigProperty (void) const
  {
    return this->in_connections <ConfigProperty> ("src");
  }

  //
  // src_of_InfoProperty
  //
  size_t Implemenation_Impl::src_of_InfoProperty (std::vector <InfoProperty> & items) const
  {
    return this->in_connections <InfoProperty> (items);
  }

  //
  // src_of_InfoProperty
  //
  GAME::Mga::Collection_T <InfoProperty> Implemenation_Impl::src_of_InfoProperty (void) const
  {
    return this->in_connections <InfoProperty> ("src");
  }
}

