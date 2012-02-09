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
  virtual unsigned int evaluate (Ocl_Context &res) = 0;

  // Pure virtual method to check if the variale is mutable
  virtual bool ismutable (void) = 0;
};


#endif