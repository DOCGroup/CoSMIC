// -*- C++ -*-

//=============================================================================
/**
 * @file    CPUWorker.h
 *
 * $Id$
 *
 * This file contains the default CPU worker in CUTS.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_CPU_WORKER_H_
#define _CUTS_CPU_WORKER_H_

#include "cuts/Worker.h"
#include "cuts/Worker_T.h"

/**
 *
 */
class CUTS_Export CUTS_CPU_Worker
  : public CUTS_Worker
{
public:
  struct Run_Processor :
    public CUTS_Action_T <CUTS_CPU_Worker>
  {
    /// Constructor.
    Run_Processor (CUTS_CPU_Worker & worker)
      : worker_ (worker)
    {

    }

    /// Functor operator to perform allocation on target worker.
    void operator () (void)
    {
      this->worker_.process ();
    }

  private:
    /// Target worker.
    CUTS_CPU_Worker & worker_;
  };

  /// Constructor.
  CUTS_CPU_Worker (void);

  /// Destructor.
  virtual ~CUTS_CPU_Worker (void);

  /// Run the CPU for the given number of repititions.
  virtual void process (void);
};

//=============================================================================
/**
 * CUTS_Worker_Traits <CUTS_Memory_Worker>
 */
//=============================================================================

template <>
class CUTS_Worker_Traits <CUTS_CPU_Worker>
{
public:
  static const long worker_id_ = 2;
};

//=============================================================================
/**
 * CUTS_Action_Traits < >
 */
//=============================================================================

template <>
class CUTS_Action_Traits <CUTS_CPU_Worker::Run_Processor>
{
public:
  static const long action_id_ = 1;
};

#endif  // !defined _CUTS_CPU_WORKER_H_
