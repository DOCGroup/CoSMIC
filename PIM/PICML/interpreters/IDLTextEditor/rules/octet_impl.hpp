#ifndef _OCTET_IMPL_H_
#define _OCTET_IMPL_H_

#include "octet.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * octet <IteratorT>::strlit_ [] =
{
  "Octet"
};

template <typename IteratorT>
octet <IteratorT>::octet (void)
: base_type (octet_)
{
  this->octet_ =
    qi::lit ("octet")[T3::store_predefined_reference (this->strlit_[0])] >>
    - (qi::lit ('<') >> qi::uint_ >> qi::lit ('>'));
}

#endif  // !defined _STRING_TYPE_IMPL_H_
