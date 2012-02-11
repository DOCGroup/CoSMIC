// -*- C++ -*-

//=============================================================================
/**
 * @file          Collection_Expr.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_COLLECTION_EXPR_H_
#define _GAME_MODEL_INTELLIGENCE_COLLECTION_EXPR_H_

#include <iostream>
#include <vector>
#include "game/mga/FCO.h"
#include "Model_Intelligence_Context.h"

/**
 * @class Collection_Expr
 *
 * Base class for any expression returning collection
 */
class Collection_Expr 
{
public:
  /// Default constructor.
	Collection_Expr (void);

	/// Destructor.
	~Collection_Expr (void);

  // Pure virtual evaluate method to be implemented by the 
  // derived classes
  virtual void evaluate (std::vector <GAME::Mga::FCO> &parts, 
                         Ocl_Context &res) = 0;
};

#endif