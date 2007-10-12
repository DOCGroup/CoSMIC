// -*- C++ -*-

//=============================================================================
/**
 * @file        CPU_Worker_T.h
 *
 * Templatized version of the CPU worker.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CPU_WORKER_T_H_
#define _CUTS_CPU_WORKER_T_H_

#include "cuts/Worker.h"

//=============================================================================
/**
 * @class CUTS_CPU_Worker_T
 *
 * Templatized version of the CPU worker. The CPU worker is
 * parameterized by a functor that defines the type of work to
 * execute.
 *
 * Template parameter requirements:
 * - Must implement perform_work () method, which executes one
 *   repetition of defined the workload.
 */
//=============================================================================

template <typename T>
class CUTS_CPU_Worker_T : public CUTS_Worker
{
public:
  /// Type definition of the work function.
  typedef T _work_function;

  /**
   * Default constructor.
   *
   * @param[in]     work_function       The work function for the worker.
   */
  CUTS_CPU_Worker_T (T work_function);

  /// Destructor.
  virtual ~CUTS_CPU_Worker_T (void);

  /**
   * Occupy the CPU for a specified amount of time. This method
   * is experimental and still under investigation.
   *
   * @param[in]     msec      Number of msec to occupy the CPU
   * @return        Number of cycles executed.
   */
  void run (size_t msec);

  // Calibrate the CPU worker.
  virtual bool calibrate (void);

private:
  /**
   * Helper method to initailize the CPU workload generator. This
   * includes loading the calibration factor for the worker on its
   * current host.
   *
   * @retval        true      Successfully initialized worker
   * @retval        false     Failed to initialize worker
   */
  bool init (void);

  /**
   * Helper method that initialized the calibration. This step
   * usually involves set the priority and scheduling class for
   * the calibration thread. If neither can be set, then the
   * calibration will continue. The results, however, may not be
   * reliable.
   *
   * @retval        true      Successfully initialized calibration
   * @retval        false     Failed to initialize calibration
   */
  bool init_calibrate (void);

  /// Helper method that determines the calibration loop factor
  /// for the target scaling factor time.
  size_t calibrate_i (void);

  /// Helper method that verifies the calibration loop factor.
  void verify_calibration (size_t trycount,
                           const ACE_CString & temp_filename);

  /**
   * Executes the worker method for the specified \a count. The
   * \a count reflects the number of milliseconds to occupy the CPU.
   * It is not the actual number of milliseconds.
   *
   * @param[in]     count       Number of loops to execute.
   */
  void work (size_t count);

  /**
   * Generate the calibration filename.
   *
   * @param[out]    filename    Full pathname of calibration file.
   */
  void make_calibration_filename (ACE_CString & filename);

  /// Generates a temp filename for calibration operation.
  void make_temp_filename (ACE_CString & tempfile);

  /// Generate the basename of the calibration file.
  void make_basename (ACE_CString & basename);

  /// The target calibration time.
  const size_t target_;

  /// The margin of error allowed in timing.
  const size_t margin_;

  /// Number of counts per millisecond.
  double count_per_msec_;

  /// The work function for the CPU worker.
  T work_function_;
};

#include "CPU_Worker_T.cpp"

#endif  // !defined _CUTS_CPU_WORKER_T_H_
