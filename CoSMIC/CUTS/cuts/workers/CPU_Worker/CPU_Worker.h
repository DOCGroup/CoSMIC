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
#include "CPU_Worker_export.h"

//=============================================================================
/**
 * @class CUTS_CPU_Worker
 *
 * @brief Basic worker that burns CPU cycles.
 */
//=============================================================================

class CUTS_CPU_WORKER_Export CUTS_CPU_Worker : public CUTS_Worker
{
public:
  /// Constructor.
  CUTS_CPU_Worker (void);

  /// Destructor.
  virtual ~CUTS_CPU_Worker (void);

  /**
   * Get the number of visits handled by this CPU worker.
   */
  virtual long counter (void) const;

  /**
   * Occupy the CPU for a specified amount of time. This method
   * is experimental and still under investigation.
   *
   * @param[in]     msec      Number of msec to occupy the CPU
   * @return        Number of cycles executed.
   */
  void run (size_t msec);

  // Calibrate the CPU worker.
  bool calibrate (void);

private:
  bool init (void);

  void run_i (size_t count);

  bool init_calibrate (void);

  size_t calibrate_i (void);

  void verify_calibration (void);

  void work (size_t count);

  void make_calibration_filename (ACE_CString & filename);

  /// Number of visits completed by the CPU worker.
  long visits_;

  /// The target calibration time.
  const size_t target_;

  /// The margin of error allowed in timing.
  const size_t margin_;

  /// Number of counts per millisecond.
  double count_per_msec_;
};

CUTS_WORKER_FACTORY_EXPORT_DECL (CUTS_CPU_WORKER_Export);

#if defined (__CUTS_INLINE__)
#include "CPU_Worker.inl"
#endif

#endif  // !defined _CUTS_CPU_WORKER_H_
