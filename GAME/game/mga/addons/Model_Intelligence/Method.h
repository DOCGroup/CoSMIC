// -*- C++ -*-

//=============================================================================
/**
 * @file          Method.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_METHOD_H_

#include "Value.h"
#include "Model_Intelligence_Context.h"

/**
 * @class Method
 *
 * Base class for all methods
 */
class Method
{
public:
  /// Default constructor.
	Method (void);

	/// Destructor.
	~Method (void);

  /// Virtual method evaluate which gets invoked by the first caller
	virtual Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller) = 0;

	/// Virtual method evaluate which gets evoked for consecutive methods
	virtual Value * evaluate (Ocl_Context &res, Value *caller) = 0;  

  // Pure virtual method to check if the variable can be used for filtration
  virtual bool is_filter (void) = 0;
};

#endif //_GAME_MODEL_INTELLIGENCE_METHOD_CALL_H_