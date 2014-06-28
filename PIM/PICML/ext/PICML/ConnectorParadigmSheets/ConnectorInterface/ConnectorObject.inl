// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ConnectorObject_Impl
  //
  GAME_INLINE ConnectorObject_Impl::ConnectorObject_Impl (void)
  {
  }

  //
  // ConnectorObject_Impl
  //
  GAME_INLINE ConnectorObject_Impl::ConnectorObject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorObject_Impl
  //
  GAME_INLINE ConnectorObject_Impl::~ConnectorObject_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void ConnectorObject_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string ConnectorObject_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }
}

