// $Id$

#include "StdAfx.h"
#include "ParameterType.h"

#if !defined (__GAME_INLINE__)
#include "ParameterType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ParameterType_Impl::metaname ("ParameterType");

  //
  // MemberType_is_nil
  //
  bool ParameterType_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType ParameterType_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

