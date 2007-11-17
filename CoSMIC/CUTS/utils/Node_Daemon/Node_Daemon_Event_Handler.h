/* -*- C++ -*- */

//=============================================================================
/**
 * @file      Node_Daemon_Event_Handler.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _NODE_DAEMON_EVENT_HANDLER_H_
#define _NODE_DAEMON_EVENT_HANDLER_H_

#include "ace/Event_Handler.h"
#include "ace/Task.h"
#include "ace/Reactor.h"

// Forward decl.
class CUTS_Node_Daemon_i;

//=============================================================================
/**
 * @class Node_Daemon_Event_Handler
 */
//=============================================================================

class Node_Daemon_Event_Handler : public ACE_Task_Base
{
public:
  /**
   * Default constructor.
   *
   * @param[in]       deamon
   */
  Node_Daemon_Event_Handler (CUTS_Node_Daemon_i & daemon);

  virtual ~Node_Daemon_Event_Handler (void);

  bool activate (void);

  void deactivate (void);

private:
  /// Callback routine for handling process termination.
  int handle_exit (ACE_Process * process);

  /// Callback routine for handling timeout.
  int handle_timeout (const ACE_Time_Value & tv, const void * act);

  int svc (void);

  /// The target node daemon associated with handler.
  CUTS_Node_Daemon_i & daemon_;

  /// Target reactor for the handler.
  ACE_Reactor reactor_;

  /// The active state of the handler.
  bool active_;
};

#endif  /* !defined _NODE_DAEMON_EVENT_HANDLER_H_ */
