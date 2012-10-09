// $Id$

#include "stdafx.h"
#include "Extension_Classes_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Extension_Classes_Visitor.inl"
#endif

#include "Functors.h"
#include "Object_Manager.h"
#include "Object_Class_Definition.h"
#include "Utils.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <iomanip>

namespace GAME
{
namespace Mga
{

//
// Extension_Clases_Visitor
//
Extension_Classes_Visitor::
Extension_Classes_Visitor (const std::string & outdir,
                           const Folder_in root,
                           const std::string & pch_basename)
: outdir_ (outdir),
  define_prefix_ (root->name ()),
  pch_basename_ (pch_basename)
{
  ::GAME::Utils::normalize (this->define_prefix_);
  std::transform (this->define_prefix_.begin (),
                  this->define_prefix_.end (),
                  this->define_prefix_.begin (),
                  &::toupper);

  std::string export_name = root->name ();
  ::GAME::Utils::normalize (export_name);

  this->export_filename_ = export_name + "_export.h";

  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  this->export_macro_ = export_name + "_Export";
}

//
// ~Extension_Classes_Visitor
//
Extension_Classes_Visitor::~Extension_Classes_Visitor (void)
{

}

//
// generate
//
void Extension_Classes_Visitor::
generate (Object_Class_Definition * definition)
{
  // Make sure the class definition's output path exists.
  const std::string basename = this->outdir_ + definition->get_object ()->path ("/");
  this->mkdir (basename);

  // Start a new extension class.
  const std::string hxx_filename = basename + ".h";
  const std::string cpp_filename = basename + ".cpp";
  const std::string inl_filename = basename + ".inl";

  std::ofstream hfile (hxx_filename.c_str ());
  std::ofstream ifile (inl_filename.c_str ());
  std::ofstream sfile (cpp_filename.c_str ());

  if (!(hfile.is_open () && ifile.is_open () && sfile.is_open ()))
    return;

  do
  {
    // Set the indentation implanter for this extension class.
    Indentation::Implanter <Indentation::Cxx, char> header_indent (hfile);
    Indentation::Implanter <Indentation::Cxx, char> source_indent (sfile);
    Indentation::Implanter <Indentation::Cxx, char> inline_indent (ifile);

    // Initialize the generation context.
    Generation_Context context (hfile, ifile, sfile);

    context.export_filename_ = this->export_filename_;
    context.export_macro_ = this->export_macro_;

    // Generate the class definition.
    definition->generate (context);
  }
  while (false);

  // Close the file handles.
  hfile.close ();
  sfile.close ();
  ifile.close ();
}

//
// mkdir
//
void Extension_Classes_Visitor::mkdir (const std::string & basename)
{
  // Get the path from the basename.
  std::string path = basename.substr (0, basename.find_last_of ("/") + 1);

  // Normalize the path.
  std::replace (path.begin (),
                path.end (),
                '\\',
                '/');

  // Create the path.
  Utils::create_path (path, '/');
}

}
}
