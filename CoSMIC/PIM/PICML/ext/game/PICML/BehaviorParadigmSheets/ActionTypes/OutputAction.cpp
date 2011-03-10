// $Id$

#include "stdafx.h"
#include "OutputAction.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutputAction_Impl::metaname = "OutputAction";

  //
  // OutputAction_Impl
  //
  OutputAction_Impl::OutputAction_Impl (void)
  {
  }

  //
  // OutputAction_Impl
  //
  OutputAction_Impl::OutputAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutputAction_Impl
  //
  OutputAction_Impl::~OutputAction_Impl (void)
  {
  }

  //
  // accept
  //
  void OutputAction_Impl::accept (Visitor * v)
  {
    v->visit_OutputAction (this);
  }
}

