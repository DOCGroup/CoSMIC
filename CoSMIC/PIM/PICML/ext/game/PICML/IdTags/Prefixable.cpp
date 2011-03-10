// $Id$

#include "stdafx.h"
#include "Prefixable.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Prefixable_Impl::metaname = "Prefixable";

  //
  // Prefixable_Impl
  //
  Prefixable_Impl::Prefixable_Impl (void)
  {
  }

  //
  // Prefixable_Impl
  //
  Prefixable_Impl::Prefixable_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Prefixable_Impl
  //
  Prefixable_Impl::~Prefixable_Impl (void)
  {
  }

  //
  // PrefixTag
  //
  void Prefixable_Impl::PrefixTag (const std::string & val)
  {
    static const std::string attr_PrefixTag ("PrefixTag");
    this->attribute (attr_PrefixTag)->string_value (val);
  }

  //
  // PrefixTag
  //
  std::string Prefixable_Impl::PrefixTag (void) const
  {
    static const std::string attr_PrefixTag ("PrefixTag");
    return this->attribute (attr_PrefixTag)->string_value ();
  }
}

