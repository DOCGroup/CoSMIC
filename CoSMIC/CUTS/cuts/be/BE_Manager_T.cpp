// $Id$

#include "PICML/PICML.h"
#include "BE_Workspace_Generator_T.h"
#include "BE_Impl_Generator_T.h"

//
// CUTS_BE_Manager_T
//
template <typename WORKSPACE_STRATEGY,
          typename PROJECT_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
CUTS_BE_Manager_T <
WORKSPACE_STRATEGY, PROJECT_STRATEGY, EXEC_STRATEGY, PROXY_STRATEGY>::
CUTS_BE_Manager_T (void)
{

}

//
// ~CUTS_BE_Manager_T
//
template <typename WORKSPACE_STRATEGY,
          typename PROJECT_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
CUTS_BE_Manager_T <
WORKSPACE_STRATEGY, PROJECT_STRATEGY, EXEC_STRATEGY, PROXY_STRATEGY>::
~CUTS_BE_Manager_T (void)
{

}

//
// handle
//
template <typename WORKSPACE_STRATEGY,
          typename PROJECT_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
bool CUTS_BE_Manager_T <
WORKSPACE_STRATEGY, PROJECT_STRATEGY, EXEC_STRATEGY, PROXY_STRATEGY>::
handle (const PICML::RootFolder & root)
{
  CUTS_BE_Impl_Generator_T <EXEC_STRATEGY> exec_generator;
  CUTS_BE_Impl_Generator_T <PROXY_STRATEGY> pxoxy_generator;

  // Generate the executor and proxy implemenation.
  PICML::RootFolder tmp_root (root);
  tmp_root.Accept (exec_generator);
  tmp_root.Accept (pxoxy_generator);

  /// Workspace generator for the manager.
  CUTS_BE_Workspace_Generator_T <
    WORKSPACE_STRATEGY, PROJECT_STRATEGY> workspace_generator;

  return workspace_generator.generate ();
}
