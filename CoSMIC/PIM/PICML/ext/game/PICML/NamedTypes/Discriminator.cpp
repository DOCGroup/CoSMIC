// $Id$

#include "stdafx.h"
#include "Discriminator.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/InterfaceDefinition/ConstantType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Discriminator_Impl::metaname = "Discriminator";

  //
  // Discriminator_Impl
  //
  Discriminator_Impl::Discriminator_Impl (void)
  {
  }

  //
  // Discriminator_Impl
  //
  Discriminator_Impl::Discriminator_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Discriminator_Impl
  //
  Discriminator_Impl::~Discriminator_Impl (void)
  {
  }

  //
  // accept
  //
  void Discriminator_Impl::accept (Visitor * v)
  {
    v->visit_Discriminator (this);
  }

  //
  // _create
  //
  Discriminator Discriminator_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object <Discriminator> (parent, Discriminator_Impl::metaname);
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate Discriminator_Impl::parent_SwitchedAggregate (void) const
  {
    return ::GAME::Mga::get_parent <SwitchedAggregate> (this->object_.p);
  }
}

