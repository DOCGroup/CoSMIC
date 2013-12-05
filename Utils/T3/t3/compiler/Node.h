// -*- C++ -*-

//=============================================================================
/**
 * @file      Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_NODE_H_
#define _T3_NODE_H_

// Forward decl.
class T3_Definition;

// Forward decl.
class T3_Node_Manager;

// Forward decl.
class T3_Node_Visitor;

/**
 * @class T3_Node
 *
 * Base class for all parser node types.
 */
class T3_Node
{
  // Friend decl.
  friend class T3_Definition;
  friend class T3_Node_Manager;

protected:
  /// Default constuctor.
  T3_Node (void);

  /// Destructor.
  virtual ~T3_Node (void);

public:
  /**
   * Get the next node.
   *
   * @return        Pointer to next node.
   */
  T3_Node * next (void) const;

  void next (T3_Node * next);

  /**
   * Accept the visitor. This method must be implemented by all
   * nodes that derive from this class.
   */
  virtual void accept (T3_Node_Visitor & node) = 0;

  virtual size_t length (void) const;

  bool is_end (void) const;

protected:
  /// Pointer to the next node.
  T3_Node * next_;

  T3_Node (const T3_Node &);
  const T3_Node & operator = (const T3_Node &);
};

#include "Node.inl"

#endif  // !defined _T3_NODE_H_
