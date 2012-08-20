#ifndef _QUOTED_STRING_IMPL_H_
#define _QUOTED_STRING_IMPL_H_

#include "quoted_string.hpp"

template <typename IteratorT>
quoted_string <IteratorT>::quoted_string (void)
: quoted_string::base_type (quoted_string_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->quoted_string_ %= qi::lexeme[qi::lit ('"') >> *(qi::char_ - '"') >> qi::lit ('"')]; 
}

#endif