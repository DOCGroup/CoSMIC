  // -*- C++ -*-

//=============================================================================
/**
 * @file          Iterator.h
 *
 * $Id: $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_ITERATOR_H_
#define _GAME_MODEL_INTELLIGENCE_ITERATOR_H_

#include <iostream>
#include <vector>
#include "game/mga/Model.h"
#include "Model_Intelligence_Context.h"
#include "Value.h"

/**
 * @class Iterator
 *
 * Base class for all iterators
 */
class Iterator 
{
public:
  /// Default constructor.
	Iterator (void);

	/// Destructor.
	~Iterator (void);

  // Pure virtual method for evaluating respective expression
  virtual Value * evaluate (Ocl_Context &res) = 0;

};


#endif