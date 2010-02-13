#ifndef _PREPROCESSOR_H_
#define _PREPROCESSOR_H_

#include "t3/runtime/grammar.hpp"
#include "ident.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

template <typename IteratorT>
class preprocessor : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  preprocessor (void);

private:
  start_rule preprocessor_;

  noreturn_rule include_stmt_;

  noreturn_rule pragma_stmt_;

  noreturn_rule hashdef_;

  ident <IteratorT> ident_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type>
            sys_filepath_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type>
            usr_filepath_;
};

#endif
