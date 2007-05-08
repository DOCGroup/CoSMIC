// -*- C++ -*-
// $Id$

//
// CUTS_CPU_Calibration_Details
//
CUTS_INLINE
CUTS_CPU_Calibration_Details::
CUTS_CPU_Calibration_Details (void)
: percent_error_max_ (0.0),
  percent_error_min_ (0.0),
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
// max_value
//
CUTS_INLINE
double CUTS_CPU_Calibration_Details::max_value (void) const
{
  return this->percent_error_max_;
}

//
// min_value
//
CUTS_INLINE
double CUTS_CPU_Calibration_Details::min_value (void) const
{
  return this->percent_error_min_;
}

//
// avg_value
//
CUTS_INLINE
double CUTS_CPU_Calibration_Details::avg_value (void) const
{
  return this->percent_error_sum_ / (double) this->count_;
}

//
// avg_value
//
CUTS_INLINE
size_t CUTS_CPU_Calibration_Details::count (void) const
{
  return this->count_;
}
