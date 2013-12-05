#ifndef _CHAR_TYPE_H_
#define _CHAR_TYPE_H_

#include "t3/runtime/grammar.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

/**
 * @class char_type
 */
template <typename IteratorT>
class char_type : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  char_type (void);

private:
  start_rule char_type_;

  static const char * strlit_ [];
};

#endif
