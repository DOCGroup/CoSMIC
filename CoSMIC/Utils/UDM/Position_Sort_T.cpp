// $Id$

//
// UDM_Position_Sort_T
//
template <typename T, typename SORT>
UDM_Position_Sort_T <T, SORT>::UDM_Position_Sort_T (void)
{

}

//
// UDM_Position_Sort_T
//
template <typename T, typename SORT>
UDM_Position_Sort_T <T, SORT>::
UDM_Position_Sort_T (const SORT & sorter)
: sorter_ (sorter)
{

}

//
// operator ()
//
template <typename T, typename SORT>
bool UDM_Position_Sort_T <T, SORT>::
operator () (const T & lhs, const T & rhs)
{
  // Extract the position for each element.
  position_t lhs_pos;
  lhs_pos <<= lhs.position ();

  position_t rhs_pos;
  rhs_pos <<= rhs.position ();

  // Let the sorter compare the positions.
  return this->sorter_ (lhs_pos, rhs_pos);
}

//
// UDM_Position_Sort_T
//
template <typename T, typename SORT>
const UDM_Position_Sort_T <T, SORT> &
UDM_Position_Sort_T <T, SORT>::
operator = (const UDM_Position_Sort_T <T, SORT> & sorter)
{
  this->sorter_ = sorter.sorter_;
  return *this;
}
