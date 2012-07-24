// -*- C++ -*-

//=============================================================================
/**
 * @file          Local_Value_Expr.h
 *
 * $Id: Local_Value_Expr.h 2902 2012-05-07 03:08:44Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_EXPR_H_

#include "Value_SubExpr.h"

/**
 * @class Local_Value_Expr
 *
 * Class derived from Value_SubExpr. This class deals
 * with the local variable values
 */
class Local_Value_Expr : public Value_SubExpr
{
public:
  /// Default constructor.
  Local_Value_Expr (std::string & var);

	/// Destructor.
	~Local_Value_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value object of the local variable
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
  // The local variable
  std::string localvar_;
};

#endif //_GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_EXPR_H_