// -*- C++ -*-
namespace PICML
{
  //
  // ConnectorInstance_Impl
  //
  GAME_INLINE ConnectorInstance_Impl::ConnectorInstance_Impl (void)
  {
  }

  //
  // ConnectorInstance_Impl
  //
  GAME_INLINE ConnectorInstance_Impl::ConnectorInstance_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorInstance_Impl
  //
  GAME_INLINE ConnectorInstance_Impl::~ConnectorInstance_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void ConnectorInstance_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string ConnectorInstance_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }
}

