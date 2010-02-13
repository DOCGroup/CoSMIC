// -*- C++ -*-

//=============================================================================
/**
 * @file        Node_Visitor.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _T3_NODE_VISITOR_H_
#define _T3_NODE_VISITOR_H_

// Forward decl.
class T3_Rule_Node;

// Forward decl.
class T3_String_Attr_Node;

// Forward decl.
class T3_Boolean_Attr_Node;

// Forward decl.
class T3_Integer_Attr_Node;

// Forward decl.
class T3_Real_Attr_Node;

// Forward decl.
class T3_Optional_Node;

// Forward decl.
class T3_String_Literal_Node;

// Forward decl.
class T3_Keyword_Node;

// Forward decl.
class T3_Selection_Node;

// Forward decl.
class T3_Substitution_Node;

/**
 * @class T3_Node_Visitor
 */
class T3_Node_Visitor
{
public:
  T3_Node_Visitor (void);

  virtual ~T3_Node_Visitor (void);

  virtual void visit_Rule_Node (const T3_Rule_Node & node);

  virtual void visit_String_Attr_Node (const T3_String_Attr_Node & node);

  virtual void visit_Boolean_Attr_Node (const T3_Boolean_Attr_Node & node);

  virtual void visit_Integer_Attr_Node (const T3_Integer_Attr_Node & node);

  virtual void visit_Real_Attr_Node (const T3_Real_Attr_Node & node);

  virtual void visit_Optional_Node (const T3_Optional_Node & node);

  virtual void visit_String_Literal_Node (const T3_String_Literal_Node & node);

  virtual void visit_Keyword_Node (const T3_Keyword_Node & node);

  virtual void visit_Selection_Node (const T3_Selection_Node & node);

  virtual void visit_Substitution_Node (const T3_Substitution_Node & node);
};

#include "Node_Visitor.inl"

#endif  // !defined _T3_NODE_VISITOR_H_
