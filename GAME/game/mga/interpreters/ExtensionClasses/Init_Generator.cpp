// $Id$

#include "StdAfx.h"
#include "Init_Generator.h"
#include "Functors.h"

#include "game/mga/Project.h"
#include "game/mga/Utils.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <iomanip>
#include <fstream>

namespace GAME
{
namespace Mga
{

//
// Init_Generator
//
Init_Generator::Init_Generator (void)
{

}

//
// ~Init_Generator
//
Init_Generator::~Init_Generator (void)
{

}

//
// generate
//
bool Init_Generator::
generate (const std::string & location,
          const Project & proj,
          const std::string & pch_basename)
{
  // Open the .mpc file for writing.
  const std::string project_name = proj.name ();
  const std::string root = proj.root_folder ()->name ();
  const std::string filename = location + "/" + root + "/Init.cpp";

  this->cxx_file_.open (filename.c_str ());

  if (!this->cxx_file_.is_open ())
    return false;

  this->cxx_file_
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (pch_basename + ".h")
    << include_t ("Impl_Factory.h")
    << include_t ("game/mga/Init_T.h")
    << std::endl;

  this->generate_source_file (proj);

  // Close the file handles.
  this->cxx_file_.close ();
  return true;
}

//
// generate_source_files
//
void Init_Generator::generate_source_file (const Project & proj)
{
  Indentation::Implanter <Indentation::Cxx, char> source_indent (this->cxx_file_);

  const std::string project_name = GAME::Utils::normalize (proj.name ());
  std::string export_name = project_name;

  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  // Start the project namespace.
  this->cxx_file_
    << "namespace " << project_name
    << "{"
    << "/// Extension class initialization." << std::endl
    << "static ::GAME::Mga::Init_T < ::" << project_name << "::Impl_Factory > init;"
    << "}";
}

}
}
