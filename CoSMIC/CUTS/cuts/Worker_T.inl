// $Id: Worker_T.inl,v 1.1.2.1 2006/05/25 22:18:33 hillj Exp $

//
// action_count
//
template <typename WORKER_TYPE>
CUTS_INLINE
size_t CUTS_Worker_T <WORKER_TYPE>::action_count (void) const
{
  return CUTS_Worker_T <WORKER_TYPE>::action_table_.current_size ();
}
