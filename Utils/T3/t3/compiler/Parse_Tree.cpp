// $Id$

#include "Parse_Tree.h"
#include "String_Literal_Node.h"

//
// alloc_strlit_node
//
T3_String_Literal_Node *
T3_Parse_Tree::alloc_strlit_node (const char * strlit)
{
  // Allocate a new node.
  T3_String_Literal_Node * node =
    this->node_mgr_.alloc_node <T3_String_Literal_Node> (strlit);

  // Store the string literal.
  this->strlits_.insert (strlit);
  return node;
}

//
// alloc_strlit_node
//
T3_Keyword_Node * T3_Parse_Tree::
alloc_keyword_node (const char * keyword, const char * type)
{
  // Allocate a new node.
  T3_Keyword_Node * node =
    this->node_mgr_.alloc_node <T3_Keyword_Node> (keyword, type);

  // Store the string literals.
  this->strlits_.insert (keyword);
  this->strlits_.insert (type);

  return node;
}
