// -*- C++ -*-

//=============================================================================
/**
 * @file          Local_Value_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_EXPR_H_

#include "Value_Expr.h"

/**
 * @class Local_Value_Expr
 *
 * Class derived from Value_Expr. This class deals
 * with the local variable values
 */
class Local_Value_Expr : public Value_Expr
{
public:
  /// Default constructor.
  Local_Value_Expr (std::string var);

	/// Destructor.
	~Local_Value_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        unsigned int  value of the local variable
   */
  unsigned int evaluate (Ocl_Context &res);

  /**
   * Determines if the object is mutable or not.
   *
   * @return        bool          true if the object is mutable
   *                              false if the object is non-mutable
   */
  bool ismutable (void);

private:
  std::string localvar_;
};

#endif //_GAME_MODEL_INTELLIGENCE_LOCAL_VALUE_EXPR_H_