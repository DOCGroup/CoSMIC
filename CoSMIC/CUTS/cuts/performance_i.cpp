// $Id$

#include "cuts/performance_i.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/performance_i.inl"
#endif

#include "tao/corba.h"
#include "ace/Guard_T.h"

///////////////////////////////////////////////////////////////////////////////
// @@ extraction operators

static ACE_Time_Value tv_collection_time_;

//
// operator >>=
//
void operator >>= (const CUTS::Component_Metric & src,
                   CUTS_Component_Metric & dst)
{
  // Save the collection time for this component.
  tv_collection_time_ = dst.timestamp ();

  // Get an pointer to the front and back of source buffer.
  CORBA::ULong curr_size = src.metrics.length ();
  CUTS::Port_Metrics::const_value_type * iter = src.metrics.get_buffer ();
  CUTS::Port_Metrics::const_value_type * iter_stop = iter + curr_size;

  // Get the collection time for the metric. This will be need to all
  // the port agents.

  CUTS_Port_Metric * port_metric = 0;

  for (iter; iter != iter_stop; iter ++)
  {
    // Try to locate the port metrics for <uid>. If we can't find
    // it then we need to create a new one.
    if (dst.port_metrics ().find (iter->uid, port_metric) == -1)
    {
      ACE_NEW_THROW_EX (port_metric,
                        CUTS_Port_Metric,
                        ACE_bad_alloc ());

      // Insert it into the mapping for next time.
      dst.port_metrics ().bind (iter->uid, port_metric);
    }

    // Update the collection time for the component.
    port_metric->timestamp (tv_collection_time_);

    // Extract the metrics for the port.
    *iter >>= *port_metric;
  }
}

//
// operator >>=
//
void operator >>= (const CUTS::Port_Metric & pm,
                   CUTS_Port_Metric & port)
{
  // Update the time for the port metric.
  port.timestamp (tv_collection_time_);

  pm.history >>= port.log ();
  pm.sorted_metrics >>= port.sender_map ();
}

//
// operator >>=
//
void operator >>= (const CUTS::Sorted_Port_Metrics & sps,
                   CUTS_Port_Measurement_Map & pmp)
{
  CORBA::ULong curr_size = sps.length ();
  CUTS::Sorted_Port_Metrics::const_value_type * iter = sps.get_buffer ();
  CUTS::Sorted_Port_Metrics::const_value_type * iter_stop = iter + curr_size;

  pmp.empty ();

  // Empty the port measurement map.
  CUTS_Port_Measurement * port_measurement = 0;

  for (; iter != iter_stop; iter ++)
  {
    if (pmp.find (iter->uid, port_measurement) == 0)
      iter->summary >>= *port_measurement;
  }
}

//
// operator >>=
//
void operator >>= (const CUTS::Port_Summary & ps, CUTS_Port_Measurement & pm)
{
  pm.timestamp (tv_collection_time_);

  ps.process_time >>= pm.process_time ();
  ps.queue_time >>= pm.queuing_time ();
  ps.endpoint_times >>= pm.endpoints ();
}

//
// operator >>=
//
void operator >>= (const CUTS::Endpoint_Time_Infos & eti,
                   CUTS_Port_Measurement_Endpoint_Map & endpoints)
{
  // Get the current size of the buffer and a pointer to it.
  CORBA::ULong curr_size = eti.length ();
  const CUTS::Endpoint_Time_Infos::value_type * buf = eti.get_buffer ();
  const CUTS::Endpoint_Time_Infos::value_type * buf_stop = buf + curr_size;

  CUTS_Time_Measurement * measure = 0;

  for (; buf != buf_stop; buf ++)
  {
    if (endpoints.find (buf->uid, measure) != 0)
    {
      ACE_NEW_THROW_EX (measure,
                        CUTS_Time_Measurement,
                        ::CORBA::NO_MEMORY ());

      endpoints.bind (buf->uid, measure);
    }

    if (measure != 0)
      buf->info >>= *measure;
  }
}

//
// operator >>=
//
void operator >>= (const CUTS::Metric_Log & mlog,
                   CUTS_Activation_Record_Log & log)
{
  // Get the size of the log sequence then resize the activation
  // record log accordingly.
  CORBA::ULong curr_size = mlog.length ();
  log.size (curr_size);

  // Reset the record log.
  log.reset ();

  // Get a pointer to the buffer w/ the activation records.
  const CUTS::Metric_Log::value_type * buf = mlog.get_buffer ();
  const CUTS::Metric_Log::value_type * buf_stop = buf + curr_size;

  // Update the size of the log. This will prevent us from having to
  // rely on next_free_record () to increase the log size. In some
  // cases that would be feasible, but it would cause to many
  // lock/unlock request. This is more like a batch operation job.
  ACE_WRITE_GUARD (ACE_RW_Thread_Mutex, guard, log.lock ());

  while (buf < buf_stop)
    *buf ++ >>= *log.next_free_record_i ();
}

//
// operator >>=
//
void operator >>= (const CUTS::Time_Info & ti, CUTS_Time_Measurement & tm)
{
  tm.timestamp (tv_collection_time_);
  tm.count (ti.count);

  ti.total >>= tm.total ();
  ti.min >>= tm.minimum ();
  ti.max >>= tm.maximum ();
}

