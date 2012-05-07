// -*- C++ -*-

//=============================================================================
/**
 * @file          Constant_Value_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONSTANT_VALUE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_CONSTANT_VALUE_EXPR_H_

#include "Value_Expr.h"

/**
 * @class Constant_Value_Expr
 *
 * Class derived from Value_Expr. This class deals
 * with the constant values
 */
class Constant_Value_Expr : public Value_Expr
{
public:
  /// Default constructor.
  Constant_Value_Expr (unsigned int &value);

	Constant_Value_Expr (std::string &str);

	/// Destructor.
	~Constant_Value_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value Object of the constant
   */
  Value * evaluate (Ocl_Context &res);

  /**
   * filter_evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        Object     Value object of the local variable
   */
  Value * filter_evaluate (Ocl_Context &res);

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

private:
  unsigned int value_;
	std::string str_;
	int flag;
};

#endif