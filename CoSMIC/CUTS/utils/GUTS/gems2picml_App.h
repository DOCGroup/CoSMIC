// $Id$

//=============================================================================
/**
 * @file      gems2picml_App.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_GEMS2PICML_APP_H_
#define _CUTS_GEMS2PICML_APP_H_

#include "G2P_Options.h"
#include "gme/GME.h"
#include "GEMS/GEMS.h"
#include <memory>

//=============================================================================
/**
 * @class gems2picml_App
 */
//=============================================================================

class gems2picml_App
{
public:
  /// Default constructor.
  gems2picml_App (void);

  /// Destructor.
  ~gems2picml_App (void);

  int run (int argc, char * argv []);

private:
  int parse_args (int argc, char * argv []);

  /// Initialize the GEMS backend.
  int init_gems (void);

  /// Initialize the GME backend.
  int init_gme_project (void);

  /// Finalize the GME backend.
  void fini_gme_project (void);

  int find_deployment_plan (GME::Model & plan);

  int convert_gems_2_picml (GME::Model & deployment);

  int run_component (void);

  /// The command line options.
  CUTS_G2P_Options options_;

  /// Reference to the CORBA ORB.
  CORBA::ORB_var orb_;

  /// Collection of all the deployment connections.
  GEMS::Connection_Set deployments_;

  std::auto_ptr <GME::Project> project_;
};

#endif  // !defined _CUTS_GEMS2PICML_APP_H_
