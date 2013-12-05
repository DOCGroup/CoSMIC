// -*- C++ -*-

//=============================================================================
/**
 * @file      Substitution_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_SUBSTITUITION_NODE_H_
#define _T3_SUBSTITUITION_NODE_H_

#include "ace/SString.h"
#include "Quantifier_Node.h"

// Forward decl.
class T3_Rule_Node;

/**
 * @class T3_Substitution_Node
 *
 * Node for the substitution specificiation of a grammar.
 */
class T3_Substitution_Node : public T3_Quantifier_Node
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       name        Target rule for
   */
  T3_Substitution_Node (const T3_Rule_Node * rule);

  /// Destructor.
  virtual ~T3_Substitution_Node (void);

  /**
   * Get the target rule.
   *
   * @return          Name of the rule.
   */
  const T3_Rule_Node * target_rule (void) const;

  /// Accept the node visitor.
  virtual void accept (T3_Node_Visitor & visitor);

private:
  /// Name of the rule.
  const T3_Rule_Node * rule_;
};

#include "Substitution_Node.inl"

#endif  // !defined _T3_SUBSTITUITION_NODE_H_