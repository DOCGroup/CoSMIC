// $Id$

#include "PICML/PICML.h"
#include "BE_Workspace_Generator_T.h"
#include "BE_Impl_Generator_T.h"

//
// CUTS_BE_Manager_T
//
template <typename WORKSPACE_STRATEGY,
          typename PROJECT_STRATEGY,
          typename EXECUTOR_STRATEGY>
CUTS_BE_Manager_T <
WORKSPACE_STRATEGY, PROJECT_STRATEGY, EXECUTOR_STRATEGY>::
CUTS_BE_Manager_T (void)
{

}

//
// ~CUTS_BE_Manager_T
//
template <typename WORKSPACE_STRATEGY,
          typename PROJECT_STRATEGY,
          typename EXECUTOR_STRATEGY>
CUTS_BE_Manager_T <
WORKSPACE_STRATEGY, PROJECT_STRATEGY, EXECUTOR_STRATEGY>::
~CUTS_BE_Manager_T (void)
{

}

//
// handle
//
template <typename WORKSPACE_STRATEGY,
          typename PROJECT_STRATEGY,
          typename EXECUTOR_STRATEGY>
bool CUTS_BE_Manager_T <
WORKSPACE_STRATEGY, PROJECT_STRATEGY, EXECUTOR_STRATEGY>::
handle (const PICML::RootFolder & root)
{
  // Generate the executor implementations.
  CUTS_BE_Impl_Generator_T <EXECUTOR_STRATEGY> exec_generator;
  PICML::RootFolder tmp_root (root);
  tmp_root.Accept (exec_generator);

  // Workspace generator for the manager.
  CUTS_BE_Workspace_Generator_T <
    WORKSPACE_STRATEGY, PROJECT_STRATEGY> workspace_generator;

  workspace_generator.generate ();
  return true;
}
