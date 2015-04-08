#include "StdAfx.h"
#include "PrivateFlag.h"

#if !defined (__GAME_INLINE__)
#include "PrivateFlag.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PrivateFlag_Impl::metaname ("PrivateFlag");

  //
  // is_abstract
  //
  const bool PrivateFlag_Impl::is_abstract = false;

  //
  // _create (const ObjectByValue_in)
  //
  PrivateFlag PrivateFlag_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create < PrivateFlag > (parent, PrivateFlag_Impl::metaname);
  }

  //
  // accept
  //
  void PrivateFlag_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PrivateFlag (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ObjectByValue
  //
  ObjectByValue PrivateFlag_Impl::parent_ObjectByValue (void)
  {
    return ObjectByValue::_narrow (this->parent ());
  }

  //
  // dst_of_MakeMemberPrivate
  //
  size_t PrivateFlag_Impl::dst_of_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const
  {
    return this->in_connections <MakeMemberPrivate> (items);
  }

  //
  // dst_of_MakeMemberPrivate
  //
  MakeMemberPrivate PrivateFlag_Impl::dst_of_MakeMemberPrivate (void) const
  {
    return this->in_connections <MakeMemberPrivate> ("dst").first ();
  }
}

