// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CIAO_MANAGER_H_
#define _CUTS_BE_CIAO_MANAGER_H_

#include "CIAO_Project_Generator.h"
#include "CIAO_Traits.h"
#include "cuts/be/BE_Manager_T.h"
#include "cuts/be/BE_MPC_Workspace.h"

/// Type definition for the CIAO backend manager.
typedef CUTS_BE_Manager_T <CUTS_BE_MPC_Workspace,
                           CUTS_CIAO_Project_Generator,
                           CUTS_BE_CIAO>
                           CIAO_BE_Manager;

#endif  // !defined _CUTS_BE_CIAO_MANAGER_H_
