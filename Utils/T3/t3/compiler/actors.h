// -*- C++ -*-

//=============================================================================
/**
 * @file      T3_Compiler_App.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_ACTORS_H_
#define _T3_ACTORS_H_

#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_fusion.hpp"
#include "boost/spirit/include/phoenix_stl.hpp"

#include "ace/Log_Msg.h"
#include "Attr_Node.h"
#include "Optional_Node.h"
#include "Parse_Tree.h"
#include "String_Literal_Node.h"
#include "Substitution_Node.h"

// Forward decl.
class T3_Node;

// Forward decl.
class T3_Rule_Node;

namespace T3
{
  namespace qi = boost::spirit::qi;

  /**
   * @struct begin_rule_impl
   *
   * Implementation of the begin_rule function.
   */
  struct begin_rule_impl
  {
    // Type definition of the result for the function.
    template <typename Arg1, typename Arg2>
    struct result { typedef T3_Rule_Node * type; };

    /**
     * Functor operation.
     *
     * @param[in]       arg1        Beginning of the rule name.
     * @param[in]       arg2        End of the rule name.
     */
    template <typename Arg1, typename Arg2>
    T3_Rule_Node * operator () (Arg1 & parse_tree, const Arg2 & rule_name) const
    {
      // Lookup the rule, create if not exists.
      T3_Rule_Node * rule_node = 0;
      parse_tree->lookup_rule (rule_name.c_str (), rule_node);

      return rule_node;
    }
  };

  typedef ::boost::phoenix::function < begin_rule_impl > begin_rule;

  /**
   * @struct alloc_node
   *
   * Implementation of the alloc_node function.
   */
  template <typename T>
  struct alloc_node
  {
    template <typename Context>
    void operator () (qi::unused_type, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      // Get the parse tree from the context, which is qi::_r1.
      T3_Parse_Tree & pt = fusion::at_c <1> (ctx.attributes);
      T * node = pt->alloc_node <T> ();

      // Store node as the return value (i.e., qi::_val).
      fusion::at_c <0> (ctx.attributes) = node;
    }
  };

  /**
   * @struct append_node_impl
   *
   * Implementation of the attach_node function.
   */
  struct append_node_impl
  {
    template <typename Arg1, typename Arg2>
    struct result { typedef void type; };

    template <typename Arg1, typename Arg2>
    void operator () (Arg1 & definition, Arg2 item) const
    {
      definition.append_node (item);
    }
  };

  typedef
    ::boost::phoenix::function <append_node_impl>
    append_node;

  /**
   * @struct set_attr_name
   */
  struct set_attr_name
  {
    template <typename Context>
    void operator () (const std::string & attr_name, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      T3_Attr_Node * node = fusion::at_c <0> (ctx.attributes);
      node->name (attr_name.c_str ());
    }
  };

  /**
   * @struct set_quantifier_value
   */
  struct set_quantifier_value
  {
    template <typename Context>
    void operator () (char value, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      T3_Quantifier_Node  * node = fusion::at_c <0> (ctx.attributes);

      switch (value)
      {
      case '+':
        node->quantifier_value (T3_Quantifier_Node::Q_ONE_OR_MORE);
        break;

      case '*':
        node->quantifier_value (T3_Quantifier_Node::Q_ZERO_OR_MORE);
        break;
      }
    }
  };

  /**
   * @struct set_start_rule
   */
  struct set_start_rule
  {
    template <typename Context>
    void operator () (const std::string & rule_name, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      // Set the start rule for the parse tree.
      T3_Parse_Tree & parse_tree = fusion::at_c <1> (ctx.attributes);
      parse_tree.start_rule (rule_name.c_str ());
    }
  };

  /**
   * @struct set_bool_value_impl
   */
  template <bool value>
  struct set_bool_value;

  /**
   * @struct set_bool_value <true>
   */
  template < >
  struct set_bool_value <true>
  {
    template <typename Context>
    void operator () (const std::string & value, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      T3_Boolean_Attr_Node * node = fusion::at_c <0> (ctx.attributes);
      node->true_value (value.c_str ());
    }
  };

  /**
   * @struct set_bool_value <false>
   */
  template < >
  struct set_bool_value <false>
  {
    template <typename Context>
    void operator () (const std::string & value, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      T3_Boolean_Attr_Node * node = fusion::at_c <0> (ctx.attributes);
      node->false_value (value.c_str ());
    }
  };

  /**
   * @struct alloc_strlit_node
   *
   * Semantic action for allocating a string literal node. The allocated
   * node is stored as the return value (or synthesized attribute)
   * of the parent rule.
   */
  struct alloc_strlit_node
  {
    template <typename Context>
    void operator () (const std::string & strlit, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      // Get the parse tree from the context, which is qi::_r1.
      T3_Parse_Tree & parse_tree = fusion::at_c <1> (ctx.attributes);

      // Allocate new string literal node for parse tree.
      T3_String_Literal_Node * strlit_node =
        parse_tree.alloc_strlit_node (strlit.c_str ());

      // Store node as the return value (i.e., qi::_val).
      fusion::at_c <0> (ctx.attributes) = strlit_node;
    }
  };

  /**
   * @struct alloc_keyword_node
   *
   * Semantic action for allocating a keyword node. The allocated
   * node is stored as the return value (or synthesized attribute)
   * of the parent rule.
   */
  struct alloc_keyword_node
  {
    template <typename Context>
    void operator () (qi::unused_type, Context & ctx, qi::unused_type) const
    {
      namespace fusion = ::boost::fusion;

      // Get parent from the context, which is qi::_r1.
      const std::string & keyword = fusion::at_c <0> (ctx.locals);
      const std::string & type = fusion::at_c <1> (ctx.locals);

      // Get the parse tree from the context, which is qi::_r1.
      T3_Parse_Tree & pt = fusion::at_c <1> (ctx.attributes);

      T3_Keyword_Node * node =
        pt.alloc_keyword_node (keyword.c_str (), type.c_str ());

      // Store node as the return value (i.e., qi::_val).
      fusion::at_c <0> (ctx.attributes) = node;
    }
  };

  /**
   * @struct alloc_substitution_node_impl
   *
   * Implementation of the functor for allocating a T3_String_Literal_Node
   * for the parse tree. Once the value of the node has been set, it
   * cannot be changed.
   */
  struct alloc_substitution_node_impl
  {
    template <typename Arg1, typename Arg2>
    struct result { typedef T3_Substitution_Node * type; };

    template <typename Arg1, typename Arg2>
    T3_Substitution_Node * operator () (Arg1 & parse_tree, const Arg2 & rule_name) const
    {
      // Lookup the rule in the parse tree.
      T3_Rule_Node * rule_node = 0;
      parse_tree->lookup_rule (rule_name.c_str (), rule_node);

      // Allocate a substitution node for the rule.
      T3_Substitution_Node * substitution_node =
        parse_tree->alloc_node <T3_Substitution_Node> (rule_node);

      return substitution_node;
    }
  };

  /// Type definition of the alloc_substitution_node_impl Pheonix function.
  typedef
    ::boost::phoenix::function <alloc_substitution_node_impl>
    alloc_substitution_node;

  /**
   * @struct alloc_optional_node_impl
   */
  struct alloc_optional_node_impl
  {
    template <typename Arg1, typename Arg2>
    struct result { typedef T3_Optional_Node * type; };

    template <typename Arg1, typename Arg2>
    T3_Optional_Node * operator () (Arg1 & parse_tree, const Arg2 & def) const
    {
      return parse_tree->alloc_node <T3_Optional_Node> (def.start ());
    }
  };

  typedef
    ::boost::phoenix::function <alloc_optional_node_impl>
    alloc_optional_node;

  /**
   * @struct insert_option_impl
   */
  struct insert_option_impl
  {
    template <typename Arg1, typename Arg2>
    struct result { typedef void type; };

    template <typename Arg1, typename Arg2>
    void operator () (Arg1 selection, const Arg2 & definition) const
    {
      if (selection)
        selection->insert_option (definition);
    }
  };

  typedef
    ::boost::phoenix::function <insert_option_impl>
    insert_option;

  /**
   * @struct set_definition_impl
   */
  struct set_definition_impl
  {
    template <typename Arg1, typename Arg2>
    struct result { typedef void type; };

    template <typename Arg1, typename Arg2>
    void operator () (Arg1 rule, const Arg2 & definition) const
    {
      if (rule)
        rule->next (definition.start ());
    }
  };

  typedef
    ::boost::phoenix::function <set_definition_impl>
    set_definition;
}

#endif  // !defined _T3_ACTORS_H_
