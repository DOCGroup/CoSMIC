#ifndef _RULE_SCOPED_NAME_IMPL_H_
#define _RULE_SCOPED_NAME_IMPL_H_

#include "scoped_name.hpp"

//
// scoped_name
//
template <typename IteratorT>
scoped_name <IteratorT>::scoped_name (void)
: base_type (scoped_name_)
{
  this->scoped_name_ =
    - ascii::string ("::")[qi::_val += qi::_1] >>
      this->ident_[qi::_val += qi::_1] >>
      *(ascii::string ("::")[qi::_val += qi::_1] >>
      this->ident_[qi::_val += qi::_1]);
}

#endif  // !defined _RULE_SCOPED_NAME_IMPL_H_
