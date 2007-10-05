// -*- C++ -*-

//=============================================================================
/**
 * @file      Component_Metric.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COMPONENT_METRIC_H_
#define _CUTS_COMPONENT_METRIC_H_

#include "cuts/Timestamp_Metric.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

// Forward decl.
class CUTS_Port_Metric;

// Forward decl.
class CUTS_Metrics_Visitor;

// Type definition for the collection of port metrics.
typedef
  ACE_Hash_Map_Manager <
  long, CUTS_Port_Metric *, ACE_Null_Mutex>
  CUTS_Port_Metric_Map;

//=============================================================================
/**
 * @class CUTS_Component_Metric
 *
 * Performance metrics collected for a component. All the metrics are
 * stored a component's input ports. Lastly, there is a timestamp
 * attribute that determines if the component's metrics are up-to-date.
 * If the timestamp is not the same as it's parents, then the component
 * metrics are out-of-date.
 */
//=============================================================================

class CUTS_Export CUTS_Component_Metric : public CUTS_Timestamp_Metric
{
public:
  /// Constructor.
  CUTS_Component_Metric (void);

  /// Destructor.
  ~CUTS_Component_Metric (void);

  /**
   * Get the collection of port metrics for this component. The
   * port metrics are stored by their name. Also, we only store
   * port metrics that are caused by input events, such as event
   * sinks and facets.
   *
   * @return      Reference to port metrics map.
   */
  CUTS_Port_Metric_Map & port_metrics (void);

  /// @overload
  const CUTS_Port_Metric_Map & port_metrics (void) const;

  /**
   * Get an existing port metric object. The client has the option
   * of creating the port metric if it does not exist.
   *
   * @param[in]     pmid          Port metric id.
   * @param[in]     pm            The port metric object.
   * @param[in]     auto_create   Auto create object if not exists.
   */
  int port_metric (long pmid,
                   CUTS_Port_Metric * & pm,
                   bool auto_create = true);

  /**
   * Accept the system metrics visitor.
   *
   * @param[in]   visitor       System metric's visitor.
   */
  void accept (CUTS_Metrics_Visitor & visitor) const;

private:
  /// Mapping of name to port metrics.
  CUTS_Port_Metric_Map port_metrics_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Metric.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_METRIC_H_
