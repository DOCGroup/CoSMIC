#ifndef _IDENT_IMPL_H_
#define _IDENT_IMPL_H_

#include "ident.hpp"

template <typename IteratorT>
ident <IteratorT>::ident (void)
: ident::base_type (ident_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->ident_ %=
      qi::lexeme[(ascii::char_('_') | qi::alpha) >>
      *(ascii::char_('_') | qi::alnum)];
}

#endif