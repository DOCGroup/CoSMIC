// $Id$

//
// graph
//
template <typename T>
CUTS_INLINE
typename CUTS_BE_Depend_Graph_T <T>::Node_Map &
CUTS_BE_Depend_Graph_T <T>::graph (void)
{
  return this->graph_;
}

//
// graph
//
template <typename T>
CUTS_INLINE
const typename CUTS_BE_Depend_Graph_T <T>::Node_Map &
CUTS_BE_Depend_Graph_T <T>::graph (void) const
{
  return this->graph_;
}