//
// operator >>=
//
void operator >>= (const CUTS::Action_Time & time,
                   CUTS_Activation_Record_Entry & entry)
{
  entry.uid_ = time.uid;
  entry.type_ = time.type;
  time.duration >>= entry.duration_;
}

//
// operator >>=
//
void operator >>= (const CUTS::Action_Times & times,
                   CUTS_Activation_Record_Entry_Log & entries)
{
  // Get the current size of the buffer and resize the log.
  CORBA::ULong curr_size = times.length ();
  entries.size (curr_size);

  // Get a pointer/iterator to the buffer/log.
  CUTS::Action_Times::const_value_type * buf = times.get_buffer ();
  CUTS::Action_Times::const_value_type * buf_stop = buf + curr_size;

  for (; buf != buf_stop; buf ++)
    *buf >>= *entries.next_free_record_i ();
}

//
// operator >>=
//
void operator >>= (const CUTS::Endpoint_Times & ep_times,
                   CUTS_Activation_Record_Endpoints & endpoints)
{
  // Get the pointer to the ep_times buffer and its size.
  CORBA::ULong curr_size = ep_times.length ();
  const CUTS::Endpoint_Times::value_type * buf = ep_times.get_buffer ();
  const CUTS::Endpoint_Times::value_type * buf_stop = buf + curr_size;

  // Temporary storage for the time values. First, we are going
  // to remove all values currently in the hash map.
  endpoints.unbind_all ();
  ACE_Time_Value tv_temp;

  for (; buf < buf_stop; buf ++)
  {
    // Extract the ACE_Time_Value then add mapping to <endpoints>.
    buf->exittime >>= tv_temp;
    endpoints.bind (buf->uid, tv_temp);
  }
}

//
// operator >>=
//
void operator >>= (const CUTS::Metric_Record & m_record,
                   CUTS_Activation_Record & a_record)
{
  // Extract the owner of the <m_record>.
  a_record.owner (m_record.sender);

  // Extract the open/close time for the record.
  m_record.open_time  >>= a_record.start_time ();
  m_record.close_time >>= a_record.stop_time ();

  // Extract the queueing and endpoint times from the record.
  ACE_Time_Value tv_temp;
  m_record.queue_time >>= tv_temp;
  a_record.queue_time (tv_temp);

  m_record.ep_times >>= a_record.endpoints ();
  m_record.action_log >>= a_record.entries ();
}

///////////////////////////////////////////////////////////////////////////////
// @@ insertion operators

//
// operator <<=
//
static void operator <<= (CUTS::Port_Metrics & ports,
                          const CUTS_Port_Agent_Set & agents)
{
  // Get the number of agents and update the size of the
  // port metrics.
  size_t size = agents.current_size ();
  ports.length (size);

  // Get a pointer to both the source and destination buffer.
  CUTS::Port_Metrics::value_type * buf = ports.get_buffer ();
  CUTS_Port_Agent_Set::CONST_ITERATOR iter (agents);

  // Copy all the elements from the set to the sequence.
  for (; !iter.done (); iter.advance ())
  {
    CUTS_Port_Agent * agent =
      reinterpret_cast <CUTS_Port_Agent *> (iter->key ());

    buf->uid = iter->item ();
    *buf ++ <<= *agent;

    // Reset the port agent for the next collection.
    agent->reset ();
  }
}

//
// operator <<=
//
void operator <<= (CUTS::Component_Metric & cm,
                   const CUTS_Benchmark_Agent & agent)
{
  // Set the parent id and the collection time.
  cm.uid = agent.parent ();
  cm.collection_time <<= ACE_OS::gettimeofday ();

  // Insert all the port metrics.
  cm.metrics <<= agent.port_agents ();
}

//
// operator <<=
//
void operator <<= (CUTS::Port_Metric & pm, const CUTS_Port_Agent & agent)
{
  // Insert the sorted port measurements and move to a new pool.
  pm.sorted_metrics <<= agent.sender_map ();

  // Insert the history log.
  pm.history <<= agent.log ();
}

//
// operator <<=
//
static inline
void operator <<= (CUTS::Sorted_Port_Metric & sps,
                   CUTS_Port_Measurement_Map::hash_map_t::value_type & vt)
{
  sps.uid = vt.key ();
  sps.summary <<= *vt.item ();

  // Reset the port measurement for the next collection.
  vt.item ()->reset ();
}

//
// operator <<=
//
void operator <<= (CUTS::Sorted_Port_Metrics & sps,
                   const CUTS_Port_Measurement_Map & pmp)
{
  CUTS_Port_Measurement_Map::CONST_ITERATOR iter (pmp.hash_map ());
  sps.length (pmp.hash_map ().current_size ());

  CUTS::Sorted_Port_Metrics::value_type * buf = sps.get_buffer ();

  for (; !iter.done (); iter.advance ())
    *buf ++ <<= *iter;
}

