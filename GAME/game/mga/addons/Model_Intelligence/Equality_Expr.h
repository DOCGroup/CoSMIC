// -*- C++ -*-

//=============================================================================
/**
 * @file          Equality_Expr.h
 *
 * $Id: Equality_Expr.h 2902 2012-05-07 03:08:44Z tpati $
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
};
#endif