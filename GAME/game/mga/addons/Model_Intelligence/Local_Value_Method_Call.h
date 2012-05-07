// -*- C++ -*-

//=============================================================================
/**
 * @file          Local_Value_Method_Call.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_METHOD_CALL_H_
#define _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_METHOD_CALL_H_

#include "Method_Call.h"
#include <string>

/**
 * @class Local_Value_Method_Call
 *
 * Class derived from Method_Call. This class sets the
 * object value to Local Value.
 */
class Local_Value_Method_Call : public Method_Call
{
public:
	// Constructor
	Local_Value_Method_Call (std::string &var, 
		                       Method *meth);

	// Destructor
	~Local_Value_Method_Call (void);

	/**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value object of the local variable
   */
  Value * evaluate (Ocl_Context &res);

  /**
   * filter_evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        Object     Value object of the local variable
   */
  Value * filter_evaluate (Ocl_Context &res);

  /**
   * Determines if the object is for filtration or not.
   *
   * @return        bool          true if the object is for filtration
   *                              false if the object is not for filtration
   */
  bool is_filter (void);

private:
	Method * meth_;
	std::string var_;
};

#endif //_GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_METHOD_CALL_H_