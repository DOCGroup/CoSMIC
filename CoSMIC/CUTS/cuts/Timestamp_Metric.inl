// -*- C++ -*-
// $Id$

//
// CUTS_Timestamp_Metric
//
CUTS_INLINE
CUTS_Timestamp_Metric::CUTS_Timestamp_Metric (void)
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
