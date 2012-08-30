#ifndef _ITERATOR_IMPL_H_
#define _ITERATOR_IMPL_H_

#include "iterator.hpp"

template <typename IteratorT>
iterator <IteratorT>::iterator (void)
: iterator::base_type (iterator_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->iterator_ %= this->forall_iterator_ | this->isunique_iterator_ | this->exists_iterator_ |
      this->one_iterator_;

    this->forall_iterator_ = qi::lit ("forAll")[qi::_val = phoenix::new_ <ForAll_Iterator> ()];

    this->isunique_iterator_ = qi::lit ("isUnique")[qi::_val = phoenix::new_ <IsUnique_Iterator> ()];

    this->exists_iterator_ = qi::lit ("exists")[qi::_val = phoenix::new_ <Exists_Iterator> ()];

    this->one_iterator_ = qi::lit ("one")[qi::_val = phoenix::new_ <One_Iterator> ()];
}

#endif