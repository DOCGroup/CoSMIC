// $Id$

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

#define TEST_RUNS           10
#define TEST_MIN_MSEC       10
#define TEST_MAX_MSEC       1000
#define TEST_INC_MSEC       10

#define CPU_ERROR_MAX       2.0
#define CPU_ERROR_MIN       (-1.0 * CPU_ERROR_MAX)

#define CPU_CALIBRATION_DETAILS() \
  ACE_Singleton <CUTS_CPU_Calibration_Details, ACE_Null_Mutex>::instance ()

//
// CUTS_CPU_Worker
//
template <typename T>
CUTS_CPU_Worker_T <T>::CUTS_CPU_Worker_T (T work_function)
: target_ (20000),
  margin_ (100),
  count_per_msec_ (0.0),
  work_function_ (work_function)
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
template <typename T>
CUTS_CPU_Worker_T <T>::~CUTS_CPU_Worker_T (void)
{

}

//
// run
//
template <typename T>
void CUTS_CPU_Worker_T <T>::run (size_t msec)
{
  double count = static_cast <double> (msec) * this->count_per_msec_;
  this->work (static_cast <size_t> (count));
}

//
// init_calibrate
//
template <typename T>
bool CUTS_CPU_Worker_T <T>::init_calibrate (void)
{
  int scope = ACE_SCOPE_PROCESS;
  int maxprio = ACE_Sched_Params::priority_max (ACE_SCHED_FIFO, scope);

  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): setting FIFO thread "
              "priority to %d\n",
              maxprio));

  if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                              maxprio,
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
template <typename T>
bool CUTS_CPU_Worker_T <T>::calibrate (void)
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
  this->verify_calibration (1, temp_filename);

  // Write the calibration to file.
  ACE_CString filename;
  this->make_calibration_filename (filename);

  // Delete the target file, if it exists, and replace it with the
  // new calibration metrics for the CPU workload generator.
  ACE_OS::unlink (filename.c_str ());

  if (ACE_OS::rename (temp_filename.c_str (), filename.c_str ()) != 0)
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (CUTS_CPU_Worker): failed to save calibration file [%m]\n"
                "*** info (CUTS_CPU_Worker): calibration details stored in %s\n",
                temp_filename.c_str ()));
  }

  return true;
}

//
// calibrate_i
//
template <typename T>
size_t CUTS_CPU_Worker_T <T>::calibrate_i (void)
{
  size_t count;
  bool done = false;

  ACE_Time_Value tv_elapsed;
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
    this->work (count);
    timer.stop ();

    timer.elapsed_time (tv_elapsed);

    if (tv_elapsed.sec () > 0 ||
        tv_elapsed.usec () >
        static_cast <suseconds_t> ((this->target_ + this->margin_)))
    {
      upper = count;
    }
    else if (tv_elapsed.sec () == 0 &&
             tv_elapsed.usec () <
             static_cast <suseconds_t> ((this->target_ - this->margin_)))
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
template <typename T>
void CUTS_CPU_Worker_T <T>::work (size_t count)
{
  for (size_t i = 0; i < count; i ++)
    this->work_function_.perform_work ();
}

//
// verify_calibration
//
template <typename T>
void CUTS_CPU_Worker_T <T>::
verify_calibration (size_t trycount, const ACE_CString & temp_filename)
{
  ACE_DEBUG ((LM_INFO,
              "*** info (CUTS_CPU_Worker): [try %u] verify %f counts per msec\n",
              trycount,
              this->count_per_msec_));

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

  tempfile
    << this->count_per_msec_ << " " << trycount << std::endl
    << "=================================================" << std::endl;

  // Verify the calibration factor for 0 to TEST_MAX_MSEC. We are
  // also going to write the details for the verification to the
  // temporary file.
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
        << entry->average_error_ << " "
        << entry->percent_error_ << "; "
        << entry->variance_ << " "
        << entry->stddev_ << " "
        << entry->stderr_ << std::endl;
    }
  }

  // Write the summary of the calibration detail. The summary includes
  // the number of samples processed and the min/avg/max percentage of
  // error for each sample set (i.e., each measured execution time).
  tempfile
    << "=================================================" << std::endl
    << CPU_CALIBRATION_DETAILS ()->count () << " "
    << CPU_CALIBRATION_DETAILS ()->min_error () << " "
    << CPU_CALIBRATION_DETAILS ()->max_error () << " "
    << CPU_CALIBRATION_DETAILS ()->average_percent_error () << std::endl;


  // Close the temporary file.
  if (tempfile.is_open ())
    tempfile.close ();

  // Write the information to the screen for the user.
  ACE_DEBUG ((LM_DEBUG,
              "*** info (CUTS_CPU_Worker): error set = [%f, %f]\n",
              CPU_CALIBRATION_DETAILS ()->min_error (),
              CPU_CALIBRATION_DETAILS ()->max_error ()));

  if (CPU_CALIBRATION_DETAILS ()->min_error () < CPU_ERROR_MIN ||
      CPU_CALIBRATION_DETAILS ()->max_error () > CPU_ERROR_MAX)
  {
    // Determine how much the adjust the counts per msec.
    double adjustment =
      this->count_per_msec_ *
      CPU_CALIBRATION_DETAILS ()->average_percent_error ();
    this->count_per_msec_ -= adjustment;

    // Reset the calibration details and rerun the verification.
    CPU_CALIBRATION_DETAILS ()->reset ();

    if (trycount != 10)
      this->verify_calibration (trycount + 1, temp_filename);
  }
}

//
// make_calibration_filename
//
template <typename T>
void CUTS_CPU_Worker_T <T>::
make_calibration_filename (ACE_CString & filename)
{
  // Get the basename of the temp file.
  ACE_CString basename;
  this->make_basename (basename);

  ACE_OS::macaddr_node_t macaddr;
  ACE_OS::getmacaddress (&macaddr);

  char temp_filename [1024];

  ACE_OS::sprintf (temp_filename,
                   "%s.%02X-%02X-%02X-%02X-%02X-%02X",
                   basename.c_str (),
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
template <typename T>
bool CUTS_CPU_Worker_T <T>::init (void)
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
template <typename T>
void CUTS_CPU_Worker_T <T>::
make_temp_filename (ACE_CString & tempfile)
{
  // Get the basename of the temp file.
  ACE_CString basename;
  this->make_basename (basename);

  // Create the template for the temporary file.
  char temp_filename [1024];
  ACE_OS::sprintf (temp_filename,
                   "%s-XXXXXX",
                   basename.c_str ());

  // Create the temporary filename.
  tempfile = ACE_OS::mktemp (temp_filename);
}

//
// make_basename
//
template <typename T>
void CUTS_CPU_Worker_T <T>::
make_basename (ACE_CString & basename)
{
  basename = ACE_OS::getenv ("CUTS_ROOT");
  basename += "/etc/calibration/CUTS_CPU_Worker";
}
