// $Id$

#ifndef _CUTS_ACTIVATION_RECORD_T_CPP_
#define _CUTS_ACTIVATION_RECORD_T_CPP_

#if !defined (__CUTS_INLINE__)
#include "cuts/Activation_Record_T.inl"
#endif

//
// perform_action
//
template <typename ACTION>
void CUTS_Activation_Record::
perform_action (ACTION action)
{
  // Save the start time of the action.
  this->action_state_time_ = ACE_OS::gettimeofday ();

  this->perform_action_no_logging (action);

  // Save the stop time of the action.
  this->action_stop_time_ = ACE_OS::gettimeofday ();

  // We need a better way to log the metrics of an action to the
  // record. Should we be concerned with the id of the action? Or,
  // should we let the developer/user figure out what action was
  // executed based on the ordering of the actions in the log.
}

//
// perform_action
//
template <typename ACTION, typename A1>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (ACTION action, A1 arg1)
{
  // Save the start time of the action.
  this->action_state_time_ = ACE_OS::gettimeofday ();

  this->perform_action_no_logging (action, arg1);

  // Save the stop time of the action.
  this->action_stop_time_ = ACE_OS::gettimeofday ();
}

//
// perform_action
//
template <typename ACTION, typename A1, typename A2>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (ACTION action, A1 arg1, A2 arg2)
{
  // Save the start time of the action.
  this->action_state_time_ = ACE_OS::gettimeofday ();

  this->perform_action_no_logging (action, arg1, arg2);

  // Save the stop time of the action.
  this->action_stop_time_ = ACE_OS::gettimeofday ();
}

//
// perform_action
//
template <typename ACTION, typename A1, typename A2, typename A3>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (ACTION action, A1 arg1, A2 arg2, A3 arg3)
{
  // Save the start time of the action.
  this->action_state_time_ = ACE_OS::gettimeofday ();

  this->perform_action_no_logging (action, arg1, arg2, arg3);

  // Save the stop time of the action.
  this->action_stop_time_ = ACE_OS::gettimeofday ();
}

//
// perform_action
//
template <typename ACTION, typename A1, typename A2, typename A3, typename A4>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (ACTION action, A1 arg1, A2 arg2, A3 arg3, A4 arg4)
{
  // Save the start time of the action.
  this->action_state_time_ = ACE_OS::gettimeofday ();

  this->perform_action_no_logging (action, arg1, arg2, arg3, arg4);

  // Save the stop time of the action.
  this->action_stop_time_ = ACE_OS::gettimeofday ();
}

//
// perform_action
//
template <typename ACTION, typename A1, typename A2, typename A3, typename A4,
          typename A5>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (ACTION action, A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5)
{
  // Save the start time of the action.
  this->action_state_time_ = ACE_OS::gettimeofday ();

  this->perform_action_no_logging (action, arg1, arg2, arg3, arg4, arg5);

  // Save the stop time of the action.
  this->action_stop_time_ = ACE_OS::gettimeofday ();
}

#endif  // !defined _CUTS_ACTIVATION_RECORD_T_CPP_
