// -*- C++ -*-

//=============================================================================
/**
 * @file          Local_Value_Assignment_Expr.h
 *
 * $Id: Local_Value_Assignment_Expr.h 2902 2012-05-07 03:08:44Z tpati $
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
  Local_Value_Assignment_Expr (std::string & var, Value_Expr * right);

	/// Destructor.
	~Local_Value_Assignment_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context & res);

  /**
   * filter_evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @param[in]     current    The current FCO being worked with.
   * @return        bool       True/False
   */
  bool filter_evaluate (Ocl_Context & res, GAME::Mga::FCO & current);

  /**
   * Value method for getting the value of the local variable
   * @return        value object of the local variable
   */
  Value * value (void);

  /**
   * is_association method for determining if this expression
   * can be used for association constraints
   *
   * @return       bool       True/False
   */
  bool is_association (void);

  /**
   * is_containment method for determining if this expression
   * can be used for containment constraints
   *
   * @return       bool       True/False
   */
  bool is_containment (void);

  /**
   * is_reference method for determining if this expression
   * can be used for reference constraints
   *
   * @return       bool       True/False
   */
  bool is_reference (void);

private:
  // Variable for storing the local variable name
  std::string varname_;

  // The right hand side of the expression
  Value_Expr * rhs_;

  // Value of the local variable
  Value * value_;
};


#endif