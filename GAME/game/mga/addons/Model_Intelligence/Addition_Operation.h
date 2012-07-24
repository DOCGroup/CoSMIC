// -*- C++ -*-

//=============================================================================
/**
 * @file          Addition_Operation.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_ADDITION_OPERATION_H_
#define _MODEL_INTELLIGENCE_ADDITION_OPERATION_H_

#include "Math_Operation_Expr.h"

/**
 * @class Addition_Operation
 *
 * Class derived from Math_Operation_Expr. This class deals with
 * the summation operation. The basic syntax being "A + B",
 * where A & B are value type of expressions
 */
class Addition_Operation : public Math_Operation_Expr
{
public:

  /// Default Constructor
  Addition_Operation (Value_Expr * left, Value_Expr * right);

  /// Destructor
  ~Addition_Operation (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value of the summation
   */
  Value * evaluate (Ocl_Context & res);

  /**
   * filter_evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        Object     Value of the summation
   */
  Value * filter_evaluate (Ocl_Context & res);

	/**
   * Determines if the object is mutable or not.
   *
   * @return        bool          true if the object is mutable
   *                              false if the object is non-mutable
   */
   bool is_mutable (void);

  /**
   * Determines if the object is for filtration or not.
   *
   * @return        bool          true if the object is for filtration
   *                              false if the object is not for filtration
   */
  bool is_filter (void);

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
  // The expression to the left of addition operator
  Value_Expr * lhs_;

  // The expression to the right of addition operator
  Value_Expr * rhs_;
};

#endif