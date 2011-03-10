// $Id$

#include "stdafx.h"
#include "RequestAction.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequestAction_Impl::metaname = "RequestAction";

  //
  // RequestAction_Impl
  //
  RequestAction_Impl::RequestAction_Impl (void)
  {
  }

  //
  // RequestAction_Impl
  //
  RequestAction_Impl::RequestAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequestAction_Impl
  //
  RequestAction_Impl::~RequestAction_Impl (void)
  {
  }

  //
  // accept
  //
  void RequestAction_Impl::accept (Visitor * v)
  {
    v->visit_RequestAction (this);
  }

  //
  // MethodName
  //
  void RequestAction_Impl::MethodName (const std::string & val)
  {
    static const std::string attr_MethodName ("MethodName");
    this->attribute (attr_MethodName)->string_value (val);
  }

  //
  // MethodName
  //
  std::string RequestAction_Impl::MethodName (void) const
  {
    static const std::string attr_MethodName ("MethodName");
    return this->attribute (attr_MethodName)->string_value ();
  }
}

