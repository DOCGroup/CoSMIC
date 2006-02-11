// $Id$

namespace CUTS_PIR
{
  CUTS_INLINE
  const Event_Source * Output_Action::event_source (void) const
  {
    return this->event_source_;
  }

  CUTS_INLINE
  void Output_Action::event_source (const Event_Source * event_source)
  {
    this->event_source_ = event_source;
  }

  CUTS_INLINE
  size_t Output_Action::size (void) const
  {
    return this->size_;
  }

  CUTS_INLINE
  void Output_Action::size (size_t size)
  {
    this->size_ = size;
  }
}
