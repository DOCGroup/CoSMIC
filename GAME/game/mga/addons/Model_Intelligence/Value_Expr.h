  // -*- C++ -*-

//=============================================================================
/**
 * @file          Value_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_VALUE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_VALUE_EXPR_H_

#include <iostream>
#include <vector>
#include "game/mga/Model.h"
#include "Model_Intelligence_Context.h"
#include "Value.h"

/**
 * @class Value_Expr
 *
 * Base class for any expression returning a value
 */
class Value_Expr 
{
public:
  /// Default constructor.
	Value_Expr (void);

	/// Destructor.
	~Value_Expr (void);

  // Pure virtual method for evaluating respective expression
  virtual Value * evaluate (Ocl_Context &res) = 0;

  // Pure virtual method for filtering the result list
  virtual Value * filter_evaluate (Ocl_Context &res) = 0;

  // Pure virtual method to check if the variable is mutable
  virtual bool is_mutable (void) = 0;

  // Pure virtual method to check if the variable can be used for filtration
  virtual bool is_filter (void) = 0;
};


#endif