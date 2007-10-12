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

#include "CPU_Worker_export.h"
#include "CPU_Worker_T.h"
#include "ace/High_Res_Timer.h"

//=============================================================================
/**
 * @struct CUTS_Basic_CPU_Worker
 */
//=============================================================================

struct CUTS_Basic_CPU_Worker
{
  inline void perform_work (void)
  {
    this->timer_.start ();
  }

private:
  ACE_High_Res_Timer timer_;
};

//=============================================================================
/**
 * @class CUTS_CPU_Worker
 *
 * Basic worker that burns CPU time. The CPU worker is designed to
 * occupy the CPU for the specified number of milliseconds. It does
 * not take into account CPU utilization, or monitor it.
 */
//=============================================================================

class CUTS_CPU_WORKER_Export CUTS_CPU_Worker :
  public CUTS_CPU_Worker_T <CUTS_Basic_CPU_Worker>
{
public:
  /// Constructor.
  CUTS_CPU_Worker (void);

  /// Destructor.
  virtual ~CUTS_CPU_Worker (void);
};

CUTS_WORKER_FACTORY_EXPORT_DECL (CUTS_CPU_WORKER_Export);

#endif  // !defined _CUTS_CPU_WORKER_H_
