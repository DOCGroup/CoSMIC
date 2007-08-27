// -*- C++ -*-

//=============================================================================
/**
 * @file      Natural_Lang_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_NATURAL_LANG_MANAGER_H_
#define _CUTS_BE_NATURAL_LANG_MANAGER_H_

#include "cuts/be/BE_Manager_T.h"
#include "cuts/be/BE_Workspace_Strategy.h"
#include "cuts/be/BE_Project_Generator.h"
#include "Natural_Lang_Generators.h"

typedef CUTS_BE_Manager_T <CUTS_BE_Workspace_Strategy,
                           CUTS_BE_Project_Generator,
                           CUTS_BE_Natural_Lang>
                           CUTS_BE_Natural_Lang_Manager;

#endif  // !defined _CUTS_BE_NATURAL_LANG_MANAGER_H_
