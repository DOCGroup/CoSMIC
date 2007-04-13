// $Id$

#include "cuts/CPUWorker.h"
#include "ace/Guard_T.h"
#include "ace/High_Res_Timer.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/Sched_Params.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/CPUWorker.inl"
#endif

#include <numeric>
#include <fstream>

#define CUTS_CPU_CYCLES 25

CUTS_ACTION_TABLE_BEGIN (CUTS_CPU_Worker, CUTS_Worker)
  CUTS_ACTION_TABLE_ENTRY("Run_Processor", CUTS_CPU_Worker::Run_Processor);
CUTS_ACTION_TABLE_END (CUTS_CPU_Worker)

#define TEST_RUNS        10
#define TEST_MAX_MSEC    1000
#define TEST_INC_MSEC    10

CUTS_WORKER_FACTORY_EXPORT_IMPL (CUTS_CPU_Worker);

//
// CUTS_CPU_Worker
//
CUTS_CPU_Worker::CUTS_CPU_Worker (void)
: visits_ (0),
  target_ (20000),
  margin_ (100),
  count_per_msec_ (0.0)
{
  this->init ();
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
void CUTS_CPU_Worker::run (size_t msec)
{
  if (this->count_per_msec_ == 0.0)
  {
    ACE_ERROR ((LM_CRITICAL,
                "*** critical (CUTS_CPU_Worker): "
                "worker not calibrated!!\n"));
  }

  double count = static_cast <double> (msec) * this->count_per_msec_;
  this->work (static_cast <size_t> (count));
}

//
// init_calibrate
//
bool CUTS_CPU_Worker::init_calibrate (void)
{
  int scope = ACE_SCOPE_THREAD;
  int ctrlprio =
    ACE_Sched_Params::priority_max (ACE_SCHED_FIFO,
                                    scope);

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): setting FIFO thread "
              "priority to %d\n",
              ctrlprio));

  if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                              ctrlprio,
                                              scope)) != ESUCCESS)
  {
    if (ACE_OS::last_error () == EPERM)
    {
      ACE_DEBUG ((LM_ERROR,
                  "*** error (CUTS_CPU_Worker): user is not superuser, "
                  "calibration in time-shared class\n"));
    }
    else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (CUTS_CPU_Worker): sched_params failed\n"));
    }

    return false;
  }

  return true;
}

//
// calibrate
//
bool CUTS_CPU_Worker::calibrate (void)
{
  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): running calibration; "
              "please be patient...\n"));

  // Initialize the calibration of the worker.
  if (!this->init_calibrate ())
    return false;

  // Run the calibration
  size_t calib_loop_factor = this->calibrate_i ();

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): calibration loop factor = %u\n",
              calib_loop_factor));

  this->count_per_msec_ =
    ((double) calib_loop_factor * 1000.0) / (double) this->target_;

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): counts per msec = %d\n",
              this->count_per_msec_));

  // Verify the calibration.
  verify_calibration ();

  // Write the calibration to file.
  ACE_CString filename;
  this->make_calibration_filename (filename);

  std::ofstream outfile;
  outfile.open (filename.c_str ());

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): saving calibration to %s\n",
              filename.c_str ()));

  if (outfile.is_open ())
  {
    outfile << this->count_per_msec_ << std::endl;
    outfile.close ();
  }
  else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (CUTS_CPU_Worker): failed to open %s "
                  "for writing\n",
                  filename.c_str ()));
    }

  return outfile.good ();
}

//
// calibrate_i
//
size_t CUTS_CPU_Worker::calibrate_i (void)
{
  ACE_Time_Value start, stop;
  size_t count;
  bool done = false;

  ACE_High_Res_Timer timer;

  // Create the initial upper and lower boundaries. The upper
  // boundary is 10-fold the
  size_t lower = 0;
  size_t upper = 10000000 /*std::numeric_limits <size_t>::max ()*/;

  do
  {
    // Calculate the average number of counts.
    count = (upper + lower) / 2;

    ACE_DEBUG ((LM_DEBUG,
                "--- lower|count|upper = %u|%u|%u\n",
                lower,
                count,
                upper));

    // Execute the number of counts.
    timer.start ();
    work (count);
    timer.stop ();

    ACE_Time_Value tv_elapsed;
    timer.elapsed_time (tv_elapsed);

    if (tv_elapsed.sec () > 0 ||
        tv_elapsed.usec () > (this->target_ + this->margin_))
    {
      upper = count;
    }
    else if (tv_elapsed.sec () == 0 &&
             tv_elapsed.usec () < (this->target_ - this->margin_))
    {
      lower = count;
    }
    else
    {
      done = true;
    }
  } while (!done && (upper != lower));

  return count;
}

//
// work
//
void CUTS_CPU_Worker::work (size_t count)
{
  ACE_High_Res_Timer timer;

  for (size_t i = 0; i < count; i ++)
    timer.start ();
}

//
// verify_calibration
//
void CUTS_CPU_Worker::verify_calibration (void)
{
  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): verify counts per msec\n"));

  ACE_Time_Value start, stop, duration;
  std::vector <size_t> calib_timings (TEST_RUNS);

  size_t msec = 0;

  for (size_t index = 0;
       msec <= TEST_MAX_MSEC;
       msec += TEST_INC_MSEC, index ++)
  {
    ACE_DEBUG ((LM_INFO,
                "--- running calibration test for %u msec...\n",
                msec));

    for (size_t run = 0; run < TEST_RUNS; run ++)
    {
      start = ACE_OS::gettimeofday ();
      this->run (msec);
      stop = ACE_OS::gettimeofday ();

      duration = stop - start;
      calib_timings[run] = duration.msec ();
    }

    // Determine if the test passed
    size_t sum = std::accumulate (calib_timings.begin (),
                                  calib_timings.end (),
                                  0);

    double avg = (double) sum / (double) calib_timings.size ();
    double err = avg - msec;

    ACE_DEBUG ((LM_DEBUG,
                "    average execution time = %f\n"
                "    average error = %f\n",
                avg, err));
  }
}

//
// make_calibration_filename
//
void CUTS_CPU_Worker::
make_calibration_filename (ACE_CString & filename)
{
  // Store the calibration scale.
  ACE_CString cuts_root = ACE_OS::getenv ("CUTS_ROOT");

  ACE_OS::macaddr_node_t macaddr;
  ACE_OS::getmacaddress (&macaddr);

  char temp_filename [1024];

  ACE_OS::sprintf (temp_filename,
                   "%s/etc/calibration/%s.%02X-%02X-%02X-%02X-%02X-%02X",
                   cuts_root.c_str (),
                   "CUTS_CPU_Worker",
                   macaddr.node[0],
                   macaddr.node[1],
                   macaddr.node[2],
                   macaddr.node[3],
                   macaddr.node[4],
                   macaddr.node[5]);

  filename = temp_filename;
}

//
// init
//
bool CUTS_CPU_Worker::init (void)
{
  ACE_CString filename;
  this->make_calibration_filename (filename);

  std::ifstream infile;
  infile.open (filename.c_str ());

  if (infile.is_open ())
  {
    infile >> this->count_per_msec_;
    infile.close ();
  }

  return this->count_per_msec_ != 0.0;
}
