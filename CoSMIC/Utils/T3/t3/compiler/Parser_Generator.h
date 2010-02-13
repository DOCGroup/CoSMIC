// -*- C++ -*-

//=============================================================================
/**
 * @file      Parser_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_PARSER_GENERATOR_H_
#define _T3_PARSER_GENERATOR_H_

#include <ostream>
#include "ace/SString.h"

// Forward decl.
class T3_Parse_Tree;

/**
 * @class T3_Parser_Generator
 */
class T3_Parser_Generator
{
public:
  /// Default constructor.
  T3_Parser_Generator (void);

  /// Destructor.
  ~T3_Parser_Generator (void);

  /**
   * Generate the parser. This method will generate the parser
   * for the specified grammar in the \a parse_tree into the
   * specified \a output stream.
   */
  int generate (const T3_Parse_Tree & tree, std::ostream & output);

private:
  void write_header (const T3_Parse_Tree &, std::ostream &);
  void write_grammar (const T3_Parse_Tree &, std::ostream &);
  void write_parser (const T3_Parse_Tree &, std::ostream &);
  void write_footer (std::ostream &);

  ACE_CString hashdef_;
};

#include "Parser_Generator.inl"

#endif  // !defined _T3_PARSER_GENERATOR_H_
