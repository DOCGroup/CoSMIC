// $Id$

#include "Grammar_Generator.h"
#include "Optional_Node.h"
#include "Rule_Node.h"
#include "Selection_Node.h"
#include "String_Literal_Node.h"
#include "Substitution_Node.h"
#include <ostream>

//
// visit_Rule_Node
//
void T3_Grammar_Generator::
visit_Rule_Node (const T3_Rule_Node & node)
{
  if (node.is_end ())
    return;

  // Start the rule's definition.
  this->output_
    << "this->" << node.name () << "_ = ";

  // Write the rule's definition.
  node.next ()->accept (*this);

  // End the rule's definition.
  this->output_
    << ";"
    << std::endl;
}

//
// visit_String_Literal_Node
//
void T3_Grammar_Generator::
visit_String_Literal_Node (const T3_String_Literal_Node & node)
{
  // Write the literal value to the definition.
  this->output_ << "qi::lit (\"" << node.value () << "\")";
  this->_continue (node);
}

//
// visit_Substitution_Node
//
void T3_Grammar_Generator::
visit_Substitution_Node (const T3_Substitution_Node & node)
{
  // Write the quantifier for the substitution node.
  this->visit_Quantifier_Node (node);

  // Write the substitution rule to the definition.
  this->output_ << "this->" << node.target_rule ()->name () << "_";
  this->_continue (node);
}

//
// visit_Selection_Node
//
void T3_Grammar_Generator::
visit_Selection_Node (const T3_Selection_Node & node)
{
  // Begin the list of options.
  this->output_ << "(";

  T3_Selection_Node::options_type::CONST_ITERATOR iter (node.options ());

  // Write the first option. We need to include the option in
  // parathesis if there is more than one parser node.
  bool need_grouping = (*iter)->length () > 1;

  if (need_grouping)
    this->output_ << "(";

  (*iter)->accept (*this);

  if (need_grouping)
    this->output_ << ")";

  for (++ iter; !iter.done (); ++ iter)
  {
    // Prepare for the next option.
    this->output_ << " | ";

    need_grouping = (*iter)->length () > 1;

    if (need_grouping)
     this->output_ <<  "(";

    (*iter)->accept (*this);

    if (need_grouping)
      this->output_ << ")";
  }

  // End the list of options.
  this->output_ << ")";

  this->_continue (node);
}

//
// visit_Quantifier_Node
//
void T3_Grammar_Generator::
visit_Quantifier_Node (const T3_Quantifier_Node & node)
{
  switch (node.quantifier_value ())
  {
  case T3_Quantifier_Node::Q_ONE_OR_MORE:
    this->output_ << "+ ";
    break;

  case T3_Quantifier_Node::Q_ZERO_OR_MORE:
    this->output_ << "* ";
    break;
  }
}

//
// visit_Optional_Node
//
void T3_Grammar_Generator::
visit_Optional_Node (const T3_Optional_Node & node)
{
  bool need_grouping = node.length () > 1;

  // Pring the optional character.
  this->output_ << "- ";

  // Print grouping, if necessary.
  if (need_grouping)
    this->output_ << "(";

  // Visit the definition.
  node.definition ()->accept (*this);

  // Print grouping, if necessary.
  if (need_grouping)
    this->output_ << ")";

  this->_continue (node);
}

//
// visit_Keyword_Node
//
void T3_Grammar_Generator::
visit_Keyword_Node (const T3_Keyword_Node & node)
{
  this->output_ << "qi::lit (\"" << node.value () << "\")[T3::new_element ()]";
  this->_continue (node);
}

//
// _continue
//
void T3_Grammar_Generator::_continue (const T3_Node & node)
{
  if (!node.is_end ())
  {
    this->output_ << " >> ";
    node.next ()->accept (*this);
  }
}
