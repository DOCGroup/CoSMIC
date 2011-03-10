// $Id$

#include "stdafx.h"
#include "MakeMemberPrivate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/InheritableTypes/PrivateFlag.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MakeMemberPrivate_Impl::metaname = "MakeMemberPrivate";

  //
  // MakeMemberPrivate_Impl
  //
  MakeMemberPrivate_Impl::MakeMemberPrivate_Impl (void)
  {
  }

  //
  // MakeMemberPrivate_Impl
  //
  MakeMemberPrivate_Impl::MakeMemberPrivate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MakeMemberPrivate_Impl
  //
  MakeMemberPrivate_Impl::~MakeMemberPrivate_Impl (void)
  {
  }

  //
  // accept
  //
  void MakeMemberPrivate_Impl::accept (Visitor * v)
  {
    v->visit_MakeMemberPrivate (this);
  }

  //
  // _create
  //
  MakeMemberPrivate MakeMemberPrivate_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create_object <MakeMemberPrivate> (parent, MakeMemberPrivate_Impl::metaname);
  }

  //
  // src_Member
  //
  Member MakeMemberPrivate_Impl::src_Member (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Member::_narrow (target);
  }

  //
  // dst_PrivateFlag
  //
  PrivateFlag MakeMemberPrivate_Impl::dst_PrivateFlag (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return PrivateFlag::_narrow (target);
  }

  //
  // parent_ObjectByValue
  //
  ObjectByValue MakeMemberPrivate_Impl::parent_ObjectByValue (void) const
  {
    return ::GAME::Mga::get_parent <ObjectByValue> (this->object_.p);
  }
}

