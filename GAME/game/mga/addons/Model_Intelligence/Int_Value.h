// -*- C++ -*-

//=============================================================================
/**
 * @file          Int_Value.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_INT_VALUE_H_
#define _GAME_MODEL_INTELLIGENCE_INT_VALUE_H_

#include <iostream>
#include <vector>
#include "Value.h"

/**
 * @class Int_Value. Inherited from Value class
 *
 * This class deals with integer type of values
 */
class Int_Value : public Value
{
public:
  /// Default constructor.
	Int_Value (unsigned int val);

	/// Destructor.
	~Int_Value (void);

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
   * Gets the value of variable
	 * 
	 * @return        int           The integer value      
   */
	int value (void);

private:
	unsigned int val_;

};


#endif