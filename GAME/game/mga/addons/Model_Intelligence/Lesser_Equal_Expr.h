// -*- C++ -*-

//=============================================================================
/**
 * @file          Lesser_Equal_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_LESSER_EQUAL_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_LESSER_EQUAL_EXPR_H_

#include "Comparison_Expr.h"
#include "Value_Expr.h"

/**
 * @class Lesser_Equal_Expr
 *
 * Class derived from Comparison_Expr. This class deals with
 * checking the less than equal to relation between two variables.
 * The basic syntax being "A <= B", where A & B both can be local variables
 * or one can be a constant value
 */
class Lesser_Equal_Expr : public Comparison_Expr
{
public:
  /// Default constructor.
	Lesser_Equal_Expr (Value_Expr *left, Value_Expr *right);

	/// Destructor.
	~Lesser_Equal_Expr (void);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res        Object of model intelligence context.
   * @return        bool       True/False
   */
  bool evaluate (Ocl_Context &res);

  /**
   * Adding FCO that the user selected in the dialog
   *
   * @param[in]     obj        Parent model of the FCO being added
   * @param[in]     count      Number of FCOs to be added
   * @param[in]     metatype   Metatype of the FCO being added
   * @param[in]     metarole   Metarole of the FCO being added
   * @return        bool       True/False
   */
  bool list_add (GAME::Mga::Model &obj,
                 size_t count,
                 GAME::Mga::Meta::FCO &metatype,
                 GAME::Mga::Meta::Role &metarole);

  /**
   * Deleting FCO that the user selected in the dialog
   *
   * @param[in]     obj        Parent model of the FCO being added
   * @param[in]     count      Number of FCOs to be added
   * @param[in]     metatype   Metatype of the FCO being added
   * @param[in]     metarole   Metarole of the FCO being added
   * @return        bool       True/False
   */
  bool list_delete (GAME::Mga::Model &obj,
                    size_t count,
                    GAME::Mga::Meta::FCO &metatype,
                    GAME::Mga::Meta::Role &metarole);

private:
  Value_Expr * lhs_;
  Value_Expr * rhs_;
};

#endif