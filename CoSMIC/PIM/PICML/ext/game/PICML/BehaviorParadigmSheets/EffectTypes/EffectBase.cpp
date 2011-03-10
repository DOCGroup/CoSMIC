// $Id$

#include "stdafx.h"
#include "EffectBase.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EffectBase_Impl::metaname = "EffectBase";

  //
  // EffectBase_Impl
  //
  EffectBase_Impl::EffectBase_Impl (void)
  {
  }

  //
  // EffectBase_Impl
  //
  EffectBase_Impl::EffectBase_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EffectBase_Impl
  //
  EffectBase_Impl::~EffectBase_Impl (void)
  {
  }

  //
  // Postcondition
  //
  void EffectBase_Impl::Postcondition (const std::string & val)
  {
    static const std::string attr_Postcondition ("Postcondition");
    this->attribute (attr_Postcondition)->string_value (val);
  }

  //
  // Postcondition
  //
  std::string EffectBase_Impl::Postcondition (void) const
  {
    static const std::string attr_Postcondition ("Postcondition");
    return this->attribute (attr_Postcondition)->string_value ();
  }
}

