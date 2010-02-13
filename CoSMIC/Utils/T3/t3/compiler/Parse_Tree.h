// -*- C++ -*-

//=============================================================================
/**
 * @file      Parse_Tree.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_PARSE_TREE_H_
#define _T3_PARSE_TREE_H_

#include "Node_Manager.h"

// Forward decl.
class T3_String_Literal_Node;

// Forward decl.
class T3_Keyword_Node;

/**
 * @class T3_Parse_Tree
 */
class T3_Parse_Tree
{
public:
  typedef ACE_Unbounded_Set <ACE_CString> STRING_LIT_SET;

  /// Default constructor.
  T3_Parse_Tree (void);

  /// Destructor.
  ~T3_Parse_Tree (void);

  T3_Node_Manager & node_manager (void);

  const T3_Node_Manager & node_manager (void) const;

  T3_Node_Manager * operator -> (void);

  const T3_Node_Manager * operator -> (void) const;

  /**
   * Get the start rule for the parse tree.
   */
  const T3_Rule_Node * start_rule (void) const;

  /**
   * Set the start rule for the parse tree. The name of the rule
   * is specified. If the rule has not been parsed, then a temp
   * placeholder for the rule is used.
   */
  void start_rule (const char * start_rule);

  const ACE_CString & name (void) const;

  void name (const ACE_CString & name);

  T3_String_Literal_Node * alloc_strlit_node (const char * strlit);

  T3_Keyword_Node * alloc_keyword_node (const char * keyword,
                                        const char * type);

  const STRING_LIT_SET & string_literals (void) const;

private:
  /// Name of the parse tree.
  ACE_CString name_;

  /// Node manager for the parse tree.
  T3_Node_Manager node_mgr_;

  /// Pointer to rot node of parse tree.
  T3_Rule_Node * root_;

  // Set of string literals for the parser.
  STRING_LIT_SET strlits_;

  // prevent the following operation(s)
  T3_Parse_Tree (const T3_Parse_Tree &);
  const T3_Parse_Tree & operator = (const T3_Parse_Tree &);
};

#include "Parse_Tree.inl"

#endif  // !defined _T3_PARSE_TREE_H_
