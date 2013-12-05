// -*- C++ -*-

//=============================================================================
/**
 * @file      Optional_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_OPTIONAL_NODE_H_
#define _T3_OPTIONAL_NODE_H_

#include "Node.h"

/**
 * @class T3_Optional_Node
 *
 * Node for handling optional definitions in the grammar. Optional
 * definitions are enclosed in brackets [].
 */
class T3_Optional_Node : public T3_Node
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       name        Name of the rule.
   */
  T3_Optional_Node (T3_Node * definition);

  /// Destructor.
  virtual ~T3_Optional_Node (void);

  /// Get the list of options for this node.
  T3_Node * definition (void) const;

  /// Accept the node visitor.
  virtual void accept (T3_Node_Visitor & visitor);

private:
  /// Definition for the optional node.
  T3_Node * definition_;
};

#include "Optional_Node.inl"

#endif  // !defined _T3_SELECTION_NODE_H_