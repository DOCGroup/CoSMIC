// -*- C++ -*-

//=============================================================================
/**
 * @file      UDM_Utility_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_UDM_UTILITY_T_H_
#define _CUTS_UDM_UTILITY_T_H_

#include "cuts/config.h"
#include <string>

//=============================================================================
/**
 * @struct Sort_By_Position
 *
 * @brief Help functor to sort objects by their position. The object
 * sorted by this method are in left-to-right ordering. Their y-value
 * is currently ignored when sorting objects.
 */
//=============================================================================

template <typename T>
struct Sort_By_Position
{
  struct Position
  {
    /// X-value of the position.
    long x;

    /// Y-value of the position
    long y;

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
      istr >> this->x;
      istr >> tmp;
      istr >> this->y;
    }
  };

  /**
   * Functor operation. This method will compare the determine
   * which object is the furthest most left object of the two.
   */
  bool operator () (const T & lhs, const T & rhs)
  {
    Position pos_lhs;
    pos_lhs <<= lhs.position ();

    Position pos_rhs;
    pos_rhs <<= rhs.position ();

    return pos_lhs.x < pos_rhs.x;
  }
};

//=============================================================================
/**
 * @struct is_type
 *
 * Functor for checking the type of a UDM object. This is very
 * useful with boost and their template methods.
 */
//=============================================================================

template <typename T>
struct is_type
{
public:
  bool operator () (const T & element);
};

template <typename T>
struct not_is_type
{
  inline
  not_is_type (const std::string & type)
  : type_ (type) { }

  inline
  bool operator () (const T & element)
  {
    return this->type_ != element.type ().name ();
  }

private:
  /// Name of the type.
  const std::string & type_;
};

#if defined (__CUTS_INLINE__)
#include "UDM_Utility_T.inl"
#endif

#include "UDM_Utility_T.cpp"

#endif  /* !defined _CUTS_UDM_UTILITY_H_ */
