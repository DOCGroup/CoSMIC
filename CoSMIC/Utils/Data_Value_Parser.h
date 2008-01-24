/* -*- C++ -*- */

//=============================================================================
/**
 * @file          DataValue_Parser.h
 *
 * INSERT FILE DESCRIPTION HERE
 *
 * $Id$
 *
 * @author        James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DATAVALUE_PARSER_H_
#define _DATAVALUE_PARSER_H_

#include "boost/spirit/core.hpp"
#include <stack>

// Forward decl.
class PICML_Data_Value;

//=============================================================================
/**
 * @class PICML_Data_Value_Parser
 *
 * Parser for PICML aggregate values.
 */
//=============================================================================

class PICML_Data_Value_Parser :
  public boost::spirit::grammar <PICML_Data_Value_Parser>
{
public:
  enum parser_type
  {
    /// Start with a struct parser.
    PARSER_STRUCT,

    /// Start with a sequence parser.
    PARSER_SEQUENCE
  };

  PICML_Data_Value_Parser (PICML_Data_Value * const value,
                           PICML_Data_Value_Parser::parser_type type);

  void select_member (const char * start, const char * end) const;

  void set_member_value (const char * start, const char * end) const;

  template <typename ScannerT>
  class definition
  {
  public:
    /**
     * Initializing constructor.
     *
     * @param[in]     self        The input grammar.
     */
    definition (PICML_Data_Value_Parser const & self);

    /**
     * Start of the input grammar.
     *
     * @return        Starting expression for the grammar.
     */
    const boost::spirit::rule <ScannerT> & start (void) const;

  private:
    /// rule: name_
    boost::spirit::rule <ScannerT> name_;

    /// rule: string_
    boost::spirit::rule <ScannerT> string_;

    /// rule: value_
    boost::spirit::rule <ScannerT> value_;

    /// rule: member_
    boost::spirit::rule <ScannerT> member_;

    /// rule: member_list_
    boost::spirit::rule <ScannerT> member_list_;

    /// rule: struct_
    boost::spirit::rule <ScannerT> struct_;

    /// rule: sequence_
    boost::spirit::rule <ScannerT> sequence_;

    /// rule: sequence_
    boost::spirit::rule <ScannerT> sequence_list_;

    /// rule: start_
    boost::spirit::rule <ScannerT> start_;
  };

  parser_type type (void) const;

private:
  PICML_Data_Value * const value_;

  parser_type type_;

  mutable std::string token_;
};

#include "Data_Value_Parser_T.cpp"

#endif  /* !defined _DATAVALUE_PARSER_H_ */
