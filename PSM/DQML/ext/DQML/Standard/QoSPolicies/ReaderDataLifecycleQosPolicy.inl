// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // ReaderDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE ReaderDataLifecycleQosPolicy_Impl::ReaderDataLifecycleQosPolicy_Impl (void)
  {
  }

  //
  // ReaderDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE ReaderDataLifecycleQosPolicy_Impl::ReaderDataLifecycleQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReaderDataLifecycleQosPolicy_Impl
  //
  GAME_INLINE ReaderDataLifecycleQosPolicy_Impl::~ReaderDataLifecycleQosPolicy_Impl (void)
  {
  }

  //
  // autopurge_nowriter_samples_delay
  //
  GAME_INLINE void ReaderDataLifecycleQosPolicy_Impl::autopurge_nowriter_samples_delay (double val)
  {
    static const std::string attr_name ("autopurge_nowriter_samples_delay");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // autopurge_nowriter_samples_delay
  //
  GAME_INLINE double ReaderDataLifecycleQosPolicy_Impl::autopurge_nowriter_samples_delay (void) const
  {
    static const std::string attr_name ("autopurge_nowriter_samples_delay");
    return this->attribute (attr_name)->double_value ();
  }

  //
  // autopurge_disposed_samples_delay
  //
  GAME_INLINE void ReaderDataLifecycleQosPolicy_Impl::autopurge_disposed_samples_delay (double val)
  {
    static const std::string attr_name ("autopurge_disposed_samples_delay");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // autopurge_disposed_samples_delay
  //
  GAME_INLINE double ReaderDataLifecycleQosPolicy_Impl::autopurge_disposed_samples_delay (void) const
  {
    static const std::string attr_name ("autopurge_disposed_samples_delay");
    return this->attribute (attr_name)->double_value ();
  }
}
