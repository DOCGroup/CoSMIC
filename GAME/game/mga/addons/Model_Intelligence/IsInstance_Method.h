// -*- C++ -*-

//=============================================================================
/**
 * @file          IsInstance_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ISINSTANCE_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_ISINSTANCE_METHOD_H_

#include "Method.h"

/**
 * @class IsInstance_Method
 *
 * Class derived from Method. This class finds
 * if the object is an instance
 */
class IsInstance_Method : public Method
{
public:
  /// Default constructor.
	IsInstance_Method (void);

	/// Destructor.
	~IsInstance_Method (void);

  /**
   * evaluate method for evaluating the refers_to method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Collection Value object
   */
  Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the refers_to method
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

#endif //_GAME_MODEL_INTELLIGENCE_ISINSTANCE_METHOD_CALL_H_