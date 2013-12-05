// -*- C++ -*-

//=============================================================================
/**
 *  @file         parsers.hpp
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _T3_PARSERS_HPP_
#define _T3_PARSERS_HPP_

#include "boost/spirit/include/qi.hpp"
#include <string>

namespace T3
{
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/**
 * @struct IDENT
 *
 * Boost grammar for parsing identifiers.
 */
template <typename IteratorT>
struct IDENT : qi::grammar <IteratorT, std::string (), ascii::space_type>
{
public:
  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  IDENT (void)
    : IDENT::base_type (this->ident_),
      ident_ (std::string ("t3-ident"))
  {
    this->ident_ %= qi::lexeme[qi::alpha >> *(qi::alnum | '_')];
  }

private:
  qi::rule <IteratorT, std::string (), ascii::space_type> ident_;
};

/**
 * @struct IDENT
 *
 * Boost grammar for parsing identifiers.
 */
template <typename IteratorT>
struct IDENT_ : qi::grammar <IteratorT, std::string (), ascii::space_type>
{
public:
  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  IDENT_ (void)
    : IDENT_::base_type (this->ident_),
      ident_ (std::string ("t3-ident"))
  {
    this->ident_ %= qi::alpha >> *(qi::alnum | '_');
  }

private:
  qi::rule <IteratorT, std::string (), ascii::space_type> ident_;
};

}

#endif  // !defined _T3_PARSERS_HPP_
