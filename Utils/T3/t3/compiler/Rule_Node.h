// -*- C++ -*-

//=============================================================================
/**
 * @file      Rule_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_RULE_NODE_H_
#define _T3_RULE_NODE_H_

#include "ace/SString.h"
#include "Node.h"

// Forward decl.
class T3_Definition;

/**
 * @class T3_Rule_Node
 *
 * Node for a rule in the grammar specification.
 */
class T3_Rule_Node : public T3_Node
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       name        Name of the rule.
   */
  T3_Rule_Node (const ACE_CString & name);

  /// Destructor.
  virtual ~T3_Rule_Node (void);

  /**
   * Get the name of the rule.
   *
   * @return          Name of the rule.
   */
  const ACE_CString & name (void) const;

  virtual void accept (T3_Node_Visitor & visitor);

  virtual size_t length (void) const;

private:
  /// Name of the rule.
  ACE_CString name_;
};

#include "Rule_Node.inl"

#endif  // !defined _T3_RULE_NODE_H_