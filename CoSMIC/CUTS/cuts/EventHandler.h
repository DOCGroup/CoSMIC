// -*- C++ -*-

//=============================================================================
/**
 * @file    EventHandler.h
 *
 * $Id$
 */
//=============================================================================

#ifndef _CUTS_EVENT_HANDLER_H_
#define _CUTS_EVENT_HANDLER_H_

#include "cuts/config.h"
#include <set>

// forward declarations
class CUTS_Bounded_Counter;

//=============================================================================
/**
 * @class CUTS_Single_Event_Handler
 */
//=============================================================================

class CUTS_Export CUTS_Single_Event_Handler
{
public:
  /// Constructor.
  CUTS_Single_Event_Handler (void);

  /// Destructor.
  ~CUTS_Single_Event_Handler (void);

  /// Handle the event.
  void handle_event (void);

  /// Register a counter with the event handler.
  bool register_counter (CUTS_Bounded_Counter * counter);

  /// Remove a counter from the event handler.
  void unregister_counter (CUTS_Bounded_Counter * counter);

private:
  /// Type definition for the set of counters.
  typedef std::set <CUTS_Bounded_Counter *> CUTS_Counter_Set;

  /// The set of counter for this event handler.
  CUTS_Counter_Set counter_;
};

#if defined (__CUTS_INLINE__)
# include "cuts/EventHandler.inl"
#endif  

#endif  // !defined _CUTS_EVENT_HANDLER_H_
