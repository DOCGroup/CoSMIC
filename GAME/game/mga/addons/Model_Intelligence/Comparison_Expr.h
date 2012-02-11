// -*- C++ -*-

//=============================================================================
/**
 * @file          Comparison_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_COMPARISON_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_COMPARISON_EXPR_H_

#include "Equality_Expr.h"

/**
 * @class Comparison_Expr
 *
 * Class derived from Equality_Expr. This class forms the
 * base class for comparisons like "=", ">=", "<="
 */
class Comparison_Expr : public Equality_Expr
{
public:
  /// Default Constructor
  Comparison_Expr (void);

  ///Destructor
  ~Comparison_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context &res);

};
#endif