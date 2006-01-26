// -*- C++ -*-

//=============================================================================
/**
 * @file    Worker.h
 *
 * $Id$
 *
 * This file contains the base class for all workers in CUTS.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_WORKER_H_
#define  _CUTS_WORKER_H_

#include "cuts/config.h"

//=============================================================================
/**
 * @class CUTS_Worker
 *
 * @brief Abstact base class for worker objects.
 *
 * This class contains methods that are common across all worker objects
 * in CUTS.
 */
//=============================================================================

class CUTS_Export CUTS_Worker
{
public:
  /// Constructor.
  CUTS_Worker (void);

  /// Destructor.
  virtual ~CUTS_Worker (void) = 0;

  /// Get the parent of the worker.
  long parent (void) const;

  /// Set the parent of the worker.
  void parent (long parent);

protected:
  /// ID of the parent
  long parent_;
};

#if defined (__CUTS_INLINE__)
# include "cuts/Worker.inl"
#endif

#endif  // !defined _CUTS_WORKER_H_