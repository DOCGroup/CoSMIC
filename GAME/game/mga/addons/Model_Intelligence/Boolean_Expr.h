// -*- C++ -*-

//=============================================================================
/**
 * @file          Boolean_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_BOOLEAN_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_BOOLEAN_EXPR_H_

#include <iostream>
#include <map>
#include "Model_Intelligence_Context.h"

/**
 * @class Boolean_Expr
 *
 * Base class for any expression returning boolean
 */
class Boolean_Expr
{
public:
  /// Default constructor.
	Boolean_Expr (void);

	/// Destructor.
	~Boolean_Expr (void);

  // Pure virtual evaluate method used by derived classes 
  // for evaluating the respective sub-expresion
  virtual bool evaluate (Ocl_Context &res) = 0;
};

#endif