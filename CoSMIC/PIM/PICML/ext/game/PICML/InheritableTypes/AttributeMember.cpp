// $Id$

#include "StdAfx.h"
#include "AttributeMember.h"

#if !defined (__GAME_INLINE__)
#include "AttributeMember.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMember_Impl::metaname ("AttributeMember");

  //
  // _create (const ReadonlyAttribute_in)
  //
  AttributeMember AttributeMember_Impl::_create (const ReadonlyAttribute_in parent)
  {
    return ::GAME::Mga::create_object < AttributeMember > (parent, AttributeMember_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeMember_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeMember (this);
    else
      v->visit_Reference (this);
  }

  //
  // MemberType_is_nil
  //
  bool AttributeMember_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MemberType
  //
  MemberType AttributeMember_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