//
// operator <<=
//
void operator <<= (CUTS::Port_Summary & ps, const CUTS_Port_Measurement & pm)
{
  ps.process_time <<= pm.process_time ();
  ps.queue_time <<= pm.queuing_time ();
  ps.endpoint_times <<= pm.endpoints ();
}

//
// operator <<=
//
void operator <<= (CUTS::Endpoint_Time_Infos & eti,
                   const CUTS_Port_Measurement_Endpoint_Map & endpoints)
{
  // Set the current size of the buffer.
  CORBA::ULong curr_size = endpoints.current_size ();
  eti.length (curr_size);

  // Get a pointer to the buffer.
  CUTS::Endpoint_Time_Infos::value_type * buf = eti.get_buffer ();

  size_t count = 0;
  CUTS_Port_Measurement_Endpoint_Map::CONST_ITERATOR iter (endpoints);

  for (; !iter.done (); iter.advance ())
  {
    if (iter->item ()->count () > 0)
    {
      *buf ++ <<= *iter;
      ++ count;
    }
  }

  eti.length (buf - eti.get_buffer ());
}

//
// operator <<=
//
void operator <<= (CUTS::Time_Info & ti, const CUTS_Time_Measurement & tm)
{
  ti.count = tm.count ();

  ti.total <<= tm.total ();
  ti.min <<= tm.minimum ();
  ti.max <<= tm.maximum ();
}

//
// operator <<=
//
void operator <<= (CUTS::Metric_Log & mlog,
                   const CUTS_Activation_Record_Log & log)
{
  ::CORBA::ULong final_size = 0;

  do
  {
    ACE_READ_GUARD (ACE_RW_Thread_Mutex,
      guard,
      const_cast <CUTS_Activation_Record_Log &> (log).lock ());

    // Set the size of the <mlog> sequence.
    ::CORBA::ULong curr_size = log.used_size ();
    mlog.length (curr_size);

    // Get a iterator to the logs and a pointer to the head
    // of the target buffer.
    CUTS_Activation_Record_Log::const_iterator iter = log.begin ();
    CUTS::Metric_Log::value_type * buf = mlog.get_buffer ();

    // Get a read lock to the log. This will allow use to do a batch
    // processing operation and prevent other threads from trying to
    // increase the size of the record log.
    for (::CORBA::ULong i = 0; i < curr_size; i ++)
    {
      // Only copy records that are not open (i.e., have be used). Since we
      // are only looking at used records, we do not have to worry about a
      // record in the middle of the pack being unused.

      if (!iter->is_open ())
      {
        *buf ++ <<= *iter ++;

        // Keep track of the actual size.
        ++ final_size;
      }
    }
  } while (0);

  // Make sure the size of the buffer reflects the number of
  // used records that we copied.
  mlog.length (final_size);
}

//
// operator <<=
//
void operator <<= (CUTS::Endpoint_Times & ep_times,
                   const CUTS_Activation_Record_Endpoints & endpoints)
{
  // Set the correct size of the target buffer.
  ::CORBA::ULong curr_size = endpoints.current_size ();
  ep_times.length (curr_size);

  // Get an iterator to the endpoint times and a pointer to the
  // buffer that will store the endpoint times.
  CUTS_Activation_Record_Endpoints::CONST_ITERATOR iter (endpoints);
  CUTS::Endpoint_Times::value_type * buf = ep_times.get_buffer ();

  for (::CORBA::ULong index = 0; index < curr_size; index ++)
  {
    // Store the information in the buffer. This is the unique
    // id of the endpoint and the time it was encountered.
    buf->uid = iter->key ();
    buf->exittime <<= iter->item ();

    // Move the next location in the map and the next slot
    // in the target buffer.
    iter.advance ();
    buf ++;
  }
}

//
// operator <<=
//
void operator <<= (CUTS::Action_Time & act,
                   const CUTS_Activation_Record_Entry & entry)
{
  act.uid = entry.uid_;
  act.type = entry.type_;
  act.duration <<= entry.duration_;
}

//
// operetor <<=
//
void operator <<= (CUTS::Action_Times & times,
                   const CUTS_Activation_Record_Entry_Log & entries)
{
  // Get the current size of the log and resize the sequence.
  size_t curr_size = entries.used_size ();
  times.length (curr_size);

  // Get iterators to the source and destination buffer.
  CUTS::Action_Times::value_type * buf = times.get_buffer ();
  CUTS_Activation_Record_Entry_Log::const_iterator iter = entries.begin ();
  CUTS_Activation_Record_Entry_Log::const_iterator iter_stop = iter + curr_size;

  for (; iter != iter_stop; iter ++)
    *buf ++ <<= *iter;
}

//
// operator <<=
//
void operator <<= (CUTS::Metric_Record & dest,
                   const CUTS_Activation_Record & src)
{
  // Insert the owner of the record (i.e., event that caused the
  // creation of this record).
  dest.sender = src.owner ();

  // Insert the open/close time for the record.
  dest.open_time  <<= src.start_time ();
  dest.close_time <<= src.stop_time ();

  // Insert the queueing and endpoint times into the record.
  dest.queue_time <<= src.queue_time ();
  dest.ep_times   <<= src.endpoints ();
  dest.action_log <<= src.entries ();
}
