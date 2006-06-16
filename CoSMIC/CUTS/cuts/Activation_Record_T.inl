// $Id: Activation_Record_T.inl,v 1.1.2.1 2006/05/15 20:37:06 hillj Exp $

//
// perform_action_no_logging
//
template <typename ACTION>
CUTS_INLINE
void CUTS_Activation_Record::perform_action_no_logging (
  const ACTION & action)
{
  action.execute ();
}
