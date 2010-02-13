// $Id$

#include "Parser_Generator.h"
#include "Grammar_Generator.h"
#include "Parse_Tree.h"
#include "Rule_Node.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

namespace T3
{
/**
 * @struct base_member_init
 *
 * Functor for generating the base member initialization section.
 */
struct base_member_init
{
  base_member_init (std::ostream & out)
    : out_ (out)
  {

  }

  void operator () (const T3_Node_Manager::rule_map_type::ENTRY & entry) const
  {
    this->out_
      << "," << std::endl
      << "   " << entry.key ()
      << "_ (std::string (\"" << entry.key () << "\"))";
  }

private:
  std::ostream & out_;
};

/**
 * @struct generate_rule
 *
 * Functor for generating the rule.
 */
struct generate_rule
{
  generate_rule (std::ostream & out)
    : out_ (out)
  {

  }

  void operator () (const T3_Node_Manager::rule_map_type::ENTRY & entry) const
  {
    T3_Grammar_Generator gen (this->out_);
    entry.item ()->accept (gen);
  }

private:
  std::ostream & out_;
};
}

//
// generate
//
int T3_Parser_Generator::
generate (const T3_Parse_Tree & tree, std::ostream & output)
{
  // Setup the indentation for the file.
  typedef Indentation::Implanter <Indentation::Cxx, char> formatter_type;
  formatter_type formatter (output);

  // Construct the hash definition for the file.
  this->hashdef_ = "_";
  this->hashdef_ += (tree.name ());
  this->hashdef_ += "_HPP_";

  std::for_each (this->hashdef_.begin (),
                 this->hashdef_.end (),
                 &::toupper);

  // Write the parser to file.
  this->write_header (tree, output);
  this->write_grammar (tree, output);
  this->write_parser (tree, output);
  this->write_footer (output);

  return 0;
}

//
// write_header
//
void T3_Parser_Generator::
write_header (const T3_Parse_Tree & tree, std::ostream & output)
{
  output
    << "/* -*- C++ -*- */" << std::endl
    << std::endl
    << "//=============================================================================" << std::endl
    << "/**" << std::endl
    << " * @file " << tree.name () << ".hpp" << std::endl
    << " *" << std::endl
    << " * $" << "Id" << "$" << std::endl
    << " */" << std::endl
    << "//=============================================================================" << std::endl
    << std::endl
    << "#ifndef " << this->hashdef_ << std::endl
    << "#define " << this->hashdef_ << std::endl
    << std::endl;
}

//
// write_grammar
//
void T3_Parser_Generator::
write_grammar (const T3_Parse_Tree & tree, std::ostream & output)
{
  ACE_CString grammar_classname (tree.name ());
  grammar_classname += "_Parser_Grammar";

  output
    << "/**" << std::endl
    << " * @class " << grammar_classname << std::endl
    << " *" << std::endl
    << " * Grammar definition for the " << tree.name  () << "_Parser" << std::endl
    << " */" << std::endl
    << "template <typename IteratorT>" << std::endl
    << "class " << grammar_classname << " : " << std::endl
    << "  public T3::grammar <IteratorT>"
    << "{"
    << "public:" << std::endl
    << "typedef T3::grammar <IteratorT> base_type;"
    << std::endl
    << "// Type definition of the grammar class" << std::endl
    << "typedef " << grammar_classname << " self_t;"
    << std::endl
    << "// Type definition of the iterator type"
    << std::endl
    << "typedef IteratorT iterator_type;"
    << std::endl
    << grammar_classname << " (void)" << std::endl
    << " : base_type (" << tree.start_rule ()->name () << "_)";

  // Write base member initialize section of constructor.
  std::for_each (tree->rules ().begin (),
                 tree->rules ().end (),
                 T3::base_member_init (output));

  output
    << "{";

  // Generate each rule in the grammar.
  std::for_each (tree->rules ().begin (),
                 tree->rules ().end (),
                 T3::generate_rule (output));

  output
    << "}"
    << std::endl
    << "~" << grammar_classname << " (void)" << std::endl
    << "{"
    << "}";

  // Close the class definition for the grammar.
  output
    << "};"
    << std::endl;
}

//
// write_parser
//
void T3_Parser_Generator::
write_parser (const T3_Parse_Tree & tree, std::ostream & output)
{
  output
    << "/**" << std::endl
    << " * @class " << tree.name () << "_Parser" << std::endl
    << " */" << std::endl
    << "class " << tree.name () << "_Parser"
    << "{"
    << "public:" << std::endl
    << "template <typename IteratorT>" << std::endl
    << "bool parse (IteratorT begin, IteratorT end, ::BON::Object & obj)"
    << "{"
    << "using boost::phoenix::ref;"
    << std::endl
    << tree.name () << "_Parser_Grammar <IteratorT> grammar;"
    << "boost::spirit::qi::parse (begin, end, grammar (ref(obj)));"
    << "return true;"
    << "}"
    << "};";
}

//
// write_footer
//
void T3_Parser_Generator::write_footer (std::ostream & output)
{
  output
    << "#endif  // !defined " << this->hashdef_ << std::endl;
}
