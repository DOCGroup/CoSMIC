// -*- C++ -*-

//=============================================================================
/**
 * @file          Constant_Value_Expr.h
 *
 * $Id: Constant_Value_Expr.h 2902 2012-05-07 03:08:44Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONSTANT_VALUE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_CONSTANT_VALUE_EXPR_H_

#include "Value_SubExpr.h"

/**
 * @class Constant_Value_Expr
 *
 * Class derived from Value_SubExpr. This class deals
 * with the constant values
 */
class Constant_Value_Expr : public Value_SubExpr
{
public:
  /// Int constructor.
  Constant_Value_Expr (unsigned int & value);

  /// String constructor
	Constant_Value_Expr (std::string & str);

	/// Destructor.
	~Constant_Value_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value Object of the constant
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
private:
  // Integer value of the constant
  unsigned int value_;

  // String value of the constant
	std::string str_;

  // Flag to determine the case
	int flag;
};

#endif