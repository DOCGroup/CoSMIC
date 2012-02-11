// -*- C++ -*-

//=============================================================================
/**
 * @file          Size_Method_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_SIZE_METHOD_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_SIZE_METHOD_EXPR_H_

#include "Value_Expr.h"
#include "Collection_Expr.h"

/**
 * @class Size_Method_Expr
 *
 * Class derived from Value_Expr. This class deals
 * with finding the size of collection
 */
class Size_Method_Expr : public Value_Expr
{
public:
  /// Default constructor.
	Size_Method_Expr (Collection_Expr *coll);

	/// Destructor.
	~Size_Method_Expr (void);

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
  Collection_Expr * coll_;
};

#endif