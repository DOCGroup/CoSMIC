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

#include "cuts/Metrics_Visitor.h"
#include "ace/SString.h"
#include "ace/streams.h"
#include "ace/Time_Value.h"

// Forward decl.
class CUTS_Component_Registry;

// Forward decl.
struct CUTS_Component_Info;

//=============================================================================
/**
 * @class CUTS_XML_Metrics_Writer
 *
 * Utility class for generating the system metrics in an XML format.
 */
//=============================================================================

class CUTS_Export CUTS_XML_Metrics_Writer :
  public CUTS_Metrics_Visitor
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

  // Handle the system metric visit.
  virtual void visit_system_metric (const CUTS_System_Metric & metrics);

  // Handle the component metric visit.
  virtual void visit_component_metric (const CUTS_Component_Metric & metrics);

  // Handle the port metric visit.
  virtual void visit_port_metric (const CUTS_Port_Metric & metrics);

  // Handle the port metric visit.
  virtual void visit_port_measurement (const CUTS_Port_Measurement & pm);

  // Handle the time measurement visit.
  virtual void visit_time_measurement (const CUTS_Time_Measurement & tm);

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

  /// Information about the current component.
  const CUTS_Component_Info * myinfo_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/XML_Metrics_Writer.inl"
#endif

#endif  // !defined _CUTS_XML_METRICS_WRITER_H_
