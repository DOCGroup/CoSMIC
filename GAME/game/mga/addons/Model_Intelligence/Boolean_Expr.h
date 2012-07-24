// -*- C++ -*-

//=============================================================================
/**
 * @file          Boolean_Expr.h
 *
 * $Id: Boolean_Expr.h 2902 2012-05-07 03:08:44Z tpati $
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

  // Pure virtual filter_evaluate method used by derived classes
  // for evaluating the respective sub-expression for filtration purpose
  virtual bool filter_evaluate (Ocl_Context &res, GAME::Mga::FCO &current) = 0;

  // is_association method to check if the expression can be used for 
  // association constraints
  virtual bool is_association (void) = 0;

  // is_containment method to check if the expression can be used for 
  // containment constraints
  virtual bool is_containment (void) = 0;

  // is_reference method to check if the expression can be used for 
  // reference constraints
  virtual bool is_reference (void) = 0;
};

#endif