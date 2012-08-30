#ifndef _DECLARATORLIST_IMPL_H_
#define _DECLARATORLIST_IMPL_H_

#include "declaratorlist.hpp"

template <typename IteratorT>
declaratorlist <IteratorT>::declaratorlist (void)
: declaratorlist::base_type (declarator_list_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->declarator_list_ = (this->ident_[phoenix::push_back (qi::_val, qi::_1)] >>
      *(qi::lit(",") >> this->ident_[phoenix::push_back (qi::_val, qi::_1)]));
}

#endif