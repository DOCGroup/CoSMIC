// -*- C++ -*-

//=============================================================================
/**
 * @file          Refers_to_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_REFERS_TO_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_REFERS_TO_METHOD_H_

#include "Method.h"

/**
 * @class Refers_to_Method
 *
 * Class derived from Method. This class deals
 * with finding the FCO that the current object refers to
 */
class Refers_to_Method : public Method
{
public:
  /// Default constructor.
	Refers_to_Method (void);

	/// Destructor.
	~Refers_to_Method (void);

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
};

#endif //_GAME_MODEL_INTELLIGENCE_REFERS_TO_METHOD_CALL_H_