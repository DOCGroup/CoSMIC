// -*- C++ -*-

//=============================================================================
/**
 * @file          Or_Expr.h
 *
 * $Id: And_Expr.h 2902 2012-05-07 03:08:44Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_OR_EXPR_H_
#define _MODEL_INTELLIGENCE_OR_EXPR_H_

#include "Conjunction_Expr.h"
#include "Comparison_Expr.h"

/**
 * @class Or_Expr
 *
 * Class derived from Conjunction_Expr. This class deals with
 * the oring operation. The basic syntax being "A or B",
 * where A & B are equality type of expressions
 */
class Or_Expr : public Conjunction_Expr
{
public:
  /// Default Constructor
  Or_Expr (Equality_Expr * left, Equality_Expr * right);

  /// Destructor
  ~Or_Expr (void);

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
  // Left side equality expression
  Equality_Expr * lhs_;

  // Right side equality expression
  Equality_Expr * rhs_;
};

#endif