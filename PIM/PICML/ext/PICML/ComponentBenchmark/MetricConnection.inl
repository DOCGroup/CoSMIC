// -*- C++ -*-
namespace PICML
{
  //
  // MetricConnection_Impl
  //
  GAME_INLINE MetricConnection_Impl::MetricConnection_Impl (void)
  {
  }

  //
  // MetricConnection_Impl
  //
  GAME_INLINE MetricConnection_Impl::MetricConnection_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MetricConnection_Impl
  //
  GAME_INLINE MetricConnection_Impl::~MetricConnection_Impl (void)
  {
  }
}

