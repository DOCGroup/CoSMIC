// $Id$

//
// lock
//
CUTS_INLINE
ACE_RW_Thread_Mutex & CUTS_Port_Metric::lock (void)
{
  return this->lock_;
}

//
// transit_time
//
CUTS_INLINE
CUTS_Time_Metric & CUTS_Port_Metric::transit_time (void)
{
  return this->transit_time_;
}

//
// transit_time
//
CUTS_INLINE
const CUTS_Time_Metric & CUTS_Port_Metric::transit_time (void) const
{
  return this->transit_time_;
}

//
// endpoints
//
CUTS_INLINE
const CUTS_Endpoint_Metric_Map &
CUTS_Port_Metric::endpoints (void) const
{
  return this->endpoints_;
}

//
// timestamp
//
CUTS_INLINE
void CUTS_Port_Metric::timestamp (const ACE_Time_Value & timestamp)
{
  this->timestamp_ = timestamp;
}

//
// timestamp
//
CUTS_INLINE
const ACE_Time_Value & CUTS_Port_Metric::timestamp (void) const
{
  return this->timestamp_;
}

//
// log
//
CUTS_INLINE
const CUTS_Activation_Record_Log & CUTS_Port_Metric::log (void) const
{
  return this->log_;
}

//
// log
//
CUTS_INLINE
CUTS_Activation_Record_Log & CUTS_Port_Metric::log (void)
{
  return this->log_;
}

//
// endpoint_name
//
CUTS_INLINE
ACE_CString CUTS_Port_Metric::endpoint_name (long id) const
{
  CUTS_Endpoint_Name_Map::const_iterator iter;
  iter = this->name_map_.find (id);

  return iter != this->name_map_.end () ? iter->second : "";
}

//
// endpoint_name
//
CUTS_INLINE
void CUTS_Port_Metric::endpoint_name (long id, const ACE_CString & name)
{
  this->name_map_[id] = name;
}
