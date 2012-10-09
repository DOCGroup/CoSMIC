// $Id$

#include "StdAfx.h"
#include "Visitor_Generator.h"
#include "Functors.h"
#include "Object_Class_Definition.h"
#include "Object_Manager.h"

#include "game/mga/Project.h"
#include "game/mga/Utils.h"
#include "game/mga/FCO.h"
#include "game/mga/Attribute.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <iomanip>
#include <fstream>

namespace GAME
{
namespace Mga
{
/**
 * @struct include_source_file
 *
 * Functor that generates an extension classes source file to the
 * provided MPC project file.
 */
struct visitor_method_generator_t
{
  visitor_method_generator_t (std::ofstream & hfile, std::ofstream & cfile)
    : hfile_ (hfile),
      cfile_ (cfile)
  {

  }

  void operator () (const Object_Manager::map_type::ENTRY & entry) const
  {
    // Make sure this object is not abstract. We are not allow to
    // visit any object that is abstract. Only concrete elements can
    // in a project can be visited by a visitor.
    if (entry.item ()->is_abstract ())
      return;

    const std::string type = entry.key ();
    const std::string in_type = type + "_in";
    const std::string method_name = "visit_" + type;

    this->hfile_
      << "virtual void " << method_name << " (" << in_type << " item);";

    this->cfile_
      << function_header_t (method_name)
      << "void Visitor::" << method_name << " (" << in_type << " item)"
      << "{"
      << "}";
  }

private:
  /// The target header file.
  std::ofstream & hfile_;

  /// The target source file.
  std::ofstream & cfile_;
};

//
// Visitor_Generator
//
Visitor_Generator::Visitor_Generator (void)
{

}

//
// ~Visitor_Generator
//
Visitor_Generator::~Visitor_Generator (void)
{

}

//
// generate
//
bool Visitor_Generator::
generate (const std::string & location,
          const Project & proj,
          const std::string & pch_basename,
          const Object_Manager * obj_mgr)
{
  // Open the .mpc file for writing.
  const std::string project_name = proj.name ();
  const std::string root = proj.root_folder ()->name ();
  const std::string basename = location + "/" + root + "/Visitor";

  // Start a new extension class.
  const std::string hxx_filename = basename + ".h";
  const std::string cpp_filename = basename + ".cpp";

  this->hxx_file_.open (hxx_filename.c_str ());
  this->cxx_file_.open (cpp_filename.c_str ());

  if (!this->hxx_file_.is_open () || !this->cxx_file_.is_open ())
    return false;

  std::string export_name = project_name;
  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  this->hxx_file_
    << "// -*- C++ -*-" << std::endl
    << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << "/**" << std::endl
    << " * @file    Visitor.h" << std::endl
    << " *" << std::endl
    << " * $" << "Id" << "$" << std::endl
    << " *" << std::endl
    << " * @author  Alhad Mokashi <amokashi at iupui dot edu>" << std::endl
    << " *          James H. Hill <hillj at cs dot iupui dot edu>" << std::endl
    << " */" << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << std::endl
    << "#ifndef _" << export_name << "_VISITOR_H_" << std::endl
    << "#define _" << export_name << "_VISITOR_H_" << std::endl
    << std::endl
    << include_t ("game/mga/Visitor.h")
    << std::endl
    << include_t (project_name + "_fwd.h")
    << include_t (project_name + "_export.h");

  this->cxx_file_
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (pch_basename + ".h")
    << include_t ("Visitor.h");

  this->generate_source_files (proj, obj_mgr);

  // Close the file handles.
  this->hxx_file_.close ();
  this->cxx_file_.close ();
  return true;
}

//
// generate_source_files
//
void Visitor_Generator::
generate_source_files (const Project & proj, const Object_Manager * obj_mgr)
{
  Indentation::Implanter <Indentation::Cxx, char> header_indent (this->hxx_file_);
  Indentation::Implanter <Indentation::Cxx, char> source_indent (this->cxx_file_);

  const std::string project_name = GAME::Utils::normalize (proj.name ());
  std::string export_name = project_name;

  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  // Start the project namespace.
  this->hxx_file_
    << std::endl
    << "namespace " << project_name
    << "{"
    << "class " << export_name << "_Export Visitor : public ::GAME::Mga::Visitor"
    << "{"
    << "protected:" << std::endl
    << "/// Default constructor." << std::endl
    << "Visitor (void);"
    << std::endl
    << "public:" << std::endl
    << "/// Destructor." << std::endl
    << "virtual ~Visitor (void);"
    << std::endl
    << "/**" << std::endl
    << " * @name Visit Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl;

  this->cxx_file_
    << std::endl
    << "namespace " << project_name
    << "{"
    << function_header_t ("Visitor")
    << "Visitor::Visitor (void)"
    << "{"
    << "}"
    << function_header_t ("~Visitor")
    << "Visitor::~Visitor (void)"
    << "{"
    << "}";

  std::for_each (obj_mgr->objects ().begin (),
                 obj_mgr->objects ().end (),
                 visitor_method_generator_t (this->hxx_file_, this->cxx_file_));

  // End the project namespace.
  this->hxx_file_
    << "///@}" << std::endl
    << "private:" << std::endl
    << "// prevent the following operation(s)" << std::endl
    << "const Visitor & operator = (const Visitor &);"
    << "};"
    << "}"
    << "#endif" << std::endl;

  this->cxx_file_
    << "}";
}

}
}
