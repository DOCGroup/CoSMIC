// -*- C++ -*-

//=============================================================================
/**
 * @file      Node_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_NODE_MANAGER_H_
#define _T3_NODE_MANAGER_H_

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"
#include "ace/Unbounded_Set.h"

// Forward decl.
class T3_Node;

// Forward decl.
class T3_Rule_Node;

/**
 * @class T3_Node_Manager
 */
class T3_Node_Manager
{
public:
  /// Map for storing nodes by their name.
  typedef ACE_Hash_Map_Manager <ACE_CString,
                                T3_Rule_Node *,
                                ACE_Null_Mutex> rule_map_type;

  /// Default constructor.
  T3_Node_Manager (void);

  /// Destructor.
  ~T3_Node_Manager (void);

  /**
   * Lookup a rule in the manager.
   *
   * @param[in]     name        Name of the rule.
   * @param[in]     node        Pointer to the rule node.
   */
  int lookup_rule (const ACE_CString & name, T3_Rule_Node * &node);

  /**
   * Get the collection of rules in the parse tree.
   *
   * @return        Reference to the rules.
   */
  const rule_map_type & rules (void) const;

  template <typename T>
  T * alloc_node (void)
  {
    T * new_node = 0;
    ACE_NEW_RETURN (new_node, T (), 0);

    ACE_Auto_Ptr <T> auto_clean (new_node);

    if (0 == this->nodes_.insert (new_node))
      return auto_clean.release ();

    return 0;
  }

  template <typename T, typename Arg1>
  T * alloc_node (Arg1 arg1)
  {
    T * new_node = 0;
    ACE_NEW_RETURN (new_node, T (arg1), 0);

    ACE_Auto_Ptr <T> auto_clean (new_node);

    if (0 == this->nodes_.insert (new_node))
      return auto_clean.release ();

    return 0;
  }

  template <typename T, typename Arg1, typename Arg2>
  T * alloc_node (Arg1 arg1, Arg2 arg2)
  {
    T * new_node = 0;
    ACE_NEW_RETURN (new_node, T (arg1, arg2), 0);

    ACE_Auto_Ptr <T> auto_clean (new_node);

    if (0 == this->nodes_.insert (new_node))
      return auto_clean.release ();

    return 0;
  }

  /**
   * Release the specified node.
   *
   * @param[in]       node        Target node to release.
   */
  int release_node (T3_Node * node);

private:
  /// Type definition for the set of nodes.
  typedef ACE_Unbounded_Set <T3_Node *> node_set_type;

  /// Collection of nodes.
  node_set_type nodes_;

  /// Collection of nodes by their name.
  rule_map_type rule_map_;
};

#include "Node_Manager.inl"

#endif  // !defined _T3_NODE_MANAGER_H_
