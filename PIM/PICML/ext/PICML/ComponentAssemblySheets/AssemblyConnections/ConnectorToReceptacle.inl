// -*- C++ -*-
namespace PICML
{
  //
  // ConnectorToReceptacle_Impl
  //
  GAME_INLINE ConnectorToReceptacle_Impl::ConnectorToReceptacle_Impl (void)
  {
  }

  //
  // ConnectorToReceptacle_Impl
  //
  GAME_INLINE ConnectorToReceptacle_Impl::ConnectorToReceptacle_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorToReceptacle_Impl
  //
  GAME_INLINE ConnectorToReceptacle_Impl::~ConnectorToReceptacle_Impl (void)
  {
  }

  //
  // InnerName
  //
  GAME_INLINE void ConnectorToReceptacle_Impl::InnerName (const std::string & val)
  {
    static const std::string attr_name ("InnerName");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // InnerName
  //
  GAME_INLINE std::string ConnectorToReceptacle_Impl::InnerName (void) const
  {
    static const std::string attr_name ("InnerName");
    return this->attribute (attr_name)->string_value ();
  }
}

