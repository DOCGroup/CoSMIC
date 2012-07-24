// -*- C++ -*-

//=============================================================================
/**
 * @file          Value_SubExpr.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_VALUE_SUBEXPR_H_
#define _GAME_MODEL_INTELLIGENCE_VALUE_SUBEXPR_H_

#include "Value_Expr.h"

/**
 * @class Value_SubExpr
 *
 * Class derived from Value_Expr. This class forms the
 * base class for general value expressions like methodcalls
 */
class Value_SubExpr : public Value_Expr
{
public:
  /// Default Constructor
  Value_SubExpr (void);

  ///Destructor
  ~Value_SubExpr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value Object of the arithmetic operation
   */
  Value * evaluate (Ocl_Context & res);

  /**
   * filter_evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        Object     Value object of the local variable
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

};
#endif