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
#include "boost/spirit/utility/grammar_def.hpp"

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
  enum
  {
    aggregate = 0,
    sequence  = 1
  };


  PICML_Data_Value_Parser (PICML_Data_Value * const value);

  void aggregate_member (const char * start, const char * end) const;

  void aggregate_member_value (const char * start, const char * end) const;

  void insert_sequence_value (const char * start, const char * end) const;

  template <typename ScannerT>
  class definition :
    public boost::spirit::grammar_def <boost::spirit::rule <ScannerT>,
                                       boost::spirit::same,
                                       boost::spirit::same>
  {
  public:
    /**
     * Initializing constructor.
     *
     * @param[in]     self        The input grammar.
     */
    definition (PICML_Data_Value_Parser const & self);

  private:
    /// rule: ident_
    boost::spirit::rule <ScannerT> ident_;

    /// rule: operators_
    boost::spirit::rule <ScannerT> operators_;

    /// rule: string_
    boost::spirit::rule <ScannerT> string_;

    /// rule: value_
    boost::spirit::rule <ScannerT> value_;

    /// rule: member_
    boost::spirit::rule <ScannerT> member_;

    /// rule: member_name_
    boost::spirit::rule <ScannerT> member_name_;

    /// rule: member_value_
    boost::spirit::rule <ScannerT> member_value_;

    /// rule: member_list_
    boost::spirit::rule <ScannerT> member_list_;

    /// rule: struct_value_
    boost::spirit::rule <ScannerT> struct_value_;

    /// rule: struct_
    boost::spirit::rule <ScannerT> struct_;

    /// rule: sequence_
    boost::spirit::rule <ScannerT> sequence_;

    /// rule: sequence_value_
    boost::spirit::rule <ScannerT> sequence_value_;

    /// rule: sequence_item_
    boost::spirit::rule <ScannerT> sequence_item_;

    /// rule: sequence_list_
    boost::spirit::rule <ScannerT> sequence_list_;
  };

private:
  PICML_Data_Value * const value_;

  mutable std::string member_;
};

#include "Data_Value_Parser_T.cpp"

#endif  /* !defined _DATAVALUE_PARSER_H_ */
