// -*- C++ -*-

//=============================================================================
/**
 * @file          Greater_Equal_Expr.h
 *
 * $Id: Greater_Equal_Expr.h 2902 2012-05-07 03:08:44Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_GREATER_EQUAL_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_GREATER_EQUAL_EXPR_H_

#include "Comparison_Expr.h"
#include "Value_Expr.h"

/**
 * @class Greater_Equal_Expr
 *
 * Class derived from Comparison_Expr. This class deals with
 * checking the greater than equal to relation between two variables.
 * The basic syntax being "A >= B", where A & B both can be local variables
 * or one can be a constant value
 */
class Greater_Equal_Expr : public Comparison_Expr
{
public:
  /// Default constructor.
	Greater_Equal_Expr (Value_Expr * left, Value_Expr * right);

	/// Destructor.
	~Greater_Equal_Expr (void);

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

  /**
   * Adding FCO that the user selected in the dialog
   *
   * @param[in]     obj        Parent model of the FCO being added
   * @param[in]     count      Number of FCOs to be added
   * @param[in]     metatype   Metatype of the FCO being added
   * @param[in]     metarole   Metarole of the FCO being added
   * @return        bool       True/False
   */
  bool list_add (GAME::Mga::Model & obj,
                 size_t count,
                 GAME::Mga::Meta::FCO & metatype,
                 GAME::Mga::Meta::Role & metarole);

  /**
   * Deleting FCO that the user selected in the dialog
   *
   * @param[in]     obj        Parent model of the FCO being added
   * @param[in]     count      Number of FCOs to be added
   * @param[in]     metatype   Metatype of the FCO being added
   * @param[in]     metarole   Metarole of the FCO being added
   * @return        bool       True/False
   */
  bool list_delete (GAME::Mga::Model & obj,
                    size_t count,
                    GAME::Mga::Meta::FCO & metatype,
                    GAME::Mga::Meta::Role & metarole);

private:
  // Left side expression
  Value_Expr * lhs_;

  // Right side expression
  Value_Expr * rhs_;
};

#endif