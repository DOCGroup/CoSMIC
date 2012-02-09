// -*- C++ -*-

//=============================================================================
/**
 * @file          And_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _MODEL_INTELLIGENCE_AND_EXPR_H_
#define _MODEL_INTELLIGENCE_AND_EXPR_H_

#include "Conjunction_Expr.h"
#include "Comparison_Expr.h"

/**
 * @class And_Expr
 *
 * Class derived from Conjunction_Expr. This class deals with
 * the anding operation. The basic syntax being "A and B",
 * where A & B are equality type of expressions
 */
class And_Expr : public Conjunction_Expr
{
public:
  /// Default Constructor
  And_Expr (Equality_Expr * left, Equality_Expr * right);

  /// Destructor
  ~And_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context &res);

private:
  Equality_Expr * lhs_;
  Equality_Expr * rhs_;
};

#endif