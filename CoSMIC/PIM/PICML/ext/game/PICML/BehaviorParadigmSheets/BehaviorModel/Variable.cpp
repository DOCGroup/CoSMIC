// $Id$

#include "stdafx.h"
#include "Variable.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/PredefinedTypes/PredefinedType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Variable_Impl::metaname = "Variable";

  //
  // Variable_Impl
  //
  Variable_Impl::Variable_Impl (void)
  {
  }

  //
  // Variable_Impl
  //
  Variable_Impl::Variable_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Variable_Impl
  //
  Variable_Impl::~Variable_Impl (void)
  {
  }

  //
  // accept
  //
  void Variable_Impl::accept (Visitor * v)
  {
    v->visit_Variable (this);
  }

  //
  // _create
  //
  Variable Variable_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object <Variable> (parent, Variable_Impl::metaname);
  }

  //
  // InitialValue
  //
  void Variable_Impl::InitialValue (const std::string & val)
  {
    static const std::string attr_InitialValue ("InitialValue");
    this->attribute (attr_InitialValue)->string_value (val);
  }

  //
  // InitialValue
  //
  std::string Variable_Impl::InitialValue (void) const
  {
    static const std::string attr_InitialValue ("InitialValue");
    return this->attribute (attr_InitialValue)->string_value ();
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel Variable_Impl::parent_BehaviorModel (void) const
  {
    return ::GAME::Mga::get_parent <BehaviorModel> (this->object_.p);
  }
}

