// $Id$

#include "stdafx.h"
#include "ECBehavior.h"

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
  const std::string ECBehavior_Impl::metaname = "ECBehavior";

  //
  // ECBehavior_Impl
  //
  ECBehavior_Impl::ECBehavior_Impl (void)
  {
  }

  //
  // ECBehavior_Impl
  //
  ECBehavior_Impl::ECBehavior_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ECBehavior_Impl
  //
  ECBehavior_Impl::~ECBehavior_Impl (void)
  {
  }

  //
  // accept
  //
  void ECBehavior_Impl::accept (Visitor * v)
  {
    v->visit_ECBehavior (this);
  }

  //
  // _create
  //
  ECBehavior ECBehavior_Impl::_create (const ECRequirements_in parent)
  {
    return ::GAME::Mga::create_object <ECBehavior> (parent, ECBehavior_Impl::metaname);
  }

  //
  // MultithreadedSupplier
  //
  void ECBehavior_Impl::MultithreadedSupplier (bool val)
  {
    static const std::string attr_MultithreadedSupplier ("MultithreadedSupplier");
    this->attribute (attr_MultithreadedSupplier)->bool_value (val);
  }

  //
  // MultithreadedSupplier
  //
  bool ECBehavior_Impl::MultithreadedSupplier (void) const
  {
    static const std::string attr_MultithreadedSupplier ("MultithreadedSupplier");
    return this->attribute (attr_MultithreadedSupplier)->bool_value ();
  }

  //
  // DispatchingMultithreadingLevel
  //
  void ECBehavior_Impl::DispatchingMultithreadingLevel (long val)
  {
    static const std::string attr_DispatchingMultithreadingLevel ("DispatchingMultithreadingLevel");
    this->attribute (attr_DispatchingMultithreadingLevel)->int_value (val);
  }

  //
  // DispatchingMultithreadingLevel
  //
  long ECBehavior_Impl::DispatchingMultithreadingLevel (void) const
  {
    static const std::string attr_DispatchingMultithreadingLevel ("DispatchingMultithreadingLevel");
    return this->attribute (attr_DispatchingMultithreadingLevel)->int_value ();
  }

  //
  // MultithreadedConsumer
  //
  void ECBehavior_Impl::MultithreadedConsumer (bool val)
  {
    static const std::string attr_MultithreadedConsumer ("MultithreadedConsumer");
    this->attribute (attr_MultithreadedConsumer)->bool_value (val);
  }

  //
  // MultithreadedConsumer
  //
  bool ECBehavior_Impl::MultithreadedConsumer (void) const
  {
    static const std::string attr_MultithreadedConsumer ("MultithreadedConsumer");
    return this->attribute (attr_MultithreadedConsumer)->bool_value ();
  }

  //
  // DisconnectDanglingConnections
  //
  void ECBehavior_Impl::DisconnectDanglingConnections (bool val)
  {
    static const std::string attr_DisconnectDanglingConnections ("DisconnectDanglingConnections");
    this->attribute (attr_DisconnectDanglingConnections)->bool_value (val);
  }

  //
  // DisconnectDanglingConnections
  //
  bool ECBehavior_Impl::DisconnectDanglingConnections (void) const
  {
    static const std::string attr_DisconnectDanglingConnections ("DisconnectDanglingConnections");
    return this->attribute (attr_DisconnectDanglingConnections)->bool_value ();
  }

  //
  // ConsumerBasedFiltering
  //
  void ECBehavior_Impl::ConsumerBasedFiltering (bool val)
  {
    static const std::string attr_ConsumerBasedFiltering ("ConsumerBasedFiltering");
    this->attribute (attr_ConsumerBasedFiltering)->bool_value (val);
  }

  //
  // ConsumerBasedFiltering
  //
  bool ECBehavior_Impl::ConsumerBasedFiltering (void) const
  {
    static const std::string attr_ConsumerBasedFiltering ("ConsumerBasedFiltering");
    return this->attribute (attr_ConsumerBasedFiltering)->bool_value ();
  }

  //
  // SupplierBasedFiltering
  //
  void ECBehavior_Impl::SupplierBasedFiltering (bool val)
  {
    static const std::string attr_SupplierBasedFiltering ("SupplierBasedFiltering");
    this->attribute (attr_SupplierBasedFiltering)->bool_value (val);
  }

  //
  // SupplierBasedFiltering
  //
  bool ECBehavior_Impl::SupplierBasedFiltering (void) const
  {
    static const std::string attr_SupplierBasedFiltering ("SupplierBasedFiltering");
    return this->attribute (attr_SupplierBasedFiltering)->bool_value ();
  }

  //
  // parent_ECRequirements
  //
  ECRequirements ECBehavior_Impl::parent_ECRequirements (void) const
  {
    return ::GAME::Mga::get_parent <ECRequirements> (this->object_.p);
  }
}

