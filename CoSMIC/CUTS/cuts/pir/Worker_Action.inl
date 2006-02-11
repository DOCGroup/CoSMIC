// $Id$

namespace CUTS_PIR
{
  //
  // parent
  //
  CUTS_INLINE
  const Worker_Type * Worker_Action::parent (void) const
  {
    return this->parent_;
  }

  //
  // repetitions
  //
  CUTS_INLINE
  size_t Worker_Action::repetitions (void) const
  {
    return this->repetitions_;
  }

  CUTS_INLINE
  void Worker_Action::repetitions (size_t reps)
  {
    this->repetitions_ = reps;
  }

  //
  // log_action
  //
  CUTS_INLINE
  void Worker_Action::log_action (bool log)
  {
    this->log_action_ = log;
  }

  CUTS_INLINE
  bool Worker_Action::log_action (void) const
  {
    return this->log_action_;
  }

  //
  // properties
  //
  CUTS_INLINE
  Worker_Action::Properties &
  Worker_Action::properties (void)
  {
    return this->properties_;
  }

  CUTS_INLINE
  const Worker_Action::Properties &
  Worker_Action::properties (void) const
  {
    return this->properties_;
  }
}
