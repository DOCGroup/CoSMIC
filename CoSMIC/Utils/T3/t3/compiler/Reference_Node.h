// -*- C++ -*-

//=============================================================================
/**
 * @file      Reference_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_REFERENCE_NODE_H_
#define _T3_REFERENCE_NODE_H_

#include "Node.h"

/**
 * @class T3_Reference_Node
 *
 * Node for handling references in the target grammar.
 */
class T3_Reference_Node : public T3_Node
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       name        Name of the rule.
   */
  T3_Reference_Node (void);

  /// Destructor.
  virtual ~T3_Reference_Node (void);

  virtual void accept (T3_Node_Visitor & visitor);
};

#include "Reference_Node.inl"

#endif  // !defined _T3_SELECTION_NODE_H_