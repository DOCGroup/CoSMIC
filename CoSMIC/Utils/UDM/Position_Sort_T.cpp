// $Id$

#include <string>

////
//// UDM_Position_Sort_T
////
template <typename T, typename SORT>
UDM_Position_Sort_T <T, SORT>::UDM_Position_Sort_T (void)
{

}

//
// UDM_Position_Sort_T
//
template <typename T, typename SORT>
UDM_Position_Sort_T <T, SORT>::
UDM_Position_Sort_T (const std::string & aspect, const SORT & sorter)
: aspect_ (aspect),
  sorter_ (sorter)
{

}

//
// operator ()
//
template <typename T, typename SORT>
bool UDM_Position_Sort_T <T, SORT>::
operator () (const T & lhs, const T & rhs)
{
  position_t lhs_pos, rhs_pos;

  if (this->get_position (lhs, lhs_pos) &&
      this->get_position (rhs, rhs_pos))
  {
    return this->sorter_ (lhs_pos, rhs_pos);
  }
  else
    return false;
}

//
// get_position
//
template <typename T, typename SORT>
bool UDM_Position_Sort_T <T, SORT>::
get_position (const T & element, position_t & pos)
{
  std::string posstr = element.position ();

  // Find the aspect in the position string.
  size_t pos_start = posstr.find (this->aspect_);
  if (pos_start == std::string::npos)
    return false;

  // Move to the end of the aspect's name.
  pos_start += this->aspect_.length () + 1;

  // Find the close paranthesis for the aspects using the start
  // position as the start index.
  size_t pos_end = posstr.find_first_of (')', pos_start);
  if (pos_end == std::string::npos)
    return false;

  // Extract the position from the string.
  posstr = posstr.substr (pos_start, pos_end - pos_start);

  // Convert the position string to binary format.
  std::istringstream istr (posstr);
  istr >> pos.x_;
  istr.ignore (1);
  istr >> pos.y_;

  return !istr.fail ();
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
