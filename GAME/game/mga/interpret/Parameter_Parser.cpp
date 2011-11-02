// $Id$

#include "stdafx.h"
#include "Parameter_Parser.h"

#include "boost/spirit/include/qi.hpp"
#include "boost/fusion/include/adapt_struct.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

struct param_t
{
  std::string name_;
  std::string value_;
};

BOOST_FUSION_ADAPT_STRUCT (
  param_t,
  (std::string, name_)
  (std::string, value_)
);

/**
 * @class Parameter_Parser_Grammar
 *
 * Boost.Spirit grammar for the parameter parser.
 */
template <typename IteratorT>
struct Parameter_Parser_Grammar :
  qi::grammar <IteratorT, param_t (), ascii::space_type>
{
public:
  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  Parameter_Parser_Grammar (void)
    : Parameter_Parser_Grammar::base_type (this->parser_),
      parser_ (std::string ("parser"))
  {
    this->parser_ %=
      qi::lexeme[*(ascii::char_ - '=')] >>
      -(qi::lit ("=") >> qi::lexeme[*ascii::char_]);
  }

private:
  qi::rule <IteratorT,
            param_t (),
            ascii::space_type> parser_;
};

///////////////////////////////////////////////////////////////////////////////
// Parameter_Parser

//
// Parameter_Parser
//
Parameter_Parser::Parameter_Parser (void)
{

}

//
// parse
//
bool Parameter_Parser::
parse (const char * str, std::map <std::string, std::string> & out)
{
  std::string tempstr (str);
  Parameter_Parser_Grammar <std::string::iterator> grammar;
  param_t param;

  if (!qi::phrase_parse (tempstr.begin (),
                         tempstr.end (),
                         grammar,
                         ascii::space,
                         param))
  {
    return false;
  }

  // Save the parameter.
  out[param.name_] = param.value_;

  return true;
}
