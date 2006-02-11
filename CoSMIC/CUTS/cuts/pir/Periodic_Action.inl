namespace CUTS_PIR
{
  //
  // probability
  //
  CUTS_INLINE
  void Periodic_Action::probability (double probability)
  {
    this->probability_ = probability;
  }

  CUTS_INLINE
  double Periodic_Action::probability (void) const
  {
    return this->probability_;
  }

  //
  // period
  //
  CUTS_INLINE
  long Periodic_Action::period (void) const
  {
    return this->period_;
  }

  CUTS_INLINE
  void Periodic_Action::period (long period)
  {
    this->period_ = period;
  }
}
