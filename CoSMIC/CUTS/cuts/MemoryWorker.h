// -*- C++ -*-

//=============================================================================
/**
 * @file    MemoryWorker.h
 *
 * $Id$
 *
 * This file contains the default memory worker in CUTS.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_MEMORY_WORKER_H_
#define _CUTS_MEMORY_WORKER_H_

#include "cuts/Worker.h"
#include "ace/Thread_Mutex.h"
#include <list>

class CUTS_Export CUTS_Memory_Worker : public CUTS_Worker
{
public:
  /// Constructor.
  CUTS_Memory_Worker (void);

  /// Destructor.
  virtual ~CUTS_Memory_Worker (void);

  /// Perform memory allocation.
  virtual void allocate (size_t kilobytes);

  /// Perform memory deallocation.
  virtual void deallocate (size_t kilobytes);

  virtual long counter (void) const;

private:
  /// Type definition for the container of allocations.
  typedef std::list <char *> Memory_Allocations;

  /// Locking mechanism for protecting <memory_>.
  ACE_Thread_Mutex lock_;

  /// Collection of memory allocations.
  Memory_Allocations memory_;
};

//=============================================================================
/**
 * CUTS_Worker_Traits <CUTS_Memory_Worker>
 */
//=============================================================================

template <>
class CUTS_Worker_Traits <CUTS_Memory_Worker>
{
public:
  static const long worker_id_ = 1;
};

#if defined (__CUTS_INLINE__)
#include "cuts/MemoryWorker.inl"
#endif

#endif  // !defined _CUTS_MEMORY_WORKER_H_
