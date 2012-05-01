// -*- C++ -*-

//=============================================================================
/**
 * @file          Local_Value_Assignment_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_ASSIGNMENT_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_ASSIGNMENT_EXPR_H_

#include "Boolean_Expr.h"
#include "Value_Expr.h"
#include "Value.h"

/**
 * @class Local_Value_Assignment_Expr
 *
 * Class derived from Boolean_Expr. This class deals with the
 * local value assignment expressions which further may contain
 * sub-expression. The syntax being "let <identifier> = <sub-exprs> in"
 */
class Local_Value_Assignment_Expr : public Boolean_Expr
{
public:

  /// Default constructor.
  Local_Value_Assignment_Expr (std::string &var, Value_Expr *right);

	/// Destructor.
	~Local_Value_Assignment_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context &res);

  /**
   * Value method for getting the value of the local variable
   * @return        value object of the local variable
   */
  Value * value (void);

private:
  // Variable for storing the local variable name
  std::string varname_;

  // The right hand side of the expression
  Value_Expr * rhs_;

  // Value of the local variable
  Value * value_;
};


#endif