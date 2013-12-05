// $Id$

#include "Compiler_App.h"
#include "Parser_Generator.h"
#include "Grammar_Parser.hpp"
#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"
#include "boost/spirit/include/classic_multi_pass.hpp"
#include "boost/bind.hpp"
#include <fstream>

namespace T3
{
/**
 * @struct is_defined
 */
struct is_defined
{
  bool operator () (T3_Node_Manager::rule_map_type::ENTRY & entry) const
  {
    return !entry.item ()->is_end ();
  }
};
}

//
// operator <<=
//
bool
operator <<= (T3_Parse_Tree & parse_tree, const ACE_CString & t3_file)
{
  // Open the grammar file for reading.
  std::ifstream infile;
  infile.open (t3_file.c_str ());

  if (!infile.is_open ())
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to open %s\n"),
                       t3_file.c_str ()),
                       false);

  using namespace boost::spirit::classic;

  // Adapt the iterator to support Boost backtracking.
  typedef char char_t;
  typedef multi_pass < std::istream_iterator <char_t> > iterator_t;

  iterator_t begin (make_multi_pass (std::istream_iterator <char_t> (infile)));
  iterator_t end (make_multi_pass (std::istream_iterator <char_t> ()));

  // Parse the file and construct the parse tree.
  T3_Grammar_Parser parser;

  if (!parser.parse (begin, end, parse_tree))
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to parse %s [rules=%d]\n"),
                       t3_file.c_str (),
                       parse_tree->rules ().current_size ()),
                       false);

  return true;
}

//
// T3_Compiler_App
//
T3_Compiler_App::T3_Compiler_App (void)
{

}

//
// ~T3_Compiler_App
//
T3_Compiler_App::~T3_Compiler_App (void)
{

}

//
// run_main
//
int T3_Compiler_App::run_main (int argc, char * argv [])
{
  // Parse the command-line options.
  if (0 != this->parse_args (argc, argv))
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to parse command-line options\n")),
                       -1);

  std::for_each (this->opts_.t3_files_.begin (),
                 this->opts_.t3_files_.end (),
                 boost::bind (&T3_Compiler_App::generate_parser, this, _1));

  return 0;
}

//
// parse_args
//
int T3_Compiler_App::parse_args (int argc, char * argv [])
{
  const char * optargs = "hv";
  ACE_Get_Opt get_opt (argc, argv, optargs);

  get_opt.long_option ("help", 'h');
  get_opt.long_option ("verbose", 'v');
  get_opt.long_option ("debug");

  char opt;

  while ((opt = get_opt ()) != EOF)
  {
    switch (opt)
    {
    case 0:
      if (0 == ACE_OS::strcmp (get_opt.long_option (), "help"))
        this->print_help ();

      break;

    case 'h':
      this->print_help ();
      break;

    case 'v':
      break;
    }
  }

  // The remaining arguments are T3 grammer files.
  argc = get_opt.argc ();

  for (int i = get_opt.opt_ind (); i < argc; ++ i)
    this->opts_.t3_files_.insert (get_opt.argv ()[i]);

  return 0;
}

//
// generate_parser
//
int T3_Compiler_App::generate_parser (const ACE_CString & t3_file)
{
  ACE_DEBUG ((LM_INFO,
              ACE_TEXT ("%T (%t) - %M - parsing %s...\n"),
              t3_file.c_str ()));

  // Build the parse tree from the grammar.
  T3_Parse_Tree parse_tree;

  if (!(parse_tree <<= t3_file))
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to parse %s\n"),
                       t3_file.c_str ()),
                       -1);

  // Get the basename of the filename.
  ACE_CString basename;
  this->get_basename (t3_file, basename);

  // Set the name of the parse tree.
  parse_tree.name (basename);

  // Append the new extension to the basename.
  basename += ".hpp";

  // Open the generator file for writing.
  std::ofstream outfile;
  outfile.open (basename.c_str ());

  if (!outfile.is_open ())
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to open %s for writing\n"),
                       basename.c_str ()),
                       -1);

  // Write the generator to the output file.
  T3_Parser_Generator p_gen;
  int retval = p_gen.generate (parse_tree, outfile);

  // Make sure we close the file.
  outfile.close ();
  return retval;
}

//
// get_basename
//
void T3_Compiler_App::
get_basename (const ACE_CString & filename, ACE_CString & basename)
{
  // Normalize filename by making sure all slashes are backslashes.
  ACE_CString dup_filename (filename);
  std::replace (dup_filename.begin (),
                dup_filename.end (),
                '\\',
                '/');

  // Find the last slash in the filename.
  size_t name_index = dup_filename.rfind ('/');

  // Adjust name_index to reflect the location of the name.
  if (name_index != ACE_CString::npos)
    ++ name_index;
  else
    name_index = 0;

  // Find the extension for the filename.
  size_t ext_index = dup_filename.rfind ('.');

  if (ext_index == ACE_CString::npos)
    ext_index = dup_filename.length ();

  // Determine the length of the basename.
  size_t length = ext_index - name_index;

  // Extract the basename from the filename.
  basename = dup_filename.substring (name_index, length);
}

//
// print_help
//
void T3_Compiler_App::print_help (void)
{
  ACE_OS::exit (1);
}
