// -*- C++ -*-
// $Id$

//
// CUTS_Timestamp_Metric
//
CUTS_INLINE
CUTS_Timestamp_Metric::CUTS_Timestamp_Metric (void)
: timestamp_ (ACE_Time_Value::zero)
{

}

//
// CUTS_Timestamp_Metric
//
CUTS_INLINE
CUTS_Timestamp_Metric::CUTS_Timestamp_Metric (const CUTS_Timestamp_Metric & tm)
  : timestamp_ (tm.timestamp_)
{

}

//
// CUTS_Timestamp_Metric
//
CUTS_INLINE
CUTS_Timestamp_Metric::CUTS_Timestamp_Metric (const ACE_Time_Value & tv)
: timestamp_ (tv)
{

}

//
// ~CUTS_Timestamp_Metric
//
CUTS_INLINE
CUTS_Timestamp_Metric::~CUTS_Timestamp_Metric (void)
{

}

//
// timestamp
//
CUTS_INLINE
void CUTS_Timestamp_Metric::timestamp (const ACE_Time_Value & tv)
{
  this->timestamp_ = tv;
}

//
// timestamp
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Timestamp_Metric::timestamp (void) const
{
  return this->timestamp_;
}

//
// timestamp
//
CUTS_INLINE
ACE_Time_Value & CUTS_Timestamp_Metric::timestamp (void)
{
  return this->timestamp_;
}

//
// reset
//
CUTS_INLINE
void CUTS_Timestamp_Metric::reset (void)
{
  this->timestamp_ = ACE_Time_Value::zero;
}

//
// is_valid
//
CUTS_INLINE
bool CUTS_Timestamp_Metric::is_valid (void) const
{
  return this->timestamp_ != ACE_Time_Value::zero;
}
