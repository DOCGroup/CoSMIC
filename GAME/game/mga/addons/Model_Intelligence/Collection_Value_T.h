// -*- C++ -*-

//=============================================================================
/**
 * @file          Collection_Value_T.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_COLLECTION_VALUE_T_H_
#define _GAME_MODEL_INTELLIGENCE_COLLECTION_VALUE_T_H_

#include <iostream>
#include <vector>
#include "game/mga/FCO.h"
#include "Value.h"

/**
 * @class Collection_Value_T. Inherited from Value class
 *
 * This template class deals with collection of any 
 * type of values
 */
template<typename T>
class Collection_Value_T : public Value
{
public:
  /// Default constructor.
	Collection_Value_T (std::vector<T> & parts);

	/// Destructor.
	~Collection_Value_T (void);

  /**
   * Determines if the object is equal or not.
   *
	 * @param[in]     v             Object of Value type
   * @return        bool          true if the object is equal
   *                              false if the object is not equal
   */
  bool is_equal (Value * v);

	/**
   * Determines if the object is greater or not.
   *
	 * @param[in]     v             Object of Value type
   * @return        bool          true if the object is greater
   *                              false if the object is not greater
   */
  bool is_greater (Value * v);

	/**
   * Determines if the object is greater or equal.
   *
	 * @param[in]     v             Object of Value type
   * @return        bool          true if the object is greater or equal
   *                              false if the object is not greater or equal
   */
  bool is_greater_equal (Value * v);

	/**
   * Determines if the object is lesser or not.
   *
	 * @param[in]     v             Object of Value type
   * @return        bool          true if the object is lesser
   *                              false if the object is not lesser
   */
  bool is_lesser (Value * v);

	/**
   * Determines if the object is lesser or equal.
   *
	 * @param[in]     v             Object of Value type
   * @return        bool          true if the object is lesser or equal
   *                              false if the object is not lesser or equal
   */
  bool is_lesser_equal (Value * v);

	/**
   * Gets the difference between two variables
   *
	 * @param[in]     v             Object of Value type
	 * @param[out]    count         The difference value
   * @return        bool          true if successful
   *                              false if not successful
   */
	bool get_diff (Value * v, double & count);

  /**
   * Gets the summation between two variables
   *
	 * @param[in]     v             Object of Value type
	 * @param[out]    count         The added value
   * @return        bool          true if successful
   *                              false if not successful
   */
	bool get_sum (Value * v, double & count);

	/**
   * Gets the summation between two variables
	 *
	 * @return                      The size of the collection
	 */
	size_t size (void);

  /**
   * Gets the value of variable
	 * 
	 * @return        vector           The vector containing the values      
   */
	std::vector<T> value (void);

private:
	std::vector<T> parts_;

};

#include "Collection_Value_T.cpp"

#endif