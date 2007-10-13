// $Id$

//
// perform_action_no_logging
//
template <typename R, typename F, typename T>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (R (F::*method) (void), T & obj)
{
  (obj.*method) ();
}

//
// perform_action_no_logging
//
template <typename R, typename F, typename T,
          typename P1, typename A1>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (R (F::*method) (P1), T & obj, A1 arg1)
{
  (obj.*method) (arg1);
}

//
// perform_action_no_logging
//
template <typename R, typename F, typename T,
          typename P1, typename P2,
          typename A1, typename A2>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (R (F::*method) (P1, P2), T & obj,
                           A1 arg1, A2 arg2)
{
  (obj.*method) (arg1, arg2);
}

//
// perform_action_no_logging
//
template <typename R, typename F, typename T,
          typename P1, typename P2, typename P3,
          typename A1, typename A2, typename A3>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (R (F::*method) (P1, P2, P3), T & obj,
                           A1 arg1, A2 arg2, A3 arg3)
{
  (obj.*method) (arg1, arg2, arg3);
}

//
// perform_action_no_logging
//
template <typename R, typename F, typename T,
          typename P1, typename P2, typename P3, typename P4,
          typename A1, typename A2, typename A3, typename A4>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (R (F::*method) (P1, P2, P3, P4), T & obj,
                           A1 arg1, A2 arg2, A3 arg3, A4 arg4)
{
  (obj.*method) (arg1, arg2, arg3, arg4);
}

//
// perform_action_no_logging
//
template <typename R, typename F, typename T,
          typename P1, typename P2, typename P3, typename P4, typename P5,
          typename A1, typename A2, typename A3, typename A4, typename A5>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (R (F::*method) (P1, P2, P3, P4, P5), T & obj,
                           A1 arg1, A2 arg2, A3 arg3, A4 arg4, A5 arg5)
{
  (obj.*method) (arg1, arg2, arg3, arg4, arg5);
}
