// -*- C++ -*-

//=============================================================================
/**
 * @file          Method_Call.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_METHOD_CALL_H_
#define _GAME_MODEL_INTELLIGENCE_METHOD_CALL_H_

#include "Value_Expr.h"
#include "Method.h"

/**
 * @class Method_Call
 *
 * Class derived from Value_Expr. This class deals
 * with the methodcalls
 */
class Method_Call : public Value_Expr
{
public:
  /// constructor.
	Method_Call (void);

	/// Destructor.
	~Method_Call (void);

	/**
   * set_next method for setting the value of next method
   *
	 * @param[in]     m             Method pointer to be placed in next
   */
	void set_next (std::vector <Method *> &next);

  /**
   * evaluate method for evaluating the respective expression
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Value object of the local variable
   */
  Value * evaluate (Ocl_Context &res);

  /**
   * Determines if the object is mutable or not.
   *
   * @return        bool          true if the object is mutable
   *                              false if the object is non-mutable
   */
  bool is_mutable (void);

protected:
  GAME::Mga::Object caller_;
	Method * base_meth_;
	std::vector <Method *> next_;
};

#endif //_GAME_MODEL_INTELLIGENCE_METHOD_CALL_H_