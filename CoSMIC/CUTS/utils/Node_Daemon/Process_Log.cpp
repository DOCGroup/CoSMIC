// $Id$

#include "Process_Log.h"

#if !defined (__CUTS_INLINE__)
#include "Process_Log.inl"
#endif

#include "ace/Guard_T.h"
#include "ace/Log_Msg.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_unistd.h"
#include "ace/streams.h"
#include <algorithm>

static const size_t ENTRY_BUFFER_SIZE = 10;

static const char * TEMP_FILENAME = "cutsnode_d.tmp";

struct Find_By_PID
{
  Find_By_PID (pid_t pid)
    : pid_ (pid)
  {

  }

  bool operator () (const Process_Log_Entry & ple)
  {
    return this->pid_ == ple.pid ();
  }

private:
  pid_t pid_;
};

//=============================================================================
/*
 * Process_Log_Entry
 */
//=============================================================================

//
// Process_Log_Entry
//
Process_Log_Entry::Process_Log_Entry (void)
: flags_ (0),
  port_ (0)
{

}

//
// Process_Log_Entry
//
Process_Log_Entry::Process_Log_Entry (const Process_Log_Entry & entry)
: flags_ (entry.flags_),
  port_ (entry.port_)
{

}

//
// operator =
//
const Process_Log_Entry & Process_Log_Entry::operator = (
  const Process_Log_Entry & entry)
{
  this->flags_ = entry.flags_;
  this->port_ = entry.port_;
  this->pid_ = entry.pid_;
  return *this;
}

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
bool Process_Log::process_spawn (pid_t pid, u_short port, bool local)
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
                       "(%N:%l) failed to open file %s\n",
                       this->log_file_.c_str ()),
                       false);
  }

  Process_Log_Entry entry;

  // Configure the appropriate flags for the entry.
  ACE_SET_BITS (entry.flags_, Process_Log_Entry::PLE_ACTIVE);

  if (local)
    ACE_SET_BITS (entry.flags_, Process_Log_Entry::PLE_LOCAL);
  else
    ACE_CLR_BITS (entry.flags_, Process_Log_Entry::PLE_LOCAL);

  // Copy the <pid> and <port> into the entry.
  entry.pid_ = pid;
  entry.port_ = port;

  // Write the entry to file.
  logfile.write (reinterpret_cast <const char *> (&entry),
                 sizeof (Process_Log_Entry));

  // Save the status and close the <log_>.
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
                       "(%N:%l) failed to open file %s\n",
                       this->log_file_.c_str ()),
                       false);
  }

  Process_Log_Entry e_buffer [ENTRY_BUFFER_SIZE];
  size_t entry_count;

  do
  {
    entry_count = Process_Log::batch_read (logfile,
                                           e_buffer,
                                           ENTRY_BUFFER_SIZE);

    // Try and find the entry inside the collection of
    // records read in from the file.
    Process_Log_Entry * last_entry =
      e_buffer + min (entry_count, ENTRY_BUFFER_SIZE);

    Process_Log_Entry * entry =
      std::find_if (e_buffer, last_entry, Find_By_PID (pid));

    if (entry != last_entry)
    {
      // We have to reset the state if we have failed to get
      // the real position.
      if (logfile.fail ())
        logfile.clear ();

      // Move the output pointer to the location of the entry.
      int offset = (int) logfile.tellg () - sizeof (Process_Log_Entry);
      logfile.seekp (offset, std::ios_base::beg);

      // Clear the active bit and write the entry back to
      // file.
      ACE_CLR_BITS (entry->flags_, Process_Log_Entry::PLE_ACTIVE);
      logfile.write (reinterpret_cast <const char *> (entry),
                      sizeof (Process_Log_Entry));
      logfile.close ();
      return true;
    }
  } while (entry_count != 0);

  ACE_ERROR ((LM_WARNING,
              "process with id %u is not in process log\n",
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
                "(%N:%l) failed to create file %s\n",
                log_file));
  }
}

//
// get_active_processes
//
bool Process_Log::get_active_processes (Process_List & list)
{
  ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, this->lock_, false);

  std::ifstream logfile;
  logfile.open (this->log_file_.c_str (),
                std::ios_base::in | std::ios_base::binary);

  if (logfile.is_open ())
  {
    size_t entry_count;
    Process_Log_Entry e_buffer [ENTRY_BUFFER_SIZE];

    do
    {
      // Read a batch of entry elements and then only save the
      // active processes to the log.
      entry_count = Process_Log::batch_read (logfile,
                                             e_buffer,
                                             ENTRY_BUFFER_SIZE);

      for (size_t i = 0; i < entry_count; i ++)
      {
        if (e_buffer[i].is_active ())
          list.insert (e_buffer[i]);
      }
    } while (entry_count != 0);

    logfile.close ();
    return true;
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "(%N:%l) failed to open file %s\n",
                this->log_file_.c_str ()));
  }

  return false;
}

//
// batch_read
//
size_t Process_Log::batch_read (std::istream & infile,
                                Process_Log_Entry * buffer,
                                size_t count)
{
  infile.read (reinterpret_cast <char *> (buffer),
               count * sizeof (Process_Log_Entry));

  return infile.gcount () / sizeof (Process_Log_Entry);
}

//
// clean
//
bool Process_Log::clean (void)
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

  Process_Log_Entry e_buffer [ENTRY_BUFFER_SIZE];
  size_t entry_count;
  bool error = false;

  do
  {
    entry_count = Process_Log::batch_read (logfile,
                                           e_buffer,
                                           ENTRY_BUFFER_SIZE);

    for (size_t i = 0; i < entry_count; i ++)
    {
      // We only care to copy over the active processes.
      if (e_buffer[i].is_active ())
      {
        tmpfile.write (reinterpret_cast <char *> (&e_buffer[i]),
                       sizeof (Process_Log_Entry));

        // Something bad has happened and we need to just stop
        // and abort the cleaning operation.
        if (tmpfile.bad ())
        {
          ACE_ERROR ((LM_ERROR,
                      "(%N:%l) error occured while clean file; "
                      "aborting...\n"));
          error = true;
          break;
        }
      }
    }
  } while (entry_count != 0);

  // Close both files then replace the old file w/ the new file
  // if we did not experience any errors.
  logfile.close ();
  tmpfile.close ();

  if (error == false)
  {
    ACE_OS::unlink (this->log_file_.c_str ());
    ACE_OS::rename (TEMP_FILENAME, this->log_file_.c_str ());
  }
  else
    ACE_OS::unlink (TEMP_FILENAME);

  return !error;
}
