// -*- C++ -*-

//=============================================================================
/**
 * @file          Self_Method_Call.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_SELF_METHOD_CALL_H_
#define _GAME_MODEL_INTELLIGENCE_SELF_METHOD_CALL_H_

#include "Method_Call.h"
#include <string>

/**
 * @class Self_Method_Call
 *
 * Class derived from Method_Call. This class sets the
 * object value to self.
 */
class Self_Method_Call : public Method_Call
{
public:
	// Constructor
	Self_Method_Call (Method *meth);

	// Destructor
	~Self_Method_Call (void);

	/**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value object of the local variable
   */
  Value * evaluate (Ocl_Context &res);

private:
	Method * meth_;
};

#endif //_GAME_MODEL_INTELLIGENCE_SELF_METHOD_CALL_H_