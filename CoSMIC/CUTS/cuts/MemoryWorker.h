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
#include "cuts/Worker_T.h"
#include <queue>

class CUTS_Export CUTS_Memory_Worker
  : public CUTS_Worker
{
public:
  //===========================================================================
  /**
   * @struct Allocate_Memory
   */
  //===========================================================================

  struct Allocate_Memory :
    public CUTS_Action_T <CUTS_Memory_Worker>
  {
    /// Constructor.
    Allocate_Memory (CUTS_Memory_Worker & worker, size_t kilobytes)
      : worker_ (worker),
        kilobytes_ (kilobytes)
    {

    }

    /// Functor operator to perform allocation on target worker.
    void operator () (void)
    {
      this->worker_.allocate (this->kilobytes_);
    }
  private:
    /// Target worker.
    CUTS_Memory_Worker & worker_;

    /// Size of memory operation.
    size_t kilobytes_;
  };

  //===========================================================================
  /**
   *
   */
  //===========================================================================

  struct Deallocate_Memory :
    public CUTS_Action_T <CUTS_Memory_Worker>
  {
    /// Constructor.
    Deallocate_Memory (CUTS_Memory_Worker & worker, size_t kilobytes)
      : worker_ (worker),
        kilobytes_ (kilobytes)
    {

    }

    /// Functor operator to perform deallocation on target worker.
    void operator () (void)
    {
      this->worker_.deallocate (this->kilobytes_);
    }

  private:
    /// Target worker.
    CUTS_Memory_Worker & worker_;

    /// Size of memory operation.
    size_t kilobytes_;
  };

  /// Constructor.
  CUTS_Memory_Worker (void);

  /// Destructor.
  virtual ~CUTS_Memory_Worker (void);

  /// Perform memory allocation.
  virtual void allocate (size_t kilobytes);

  /// Perform memory deallocation.
  virtual void deallocate (size_t kilobytes);

private:
  /// Type definition for the container of allocations.
  typedef std::queue <char *> Memory_Allocations;

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

//=============================================================================
/**
 * CUTS_Action_Traits < >
 */
//=============================================================================

template <>
class CUTS_Action_Traits <CUTS_Memory_Worker::Allocate_Memory>
{
public:
  static const long action_id_ = 1;
};

template <>
class CUTS_Action_Traits <CUTS_Memory_Worker::Deallocate_Memory>
{
public:
  static const long action_id_ = 2;
};

#endif  // !defined _CUTS_MEMORY_WORKER_H_
