
#ifndef _CUTS_ACTIVATION_RECORD_H_
#define _CUTS_ACTIVATION_RECORD_H_

#include "cuts/Timing.h"
#include <queue>

class CUTS_Export CUTS_Activation_Record
{
public:
  struct Entry
  {
    Entry (size_t reps, long worker_id, long action_id,
      ACE_Time_Value & start, ACE_Time_Value &stop)
      : reps_ (reps),
        worker_id_ (worker_id),
        action_id_ (action_id),
        start_time_ (start),
        stop_time_ (stop)
    {

    }

    const Entry & operator = (const Entry & entry)
    {
      this->reps_ = entry.reps_;
      this->worker_id_ = entry.worker_id_;
      this->action_id_ = entry.action_id_;
      this->start_time_ = entry.start_time_;
      this->stop_time_ = entry.stop_time_;
      return *this;
    }

    /// Number of repetitions.
    size_t reps_;

    /// ID is the worker performing the action.
    long worker_id_;

    /// ID of the action for the <worker_id_>.
    long action_id_;

    /// Start time for the entry.
    ACE_Time_Value start_time_;

    /// Stop time for the entry.
    ACE_Time_Value stop_time_;
  };

  typedef std::queue <Entry> Entries;

  /// Constructor.
  CUTS_Activation_Record (void);

  /// Destructor.
  ~CUTS_Activation_Record (void);

  /// Get the start time for the activation record.
  const ACE_Time_Value & start_time (void) const;

  /// Get the start time for the activation record.
  const ACE_Time_Value & stop_time (void) const;

  /// Rest the activation record.
  void reset (void);

  /// Activate the activation record.
  void activate (void);

  /// Close the activation record.
  void close (void);

  /// Determine if the record is active.
  bool is_active (void);

  /// Get the entries for the record.
  const Entries & entries (void) const;

  /// Perform the specified action without any logging.
  template <typename ACTION>
  void perform_action_no_logging (size_t repetitions, ACTION & action)
  {
    for (size_t rep = 0; rep < repetitions; rep ++)
    {
      action ();
    }
  }

  /// Perform the specified action and log its performance.
  template <typename ACTION>
  void perform_action (size_t repetitions, ACTION & action)
  {
    // Save the start time of the action.
    this->action_state_time_ = ACE_OS::gettimeofday ();

    for (size_t rep = 0; rep < repetitions; rep ++)
    {
      action ();
    }

    // Save the stop time of the action.
    this->action_stop_time_ = ACE_OS::gettimeofday ();

    // Save the timing information into the record.
    log_time_measurement (
      repetitions,
      CUTS_Worker_Traits <ACTION::Worker_Type>::worker_id_,
      CUTS_Action_Traits <ACTION>::action_id_);
  }

private:
  /// Log the timing measurement.
  void log_time_measurement (size_t reps, long worker_id, long action_id);

  /// Active state of the record.
  bool active_;

  /// The start for the activation record.
  ACE_Time_Value start_time_;

  /// The stop time for the activation record.
  ACE_Time_Value stop_time_;

  /// Start time of the operation.
  ACE_Time_Value action_state_time_;

  /// Stop time of the operation.
  ACE_Time_Value action_stop_time_;

  /// Entries in the activation record.
  Entries entries_;

  /// Disallowed operation.
  CUTS_Activation_Record (const CUTS_Activation_Record &);

  /// Disallowed operation.
  const CUTS_Activation_Record & operator = (const CUTS_Activation_Record &);
};

#if defined (__CUTS_INLINE__)
#include "ace/OS_NS_sys_time.h"
#include "cuts/ActivationRecord.inl"
#endif

#endif  // !defined _CUTS_ACTIVATION_RECORD_H_
