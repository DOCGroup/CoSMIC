// $Id$

#include "stdafx.h"
#include "MemberType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/NamedTypes/Collection.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MemberType_Impl::metaname = "MemberType";

  //
  // MemberType_Impl
  //
  MemberType_Impl::MemberType_Impl (void)
  {
  }

  //
  // MemberType_Impl
  //
  MemberType_Impl::MemberType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MemberType_Impl
  //
  MemberType_Impl::~MemberType_Impl (void)
  {
  }
}

