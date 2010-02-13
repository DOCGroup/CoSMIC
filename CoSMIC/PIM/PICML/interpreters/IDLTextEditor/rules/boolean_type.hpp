#ifndef _RULE_BOOLEAN_TYPE_H_
#define _RULE_BOOLEAN_TYPE_H_

#include "t3/runtime/grammar.hpp"
#include "t3/runtime/actors.hpp"
#include "t3/runtime/parsers.hpp"
#include "../IDLTextEditor_Core_export.h"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

/**
 * @class boolean_type
 */
template <typename IteratorT>
class boolean_type : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  boolean_type (void);

private:
  start_rule boolean_type_;

  static const char * strlit_ [];
};

#endif
