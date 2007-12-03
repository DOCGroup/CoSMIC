// $Id$

#include "Process_Log.h"

#if !defined (__CUTS_INLINE__)
#include "Process_Log.inl"
#endif

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_unistd.h"
#include "ace/streams.h"
#include <algorithm>

#define ENTRY_BUFFER_SIZE  10

static const char * TEMP_FILENAME = "cutsnode_d.tmp";

//=============================================================================
/**
 * @struct Find_By_PID
 *
 * Functor for locating a Process_Log_Entry by its pid_t.
 */
//=============================================================================

struct Find_By_PID
{
  /**
   * Constructor
   *
   * @param[in]       pid           Id of the process
   */
  inline Find_By_PID (pid_t pid)
    : pid_ (pid)
  {

  }

  /**
   * Functor operator.
   *
   * @param[in]     ple       Current element from a collection.
   * @retval        true      The pid of the \ple is a match.
   * @retval        false     The pid of the \ple is not a match.
   */
  inline bool operator () (const Process_Log_Entry & ple)
  {
    return this->pid_ == ple.pid_;
  }

private:
  /// Process id in question.
  pid_t pid_;
};

//=============================================================================
/*
 * Process_Log
 */
//=============================================================================

//
// Process_Log
//
Process_Log::Process_Log (void)
{

}

//
// Process_Log
//
Process_Log::Process_Log (const char * log)
: log_file_ (log)
{

}

//
// ~Process_Log
//
Process_Log::~Process_Log (void)
{

}

//
// process_spawn
//
bool Process_Log::process_spawn (const ACE_CString & name, pid_t pid)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, false);

  // We are going to open the file for writing and append the
  // new information to the end of the <logfile>. We will have
  // a seperate thread that will "clean" the <logfile> periodically.

  std::ofstream logfile;
  logfile.open (this->log_file_.c_str (),
                std::ios_base::out |
                std::ios_base::binary |
                std::ios_base::app);

  if (!logfile.is_open ())
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (process log): failed to open file %s\n",
                       this->log_file_.c_str ()),
                       false);
  }

  // Create the entry for the process log.
  Process_Log_Entry entry;

  entry.active_ = true;
  entry.pid_ = pid;
  ACE_OS::strncpy (entry.name_, name.c_str (), PROCESS_LOG_NAME_MAX_LENGTH);

  // Write the entry to file and close it.
  logfile.write (reinterpret_cast <const char *> (&entry),
                 sizeof (Process_Log_Entry));

  logfile.close ();

  return logfile.good ();
}

//
// process_exit
//
bool Process_Log::process_exit (pid_t pid)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, false);

  // Open the log file for processing. We want to overwrite any
  // inactive processes before appending to the file.
  // proce

  std::fstream logfile;
  logfile.open (this->log_file_.c_str (),
                std::ios_base::in |
                std::ios_base::out |
                std::ios_base::binary);

  if (!logfile.is_open ())
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (process log): failed to open file %s\n",
                       this->log_file_.c_str ()),
                       false);
  }

  Process_Log_Entry buffer [ENTRY_BUFFER_SIZE];
  size_t entry_count;
  int index = 0;

  do
  {
    entry_count = this->batch_read (logfile, buffer,  ENTRY_BUFFER_SIZE);

    // Try and find the entry inside the collection of
    // records read in from the file.
    Process_Log_Entry * last_entry =
      buffer + std::min (entry_count, (size_t)ENTRY_BUFFER_SIZE);

    Process_Log_Entry * entry =
      std::find_if (buffer, last_entry, Find_By_PID (pid));

    if (entry != last_entry)
    {
      // Move the output pointer to the location of the entry. But
      // first we have to clear any errors that may have occurred,
      // e.g., failbit or eofbit
      if (logfile.fail () || logfile.eof ())
        logfile.clear ();

      index += (entry - buffer);
      int offset = index * sizeof (Process_Log_Entry);
      logfile.seekp (offset, std::ios_base::beg);

      // Clear active bit and write entry back to file.
      entry->active_ = false;
      logfile.write (reinterpret_cast <const char *> (entry),
                     sizeof (Process_Log_Entry));

      logfile.close ();
      return logfile.good ();
    }
    else
    {
      index += entry_count;
    }
  } while (entry_count != 0);

  ACE_ERROR ((LM_ERROR,
              "(%N:%l) failed to locate process with id %u\n",
              pid));

  logfile.close ();
  return false;
}

