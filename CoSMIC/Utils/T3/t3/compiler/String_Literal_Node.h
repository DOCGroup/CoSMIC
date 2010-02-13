// -*- C++ -*-

//=============================================================================
/**
 * @file      String_Literal_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_STRING_LITERAL_NODE_H_
#define _T3_STRING_LITERAL_NODE_H_

#include "ace/SString.h"
#include "Node.h"

/**
 * @class T3_Rule_Node
 *
 * Node for a rule in the grammar specification.
 */
class T3_String_Literal_Node : public T3_Node
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       name        Name of the rule.
   */
  T3_String_Literal_Node (const char * value);

  /// Destructor.
  virtual ~T3_String_Literal_Node (void);

  /**
   * Get the name of the rule.
   *
   * @return          Name of the rule.
   */
  const ACE_CString & value (void) const;

  virtual void accept (T3_Node_Visitor & visitor);

private:
  /// Name of the rule.
  ACE_CString value_;
};

/**
 * @class T3_Keyword_Node
 */
class T3_Keyword_Node : public T3_String_Literal_Node
{
public:
  T3_Keyword_Node (const char * keyword, const char * type);

  virtual ~T3_Keyword_Node (void);

  const ACE_CString & element_type (void) const;

  virtual void accept (T3_Node_Visitor & visitor);

private:
  /// Keyword associated with rule.
  ACE_CString element_type_;
};

#include "String_Literal_Node.inl"

#endif  // !defined _T3_STRING_LITERAL_NODE_H_