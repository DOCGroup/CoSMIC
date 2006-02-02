// -*- C++ -*-

#ifndef _CUTS_PORT_AGENT_H_
#define _CUTS_PORT_AGENT_H_

#include "cuts/ActivationRecord.h"
#include "ace/Thread_Mutex.h"
#include "ace/Task.h"
#include "ace/Message_Queue_T.h"
#include "ace/Auto_Ptr.h"
#include "ace/Reactor_Notification_Strategy.h"
#include <string>
#include <set>
#include <stack>

// forward declarations
class CUTS_Port_Measurement;

//=============================================================================
/**
 *
 */
//=============================================================================

class CUTS_Export CUTS_Port_Agent :
  protected ACE_Task_Base
{
public:
  /// Constructor.
  CUTS_Port_Agent (const char * uuid, const char * name);

  /// Destructor.
  virtual ~CUTS_Port_Agent (void);

  /// Get the name of the port agent.
  const char * name (void) const;

  /// Get the uuid of the port agent.
  const char * uuid (void) const;

  /// Create a new activation record from the port agent.
  CUTS_Activation_Record * create_activation_record (void);

  /// Close an activation record. This causes the benchmark agent
  /// to consolidate the record contents into a single location.
  void close_activation_record (CUTS_Activation_Record * record);

  /// Activate the port agent.
  void activate (void);

  /// Deactivate the port agent.
  void deactivate (void);

  /**
   * Release the current port measurements. This will give control
   * of the measurements to the client to do whatever it desires.
   */
  const CUTS_Port_Measurement * release_measurements (void);

private:
  /// Service handler for the port agent.
  int svc (void);

  /// Handle the input to the message queue.
  int handle_input (ACE_HANDLE fd);

  /// Type definition for the collection of all records
  typedef std::set <CUTS_Activation_Record *> Record_List;

  /// The collection of active and inactive records.
  Record_List records_;

  /// Name of the port.
  std::string name_;

  /// UUID of the port.
  std::string uuid_;

  /// The active state of the port agent.
  bool active_;

  /// Notification strategy for the <closed_list_>.
  ACE_Auto_Ptr <ACE_Reactor_Notification_Strategy> notify_strategy_;

  /// Collection of free activation records.
  ACE_Message_Queue_Ex <CUTS_Activation_Record, ACE_MT_SYNCH> free_list_;

  /// Collection of unprocessed closed activation records.
  ACE_Message_Queue_Ex <CUTS_Activation_Record, ACE_MT_SYNCH> closed_list_;

  /// Thread lock for synchronization.
  ACE_Thread_Mutex lock_;

  /// The measurement information for this port.
  ACE_Auto_Ptr <CUTS_Port_Measurement> port_measurement_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/PortAgent.inl"
#endif

#endif  // !defined _CUTS_PORT_AGENT_H_
