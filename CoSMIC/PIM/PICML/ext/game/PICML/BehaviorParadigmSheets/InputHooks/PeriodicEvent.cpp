// $Id$

#include "stdafx.h"
#include "PeriodicEvent.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PeriodicEvent_Impl::metaname = "PeriodicEvent";

  //
  // PeriodicEvent_Impl
  //
  PeriodicEvent_Impl::PeriodicEvent_Impl (void)
  {
  }

  //
  // PeriodicEvent_Impl
  //
  PeriodicEvent_Impl::PeriodicEvent_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PeriodicEvent_Impl
  //
  PeriodicEvent_Impl::~PeriodicEvent_Impl (void)
  {
  }

  //
  // accept
  //
  void PeriodicEvent_Impl::accept (Visitor * v)
  {
    v->visit_PeriodicEvent (this);
  }

  //
  // Distribution
  //
  void PeriodicEvent_Impl::Distribution (const std::string & val)
  {
    static const std::string attr_Distribution ("Distribution");
    this->attribute (attr_Distribution)->string_value (val);
  }

  //
  // Distribution
  //
  std::string PeriodicEvent_Impl::Distribution (void) const
  {
    static const std::string attr_Distribution ("Distribution");
    return this->attribute (attr_Distribution)->string_value ();
  }

  //
  // Hertz
  //
  void PeriodicEvent_Impl::Hertz (const std::string & val)
  {
    static const std::string attr_Hertz ("Hertz");
    this->attribute (attr_Hertz)->string_value (val);
  }

  //
  // Hertz
  //
  std::string PeriodicEvent_Impl::Hertz (void) const
  {
    static const std::string attr_Hertz ("Hertz");
    return this->attribute (attr_Hertz)->string_value ();
  }
}

