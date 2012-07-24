// -*- C++ -*-

//=============================================================================
/**
 * @file          ModelParts_Method.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_MODELPARTS_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_MODELPARTS_METHOD_H_

#include "Method.h"

/**
 * @class ModelParts_Method
 *
 * Class derived from Method. This class deals
 * with all the Model parts that a particular metarole/metatype
 * has i.e. with the Model present in the model
 */
class ModelParts_Method : public Method
{
public:
  /// Default constructor.
	ModelParts_Method (std::string & role);

	/// Destructor.
	~ModelParts_Method (void);

  /**
   * evaluate method for evaluating the modelParts method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Value object
   */
  Value * evaluate (Ocl_Context & res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the modelParts method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        Value from previous method
   * @return        Object        Value object
   */
	Value * evaluate (Ocl_Context & res, Value * caller);

  /**
   * Determines if the object is for filtration or not.
   *
   * @return        bool          true if the object is for filtration
   *                              false if the object is not for filtration
   */
  bool is_filter (void);

 /**
   * is_association method for determining if this method
   * can be used for association constraints
   *
   * @return       bool       True/False
   */
  bool is_association (void);

  /**
   * is_containment method for determining if this method
   * can be used for containment constraints
   *
   * @return       bool       True/False
   */
  bool is_containment (void);

  /**
   * is_reference method for determining if this method
   * can be used for reference constraints
   *
   * @return       bool       True/False
   */
  bool is_reference (void);
private:
  // The containment role of the element being collected
  std::string role_;
};

#endif //_GAME_MODEL_INTELLIGENCE_MODELPARTS_METHOD_CALL_H_