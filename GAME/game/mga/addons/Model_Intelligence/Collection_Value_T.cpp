// $Id:  $

#include "StdAfx.h"

//
// Default Constructor
//
template <typename T>
Collection_Value_T<T>::Collection_Value_T (std::vector<T> & parts)
: parts_ (parts)
{
}

//
// Destructor
//
template <typename T>
Collection_Value_T<T>::~Collection_Value_T (void)
{
}

//
// is_equal
//
template <typename T>
bool Collection_Value_T<T>::is_equal (Value * v)
{
	// This function is not yet here
	return false;
}

//
// is_greater
//
template <typename T>
bool Collection_Value_T<T>::is_greater (Value *v)
{
	return false;
}

//
// is_greater_equal
//
template <typename T>
bool Collection_Value_T<T>::is_greater_equal (Value *v)
{
	return false;
}

//
// is_lesser
//
template <typename T>
bool Collection_Value_T<T>::is_lesser (Value *v)
{
	return false;
}

//
// is_lesser_equal
//
template <typename T>
bool Collection_Value_T<T>::is_lesser_equal (Value * v)
{
	return false;
}

//
// get_diff
//
template <typename T>
bool Collection_Value_T<T>::get_diff (Value * v, double & count)
{
	return false;
}

//
// get_sum
//
template <typename T>
bool Collection_Value_T<T>::get_sum (Value * v, double & count)
{
	return false;
}

//
// size
//
template <typename T>
size_t Collection_Value_T<T>::size (void)
{
	return this->parts_.size ();
}

//
// value
//
template <typename T>
std::vector <T> Collection_Value_T<T>::value (void)
{
  return this->parts_;
}
