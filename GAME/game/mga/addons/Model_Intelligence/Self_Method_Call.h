// -*- C++ -*-

//=============================================================================
/**
 * @file          Self_Method_Call.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_SELF_METHOD_CALL_H_
#define _GAME_MODEL_INTELLIGENCE_SELF_METHOD_CALL_H_

#include "Method_Call.h"
#include <string>

/**
 * @class Self_Method_Call
 *
 * Class derived from Method_Call. This class sets the
 * object value to self.
 */
class Self_Method_Call : public Method_Call
{
public:
	// Constructor
	Self_Method_Call (Method * meth);

	// Destructor
	~Self_Method_Call (void);

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

private:
  // The invoking method
	Method * meth_;
};

#endif //_GAME_MODEL_INTELLIGENCE_SELF_METHOD_CALL_H_