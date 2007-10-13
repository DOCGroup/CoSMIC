// $Id$

#if !defined (__CUTS_INLINE__)
#include "cuts/Activation_Record_T.inl"
#endif

//
// perform_action
//
template <typename R, typename F, typename T>
void CUTS_Activation_Record::
perform_action (size_t uid, size_t type,
                R (F::*method) (void), T & obj)
{
  // Get the start of the action, execute the action, then get
  // the stop time of the action.
  this->action_timer_.start ();
  this->perform_action_no_logging (method, obj);
  this->action_timer_.stop ();

  // Store the information about the action.
  this->perform_action_i (uid, type);
}

//
// perform_action
//
template <typename R, typename F, typename T,
          typename P1, typename A1>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (size_t uid, size_t type,
                R (F::*method) (P1), T & obj, A1 arg1)
{
  // Get the start of the action, execute the action, then get
  // the stop time of the action.
  this->action_timer_.start ();
  this->perform_action_no_logging (method, obj, arg1);
  this->action_timer_.stop ();

  // Store the information about the action.
  this->perform_action_i (uid, type);
}

//
// perform_action
//
template <typename R, typename F, typename T,
          typename P1, typename P2,
          typename A1, typename A2>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (size_t uid, size_t type,
                R (F::*method) (P1, P2), T & obj,
                A1 arg1, A2 arg2)
{
  // Get the start of the action, execute the action, then get
  // the stop time of the action.
  this->action_timer_.start ();
  this->perform_action_no_logging (method, obj, arg1, arg2);
  this->action_timer_.stop ();

  // Store the information about the action.
  this->perform_action_i (uid, type);
}

//
// perform_action
//
template <typename R, typename F, typename T,
          typename P1, typename P2, typename P3,
          typename A1, typename A2, typename A3>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (size_t uid, size_t type,
                R (F::*method) (P1, P2, P3), T & obj,
                A1 arg1, A2 arg2, A3 arg3)
{
  // Get the start of the action, execute the action, then get
  // the stop time of the action.
  this->action_timer_.start ();
  this->perform_action_no_logging (method, obj, arg1, arg2, arg3);
  this->action_timer_.stop ();

  // Store the information about the action.
  this->perform_action_i (uid, type);
}

//
// perform_action
//
template <typename R, typename F, typename T,
          typename P1, typename P2, typename P3, typename P4,
          typename A1, typename A2, typename A3, typename A4>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (size_t uid, size_t type,
                R (F::*method) (P1, P2, P3, P4), T & obj,
                A1 arg1, A2 arg2, A3 arg3, A4 arg4)
{
  // Get the start of the action, execute the action, then get
  // the stop time of the action.
  this->action_timer_.start ();
  this->perform_action_no_logging (method, obj, arg1, arg2, arg3, arg4);
  this->action_timer_.stop ();

  // Store the information about the action.
  this->perform_action_i (uid, type);
}

//
// perform_action
//
template <typename R, typename F, typename T,
          typename P1, typename P2, typename P3, typename P4, typename P5,
          typename A1, typename A2, typename A3, typename A4, typename A5>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action (size_t uid, size_t type,
                R (F::*method) (P1, P2, P3, P4, P5), T & obj,
                A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5)
{
  // Get the start of the action, execute the action, then get
  // the stop time of the action.
  this->action_timer_.start ();
  this->perform_action_no_logging (method, obj, arg1, arg2, arg3, arg4, arg5);
  this->action_timer_.stop ();

  // Store the information about the action.
  this->perform_action_i (uid, type);
}
