// -*- C++ -*-

//=============================================================================
/**
 * @file          Grammar_Generator.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _T3_GRAMMAR_GENERATOR_H_
#define _T3_GRAMMAR_GENERATOR_H_

#include "Node_Visitor.h"
#include <iosfwd>

// Forward decl.
class T3_Node;

// Forward decl.
class T3_Quantifier_Node;

/**
 * @class T3_Grammar_Generator
 *
 * Visitor responsible for generating the grammar portion of the parser.
 */
class T3_Grammar_Generator : public T3_Node_Visitor
{
public:
  T3_Grammar_Generator (std::ostream & output);

  virtual ~T3_Grammar_Generator (void);

  virtual void visit_Rule_Node (const T3_Rule_Node & node);

  virtual void visit_String_Literal_Node (const T3_String_Literal_Node & node);

  virtual void visit_Substitution_Node (const T3_Substitution_Node & node);

  virtual void visit_Selection_Node (const T3_Selection_Node & node);

  virtual void visit_Optional_Node (const T3_Optional_Node & node);

  virtual void visit_Keyword_Node (const T3_Keyword_Node & node);

private:
  void visit_Quantifier_Node (const T3_Quantifier_Node & node);

  void _continue (const T3_Node & node);

  /// The target output stream.
  std::ostream & output_;
};

#include "Grammar_Generator.inl"

#endif  // !defined _T3_GRAMMAR_GENERATOR_H_
