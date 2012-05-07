// -*- C++ -*-

//=============================================================================
/**
 * @file          Equality_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_EQUALITY_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_EQUALITY_EXPR_H_

#include "Boolean_Expr.h"

/**
 * @class Equality_Expr
 *
 * Class derived from Boolean_Expr. This class deals with the
 * equality expression like conjunction and comparison type of
 * expressions.
 */
class Equality_Expr : public Boolean_Expr
{
public:
  /// Default Constructor
  Equality_Expr (void);

  ///Destructor
  ~Equality_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context &res);

  /**
   * filter_evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @param[in]     current    The current FCO being worked with.
   * @return        bool       True/False
   */
  bool filter_evaluate (Ocl_Context &res, GAME::Mga::FCO &current);

};
#endif