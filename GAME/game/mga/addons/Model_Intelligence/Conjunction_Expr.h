// -*- C++ -*-

//=============================================================================
/**
 * @file          Conjunction_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONJUNCTION_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_CONJUNCTION_EXPR_H_

#include "Equality_Expr.h"

/**
 * @class Conjunction_Expr
 *
 * Class derived from Equality_Expr. This class forms the
 * base class for conjunctions like "and", "or"
 */
class Conjunction_Expr : public Equality_Expr
{
public:
  /// Default Constructor
  Conjunction_Expr (void);

  ///Destructor
  ~Conjunction_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context &res);

};
#endif