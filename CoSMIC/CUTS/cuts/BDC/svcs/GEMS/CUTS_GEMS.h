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
#include "cuts/svcs/dbase/DB_Service.h"
#include "GEMS/GEMS.h"
#include "ace/SString.h"
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

class CUTS_GEMS_Service :
  public CUTS_BDC_Service,
  public CUTS_DB_Service
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

  /// Populate the node map with GEMS node elements.
  int populate_component_map (void);

  typedef std::map <std::string, size_t> Name_Id_Map;

  typedef std::map <size_t, std::string> Id_Name_Map;

  /// Type definition for mapping names to GME models.
  typedef std::map <std::string,
                    std::pair <size_t, GEMS::Model *> >
                    GEMS_Model_Map;

  /// Verbose flag for the service.
  bool verbose_;

  /// Location of the baseline server.
  ACE_CString baseline_server_;

  /// Stringy version of the GEMS reference.
  ACE_CString gems_string_;

  /// Id -> name mapping for GEMS.
  Name_Id_Map gems_id_;

  /// Id -> name mapping for CUTS.
  Name_Id_Map cuts_id_;

  Id_Name_Map cuts_id_ex_;

  typedef std::map <size_t, std::string> ID_String_Map;

  ID_String_Map host_map_;

  /// Map for mapping names to nodes in GEMS.
  GEMS_Model_Map component_map_;

  /// Use the naming service to resolve GEMS.
  bool use_naming_service_;

  /// GEMS method to invoke after values are pulled from GEMS.
  ACE_CString init_gems_;

  /// GEMS method to invoke after values are pushed to GEMS.
  ACE_CString fini_gems_;
};

CUTS_BDC_SERVICE_DECL (CUTS_GEMS_Export);

#if defined (__CUTS_INLINE__)
#include "CUTS_GEMS.inl"
#endif

#endif  // !defined _CUTS_GEMS_H_
