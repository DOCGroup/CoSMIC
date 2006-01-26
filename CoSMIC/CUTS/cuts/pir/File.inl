//  $Id$

namespace CUTS_PIR
{
  //
  // includes
  //
  CUTS_INLINE
  File::Includes & File::includes (void)
  {
    return this->includes_;
  }

  CUTS_INLINE
  const File::Includes & File::includes (void) const
  {
    return this->includes_;
  }

  //
  //
  //
  CUTS_INLINE
  void File::has_events (bool has_events)
  {
    this->has_events_ = has_events;
  }

  CUTS_INLINE
  bool File::has_events (void) const
  {
    return this->has_events_;
  }
}
