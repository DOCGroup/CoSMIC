// -*- C++ -*-

//=============================================================================
/**
 * @file    Trigger_T.h
 *
 * $Id$
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_TRIGGER_H_
#define _CUTS_TRIGGER_H_

#include "cuts/config.h"
#include "ace/TP_Reactor.h"
#include "ace/Task.h"
#include "ace/Time_Value.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif  // ACE_LACKS_PRAGMA_ONCE

//=============================================================================
/**
 * @class CUTS_Trigger_T
 *
 * This class defines the trigger-based workload. A trigger-based is
 * one that has it's own thread thread of execution. In order for 
 * it to perform its specified workload, it must be signaled, which
 * is done using the signal () method.
 */
//=============================================================================

template <typename COMPONENT>
class CUTS_Trigger_T : 
  protected ACE_Task_Base
{
public:
  /// Type definition for the hosting component type.
  typedef COMPONENT Component_Type;

  /// Type definition for pointer to member funcntion.
  typedef void (COMPONENT::* Method_Pointer)(void);

  /**
   * Initializing constructor.
   *
   * @param[in]     component       Owner of the trigger.
   * @param[in]     method          Method to invoke in the component.
   */
  CUTS_Trigger_T (Component_Type * component, Method_Pointer method);

  /// Destructor.
  virtual ~CUTS_Trigger_T (void);

  /// Activate the trigger. Only when the trigger has been activated
  /// can it be signaled.
  virtual bool activate (void);

  /// Deactivate the trigger. This will nullify any new signals.
  virtual void deactivate (void);

  /**
   * Determine if the trigger is active.
   *
   * @retval    true    The trigger is active.
   * @retval    false   The trigger is not active.
   */
  bool is_active (void) const;

  /**
   * Signal the workload to execute. This method returns immediately
   * regardless of whether or not the workload executes at the current
   * time.
   */
  void signal (void) const;

protected:
  /// Holds the current active state for the task.
  bool active_;

  /// Method used the signal the task to perform work.
  virtual int handle_timeout (const ACE_Time_Value &current_time, const void * act);

private:
  /// Service handler routine for the trigger.
  int svc (void);

  /// Pointer the parent component of the stored method.
  Component_Type * component_;

  /// Pointer to the <COMPONENT> member function assigned
  /// to this trigger event.
  Method_Pointer method_;
};

//=============================================================================
/**
 * @class CUTS_Periodic_Trigger_T
 *
 * This class defines a periodic trigger. A periodic trigger is one
 * that processes workload on a periodic basis. It also has an associated
 * probablity for performing the workload to create non-determinism.
 */
//=============================================================================

template <typename COMPONENT>
class CUTS_Periodic_Trigger_T : 
  public CUTS_Trigger_T <COMPONENT>
{
public:
  /// Type definition for the hosting component type.
  typedef COMPONENT Component_Type;

  /// Type definition for the <CUTS_TriggerEvent_T>.
  typedef CUTS_Trigger_T <Component_Type> Trigger_Type;

  /// Type definition for the method pointer.
  typedef typename Trigger_Type::Method_Pointer Method_Pointer;

  /// Default constructor.
  CUTS_Periodic_Trigger_T (Component_Type * component, Method_Pointer method,
                           long timeout, double probability = 1.0);

  /// Destructor.
  virtual ~CUTS_Periodic_Trigger_T (void);

  /** 
   * Activate the trigger. The periodic trigger can only be activated
   * once at a time. If the trigger is already activated it does nothing.
   *
   * @retval      true      Successfully activated the trigger
   * @retval      false     Failed to activate the trigger
   *
   * @note If the trigger is already active, then this method will still
   * return \a true.
   */
  virtual bool activate (void);

  /// Deactivate the trigger.
  virtual void deactivate (void);

  /// Get the current probability.
  double probability (void) const;

  /// Get the current timeout value.
  long timeout (void) const;

private:
  /// Handler for the timeout event.
  virtual int handle_timeout (const ACE_Time_Value &current_time, const void * act);

  /// Timer ID for the trigger.
  long timer_;

  /// Hold the timeout value.
  long timeout_;

  /// The probability of the trigger firing.
  double probability_;
};


#if defined (__CUTS_INLINE__)
# include "cuts/Trigger_T.inl"
#endif

#include "cuts/Trigger_T.cpp"

#endif  // !defined _CUTS_TRIGGER_H_
