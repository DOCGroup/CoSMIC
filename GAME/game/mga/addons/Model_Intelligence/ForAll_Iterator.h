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
   * evaluate method for evaluating the exists iterator method
   *
   * @param[in]     res           Object of model intelligence context
   * @param[in]     coll          The collection on which the iterator operates
   * @param[in]     decl          The collection of declarators
   * @param[in]     decltype      The declaration type
   * @param[in]     expr          Boolean expression applied to the iterator
   * @return        Object        Value object
   */
  Value * evaluate (Ocl_Context & res,
                    std::vector <GAME::Mga::FCO> & coll,
                    std::vector <std::string> & decl,
                    std::string & decltype,
                    Boolean_Expr * expr);

 /**
   * evaluate method for evaluating the exists iterator method
   *
   * @param[in]     res           Object of model intelligence context
   * @param[in]     coll          The collection on which the iterator operates
   * @param[in]     decl          The collection of declarators
   * @param[in]     decltype      The declaration type
   * @param[in]     valexpr       Value expression applied to the iterator
   * @return        Object        Value object
   */
  Value * evaluate (Ocl_Context & res,
                    std::vector <GAME::Mga::FCO> & coll,
                    std::vector <std::string> & decl,
                    std::string & decltype,
                    Value_Expr * valexpr);

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
};

#endif //_GAME_MODEL_INTELLIGENCE_FORALL_ITERATOR_CALL_H_