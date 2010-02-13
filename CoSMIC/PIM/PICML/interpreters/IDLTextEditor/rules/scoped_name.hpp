#ifndef _RULE_SCOPED_NAME_H_
#define _RULE_SCOPED_NAME_H_

#include "ident_impl.hpp"

template <typename IteratorT>
class scoped_name :
  public qi::grammar < IteratorT, std::string (), ascii::space_type >
{
public:
  typedef qi::grammar < IteratorT,
                        std::string (),
                        ascii::space_type >
                        base_type;

  scoped_name (void);

private:
  qi::rule <IteratorT,
            std::string (),
            ascii::space_type>
            scoped_name_;

  ident <IteratorT> ident_;
};

#endif  // !defined _RULE_SCOPED_NAME_H_
