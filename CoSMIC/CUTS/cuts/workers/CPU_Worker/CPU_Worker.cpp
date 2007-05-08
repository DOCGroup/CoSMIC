// $Id$

#include "CPU_Worker.h"
#include "Calibration_Details.h"
#include "ace/High_Res_Timer.h"
#include "ace/Log_Msg.h"
#include "ace/Null_Mutex.h"
#include "ace/OS_NS_netdb.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Sched_Params.h"
#include "ace/streams.h"
#include "ace/Singleton.h"
#include <numeric>
#include <vector>

#define TEST_RUNS           10
#define TEST_MIN_MSEC       10
#define TEST_MAX_MSEC       1000
#define TEST_INC_MSEC       10

#define PERCENT_ERROR_MAX   1.0
#define PERCENT_ERROR_MIN   (-1.0 * PERCENT_ERROR_MAX)

CUTS_WORKER_FACTORY_EXPORT_IMPL (CUTS_CPU_Worker);

#define CPU_CALIBRATION_DETAILS() \
  ACE_Singleton <CUTS_CPU_Calibration_Details, ACE_Null_Mutex>::instance ()

//
// CUTS_CPU_Worker
//
CUTS_CPU_Worker::CUTS_CPU_Worker (void)
: target_ (20000),
  margin_ (100),
  count_per_msec_ (0.0)
{
  if (!this->init ())
  {
    ACE_ERROR ((LM_CRITICAL,
                "*** critical (CUTS_CPU_Worker): worker not calibrated!!\n"));
  }
}

//
// ~CUTS_CPU_Worker
//
CUTS_CPU_Worker::~CUTS_CPU_Worker (void)
{

}

//
// run
//
void CUTS_CPU_Worker::run (size_t msec)
{
  double count = static_cast <double> (msec) * this->count_per_msec_;
  this->work (static_cast <size_t> (count));
}

//
// init_calibrate
//
bool CUTS_CPU_Worker::init_calibrate (void)
{
  int scope = ACE_SCOPE_PROCESS;
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
  {
    ACE_ERROR ((LM_CRITICAL,
                "*** critical (CUTS_CPU_Worker): failed to initialize "
                "calibration\n"));
    ACE_ERROR ((LM_WARNING,
                "*** warning (CUTS_CPU_Worker): calibration may not be "
                " accurate\n"));
  }


  // Run the calibration
  size_t calib_loop_factor = this->calibrate_i ();

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): calibration loop factor = %u\n",
              calib_loop_factor));

  this->count_per_msec_ =
    ((double) calib_loop_factor * 1000.0) / (double) this->target_;

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): counts per msec = %f\n",
              this->count_per_msec_));

  ACE_CString temp_filename;

  // Verify the calibration.
  this->make_temp_filename (temp_filename);
  this->verify_calibration (temp_filename);

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
    outfile
      << this->count_per_msec_ << std::endl
      << "=================================================" << std::endl;

    std::ifstream tempfile;
    tempfile.open (temp_filename.c_str ());

    char xfer_buffer[1024];

    if (tempfile.is_open ())
    {
      while (!tempfile.eof ())
      {
        tempfile.read (xfer_buffer, sizeof (xfer_buffer));
        outfile.write (xfer_buffer, tempfile.gcount ());
      }

      // Close and delete the temporary file.
      tempfile.close ();
      ACE_OS::unlink (temp_filename.c_str ());
    }

    // Close the calibration file.
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
void CUTS_CPU_Worker::
verify_calibration (const ACE_CString & temp_filename)
{
  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): verify counts per msec\n"));

  ACE_High_Res_Timer timer;
  ACE_Time_Value tv_duration;

  // Open the temporary file for writing.
  std::ofstream tempfile;
  tempfile.open (temp_filename.c_str ());

  if (!tempfile.is_open ())
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (CUTS_CPU_Worker): failed to open '%s'; "
                "calibration details will not be saved\n",
                temp_filename.c_str ()));
  }

  // Verify the calibration factor for 0 to TEST_MAX_MSEC. We are
  // also going to write the details for the verification to the
  // temporary file.
  double overall_average_error = 0.0;
  CUTS_CPU_Calibration_Results results (TEST_RUNS);

  for (size_t msec = TEST_MIN_MSEC;
       msec <= TEST_MAX_MSEC;
       msec += TEST_INC_MSEC)
  {
    ACE_DEBUG ((LM_INFO,
                "--- running calibration test for %u msec...\n",
                msec));

    for (size_t run = 0; run < TEST_RUNS; run ++)
    {
      timer.start ();
      this->run (msec);
      timer.stop ();

      // Get the elapsed time and store it.
      timer.elapsed_time (tv_duration);
      results[run] = tv_duration.msec ();
    }

    CUTS_CPU_Calibration_Details_Log_Entry * entry = 0;
    CPU_CALIBRATION_DETAILS ()->process (msec, results, entry);

    ACE_DEBUG ((LM_DEBUG,
                "    average execution time = %f msec\n"
                "    average error = %f msec\n",
                entry->average_time_,
                entry->average_error_));

    // Write the details to the temporary file.
    if (tempfile.is_open ())
    {
      // Write the current execution time.
      tempfile << msec << " ";

      // Write all the measured execution times.
      for (CUTS_CPU_Calibration_Results::iterator iter = results.begin ();
           iter != results.end ();
           iter ++)
      {
        tempfile << *iter << " ";
      }

      // Write the average measured execution time and the average
      // error percentage.
      tempfile
        << entry->average_time_ << " "
        << entry->average_error_ << std::endl;
    }
  }

  // Write the summary of the calibration detail. The summary includes
  // the number of samples processed and the min/avg/max percentage of
  // error for each sample set (i.e., each measured execution time).
  tempfile
    << "=================================================" << std::endl
    << CPU_CALIBRATION_DETAILS ()->count () << " "
    << CPU_CALIBRATION_DETAILS ()->min_value () << " "
    << CPU_CALIBRATION_DETAILS ()->avg_value () << " "
    << CPU_CALIBRATION_DETAILS ()->max_value () << std::endl;


  // Close the temporary file.
  if (tempfile.is_open ())
    tempfile.close ();

  // Write the information to the screen for the user.
  ACE_DEBUG ((LM_DEBUG,
              "*** info (CUTS_CPU_Worker): min error = %f\n"
              "                            avg error = %f\n"
              "                            max error = %f\n",
              CPU_CALIBRATION_DETAILS ()->min_value (),
              CPU_CALIBRATION_DETAILS ()->avg_value (),
              CPU_CALIBRATION_DETAILS ()->max_value ()));
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
  else
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (CUTS_CPU_Worker): failed to open %s\n",
                  filename.c_str ()));
    }

  return this->count_per_msec_ != 0.0;
}

//
// make_temp_filename
//
void CUTS_CPU_Worker::
make_temp_filename (ACE_CString & tempfile)
{
  // Get the CUTS_ROOT environment variable.
  ACE_CString cuts_root = ACE_OS::getenv ("CUTS_ROOT");

  // Create the template for the temporary file.
  char temp_filename [1024];
  ACE_OS::sprintf (temp_filename,
                   "%s/etc/calibration/CUTS_CPU_Worker-XXXXXX",
                   cuts_root.c_str ());

  // Create the temporary filename.
  tempfile = ACE_OS::mktemp (temp_filename);
}
