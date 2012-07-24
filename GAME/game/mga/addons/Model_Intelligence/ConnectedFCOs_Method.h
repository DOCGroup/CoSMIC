// -*- C++ -*-

//=============================================================================
/**
 * @file          ConnectedFCOs_Method.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_CONNECTEDFCOS_METHOD_H_
#define _GAME_MODEL_INTELLIGENCE_CONNECTEDFCOS_METHOD_H_

#include "Method.h"

/**
 * @class ConnectedFCOs_Method
 *
 * Class derived from Method. This class 
 * returns all the fcos that are connected to this fco
 */
class ConnectedFCOs_Method : public Method
{
public:
  /// Default constructor.
  ConnectedFCOs_Method (void);

  /// Role/Kind constructor
  ConnectedFCOs_Method (std::string & temp);

  /// Role and Kind constructor
  ConnectedFCOs_Method (std::string & role, std::string & kind);

	/// Destructor.
	~ConnectedFCOs_Method (void);

  /**
   * evaluate method for evaluating the ConnectedFCOs method
   *
   * @param[in]     res           Object of model intelligence context
	 * @param[in]     caller        The object the method works with
   * @return        Object        Value object
   */
  Value * evaluate (Ocl_Context & res, GAME::Mga::Object caller);

	/**
   * evaluate method for evaluating the ConnectedFCOs method
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
  // The kind of the connection
  std::string kind_;

  // The role of the fco
  std::string role_;

  // decided to distinguish between role and kind
  std::string temp_;

  // flag value to track the case
  int flag;
};

#endif //_GAME_MODEL_INTELLIGENCE_CONNECTEDFCOS_METHOD_CALL_H_