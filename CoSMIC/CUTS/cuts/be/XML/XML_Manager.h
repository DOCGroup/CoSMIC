// -*- C++ -*-

//=============================================================================
/**
 * @file        XML_Manager.h
 *
 * Defines the CUTS_BE_XML_Manager manager object
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_XML_MANAGER_H_
#define _CUTS_BE_XML_MANAGER_H_

#include "cuts/be/BE_Manager_T.h"
#include "cuts/be/BE_Workspace_Strategy.h"
#include "cuts/be/BE_Project_Generator.h"
#include "XML_Generators.h"

typedef CUTS_BE_Manager_T <CUTS_BE_Workspace_Strategy,
                           CUTS_BE_Project_Generator,
                           CUTS_BE_Xml>
                           CUTS_BE_XML_Manager;

#endif  // !defined _CUTS_BE_XML_MANAGER_H_
