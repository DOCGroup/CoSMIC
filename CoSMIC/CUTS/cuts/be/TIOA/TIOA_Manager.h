// -*- C++ -*-

//=============================================================================
/**
 * @file        TIOA_Manager.h
 *
 * Defines the CUTS_BE_TIOA_Manager manager object
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_TIOA_MANAGER_H_
#define _CUTS_BE_TIOA_MANAGER_H_

#include "cuts/be/BE_Manager_T.h"
#include "cuts/be/BE_Workspace_Strategy.h"
#include "cuts/be/BE_Project_Generator.h"
#include "TIOA_Generators.h"

typedef CUTS_BE_Manager_T <CUTS_BE_Workspace_Strategy,
                           CUTS_BE_Project_Generator,
                           CUTS_BE_Tioa>
                           CUTS_BE_TIOA_Manager;

#endif  // !defined _CUTS_BE_TIOA_MANAGER_H_
