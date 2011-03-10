// $Id$

#include "stdafx.h"
#include "Taggable.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Taggable_Impl::metaname = "Taggable";

  //
  // Taggable_Impl
  //
  Taggable_Impl::Taggable_Impl (void)
  {
  }

  //
  // Taggable_Impl
  //
  Taggable_Impl::Taggable_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Taggable_Impl
  //
  Taggable_Impl::~Taggable_Impl (void)
  {
  }

  //
  // VersionTag
  //
  void Taggable_Impl::VersionTag (const std::string & val)
  {
    static const std::string attr_VersionTag ("VersionTag");
    this->attribute (attr_VersionTag)->string_value (val);
  }

  //
  // VersionTag
  //
  std::string Taggable_Impl::VersionTag (void) const
  {
    static const std::string attr_VersionTag ("VersionTag");
    return this->attribute (attr_VersionTag)->string_value ();
  }

  //
  // SpecifyIdTag
  //
  void Taggable_Impl::SpecifyIdTag (const std::string & val)
  {
    static const std::string attr_SpecifyIdTag ("SpecifyIdTag");
    this->attribute (attr_SpecifyIdTag)->string_value (val);
  }

  //
  // SpecifyIdTag
  //
  std::string Taggable_Impl::SpecifyIdTag (void) const
  {
    static const std::string attr_SpecifyIdTag ("SpecifyIdTag");
    return this->attribute (attr_SpecifyIdTag)->string_value ();
  }
}

