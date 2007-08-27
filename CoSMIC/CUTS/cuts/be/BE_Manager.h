// -*- C++ -*-

//=============================================================================
/**
 * @file        BE_Manager.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_MANAGER_H_
#define _CUTS_BE_MANAGER_H_

#include "BE_export.h"

namespace PICML
{
  // forward decl.
  class RootFolder;
}

//=============================================================================
/**
 * @class CUTS_BE_Manager
 *
 * This is the manager used by each backend.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Manager
{
public:
  /**
   * Handle the root folder. This actually causes the manager
   * to begin its execution.
   *
   * @param[in]       root        Reference to root folder.
   */
  virtual bool handle (const PICML::RootFolder & root) = 0;

  /// Close the manager and release its resources.
  virtual void close (void);

protected:
  /// Default constructor.
  CUTS_BE_Manager (void);

  /// Destructor.
  virtual ~CUTS_BE_Manager (void);
};

#if defined (__CUTS_INLINE__)
#include "BE_Manager.inl"
#endif

#endif  // !defined _CUTS_BE_MANAGER_H_
