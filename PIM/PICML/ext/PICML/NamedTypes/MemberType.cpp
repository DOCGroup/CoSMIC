// $Id$

#include "StdAfx.h"
#include "MemberType.h"

#if !defined (__GAME_INLINE__)
#include "MemberType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "PICML/OperationTypes/ParameterType.h"
#include "PICML/OperationTypes/InParameter.h"
#include "PICML/OperationTypes/InoutParameter.h"
#include "PICML/OperationTypes/OutParameter.h"
#include "PICML/Common/DataType.h"
#include "PICML/InheritableTypes/AttributeMember.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MemberType_Impl::metaname ("MemberType");
}

