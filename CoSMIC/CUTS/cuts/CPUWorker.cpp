// $Id$

#include "cuts/CPUWorker.h"
#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/High_Res_Timer.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/CPUWorker.inl"
#endif

#include <iostream>

#define CUTS_CPU_CYCLES 25

CUTS_ACTION_TABLE_BEGIN (CUTS_CPU_Worker, CUTS_Worker)
  CUTS_ACTION_TABLE_ENTRY("Run_Processor", CUTS_CPU_Worker::Run_Processor);
CUTS_ACTION_TABLE_END (CUTS_CPU_Worker)

//
// CUTS_CPU_Worker
//
CUTS_CPU_Worker::CUTS_CPU_Worker (void)
: visits_ (0),
  calib_ (0),
  counts_per_run_ (25)
{
  ACE_High_Res_Timer timer;
  timer.start ();
  timer.stop ();

  ACE_Time_Value calib;
  timer.elapsed_time (calib);

  this->calib_ = calib.usec ();
}

//
// ~CUTS_CPU_Worker
//
CUTS_CPU_Worker::~CUTS_CPU_Worker (void)
{

}

//
// process
//
void CUTS_CPU_Worker::process (void)
{
  ++ this->visits_;

  for (int cycle = 0; cycle < CUTS_CPU_CYCLES; cycle ++)
  {
    ACE::is_prime (16127, 2, 16127 / 2);
  }
}

//
// run
//
size_t CUTS_CPU_Worker::run (size_t msec)
{
  size_t count = (msec * 1000) / this->calib_;
  size_t intervals = count / this->counts_per_run_;
  size_t remaining = count % this->counts_per_run_;

  for (size_t i = 0; i < intervals; i ++)
    this->run_i (this->counts_per_run_);

  if (remaining > 0)
    this->run_i (remaining);

  return (intervals * this->counts_per_run_) + remaining;
}

//
// run
//
void CUTS_CPU_Worker::run_i (size_t count)
{
  ACE_High_Res_Timer timer;

  for (size_t i = 0; i < count; i ++)
    timer.start ();
}
