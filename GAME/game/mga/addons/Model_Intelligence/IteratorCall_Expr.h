// -*- C++ -*-

//=============================================================================
/**
 * @file          IteratorCall_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ITERATORCALL_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_ITERATORCALL_EXPR_H_

#include "Boolean_Expr.h"
#include "Equality_Expr.h"
#include "Iterator.h"
#include "Value_Expr.h"


/**
 * @class IteratorCall_Expr
 *
 * Class derived from Boolean_Expr. This class deals with the
 * iterator expressions which further may contain
 * sub-expression. The syntax being:
 * "<expression> -> <iterator_name> ( {<declator> *{, <declator>}  : <declaratortype>}
 *                                      | <expression>)"
 */
class IteratorCall_Expr : public Boolean_Expr
{
public:

  /// Default constructor (ex. used for ForAll).
  IteratorCall_Expr (Value_Expr * obj,
                     Iterator * name,
                     Boolean_Expr * expr);

  /// Value expression constructor (used for IsUnique).
  IteratorCall_Expr (Value_Expr * obj,
                     Iterator * name,
                     Value_Expr * valexpr);

	/// Destructor.
	~IteratorCall_Expr (void);

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
   * set_declarators method for setting the value of next method
   *
	 * @param[in]         m          declarator to be placed in next
   */
  void set_declarators (std::vector <std::string> & next);

  /**
   * set_dec_type for setting the value of next method
   *
	 * @param[in]         m          declarator type
   */
  void set_dec_type (std::string & type);

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
	// The expression on which the iterator is invoked.
  Value_Expr * obj_;

  // The iterator object
  Iterator * name_;

  // The expression to be evaluated
  Boolean_Expr * expr_;

  // The expression to be evaluated
  Value_Expr * valexpr_;

  // Flag to determine the case
  int flag;

  // Setting the declarators
  std::vector <std::string> next_;

  // Setting the declarator type
  std::string dec_type_;
};


#endif