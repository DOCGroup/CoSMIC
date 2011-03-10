// $Id$

#include "stdafx.h"
#include "Collection.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Collection_Impl::metaname = "Collection";

  //
  // Collection_Impl
  //
  Collection_Impl::Collection_Impl (void)
  {
  }

  //
  // Collection_Impl
  //
  Collection_Impl::Collection_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Collection_Impl
  //
  Collection_Impl::~Collection_Impl (void)
  {
  }

  //
  // accept
  //
  void Collection_Impl::accept (Visitor * v)
  {
    v->visit_Collection (this);
  }

  //
  // bound
  //
  void Collection_Impl::bound (const std::string & val)
  {
    static const std::string attr_bound ("bound");
    this->attribute (attr_bound)->string_value (val);
  }

  //
  // bound
  //
  std::string Collection_Impl::bound (void) const
  {
    static const std::string attr_bound ("bound");
    return this->attribute (attr_bound)->string_value ();
  }

  //
  // refers_to_MemberType
  //
  MemberType Collection_Impl::refers_to_MemberType (void) const
  {
    return ::GAME::Mga::get_refers_to <MemberType> (this);
  }
}