//
// log_file
//
void Process_Log::log_file (const char * log_file)
{
  // Verify that the file exists.
  std::ofstream logfile;
  logfile.open (log_file, std::ios_base::in | std::ios_base::binary);

  if (!logfile.is_open ())
  {
    // Ok, we need to create a new file!!
    logfile.open (log_file, std::ios_base::out | std::ios_base::binary);
  }

  if (logfile.is_open ())
  {
    // Great, we have a valid file!!!
    logfile.close ();

    this->log_file_ = log_file;
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (process log): failed to create file %s\n",
                log_file));
  }
}

//
// get_active_processes
//
bool Process_Log::
get_active_processes (Process_List & list)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, false);

  std::ifstream logfile;
  logfile.open (this->log_file_.c_str (),
                std::ios_base::in | std::ios_base::binary);

  if (logfile.is_open ())
  {
    size_t entry_count;
    Process_Log_Entry buffer [ENTRY_BUFFER_SIZE];

    do
    {
      // Read a batch of entry elements and then only save the
      // active processes to the log.
      entry_count = Process_Log::batch_read (logfile,
                                             buffer,
                                             ENTRY_BUFFER_SIZE);

      for (size_t i = 0; i < entry_count; i ++)
      {
        if (buffer[i].active_)
          list.insert (buffer[i]);
      }
    } while (entry_count != 0);

    logfile.close ();
    return true;
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (process log): failed to open file %s\n",
                this->log_file_.c_str ()));
  }

  return false;
}

//
// batch_read
//
size_t Process_Log::
batch_read (std::istream & infile, Process_Log_Entry * buffer, size_t count)
{
  infile.read (reinterpret_cast <char *> (buffer),
               count * sizeof (Process_Log_Entry));

  return infile.gcount () / sizeof (Process_Log_Entry);
}

//
// clean
//
bool Process_Log::clean (size_t * active_count)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, false);

  // Open the log file for processing. We want to overwrite any
  // inactive processes before appending to the file.
  std::ifstream logfile;
  logfile.open (this->log_file_.c_str (),
                std::ios_base::in | std::ios_base::binary);

  if (!logfile.is_open ())
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%N:%l) file %s does not exist\n",
                       this->log_file_.c_str ()),
                       false);
  }

  ofstream tmpfile;
  tmpfile.open (TEMP_FILENAME,
                std::ios_base::out |
                std::ios_base::binary |
                std::ios_base::trunc);

  if (!tmpfile.is_open ())
  {
    logfile.close ();
    ACE_ERROR_RETURN ((LM_ERROR,
                       "(%N:%l) failed to open temporary file for copying\n"),
                       false);
  }

  size_t entry_count, count = 0;
  Process_Log_Entry buffer [ENTRY_BUFFER_SIZE];
  bool error = false;

  do
  {
    entry_count = this->batch_read (logfile, buffer, ENTRY_BUFFER_SIZE);

    for (size_t i = 0; i < entry_count; i ++)
    {
      // We only care to copy over the active processes.
      if (buffer[i].active_)
      {
        tmpfile.write (reinterpret_cast <char *> (&buffer[i]),
                       sizeof (Process_Log_Entry));

        // Something bad has happened and we need to just stop
        // and abort the cleaning operation.
        if (tmpfile.bad ())
        {
          ACE_ERROR ((LM_ERROR,
                      "*** error (process log): error occured while clean "
                      "file; aborting...\n"));
          error = true;
          break;
        }

        ++ count;
      }
    }
  } while (entry_count != 0);

  // Close both files then replace the old file w/ the new file
  // if we did not experience any errors.
  logfile.close ();
  tmpfile.close ();

  if (!error)
    ACE_OS::rename (TEMP_FILENAME, this->log_file_.c_str ());
  else
    ACE_OS::unlink (TEMP_FILENAME);

  // Save the count for the callee.
  if (active_count != 0)
    *active_count = count;

  return !error;
}
