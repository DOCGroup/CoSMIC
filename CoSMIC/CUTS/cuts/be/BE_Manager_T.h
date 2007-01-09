// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Manager_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_MANAGER_T_H_
#define _CUTS_BE_MANAGER_T_H_

#include "BE_Manager.h"
#include "BE_Workspace_Generator_T.h"
#include "BE_Impl_Generator_T.h"

//=============================================================================
/**
 * @class CUTS_BE_Manager_T
 */
//=============================================================================

template <typename PROJ_STRATEGY,
          typename EXEC_STRATEGY,
          typename PROXY_STRATEGY>
class CUTS_BE_Manager_T : public CUTS_BE_Manager
{
public:
  /// Default constructor.
  CUTS_BE_Manager_T (void);

  /// Destructor.
  virtual ~CUTS_BE_Manager_T (void);

  // Execute the manager on the root folder.
  virtual bool handle (const PICML::RootFolder & root);

private:
  /// Workspace generator for the manager.
  CUTS_BE_Workspace_Generator_T <
    PROJ_STRATEGY>
    workspace_generator_;

  /// Implementation generator for the manager.
  CUTS_BE_Impl_Generator_T <
    EXEC_STRATEGY>
    exec_generator_;

  CUTS_BE_Impl_Generator_T <
    PROXY_STRATEGY>
    pxoxy_generator_;
};

#include "BE_Manager_T.cpp"

#endif  // !defined _CUTS_BE_MANAGER_T_H_
