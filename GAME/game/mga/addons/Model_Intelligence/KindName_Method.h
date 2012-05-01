// -*- C++ -*-

//=============================================================================
/**
 * @file          KindName_Method.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_KINDNAME_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_KINDNAME_METHOD_H_

#include "Method.h"

/**
 * @class KindName_Method
 *
 * Class derived from Method. This class deals
 * with finding the name of the kind of object
 */
class KindName_Method : public Method
{
public:
  /// Default constructor.
	KindName_Method (void);

	/// Destructor.
	~KindName_Method (void);

  /**
   * evaluate method for evaluating the KindName method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Collection Value object
   */
  Value * evaluate (Ocl_Context &res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the KindName method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        Value from previous method
   * @return        Object        Collection Value object
   */
	Value * evaluate (Ocl_Context &res, Value *caller);  
};

#endif //_GAME_MODEL_INTELLIGENCE_KINDNAME_METHOD_CALL_H_