// -*- C++ -*-

//=============================================================================
/**
 * @file        BE_Condition_Parser_T.h
 *
 * Defines objects for parsing conditional expressions
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CONDITION_PARSER_H_
#define _CUTS_BE_CONDITION_PARSER_H_

#include "boost/spirit/core.hpp"

//=============================================================================
/**
 * @class CUTS_BE_Condition_Parser_T
 *
 * Parser object for parsing expressions. The expressions currently handled
 * by this parser are simple conditional expressions in preconditions.
 * Eventually, this parser will be able to handle more complex
 * expressions.
 */
//=============================================================================

template <typename BE_STRATEGY>
class CUTS_BE_Condition_Parser_T :
  public boost::spirit::grammar <CUTS_BE_Condition_Parser_T>
{
public:
  template <typename ScannerT>
  class definition
  {
  public:
    /**
     * Initializing constructor.
     *
     * @param[in]     self        The input grammar.
     */
    definition (const CUTS_BE_Condition_Parser_T & self);

    /**
     * Start of the input grammar.
     *
     * @return        Starting expression for the grammar.
     */
    const boost::spirit::rule <ScannerT> & start (void) const;

  private:
    /// rule: condition_
    boost::spirit::rule <ScannerT> condition_;

    /// rule: group_
    boost::spirit::rule <ScannerT> group_;

    /// rule: expression_
    boost::spirit::rule <ScannerT> expr_;

    /// rule: comp_op_
    boost::spirit::rule <ScannerT> comp_op_;

    /// rule: join_op_
    boost::spirit::rule <ScannerT> join_op_;

    /// rule: identifier_
    boost::spirit::rule <ScannerT> ident_;

    /// rule: number_
    boost::spirit::rule <ScannerT> number_;

    /// rule: string_
    boost::spirit::rule <ScannerT> string_;

    /// rule: char_
    boost::spirit::rule <ScannerT> char_;

    /// rule: variable_
    boost::spirit::rule <ScannerT> variable_;
  };
};

#include "BE_Condition_Parser_T.cpp"

#endif  // !defined _CUTS_BE_CONDITION_PARSER_H_
