// -*- C++ -*-

//=============================================================================
/**
 * @file        CUTS_XML.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_XML_H_
#define _CUTS_XML_H_

#include "CUTS_XML_export.h"
#include "cuts/BDC/BDC_Service.h"
#include "ace/SString.h"

//=============================================================================
/**
 * @class CUTS_XML_Service
 *
 * XML file generator the BDC. This service scribes the collected
 * metrics to the specified file using XML format.
 */
//=============================================================================

class CUTS_XML_Service : public CUTS_BDC_Service
{
public:
  /// Default constructor.
  CUTS_XML_Service (void);

  /// Destructor.
  virtual ~CUTS_XML_Service (void);

  // Initialize the service.
  int init (int argc, ACE_TCHAR * argv []);

  // Finialize the service.
  int fini (void);

  // Callback method for handling the component metrics.
  int handle_metrics (const CUTS_System_Metric & metrics);

private:
  /// Command-line argument parser.
  int parse_args (int argc, ACE_TCHAR * argv []);

  /// Name of the XML file.
  ACE_CString output_directory_;

  /// Verbose state of the service.
  bool verbose_;
};

CUTS_BDC_SERVICE_DECL (CUTS_XML_Export);

#endif  // !defined _CUTS_XML_H_
