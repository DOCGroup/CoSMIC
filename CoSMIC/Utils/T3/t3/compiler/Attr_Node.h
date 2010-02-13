// -*- C++ -*-

//=============================================================================
/**
 * @file      Attr_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_ATTR_NODE_H_
#define _T3_ATTR_NODE_H_

#include "ace/Auto_Ptr.h"
#include "ace/SString.h"
#include "Node.h"

/**
 * @class T3_Attr_Node
 *
 * Base class for all attribute nodes in the parse tree.
 */
class T3_Attr_Node : public T3_Node
{
public:
  /// Default constructor.
  T3_Attr_Node (void);

  /// Destructor.
  virtual ~T3_Attr_Node (void);

  void name (const ACE_CString & name);

  const ACE_CString & name (void) const;

  /**
   * Test if the attribute node is anonymous
   *
   * @retval        true        The node is anonymous
   * @retval        false       The node is not anonymous
   */
  bool is_anonymous (void) const;

protected:
  /// Name of the attribute.
  ACE_CString name_;
};

/**
 * @class T3_String_Attr_Node
 */
class T3_String_Attr_Node : public T3_Attr_Node
{
public:
  T3_String_Attr_Node (void);

  virtual ~T3_String_Attr_Node (void);

  virtual void accept (T3_Node_Visitor & visitor);
};

/**
 * @class T3_Boolean_Attr_Node
 */
class T3_Boolean_Attr_Node : public T3_Attr_Node
{
public:
  T3_Boolean_Attr_Node (void);

  virtual ~T3_Boolean_Attr_Node (void);

  virtual void accept (T3_Node_Visitor & visitor);

  int true_value (const char * name);

  const ACE_CString * true_value (void) const;

  bool has_true_value (void) const;

  int false_value (const char * name);

  const ACE_CString * false_value (void) const;

  bool has_false_value (void) const;

private:
  ACE_Auto_Ptr <ACE_CString> true_value_;

  ACE_Auto_Ptr <ACE_CString> false_value_;
};

/**
 * @class T3_Integer_Attr_Node
 */
class T3_Integer_Attr_Node : public T3_Attr_Node
{
public:
  T3_Integer_Attr_Node (void);

  virtual ~T3_Integer_Attr_Node (void);

  virtual void accept (T3_Node_Visitor & visitor);
};

/**
 * @class T3_Real_Attr_Node
 */
class T3_Real_Attr_Node : public T3_Attr_Node
{
public:
  T3_Real_Attr_Node (void);

  virtual ~T3_Real_Attr_Node (void);

  virtual void accept (T3_Node_Visitor & visitor);
};

#include "Attr_Node.inl"

#endif  // !defined _T3_ATTR_NODE_H_
