// $Id$

#include "stdafx.h"
#include "ECRole.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ECRole_Impl::metaname = "ECRole";

  //
  // ECRole_Impl
  //
  ECRole_Impl::ECRole_Impl (void)
  {
  }

  //
  // ECRole_Impl
  //
  ECRole_Impl::ECRole_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ECRole_Impl
  //
  ECRole_Impl::~ECRole_Impl (void)
  {
  }

  //
  // accept
  //
  void ECRole_Impl::accept (Visitor * v)
  {
    v->visit_ECRole (this);
  }

  //
  // _create
  //
  ECRole ECRole_Impl::_create (const ECRequirements_in parent)
  {
    return ::GAME::Mga::create_object <ECRole> (parent, ECRole_Impl::metaname);
  }

  //
  // rolekind
  //
  void ECRole_Impl::rolekind (const std::string & val)
  {
    static const std::string attr_rolekind ("rolekind");
    this->attribute (attr_rolekind)->string_value (val);
  }

  //
  // rolekind
  //
  std::string ECRole_Impl::rolekind (void) const
  {
    static const std::string attr_rolekind ("rolekind");
    return this->attribute (attr_rolekind)->string_value ();
  }

  //
  // ECFilterType
  //
  void ECRole_Impl::ECFilterType (const std::string & val)
  {
    static const std::string attr_ECFilterType ("ECFilterType");
    this->attribute (attr_ECFilterType)->string_value (val);
  }

  //
  // ECFilterType
  //
  std::string ECRole_Impl::ECFilterType (void) const
  {
    static const std::string attr_ECFilterType ("ECFilterType");
    return this->attribute (attr_ECFilterType)->string_value ();
  }

  //
  // parent_ECRequirements
  //
  ECRequirements ECRole_Impl::parent_ECRequirements (void) const
  {
    return ::GAME::Mga::get_parent <ECRequirements> (this->object_.p);
  }
}

