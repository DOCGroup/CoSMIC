// $Id$

#include "PICML/PICML.h"

//
// CUTS_BE_Manager_T
//
template <typename PROJ_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
CUTS_BE_Manager_T <PROJ_STRATEGY, EXEC_STRATEGY, PROXY_STRATEGY>::
CUTS_BE_Manager_T (void)
{

}

//
// ~CUTS_BE_Manager_T
//
template <typename PROJ_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
CUTS_BE_Manager_T <PROJ_STRATEGY, EXEC_STRATEGY, PROXY_STRATEGY>::
~CUTS_BE_Manager_T (void)
{

}

//
// handle
//
template <typename PROJ_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
bool CUTS_BE_Manager_T <PROJ_STRATEGY, EXEC_STRATEGY, PROXY_STRATEGY>::
handle (const PICML::RootFolder & root)
{
  PICML::RootFolder tmp_root (root);

  // Generate the executor & proxy implemenation.
  tmp_root.Accept (this->exec_generator_);
  tmp_root.Accept (this->pxoxy_generator_);

  // Generate the workspace.
  return this->workspace_generator_.generate ();
}
