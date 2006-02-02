// $Id$

namespace CUTS_PIR
{
  CUTS_INLINE
  Project::Files & Project::files (void)
  {
    return this->files_;
  }

  CUTS_INLINE
  const Project::Files & Project::files (void) const
  {
    return this->files_;
  }

  CUTS_INLINE
  const Event_Manager & Project::event_manager (void) const
  {
    return this->event_manager_;
  }

  CUTS_INLINE
  Event_Manager & Project::event_manager (void)
  {
    return this->event_manager_;
  }

  CUTS_INLINE
  const Worker_Manager & Project::worker_manager (void) const
  {
    return this->worker_manager_;
  }

  CUTS_INLINE
  Worker_Manager & Project::worker_manager (void)
  {
    return this->worker_manager_;
  }
}
