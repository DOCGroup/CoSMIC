// -*- C++ -*-

//=============================================================================
/**
 * @file          ForAll_Iterator.h
 *
 * $Id$
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_FORALL_ITERATOR_H_
#define _GAME_MODEL_INTELLIGENCE_FORALL_ITERATOR_H_

#include "Iterator.h"

/**
 * @class ForAll_Iterator
 *
 * Class derived from Iterator. This class deals
 * with iterating over the entire collection and 
 * applying the expression on it.
 */
class ForAll_Iterator : public Iterator
{
public:
  /// Default constructor.
	ForAll_Iterator (void);

	/// Destructor.
	~ForAll_Iterator (void);

  /**
   * evaluate method for evaluating the parts method
   *
   * @param[in]     res           Object of model intelligence context
   * @return        Object        Boolean value object
   */
  Value * evaluate (Ocl_Context &res);

};

#endif //_GAME_MODEL_INTELLIGENCE_FORALL_ITERATOR_CALL_H_