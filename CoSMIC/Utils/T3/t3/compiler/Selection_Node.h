// -*- C++ -*-

//=============================================================================
/**
 * @file      Selection_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_SELECTION_NODE_H_
#define _T3_SELECTION_NODE_H_

#include "ace/Unbounded_Set.h"
#include "Node.h"

// Forward decl.
class T3_Definition;

/**
 * @class T3_Selection_Node
 *
 * Node for handling selection in the target grammar. Selection
 * specifications are enclosed in parenthesis () and have a vertical
 * bar | for each option.
 */
class T3_Selection_Node : public T3_Node
{
public:
  /// Type definition for the options.
  typedef ACE_Unbounded_Set <T3_Node *> options_type;

  /**
   * Initializing constructor.
   *
   * @param[in]       name        Name of the rule.
   */
  T3_Selection_Node (void);

  /// Destructor.
  virtual ~T3_Selection_Node (void);

  /**
   * Insert a new option into the selection.
   *
   * @param[in]       option      Option to insert.
   */
  int insert_option (const T3_Definition &);

  /**
   * Remove an existing option from the selection.
   *
   * @param[in]       option      Option to remove.
   */
  int remove_option (const T3_Definition &);

  /// Get the list of options for this node.
  const options_type & options (void) const;

  /// Accept the node visitor.
  virtual void accept (T3_Node_Visitor & visitor);

private:
  /// Options for the selection.
  options_type options_;
};

void operator += (T3_Selection_Node *, const T3_Definition &);

#include "Selection_Node.inl"

#endif  // !defined _T3_SELECTION_NODE_H_