// -*- C++ -*-

//=============================================================================
/**
 * @file      CUTS_GEMS.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_GEMS_H_
#define _CUTS_GEMS_H_

#include "CUTS_GEMS_export.h"
#include "GEMS/GEMSServerC.h"
#include "cuts/BDC/BDC_Service.h"
#include "ace/SStringfwd.h"
#include "ace/String_Base.h"
#include <map>
#include <string>

//=============================================================================
/**
 * @class CUTS_GEMS_Service
 *
 * Service for allowing GEMS to communicate with CUTS. This service
 * will extract all the components in the model and map them to the
 * components in the CUTS model. It will also push data from the CUTS
 * model into the GEMS model so that the constraint solver can be used
 * to derive new deployments based on performance metrics.
 */
//=============================================================================

class CUTS_GEMS_Service : public CUTS_BDC_Service
{
public:
  /// Default constructor.
  CUTS_GEMS_Service (void);

  /// Destructor.
  virtual ~CUTS_GEMS_Service (void);

  int init (int argc, ACE_TCHAR * argv []);

  int handle_activate (void);

  int handle_deactivate (void);

  int handle_component (const CUTS_Component_Info & info);

private:
  int parse_args (int argc, ACE_TCHAR * argv []);

  int init_gems (void);
  int fini_gems (void);

  /// The GEMS remote server.
  ::GEMSServer::Model_var gems_;

  /// Stringy version of the GEMS reference.
  ACE_CString gems_string_;

  typedef std::map <std::string, size_t> Name_Id_Map;
  typedef std::map <size_t, std::string> Id_Name_Map;

  /// Id -> name mapping for GEMS.
  Name_Id_Map gems_id_;

  /// Id -> name mapping for CUTS.
  Name_Id_Map cuts_id_;

  Id_Name_Map cuts_id_ex_;

  /// Verbose flag for the service.
  bool verbose_;
};

CUTS_BDC_SERVICE_DECL (CUTS_GEMS_Export);

#if defined (__CUTS_INLINE__)
#include "CUTS_GEMS.inl"
#endif

#endif  // !defined _CUTS_GEMS_H_
