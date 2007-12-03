// $Id$

#include "cuts/XML_Metrics_Writer.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/XML_Metrics_Writer.inl"
#endif

#include "cuts/Component_Info.h"
#include "cuts/Component_Metric.h"
#include "cuts/Component_Registry.h"
#include "cuts/Component_Type.h"
#include "cuts/Port_Metric.h"
#include "cuts/System_Metric.h"
#include "cuts/Time.h"

//
// ~CUTS_XML_Metrics_Writer
//
CUTS_XML_Metrics_Writer::
CUTS_XML_Metrics_Writer (const CUTS_Component_Registry & registry,
                         const ACE_CString & pathname)
: registry_ (registry),
  pathname_ (pathname)
{

}

//
// ~CUTS_XML_Metrics_Writer
//
CUTS_XML_Metrics_Writer::~CUTS_XML_Metrics_Writer (void)
{

}

//
// visit_system_metrics
//
void CUTS_XML_Metrics_Writer::
visit_system_metric (const CUTS_System_Metric & system_metric)
{
  // Clear the flag just in case this this method was invoked
  // and things didn't end on a nice note!!
  if (!this->output_.good ())
    this->output_.clear ();

  this->output_.open (this->pathname_.c_str ());
  if (!this->output_.is_open ())
    return;

  // Save the timestamp for future reference. We will need this to
  // determine which components were updated.
  this->timestamp_ = system_metric.get_timestamp ();

  this->output_
    << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>" << std::endl
    << "<SystemMetrics>" << std::endl;

  // Generate the UUID for the system metrics. This is dependent
  // on if the UUID was set before the generation started.
  if (!this->uuid_.empty ())
  {
    this->output_
      <<  "  <UUID>" << this->uuid_.c_str () << "</UUID>" << std::endl;
  }
  else
  {
    this->output_
      <<  "  <UUID />" << std::endl;
  }

  // Print the timestamp for this XML log file.
  this->output_
    << "  <TimeStamp>"
    << CUTS_string_time (this->timestamp_.sec (), "%m-%d-%Y %H:%M:%S")
    << "</TimeStamp>" << std::endl;

  CUTS_Component_Metric_Map::
    CONST_ITERATOR iter (system_metric.component_metrics ());

  for ( ; !iter.done (); iter ++)
  {
    // There is no need to continue if there isn't any
    // up-to-date information.
    if (iter->item ()->timestamp () != this->timestamp_)
      continue;

    // Generate the open tag for the <ComponentMetrics>
    if (this->registry_.get_component_info (iter->key (), &this->myinfo_) == 0)
    {
      this->output_
        << "  " << "<ComponentMetrics id=\""
        << this->myinfo_->inst_.c_str ()   << "\">" << std::endl;

      // Visit the component's metric.
      iter->item ()->accept (*this);

      // Generate the closing tag for the <ComponentMetrics>.
      this->output_
        << "  " << "</ComponentMetrics>" << std::endl;
    }
  }

  // Generate the closing tag.
  this->output_ << "</SystemMetrics>" << std::endl;
  this->output_.close ();
}

//
// visit_component_metric
//
void CUTS_XML_Metrics_Writer::
visit_component_metric (const CUTS_Component_Metric & metrics)
{
  ACE_CString portname;
  CUTS_Port_Metric_Map::CONST_ITERATOR iter (metrics.port_metrics ());

  for ( ; !iter.done (); iter ++)
  {
    // There is no need to continue if metrics our out-of-date.
    if (iter->item ()->timestamp () != this->timestamp_)
      continue;

    // Get the name of the port.
    this->myinfo_->type_->sources_.find (iter->key (), portname);

    this->output_
      << "    <Port name=\"" << portname.c_str ()
      << "\">" << std::endl;

    iter->item ()->accept (*this);

    // Generate the closing tag and erase the port name.
    this->output_
      << "    </Port>" << std::endl;

    portname.clear ();
  }
}

