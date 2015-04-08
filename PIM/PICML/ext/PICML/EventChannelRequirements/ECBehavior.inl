// -*- C++ -*-
namespace PICML
{
  //
  // ECBehavior_Impl
  //
  GAME_INLINE ECBehavior_Impl::ECBehavior_Impl (void)
  {
  }

  //
  // ECBehavior_Impl
  //
  GAME_INLINE ECBehavior_Impl::ECBehavior_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ECBehavior_Impl
  //
  GAME_INLINE ECBehavior_Impl::~ECBehavior_Impl (void)
  {
  }

  //
  // DispatchingMultithreadingLevel
  //
  GAME_INLINE void ECBehavior_Impl::DispatchingMultithreadingLevel (long val)
  {
    static const std::string attr_name ("DispatchingMultithreadingLevel");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // DispatchingMultithreadingLevel
  //
  GAME_INLINE long ECBehavior_Impl::DispatchingMultithreadingLevel (void) const
  {
    static const std::string attr_name ("DispatchingMultithreadingLevel");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // DisconnectDanglingConnections
  //
  GAME_INLINE void ECBehavior_Impl::DisconnectDanglingConnections (bool val)
  {
    static const std::string attr_name ("DisconnectDanglingConnections");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // DisconnectDanglingConnections
  //
  GAME_INLINE bool ECBehavior_Impl::DisconnectDanglingConnections (void) const
  {
    static const std::string attr_name ("DisconnectDanglingConnections");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // SupplierBasedFiltering
  //
  GAME_INLINE void ECBehavior_Impl::SupplierBasedFiltering (bool val)
  {
    static const std::string attr_name ("SupplierBasedFiltering");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // SupplierBasedFiltering
  //
  GAME_INLINE bool ECBehavior_Impl::SupplierBasedFiltering (void) const
  {
    static const std::string attr_name ("SupplierBasedFiltering");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // ConsumerBasedFiltering
  //
  GAME_INLINE void ECBehavior_Impl::ConsumerBasedFiltering (bool val)
  {
    static const std::string attr_name ("ConsumerBasedFiltering");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // ConsumerBasedFiltering
  //
  GAME_INLINE bool ECBehavior_Impl::ConsumerBasedFiltering (void) const
  {
    static const std::string attr_name ("ConsumerBasedFiltering");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // MultithreadedConsumer
  //
  GAME_INLINE void ECBehavior_Impl::MultithreadedConsumer (bool val)
  {
    static const std::string attr_name ("MultithreadedConsumer");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // MultithreadedConsumer
  //
  GAME_INLINE bool ECBehavior_Impl::MultithreadedConsumer (void) const
  {
    static const std::string attr_name ("MultithreadedConsumer");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // MultithreadedSupplier
  //
  GAME_INLINE void ECBehavior_Impl::MultithreadedSupplier (bool val)
  {
    static const std::string attr_name ("MultithreadedSupplier");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // MultithreadedSupplier
  //
  GAME_INLINE bool ECBehavior_Impl::MultithreadedSupplier (void) const
  {
    static const std::string attr_name ("MultithreadedSupplier");
    return this->attribute (attr_name)->bool_value ();
  }
}

