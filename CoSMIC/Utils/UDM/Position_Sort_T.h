// -*- C++ -*-

//=============================================================================
/**
 * @file        UDM_Position_Sort_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _UDM_POSITION_SORT_T_H_
#define _UDM_POSITION_SORT_T_H_

#include <sstream>

/**
 * @struct position_t
 *
 * Type for storing positions, i.e., (x,y) values.
 */
struct position_t
{
  /// The x-coordinate.
  long x_;

  /// The y-coordinate.
  long y_;

  /**
   * Extraction operator. This method takes a string and extracts
   * the coordinates from it. The format of the string should be
   * (x, y). If the source string does not have coordinates stored
   * in this format, it will cause unpredictable behavior.
   *
   * @param[in]     str     Source string with the x-,y-coordinates
   */
  void operator <<= (const std::string & str)
  {
    char tmp;

    std::istringstream istr (str);

    istr >> tmp;
    istr >> this->x_;
    istr >> tmp;
    istr >> this->y_;
  }
};

/**
 * @class UDM_Position_Sort_T
 *
 * Parameterizable functor for sorting UDM elements based on their
 * position in the model.
 */
template <typename T, typename SORT>
class UDM_Position_Sort_T
{
public:
  /// Default constructor.
  UDM_Position_Sort_T (void);

  /**
   * Copy constructor.
   *
   * @param[in]       sorter        The actual sorter.
   */
  UDM_Position_Sort_T (const std::string & aspect, const SORT & sorter);

  /**
   * Functor for determine which position is greater.
   *
   * @param[in]       lhs         Left-hand side of the operator
   * @param[in]       rhs         Right-hand side of the sort.
   */
  bool operator () (const T & lhs, const T & rhs);

  /**
   * Assignment operator.
   *
   * @param[in]       rhs         Right-hand side of operator
   * @return          Reference to this object.
   */
  const UDM_Position_Sort_T & operator = (const UDM_Position_Sort_T & rhs);

private:
  bool get_position (const T & element, position_t & pos);

  /// The aspect used to sort the elements.
  const std::string aspect_;

  /// Functor that is responsible for sorting.
  SORT sorter_;
};

/**
 * @struct PS_Left_To_Right
 */
struct PS_Left_To_Right
{
  bool operator () (const position_t & lhs, const position_t & rhs)
  {
    return lhs.x_ < rhs.x_;
  }
};

/**
 * @struct PS_Top_To_Bottom
 */
struct PS_Top_To_Bottom
{
  bool operator () (const position_t & lhs, const position_t & rhs)
  {
    return lhs.y_ < rhs.y_;
  }
};

#include "Position_Sort_T.cpp"

#endif  // !_UDM_POSITION_SORT_T_H_
