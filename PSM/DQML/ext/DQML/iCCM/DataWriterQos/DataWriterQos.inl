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

  //
  // topic_name
  //
  GAME_INLINE void DataWriterQos_Impl::topic_name (const std::string & val)
  {
    static const std::string attr_name ("topic_name");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // topic_name
  //
  GAME_INLINE std::string DataWriterQos_Impl::topic_name (void) const
  {
    static const std::string attr_name ("topic_name");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // isprivate
  //
  GAME_INLINE void DataWriterQos_Impl::isprivate (bool val)
  {
    static const std::string attr_name ("isprivate");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // isprivate
  //
  GAME_INLINE bool DataWriterQos_Impl::isprivate (void) const
  {
    static const std::string attr_name ("isprivate");
    return this->attribute (attr_name)->bool_value ();
  }
}

