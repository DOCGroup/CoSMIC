// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // DataReaderQos_Impl
  //
  GAME_INLINE DataReaderQos_Impl::DataReaderQos_Impl (void)
  {
  }

  //
  // DataReaderQos_Impl
  //
  GAME_INLINE DataReaderQos_Impl::DataReaderQos_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataReaderQos_Impl
  //
  GAME_INLINE DataReaderQos_Impl::~DataReaderQos_Impl (void)
  {
  }

  //
  // isprivate
  //
  GAME_INLINE void DataReaderQos_Impl::isprivate (bool val)
  {
    static const std::string attr_name ("isprivate");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // isprivate
  //
  GAME_INLINE bool DataReaderQos_Impl::isprivate (void) const
  {
    static const std::string attr_name ("isprivate");
    return this->attribute (attr_name)->bool_value ();
  }
}

