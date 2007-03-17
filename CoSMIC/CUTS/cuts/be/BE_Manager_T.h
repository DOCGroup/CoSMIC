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

//=============================================================================
/**
 * @class CUTS_BE_Manager_T
 */
//=============================================================================

template <typename WORKSPACE, typename PROJECT,  typename EXECUTOR>
class CUTS_BE_Manager_T : public CUTS_BE_Manager
{
public:
  /// Default constructor.
  CUTS_BE_Manager_T (void);

  /// Destructor.
  virtual ~CUTS_BE_Manager_T (void);

  // Execute the manager on the root folder.
  virtual bool handle (const PICML::RootFolder & root);
};

#include "BE_Manager_T.cpp"

#endif  // !defined _CUTS_BE_MANAGER_T_H_
