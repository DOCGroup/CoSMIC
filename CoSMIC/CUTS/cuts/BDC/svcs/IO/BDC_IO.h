// -*- C++ -*-

//=============================================================================
/**
 * @file      BDC_IO.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BDC_IO_H_
#define _CUTS_BDC_IO_H_

#include "BDC_IO_export.h"
#include "cuts/BDC/BDC_Service.h"
#include "cuts/Component_Type.h"

//=============================================================================
/**
 * @class CUTS_BDC_IO_Servie
 *
 * I/O service for the BDC. The main purpose of this service is to
 * print to the console (or file) information about each collection
 * period of the BDC.
 */
//=============================================================================

class CUTS_BDC_IO_Service : public CUTS_BDC_Service
{
public:
  /// Default constructor.
  CUTS_BDC_IO_Service (void);

  /// Destructor.
  virtual ~CUTS_BDC_IO_Service (void);

  // Handle the performance metric's event.
  virtual int handle_metrics (const CUTS_System_Metric & metrics);

  // Handle the component events.
  virtual int handle_component (const CUTS_Component_Info & info);

private:
  void print_port_description (const ACE_CString & title,
                               const CUTS_Port_Description_Map & desc);

  static const char * state_cstr_ [2];
};

CUTS_BDC_SERVICE_DECL (CUTS_BDC_IO_Export);

#endif  // !defined _CUTS_BDC_IO_H_

