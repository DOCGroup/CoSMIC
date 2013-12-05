// -*- C++ -*-

//=============================================================================
/**
 *  @file         grammar.hpp
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _T3_GRAMMAR_HPP_
#define _T3_GRAMMAR_HPP_

#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_stl.hpp"
#include "game/mga/Object.h"
#include "Auto_Model.h"

namespace T3
{
  namespace qi = ::boost::spirit::qi;
  namespace ascii = ::boost::spirit::ascii;

  /**
   * @class grammar
   *
   * Base class for all T3 parser grammars.
   */
  template <typename IteratorT>
  class grammar : public qi::grammar < IteratorT, void (Auto_Model &), ascii::space_type >
  {
  protected:
    /// Type definition for rules that return no value
    typedef
      qi::rule <IteratorT,
                void (Auto_Model &),
                ascii::space_type>
                noreturn_rule;

    /// Type definition for rules that return a value.
    typedef
      qi::rule <IteratorT,
                Auto_Model (Auto_Model &),
                ascii::space_type>
                model_rule;

    /// Type definition for the start rule.
    typedef noreturn_rule start_rule;

    /**
     * Initializing constructor
     *
     * @param[in]     start     Start rule for the grammar
     */
    template <typename RuleT>
    grammar (const RuleT & start)
      : grammar::base_type (start)
    {

    }
  };
}

#endif  // !defined _T3_GRAMMAR_HPP_
