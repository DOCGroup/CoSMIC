// $Id$

#include "cuts/XML_Metrics_Writer.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/XML_Metrics_Writer.inl"
#endif

#include "cuts/Component_Registry.h"
#include "cuts/Time.h"
#include "cuts/System_Metric.h"
#include "cuts/Component_Metric.h"
#include "cuts/Port_Metric.h"
#include "cuts/Time_Metric.h"

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
visit_system_metrics (const CUTS_System_Metric & metrics)
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
  this->timestamp_ = metrics.get_timestamp ();

  this->output_
    << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
    << "<SystemMetrics>" << std::endl;

  if (!this->uuid_.empty ())
  {
    this->output_
      <<  "  <UUID>" << this->uuid_.c_str () << "</UUID>" << std::endl;
  }

  this->output_
    << "  <TimeStamp>"
    << CUTS_string_time (this->timestamp_.sec (), "%m-%d-%Y %H:%M:%S")
    << "</TimeStamp>" << std::endl;

  CUTS_Component_Metric_Map::const_iterator iter;
  for (iter  = metrics.component_metrics ().begin ();
       iter != metrics.component_metrics ().end ();
       iter ++)
  {
    // There is no need to continue if there isn't any
    // up-to-date information.
    if (iter->second->timestamp () != this->timestamp_)
    {
      continue;
    }

    // Generate the open tag for the <ComponentMetrics>
    const CUTS_Component_Info * info = 0;

    if (this->registry_.get_component_info (iter->first, &info) == 0)
    {
      this->output_
        << "  " << "<ComponentMetrics id=\""
        << info->inst_.c_str ()   << "\">" << std::endl;

      // Visit the component's metric.
      iter->second->accept (*this);

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
// visit_component_metrics
//
void CUTS_XML_Metrics_Writer::
visit_component_metrics (const CUTS_Component_Metric & metrics)
{
  CUTS_Port_Metric_Map::const_iterator iter;

  for (iter  = metrics.port_metrics ().begin ();
       iter != metrics.port_metrics ().end ();
       iter ++)
  {

    CUTS_Sender_Port_Map::const_iterator s_iter;

    // Generate the opening tag.
    this->output_
      << "    <Port name=\"" << iter->first << "\">" << std::endl;

    for (s_iter  = iter->second.begin ();
         s_iter != iter->second.end ();
         s_iter ++)
    {
      // There is no need to continue if there isn't any
      // up-to-date information.
      if (s_iter->second->timestamp () != this->timestamp_)
      {
        continue;
      }

      // Generate the opening tag for the port metrics.

      const CUTS_Component_Info * info = 0;
      if (this->registry_.get_component_info (s_iter->first, &info) == 0)
      {
        this->output_
          << "      <PortMetric sender=\""
          << info->inst_.c_str () << "\">" << std::endl;
      }
      else
      {
        this->output_
          << "      <PortMetric sender=\"UNKNOWN\">" << std::endl;
      }

      // Visit the port metrics for this sender.
      s_iter->second->accept (*this);

      // Generate the closing tag.
      this->output_
        << "      </PortMetric>" << std::endl;
    }

    // Write the history metrics for this port. Right now, the history is
    // stored under the CUTS_UNKNOWN_IMPL sender id.
    s_iter = iter->second.find (CUTS_UNKNOWN_IMPL);

    if (s_iter != iter->second.end ())
    {
      const CUTS_Port_Metric * unknown = s_iter->second;
      const CUTS_Activation_Record_Log & log = unknown->log ();
      size_t logsize = log.size ();

      this->output_
        << "      <PortLog count=\"" << logsize << "\">" << std::endl;

      for (size_t i = 0; i < logsize; i ++)
      {
        const CUTS_Component_Info * info = 0;
        this->registry_.get_component_info (log[i].owner (), &info);

        this->output_
          << "        <LogEntry sender=\""
          << info->inst_.c_str () << "\">" << std::endl
          << "          <QueueTime sec=\"" << log[i].queue_time ().sec ()
          << "\" usec=\"" << log[i].queue_time ().usec ()
          << "\" />" << std::endl
          << "          <EnterTime sec=\"" << log[i].start_time ().sec ()
          << "\" usec=\"" << log[i].start_time ().usec ()
          << "\" />" << std::endl;

        CUTS_Activation_Record_Endpoints::
          CONST_ITERATOR endpoint_iter (log[i].endpoints ());

        while (!endpoint_iter.done ())
        {
          this->output_
            << "          <ExitTime name=\""
            << unknown->endpoint_name (endpoint_iter->key ()).c_str ()
            << "\" sec=\"" << endpoint_iter->item ().sec ()
            << "\" usec=\"" << endpoint_iter->item ().usec ()
            << "\" />" << std::endl;

          endpoint_iter.advance ();
        }

        this->output_
          << "        </LogEntry>" << std::endl;
      }

      this->output_
        << "      </PortLog>" << std::endl;
    }

    // Generate the closing tag.
    this->output_ << "    </Port>" << std::endl;
  }
}

//
// visit_port_metrics
//
void CUTS_XML_Metrics_Writer::
visit_port_metrics (const CUTS_Port_Metric & metrics)
{
  // Generate the opening tag for the <TransitTime>.
  this->output_
    << "        <QueueingTime count=\""
    << metrics.transit_time ().count () << "\">" << std::endl;

  // Visit the time metrics for the transit time.
  metrics.transit_time ().accept (*this);

  // Generate the closing tag for the <TransitTime>.
  this->output_
    << "        </QueueingTime>" << std::endl;

  CUTS_Endpoint_Metric_Map::const_iterator e_iter;

  for (e_iter  = metrics.endpoints ().begin ();
       e_iter != metrics.endpoints ().end ();
       e_iter ++)
  {
    // There is no need to continue if there isn't any
    // up-to-date information.
    if (e_iter->second->timestamp () != this->timestamp_)
    {
      continue;
    }

    // Generate the opening tag.
    this->output_
      << "        <ExitPoint name=\"" << e_iter->first <<  "\" count=\""
      << e_iter->second->count ()
      << "\">" << std::endl;

    // Visit the time metrics for this exit point.
    e_iter->second->accept (*this);

    // Generate the closing tag.
    this->output_
      << "        </ExitPoint>" << std::endl;
  }
}

//
// visit_time_metrics
//
void CUTS_XML_Metrics_Writer::
visit_time_metrics (const CUTS_Time_Metric & metrics)
{
  this->output_
    << "          <Best>"
    << metrics.best_time () << "</Best>" << std::endl
    << "          <Average>"
    << metrics.avg_time () << "</Average>" << std::endl
    << "          <Worst>"
    << metrics.worse_time () << "</Worst>" << std::endl;
}

//
// print_time_value
//
void CUTS_XML_Metrics_Writer::
print_time_value (const ACE_CString & heading, const ACE_Time_Value & tv)
{
  this->output_
    << "<" << heading.c_str () << " sec=\""
    << tv.sec () << "\" msec=\"" << tv.msec () << "\" />" << std::endl;
}
