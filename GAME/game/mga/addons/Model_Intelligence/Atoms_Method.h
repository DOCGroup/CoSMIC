// -*- C++ -*-

//=============================================================================
/**
 * @file          Atoms_Method.h
 *
 * $Id:  $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ATOMS_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_ATOMS_METHOD_H_

#include "Method.h"

/**
 * @class Atoms_Method
 *
 * Class derived from Method. This class deals
 * with all the Atoms contained by a folder
 */
class Atoms_Method : public Method
{
public:
  /// Default constructor.
	Atoms_Method (void);

  // Kind constructor
  Atoms_Method (std::string & kind);

	/// Destructor.
	~Atoms_Method (void);

  /**
   * evaluate method for evaluating the atoms method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Value object
   */
  Value * evaluate (Ocl_Context & res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the atoms method
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
  // Kind of the object
  std::string kind_;

  // flag to track the case i.e. when kind is provided or not
  int flag;
};

#endif //_GAME_MODEL_INTELLIGENCE_ATOMS_METHOD_CALL_H_