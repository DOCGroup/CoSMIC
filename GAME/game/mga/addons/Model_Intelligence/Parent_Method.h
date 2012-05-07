// -*- C++ -*-

//=============================================================================
/**
 * @file          Parent_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_PARENT_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_PARENT_METHOD_H_

#include "Method.h"

/**
 * @class Parent_Method
 *
 * Class derived from Method. This class deals
 * with finding the parent of the object
 */
class Parent_Method : public Method
{
public:
  /// Default constructor.
	Parent_Method (void);

	/// Destructor.
	~Parent_Method (void);

  /**
   * evaluate method for evaluating the Parent method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Collection Value object
   */
  Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the Parent method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        Value from previous method
   * @return        Object        Collection Value object
   */
	Value * evaluate (Ocl_Context &res, Value *caller);

  /**
   * Determines if the object is for filtration or not.
   *
   * @return        bool          true if the object is for filtration
   *                              false if the object is not for filtration
   */
  bool is_filter (void);
};

#endif //_GAME_MODEL_INTELLIGENCE_PARENT_METHOD_CALL_H_