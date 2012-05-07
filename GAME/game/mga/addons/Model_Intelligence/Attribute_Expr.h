// -*- C++ -*-

//=============================================================================
/**
 * @file          Attribute_Expr.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ATTRIBUTE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_ATTRIBUTE_EXPR_H_

#include "Value_Expr.h"

/**
 * @class  Attribute_Expr
 *
 * Class derived from Value_Expr. This class deals
 * with finding the values of the attributes of FCO
 */
class  Attribute_Expr : public Value_Expr
{
public:
  /// Default constructor.
	 Attribute_Expr (std::string &var, std::string &attr);

	/// Destructor.
	~Attribute_Expr (void);

	/**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value object of the local variable
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
	std::string var_;
	std::string attribute_;
 
};

#endif //_GAME_MODEL_INTELLIGENCE_ATTRIBUTE_EXPR_H_