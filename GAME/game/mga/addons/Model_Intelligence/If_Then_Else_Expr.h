// -*- C++ -*-

//=============================================================================
/**
 * @file          If_Then_Else_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_IF_THEN_ELSE_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_IF_THEN_ELSE_EXPR_H_

#include "Boolean_Expr.h"
#include "Equality_Expr.h"

/**
 * @class If_Then_Else_Expr
 *
 * Class derived from Boolean_Expr. This class deals with the
 * If-then-else expressions which further may contain
 * sub-expression. The syntax being:
 * "if <condition> then <expression> else <expression> endif"
 */
class If_Then_Else_Expr : public Boolean_Expr
{
public:

  /// Default constructor.
  If_Then_Else_Expr (Equality_Expr * cond,
		                 std::vector <Boolean_Expr *> & first,
										 std::vector <Boolean_Expr *> & second);

	/// Destructor.
	~If_Then_Else_Expr (void);

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
   * Value method for getting the value of the local variable
   * @return        value object of the local variable
   */
  Value * value (void);

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
	// The condition.
  Equality_Expr * cond_;

	// The boolean expression associated to then statement
	std::vector <Boolean_Expr *> first_;

	// The boolean expression associated to else statement
	std::vector <Boolean_Expr *> second_; 
};


#endif