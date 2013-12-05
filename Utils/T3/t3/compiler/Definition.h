// -*- C++ -*-

//=============================================================================
/**
 * @file      Definition.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_DEFINITION_H_
#define _T3_DEFINITION_H_

// Forward decl.
class T3_Node;

/**
 * @class T3_Definition
 *
 * Utility class for constructing the definition of a rule, which is a
 * sequence of nodes. This class does not manage any of the nodes and
 * is simply a placeholder for the parser when parsing the rules of a
 * grammar. Once a definition if completely constructed, the nodes are
 * store in the parent rule and this class is no longer used.
 */
class T3_Definition
{
public:
  /// Default constructor.
  T3_Definition (void);

  /**
   * Copy constructor
   */
  T3_Definition (const T3_Definition & def);

  /// Destructor.
  ~T3_Definition (void);

  /**
   * Append a new node to the definition.
   *
   * @param[in]         node        Node to append to definition.
   */
  int append_node (T3_Node * node);

  /**
   * Plus-assignment operation.
   */
  template <typename Arg1>
  void operator += (Arg1 node)
  {

  }

  /**
   * Assignment operation.
   */
  const T3_Definition & operator = (const T3_Definition & def);

  /// Get the starting node for the definition.
  T3_Node * start (void) const;

private:
  /// First node in the definition.
  T3_Node * head_;

  /// Last node in the definition.
  T3_Node * tail_;

  /// Current size of the definition.
  size_t size_;
};

#include "Definition.inl"

#endif  // !defined _T3_DEFINITION_H_
