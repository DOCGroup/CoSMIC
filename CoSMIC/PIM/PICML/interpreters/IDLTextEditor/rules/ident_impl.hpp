#ifndef _RULE_IDENT_IMPLE_H_
#define _RULE_IDENT_IMPLE_H_

#include "ident.hpp"

//
// ident
//
template <typename IteratorT>
ident <IteratorT>::ident (void)
: ident::base_type (ident_)
{
  this->ident_ %= qi::lexeme[(qi::alpha | '_') >> *(qi::alnum | '_')];
}

#endif
