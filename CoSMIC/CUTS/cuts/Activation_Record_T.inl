// $Id$

//
// perform_action_no_logging
//
template <typename ACTION>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (ACTION action)
{
  action ();
}

template <typename ACTION, typename A1>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (ACTION action, A1 arg1)
{
  action (arg1);
}

template <typename ACTION, typename A1, typename A2>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (ACTION action, A1 arg1, A2 arg2)
{
  action (arg1, arg2);
}

template <typename ACTION, typename A1, typename A2, typename A3>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (ACTION action, A1 arg1, A2 arg2, A3 arg3)
{
  action (arg1, arg2, arg3);
}

template <typename ACTION, typename A1, typename A2, typename A3, typename A4>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (ACTION action, A1 arg1, A2 arg2, A3 arg3, A4 arg4)
{
  action (arg1, arg2, arg3, arg4);
}

template <typename ACTION, typename A1, typename A2, typename A3, typename A4,
          typename A5>
CUTS_INLINE
void CUTS_Activation_Record::
perform_action_no_logging (ACTION action, A1 arg1, A2 arg2, A3 arg3, A4 arg4,
                           A5 arg5)
{
  action (arg1, arg2, arg3, arg4, arg5);
}
