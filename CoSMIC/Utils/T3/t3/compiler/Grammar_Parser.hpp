// -*- C++ -*-

//=============================================================================
/**
 * @file          T3_Grammar_Parser.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _T3_GRAMMAR_PARSER_H_
#define _T3_GRAMMAR_PARSER_H_

#include <iostream>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/phoenix_object.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "actors.h"
#include "Attr_Node.h"
#include "Definition.h"
#include "Optional_Node.h"
#include "Parse_Tree.h"
#include "Rule_Node.h"
#include "Reference_Node.h"
#include "Selection_Node.h"
#include "Substitution_Node.h"


/**
 * @class T3_Grammar_Parser_Grammar
 */
template <typename IteratorT>
class T3_Grammar_Parser_Grammar :
  public ::boost::spirit::qi::grammar < IteratorT, void (T3_Parse_Tree &)>
{
public:
  typedef T3_Grammar_Parser_Grammar <IteratorT> self_t;

  typedef IteratorT iterator_type;

  T3_Grammar_Parser_Grammar (void)
    : self_t::base_type (this->grammar_),
      grammar_ (std::string ("grammar")),
      comment_ (std::string ("comment")),
      c_comment_ (std::string ("c_comment")),
      cpp_comment_ (std::string ("cpp_comment")),
      rule_ (std::string ("rule"))
  {
    namespace qi = boost::spirit::qi;
    namespace repo = boost::spirit::repository;
    namespace phoenix = boost::phoenix;
    namespace ascii = boost::spirit::ascii;

    this->grammar_ =
      * (this->comment_ |
         this->preprocessor_ (qi::_r1) |
         this->rule_ (qi::_r1));

    // Rule for parsing a rule in the grammar.
    this->rule_ =
      qi::lit ("rule") >>
      this->identifier_[qi::_val = T3::begin_rule () (qi::_r1, qi::_1)] >>
      - this->options_ >>
      qi::lit (':') >>
      this->definition_ (qi::_r1)[T3::set_definition () (qi::_val, qi::_1)] >>
      qi::lit (';');

    // = Preprocessor statements
    this->preprocessor_ =
      qi::lit ("#pragma") >
      this->preprocessor_stmt_ (qi::_r1);

    this->preprocessor_stmt_ =
      this->pragma_start_rule_ (qi::_r1);

    this->pragma_start_rule_ =
      qi::lit ("start") >
      qi::lit ('(') >
      qi::omit[this->identifier_[T3::set_start_rule ()]] >
      qi::lit (')');

    // Rule for parsing options for a rule. The options are
    // enclosed in brackets [] after the rule's name.
    this->options_ =
      qi::lit ('[') >> this->options_list_ >> qi::lit (']');

    this->options_list_ =
      this->option_value_ >> *(qi::lit (';') >> this->option_value_);

    this->option_value_ =
      this->merge_option_ |
      this->autocreate_option_;

    this->definition_ =
      + (this->definition_item_(qi::_r1)[T3::append_node () (qi::_val, qi::_1)]);

    // <definition_item_>
    this->definition_item_ %=
      this->string_lit_ (qi::_r1)   |
      this->variable_ (qi::_r1)     |
      this->substitution_ (qi::_r1) |
      this->optional_ (qi::_r1)     |
      this->selection_ (qi::_r1)    |
      this->reference_ (qi::_r1)    |
      this->keyword_ (qi::_r1);

    this->substitution_ =
      qi::lexeme[qi::lit ('<') >
      this->identifier_[qi::_val = T3::alloc_substitution_node ()(qi::_r1, qi::_1)] >
      qi::lit ('>')] >
      - this->quantifier_[T3::set_quantifier_value ()];

    // Rule for parsing a selection list of rules.
    this->selection_ =
      qi::lit ('(')[T3::alloc_node <T3_Selection_Node> ()] >>
      this->definition_ (qi::_r1)[T3::insert_option () (qi::_val, qi::_1)] >>
      + (qi::lit ('|') >> this->definition_ (qi::_r1)[T3::insert_option () (qi::_val, qi::_1)]) >>
      qi::lit (')');

    // Rule for parsing an optional rule in the grammar.
    this->optional_ =
      qi::lit ('[') >>
      this->definition_ (qi::_r1)[qi::_val = T3::alloc_optional_node ()(qi::_r1, qi::_1)] >>
      qi::lit (']');

    // <variable>: in this case, we just need to propogate the
    // node for the variable to its parent.
    this->variable_ %=
      this->string_var_ (qi::_r1)  |
      this->real_var_ (qi::_r1)    |
      this->integer_var_ (qi::_r1) |
      this->bool_var_ (qi::_r1);

    // <string_var_>
    this->string_var_ =
      qi::lit ("STRING")[T3::alloc_node <T3_String_Attr_Node> ()] >
      - this->identifier_[T3::set_attr_name ()];

    // <integer_var_>
    this->integer_var_ =
      qi::lit ("INTEGER")[T3::alloc_node <T3_Integer_Attr_Node> ()] >
      - this->identifier_[T3::set_attr_name ()];

    // <real_var_>
    this->real_var_ =
      qi::lit ("REAL")[T3::alloc_node <T3_Real_Attr_Node> ()] >
      - this->identifier_[T3::set_attr_name ()];

    // <bool_var_>
    this->bool_var_ =
      qi::lit ("BOOL")[T3::alloc_node <T3_Boolean_Attr_Node> ()] >
      - this->identifier_[T3::set_attr_name ()] >
      qi::lit ('(') >
      this->identifier_[T3::set_bool_value <true> ()] >
      - (qi::lit (',') > this->identifier_[T3::set_bool_value <false> ()]) >
      qi::lit (')');

    this->keyword_ =
      qi::lit ("KEYWORD") >
      qi::lit ('(') >
      qi::omit[this->quoted_string_[qi::_a = qi::_1]] >
      qi::lit (',') >
      qi::omit[this->identifier_[qi::_b = qi::_1]] >
      qi::lit (')')[T3::alloc_keyword_node ()];

    this->reference_ =
      qi::lexeme[
        qi::lit ('@') >
        qi::omit[this->identifier_] >
        qi::lit (':') >
        qi::omit[this->identifier_]];

    // The identifier is a sequence of alpha numeric characters and
    // underscores, where the first character must be an alphabetic
    // character.
    this->identifier_ %=
      qi::lexeme [(qi::alpha >> *(qi::alnum | '_'))];

    // Rule for parsing comments. Can be either C or C++ style comments.
    this->comment_ %=
      this->c_comment_ |
      this->cpp_comment_;

    this->c_comment_ %=
      qi::lexeme[repo::confix ("/*", "*/")[*(ascii::char_ - "*/")]];

    this->cpp_comment_ %=
      qi::lexeme[qi::omit[qi::lit ("//")] >> *(qi::print - qi::eol) >> qi::omit[qi::eol]];

    // Parser for the string literal.
    this->string_lit_ =
      this->quoted_string_[T3::alloc_strlit_node ()];

    // The actual value of the string literal.
    this->quoted_string_ %=
      qi::lit ('"') >> *(qi::print - '"') >> qi::lit ('"');

    // quantifier for different parsers
    this->quantifier_ %= qi::lit ('*') | qi::lit ('+');

    // options
    this->merge_option_ =
      qi::lit ("merge") >>
      qi::lit ('(') >>
      this->identifier_ >>
      qi::lit (')');

    this->autocreate_option_ =
      qi::lit ("autocreate") >>
      qi::lit ('(') >>
      this->identifier_ >>
      qi::lit (')');

    qi::on_error <qi::fail>
    (
      this->cpp_comment_,
      std::cout
        << phoenix::val ("** parse error: expecting ")
        << qi::_4                                // what failed?
        << phoenix::val (" here: \"")
        << phoenix::construct <std::string> (qi::_3, qi::_2)   // iterators to error-pos, end
        << phoenix::val ("\"")
        << std::endl
    );
  }

private:
  template <typename T>
  struct node_rule
  {
    typedef
      ::boost::spirit::qi::rule <IteratorT,
                                 T * (T3_Parse_Tree &)>
                                 type;
  };

  boost::spirit::qi::rule <IteratorT,
                           void (T3_Parse_Tree &)>
                           grammar_;

  boost::spirit::qi::rule <IteratorT,
                           void (T3_Parse_Tree &)>
                           preprocessor_;

  boost::spirit::qi::rule <IteratorT,
                           void (T3_Parse_Tree &)>
                           preprocessor_stmt_;

  boost::spirit::qi::rule <IteratorT,
                           void (T3_Parse_Tree &)>
                           pragma_start_rule_;

  boost::spirit::qi::rule <IteratorT,
                           std::string ()>
                           comment_;

  boost::spirit::qi::rule <IteratorT,
                           std::string ()>
                           c_comment_;

  boost::spirit::qi::rule <IteratorT,
                           std::string ()>
                           cpp_comment_;

  typename node_rule <T3_Rule_Node>::type rule_;

  boost::spirit::qi::rule <IteratorT> options_;

  boost::spirit::qi::rule <IteratorT> options_list_;

  boost::spirit::qi::rule <IteratorT> option_value_;

  boost::spirit::qi::rule <IteratorT> autocreate_option_;

  boost::spirit::qi::rule <IteratorT> merge_option_;

  boost::spirit::qi::rule <IteratorT, T3_Definition (T3_Parse_Tree &)> definition_;

  typename node_rule <T3_Node>::type definition_item_;

  typename node_rule <T3_Substitution_Node>::type substitution_;

  typename node_rule <T3_String_Literal_Node>::type string_lit_;

  typename node_rule <T3_Optional_Node>::type optional_;

  typename node_rule <T3_Selection_Node>::type selection_;

  ::boost::spirit::qi::rule <
    IteratorT,
    T3_Keyword_Node * (T3_Parse_Tree &),
    boost::spirit::locals <std::string, std::string> >
    keyword_;

  typename node_rule <T3_Attr_Node>::type variable_;

  typename node_rule <T3_String_Attr_Node>::type string_var_;

  typename node_rule <T3_Real_Attr_Node>::type real_var_;

  typename node_rule <T3_Integer_Attr_Node>::type integer_var_;

  typename node_rule <T3_Boolean_Attr_Node>::type bool_var_;

  typename node_rule <T3_Reference_Node>::type reference_;

  boost::spirit::qi::rule <IteratorT, std::string ()> identifier_;

  boost::spirit::qi::rule <IteratorT, std::string ()> quoted_string_;

  boost::spirit::qi::rule <IteratorT, char ()> quantifier_;
};

/**
 * @class T3_Grammar_Parser
 */
class T3_Grammar_Parser
{
public:
  template <typename IteratorT>
  bool parse (IteratorT begin, IteratorT end, T3_Parse_Tree & tree)
  {
    namespace qi = boost::spirit::qi;
    namespace phoenix = boost::phoenix;
    namespace ascii = boost::spirit::ascii;

    T3_Grammar_Parser_Grammar <IteratorT> grammar;

    bool result = qi::parse (begin,
                             end,
                             grammar (phoenix::ref(tree)),
                             ascii::space);

    return result;
  }
};

#endif  // !defined _CUTS_PROPERTY_PARSER_H_
