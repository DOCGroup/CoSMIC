// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // WriterDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE WriterDataLifecycleQosPolicy_Impl::WriterDataLifecycleQosPolicy_Impl (void)
  {
  }

  //
  // WriterDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE WriterDataLifecycleQosPolicy_Impl::WriterDataLifecycleQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WriterDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE WriterDataLifecycleQosPolicy_Impl::~WriterDataLifecycleQosPolicy_Impl (void)
  {
  }

  //
  // autodispose_unregistered_instances
  //
  GAME_INLINE void WriterDataLifecycleQosPolicy_Impl::autodispose_unregistered_instances (bool val)
  {
    static const std::string attr_name ("autodispose_unregistered_instances");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // autodispose_unregistered_instances
  //
  GAME_INLINE bool WriterDataLifecycleQosPolicy_Impl::autodispose_unregistered_instances (void) const
  {
    static const std::string attr_name ("autodispose_unregistered_instances");
    return this->attribute (attr_name)->bool_value ();
  }
}