//
// visit_port_metrics
//
void CUTS_XML_Metrics_Writer::
visit_port_metric (const CUTS_Port_Metric & metrics)
{
  CUTS_Port_Measurement_Map::
    CONST_ITERATOR sender_iter (metrics.sender_map ().hash_map ());

  int retval;
  const CUTS_Component_Info * sender = 0;

  for ( ; !sender_iter.done (); sender_iter ++)
  {
    // There is no need to continue if there isn't any
    // up-to-date information.
    if (sender_iter->item ()->timestamp () != this->timestamp_)
      continue;

    // Generate the opening tag for the port metrics.
    retval = this->registry_.get_component_info (sender_iter->key (), &sender);

    this->output_
      << "      <PortSummary sender=\""
      << (retval == 0 ? sender->inst_.c_str () : "unknown") << "\">"
      << std::endl;

    // Visit the port metrics for this sender.
    sender_iter->item ()->accept (*this);

    // Generate the closing tag.
    this->output_
      << "      </PortSummary>" << std::endl;
  }

  // Get the log for this port. We are going to write it to
  // the XML file as well.
  size_t logsize = metrics.log ().used_size ();
  CUTS_Activation_Record_Log::const_iterator
    logiter = metrics.log ().begin (),
    logiter_end = logiter + logsize;

  this->output_
    << "      <PortLog count=\"" << logsize << "\">" << std::endl;

  ACE_CString portname;

  for (; logiter != logiter_end; logiter ++)
  {
    retval =
      this->registry_.get_component_info (logiter->owner (), &sender);

    this->output_
      << "        <LogEntry sender=\""
      << (retval == 0 ? sender->inst_.c_str () : "unknown") << "\">"
      << std::endl;

    // Write the queueing time for the event.
    this->output_ << "          ";
    this->print_time_value ("QueueTime", logiter->queue_time ());

    // Write the entry time for the event.
    this->output_ << "          ";
    this->print_time_value ("EntryTime", logiter->start_time ());

    CUTS_Activation_Record_Endpoints::
      CONST_ITERATOR endpoint_iter (logiter->endpoints ());

    for (; !endpoint_iter.done (); endpoint_iter ++)
    {
      this->myinfo_->type_->sources_.find (endpoint_iter->key (), portname);

      this->output_
        << "          <ExitTime name=\""
        << portname.c_str ()
        << "\" sec=\"" << endpoint_iter->item ().sec ()
        << "\" usec=\"" << endpoint_iter->item ().usec ()
        << "\" />" << std::endl;

      // Move to the next endpoint and clear the port name.
      portname.clear ();
    }

    CUTS_Activation_Record_Entry_Log::const_iterator
      entryiter = logiter->entries ().begin (),
      entryiter_end = entryiter + logiter->entries ().used_size ();

    for (; entryiter != entryiter_end; entryiter ++)
    {
      this->output_
        << "          <ActionEntry uid=\"" << entryiter->uid_ << "\" "
        << "type=\"" << entryiter->type_ << "\" "
        << "sec=\"" << entryiter->duration_.sec () << "\" "
        << "usec=\"" << entryiter->duration_.usec () << "\" />" << std::endl;
    }

    this->output_
      << "        </LogEntry>" << std::endl;
  }

  this->output_
    << "      </PortLog>" << std::endl;
}

//
// visit_port_measurement
//
void CUTS_XML_Metrics_Writer::
visit_port_measurement (const CUTS_Port_Measurement & pm)
{
  // Generate the opening tag for the queueing time.
  this->output_
    << "        <QueueingTime count=\""
    << pm.queuing_time ().count () << "\">" << std::endl;

  // Visit the queueing time measurements.
  pm.queuing_time ().accept (*this);

  // Generate the closing tag for the queueing time.
  this->output_
    << "        </QueueingTime>" << std::endl;

  ACE_CString portname;
  CUTS_Port_Measurement_Endpoint_Map::
    CONST_ITERATOR endpoint_iter (pm.endpoints ());

  for (; !endpoint_iter.done (); endpoint_iter ++)
  {
    // There is no need to continue if there isn't any
    // up-to-date information.
    if (endpoint_iter->item ()->timestamp () != this->timestamp_)
      continue;

    // Generate the opening tag.
    this->myinfo_->type_->sources_.find (endpoint_iter->key (), portname);

    this->output_
      << "        <ExitPoint name=\"" << portname.c_str () <<  "\" count=\""
      << endpoint_iter->item ()->count ()
      << "\">" << std::endl;

    // Visit the time metrics for this exit point.
    endpoint_iter->item ()->accept (*this);

    // Generate the closing tag.
    this->output_
      << "        </ExitPoint>" << std::endl;
  }
}

//
// visit_time_measurement
//
void CUTS_XML_Metrics_Writer::
visit_time_measurement (const CUTS_Time_Measurement & time)
{
  this->output_ << "          ";
  this->print_time_value ("BestTime", time.minimum ());

  double avg_sec =
    (double) time.total ().sec () / (double) time.count ();
  double avg_usec =
    (double) time.total ().usec () / (double) time.count ();

  this->output_
    << "          <AverageTime sec=\"" << avg_sec
    << "\" usec=\"" << avg_usec << "\" />" << std::endl;

  this->output_ << "          ";
  this->print_time_value ("WorstTime", time.maximum ());
}

//
// print_time_value
//
void CUTS_XML_Metrics_Writer::
print_time_value (const ACE_CString & heading, const ACE_Time_Value & tv)
{
  this->output_
    << "<" << heading.c_str () << " sec=\""
    << tv.sec () << "\" usec=\"" << tv.usec () << "\" />" << std::endl;
}
