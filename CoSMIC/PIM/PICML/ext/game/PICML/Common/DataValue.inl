// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // DataValue_Impl
  //
  GAME_INLINE DataValue_Impl::DataValue_Impl (void)
  {
  }

  //
  // DataValue_Impl
  //
  GAME_INLINE DataValue_Impl::DataValue_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataValue_Impl
  //
  GAME_INLINE DataValue_Impl::~DataValue_Impl (void)
  {
  }

  //
  // Value
  //
  GAME_INLINE void DataValue_Impl::Value (const std::string & val)
  {
    static const std::string attr_name ("Value");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // Value
  //
  GAME_INLINE std::string DataValue_Impl::Value (void) const
  {
    static const std::string attr_name ("Value");
    return this->attribute (attr_name)->string_value ();
  }
}

