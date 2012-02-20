// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // DataWriterQos_Impl
  //
  GAME_INLINE DataWriterQos_Impl::DataWriterQos_Impl (void)
  {
  }

  //
  // DataWriterQos_Impl
  //
  GAME_INLINE DataWriterQos_Impl::DataWriterQos_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataWriterQos_Impl
  //
  GAME_INLINE DataWriterQos_Impl::~DataWriterQos_Impl (void)
  {
  }

  //
  // IsInstance
  //
  GAME_INLINE void DataWriterQos_Impl::IsInstance (bool val)
  {
    static const std::string attr_name ("IsInstance");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // IsInstance
  //
  GAME_INLINE bool DataWriterQos_Impl::IsInstance (void) const
  {
    static const std::string attr_name ("IsInstance");
    return this->attribute (attr_name)->bool_value ();
  }
}

