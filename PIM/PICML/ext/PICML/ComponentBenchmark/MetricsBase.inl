// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // MetricsBase_Impl
  //
  GAME_INLINE MetricsBase_Impl::MetricsBase_Impl (void)
  {
  }

  //
  // MetricsBase_Impl
  //
  GAME_INLINE MetricsBase_Impl::MetricsBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MetricsBase_Impl
  //
  GAME_INLINE MetricsBase_Impl::~MetricsBase_Impl (void)
  {
  }

  //
  // warmup
  //
  GAME_INLINE void MetricsBase_Impl::warmup (long val)
  {
    static const std::string attr_name ("warmup");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // warmup
  //
  GAME_INLINE long MetricsBase_Impl::warmup (void) const
  {
    static const std::string attr_name ("warmup");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // iterations
  //
  GAME_INLINE void MetricsBase_Impl::iterations (long val)
  {
    static const std::string attr_name ("iterations");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // iterations
  //
  GAME_INLINE long MetricsBase_Impl::iterations (void) const
  {
    static const std::string attr_name ("iterations");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // fileName
  //
  GAME_INLINE void MetricsBase_Impl::fileName (const std::string & val)
  {
    static const std::string attr_name ("fileName");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // fileName
  //
  GAME_INLINE std::string MetricsBase_Impl::fileName (void) const
  {
    static const std::string attr_name ("fileName");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // priority
  //
  GAME_INLINE void MetricsBase_Impl::priority (long val)
  {
    static const std::string attr_name ("priority");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // priority
  //
  GAME_INLINE long MetricsBase_Impl::priority (void) const
  {
    static const std::string attr_name ("priority");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // rate
  //
  GAME_INLINE void MetricsBase_Impl::rate (long val)
  {
    static const std::string attr_name ("rate");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // rate
  //
  GAME_INLINE long MetricsBase_Impl::rate (void) const
  {
    static const std::string attr_name ("rate");
    return this->attribute (attr_name)->int_value ();
  }

  //
  // resolution
  //
  GAME_INLINE void MetricsBase_Impl::resolution (const std::string & val)
  {
    static const std::string attr_name ("resolution");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // resolution
  //
  GAME_INLINE std::string MetricsBase_Impl::resolution (void) const
  {
    static const std::string attr_name ("resolution");
    return this->attribute (attr_name)->string_value ();
  }
}

