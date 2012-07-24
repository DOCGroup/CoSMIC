// -*- C++ -*-

//=============================================================================
/**
 * @file          Not_Equal_Expr.h
 *
 * $Id: Equal_Expr.h 2902 2012-05-07 03:08:44Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_NOT_EQUAL_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_NOT_EQUAL_EXPR_H_

#include "Comparison_Expr.h"
#include "Value_Expr.h"

/**
 * @class Not_Equal_Expr
 *
 * Class derived from Comparison_Expr. This class deals with
 * checking the equality between two variables. The basic 
 * syntax being "A <> B", where A & B both can be local variables
 * or one can be a constant value
 */
class Not_Equal_Expr : public Comparison_Expr
{
public:
  /// Default constructor.
	Not_Equal_Expr (Value_Expr * left, Value_Expr * right);

	/// Destructor.
	~Not_Equal_Expr (void);

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
   * is_association method for determining if this method
   * can be used for association constraints
   *
   * @return       bool       True/False
   */
  bool is_association (void);

  /**
   * is_containment method for determining if this method
   * can be used for containment constraints
   *
   * @return       bool       True/False
   */
  bool is_containment (void);

  /**
   * is_reference method for determining if this method
   * can be used for reference constraints
   *
   * @return       bool       True/False
   */
  bool is_reference (void);
private:
  // Left side expression
  Value_Expr * lhs_;

  // Right side expression
  Value_Expr * rhs_;
};

#endif