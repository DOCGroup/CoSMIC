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

#include "Value_SubExpr.h"
#include "Method.h"

/**
 * @class Method_Call
 *
 * Class derived from Value_SubExpr. This class deals
 * with the methodcalls
 */
class Method_Call : public Value_SubExpr
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
	void set_next (std::vector <Method *> & next);

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
protected:
  // The method caller
  GAME::Mga::Object caller_;

  // The base method
	Method * base_meth_;

  // The next method in the chain
	std::vector <Method *> next_;
};

#endif //_GAME_MODEL_INTELLIGENCE_METHOD_CALL_H_