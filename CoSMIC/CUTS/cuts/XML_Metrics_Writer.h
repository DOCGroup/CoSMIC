// -*- C++ -*-

//=============================================================================
/**
 * @file      XML_Metrics_Writer.h
 *
 * @brief     Defines the XML format generator for system metrics.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_XML_METRICS_WRITER_H_
#define _CUTS_XML_METRICS_WRITER_H_

#include "cuts/System_Metrics_Visitor.h"
#include "ace/SString.h"
#include "ace/streams.h"
#include "ace/Time_Value.h"

// Forward decl.
class CUTS_Component_Registry;

//=============================================================================
/**
 * @class CUTS_XML_Metrics_Writer
 *
 * Utility class for generating the system metrics in an XML format.
 */
//=============================================================================

class CUTS_Export CUTS_XML_Metrics_Writer :
  public CUTS_System_Metrics_Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     registry        Registry with component information.
   * @param[in]     pathane         Name of the XML file.
   */
  CUTS_XML_Metrics_Writer (const CUTS_Component_Registry & registry,
                           const ACE_CString & pathname);

  /// Destructor.
  virtual ~CUTS_XML_Metrics_Writer (void);

  /**
   * Set the UUID for the generated XML file. If the UUID is set
   * before the CUTS_System_Metric class is visited, then the UUID
   * will be stored in the file.
   *
   * @param[in]     uuid            UUID to store in the XML file.
   */
  void set_uuid (const ACE_CString & uuid);

  /**
   * Visit the component metrics. This method generates the
   * <ComponentMetrics> section of the XML file.
   *
   * @param[in]     metrics     Reference to the metrics.
   */
  virtual void visit_system_metrics (const CUTS_System_Metric & metrics);

  /**
   * Visit the system metrics. This method generates the
   * <SystemMetrics> section of the XML file. It will also
   * insert the timestamp when the generation started.
   *
   * @param[in]     metrics     Reference to the metrics.
   */
  virtual void visit_component_metrics (const CUTS_Component_Metric & metrics);

  /**
   * Visit the port metrics. This method generates the
   * <ComponentMetrics> section of the XML file.
   *
   * @param[in]     metrics     Reference to the metrics.
   */
  virtual void visit_port_metrics (const CUTS_Port_Metric & metrics);

  /**
   * Visit the time metrics. This method generates the
   * <ComponentMetrics> section of the XML file.
   *
   * @param[in]     metrics     Reference to the metrics.
   */
  virtual void visit_time_metrics (const CUTS_Time_Metric & metrics);

private:
  void print_time_value (const ACE_CString & header,
                         const ACE_Time_Value & tv);

  /// Registry of the components.
  const CUTS_Component_Registry & registry_;

  /// Location of the generate XML file (absolute/relative).
  ACE_CString pathname_;

  /// Output stream for the XML representation.
  std::ofstream output_;

  /// Current timestamp for XML generation.
  ACE_Time_Value timestamp_;

  /// UUID for the generated XML file.
  ACE_CString uuid_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/XML_Metrics_Writer.inl"
#endif

#endif  // !defined _CUTS_XML_METRICS_WRITER_H_
