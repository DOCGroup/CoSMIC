// -*- C++ -*-
// $Id$

//
// CUTS_CPU_Calibration_Details
//
CUTS_INLINE
CUTS_CPU_Calibration_Details::
CUTS_CPU_Calibration_Details (void)
: max_error_ (0.0),
  min_error_ (0.0),
  percent_error_sum_ (0.0),
  count_ (0)
{

}

//
// log
//
CUTS_INLINE
const CUTS_CPU_Calibration_Details_Log &
CUTS_CPU_Calibration_Details::log (void) const
{
  return this->log_;
}

//
// max_error
//
CUTS_INLINE
double CUTS_CPU_Calibration_Details::max_error (void) const
{
  return this->max_error_;
}

//
// min_value
//
CUTS_INLINE
double CUTS_CPU_Calibration_Details::min_error (void) const
{
  return this->min_error_;
}

//
// avg_value
//
CUTS_INLINE
double CUTS_CPU_Calibration_Details::
average_percent_error (void) const
{
  return
    this->count_ > 0 ?
    this->percent_error_sum_ / (double) this->count_ : 0.0;
}

//
// avg_value
//
CUTS_INLINE
size_t CUTS_CPU_Calibration_Details::count (void) const
{
  return this->count_;
}
