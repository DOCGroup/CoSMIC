// $Id$

#include "stdafx.h"
#include "ECRequirements.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/EventChannelRequirements/ECBehavior.h"
#include "PICML/EventChannelRequirements/ECRole.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ECRequirements_Impl::metaname = "ECRequirements";

  //
  // ECRequirements_Impl
  //
  ECRequirements_Impl::ECRequirements_Impl (void)
  {
  }

  //
  // ECRequirements_Impl
  //
  ECRequirements_Impl::ECRequirements_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ECRequirements_Impl
  //
  ECRequirements_Impl::~ECRequirements_Impl (void)
  {
  }

  //
  // accept
  //
  void ECRequirements_Impl::accept (Visitor * v)
  {
    v->visit_ECRequirements (this);
  }

  //
  // ConfigureRTQoS
  //
  void ECRequirements_Impl::ConfigureRTQoS (bool val)
  {
    static const std::string attr_ConfigureRTQoS ("ConfigureRTQoS");
    this->attribute (attr_ConfigureRTQoS)->bool_value (val);
  }

  //
  // ConfigureRTQoS
  //
  bool ECRequirements_Impl::ConfigureRTQoS (void) const
  {
    static const std::string attr_ConfigureRTQoS ("ConfigureRTQoS");
    return this->attribute (attr_ConfigureRTQoS)->bool_value ();
  }

  //
  // get_ECBehavior
  //
  ECBehavior ECRequirements_Impl::get_ECBehavior (void) const
  {
    // Get the collection of children.
    std::vector <ECBehavior> items;
    this->children (items);

    return !items.empty () ? items.front () : ECBehavior ();
  }

  //
  // get_ECRoles
  //
  size_t ECRequirements_Impl::get_ECRoles (std::vector <ECRole> & items) const
  {
    return this->children (items);
  }
}

