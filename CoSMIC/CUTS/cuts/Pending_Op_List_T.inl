// $Id$

//
// CUTS_Pending_Op_List_T
//
template <typename T>
CUTS_INLINE
CUTS_Pending_Op_List_T <T>::CUTS_Pending_Op_List_T (void)
{

}

//
// ~CUTS_Pending_Op_List_T
//
template <typename T>
CUTS_INLINE
CUTS_Pending_Op_List_T <T>::~CUTS_Pending_Op_List_T (void)
{
  this->reset ();
}

//
// size
//
template <typename T>
CUTS_INLINE
size_t CUTS_Pending_Op_List_T <T>::size (void) const
{
  return this->queue_.size ();
}

//
// insert
//
template <typename T>
CUTS_INLINE
int CUTS_Pending_Op_List_T <T>::insert (CUTS_Pending_Op_T <T> * op)
{
  return this->queue_.enqueue_tail (op);
}
