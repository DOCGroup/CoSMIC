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

//===========================================================================
 /**
  * @struct UDM_Accept_Functor
  *
  * @brief Simple functor to call accept method of a UDM object.
  *
  * This allows the accept method to be used with std::for_each
  * method by parameterizing this functor with the object type.
  */
//===========================================================================

template <typename VISITOR, typename ELEMENT>
struct UDM_Accept_Functor
{
  /// Type definition of the visitor type.
  typedef VISITOR Visitor_Type;

  /// Type definition of the element type.
  typedef ELEMENT Element_Type;

  /**
   * Constructor.
   *
   * @param[in]     visitor     Reference to target visitor.
   */
  UDM_Accept_Functor (VISITOR & visitor);

  /**
   * Functor method.
   *
   * @param[in]     element     Current element.
   */
  void operator () (ELEMENT & element);

  /// Reference to the visitor object.
  VISITOR & visitor_;
};

#include "UDM_Utility_T.cpp"

#endif  // !defined _CUTS_UDM_UTILITY_H_