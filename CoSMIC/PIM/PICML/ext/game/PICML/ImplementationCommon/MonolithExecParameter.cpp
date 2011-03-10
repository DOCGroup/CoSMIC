// $Id$

#include "stdafx.h"
#include "MonolithExecParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithExecParameter_Impl::metaname = "MonolithExecParameter";

  //
  // MonolithExecParameter_Impl
  //
  MonolithExecParameter_Impl::MonolithExecParameter_Impl (void)
  {
  }

  //
  // MonolithExecParameter_Impl
  //
  MonolithExecParameter_Impl::MonolithExecParameter_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MonolithExecParameter_Impl
  //
  MonolithExecParameter_Impl::~MonolithExecParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void MonolithExecParameter_Impl::accept (Visitor * v)
  {
    v->visit_MonolithExecParameter (this);
  }

  //
  // _create
  //
  MonolithExecParameter MonolithExecParameter_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <MonolithExecParameter> (parent, MonolithExecParameter_Impl::metaname);
  }

  //
  // src_MonolithicImplementationBase
  //
  MonolithicImplementationBase MonolithExecParameter_Impl::src_MonolithicImplementationBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return MonolithicImplementationBase::_narrow (target);
  }

  //
  // dst_Property
  //
  Property MonolithExecParameter_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_ImplementationContainer
  //
  ImplementationContainer MonolithExecParameter_Impl::parent_ImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ImplementationContainer> (this->object_.p);
  }
}

