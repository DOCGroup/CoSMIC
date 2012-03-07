// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ConnectorToFacet_Impl
  //
  GAME_INLINE ConnectorToFacet_Impl::ConnectorToFacet_Impl (void)
  {
  }

  //
  // ConnectorToFacet_Impl
  //
  GAME_INLINE ConnectorToFacet_Impl::ConnectorToFacet_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorToFacet_Impl
  //
  GAME_INLINE ConnectorToFacet_Impl::~ConnectorToFacet_Impl (void)
  {
  }

  //
  // InnerName
  //
  GAME_INLINE void ConnectorToFacet_Impl::InnerName (const std::string & val)
  {
    static const std::string attr_name ("InnerName");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // InnerName
  //
  GAME_INLINE std::string ConnectorToFacet_Impl::InnerName (void) const
  {
    static const std::string attr_name ("InnerName");
    return this->attribute (attr_name)->string_value ();
  }
}

