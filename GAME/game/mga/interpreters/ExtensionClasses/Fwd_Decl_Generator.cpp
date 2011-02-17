// $Id$

#include "StdAfx.h"
#include "Fwd_Decl_Generator.h"

#include "game/mga/Object.h"
#include "game/mga/Project.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <fstream>

namespace GAME
{
namespace Mga
{
/**
 * @struct generate_forward_decl
 *
 * Functor that generates an extension classes source file to the
 * provided MPC project file.
 */
struct generate_forward_decl
{
  generate_forward_decl (std::ofstream & hfile)
    : hfile_ (hfile)
  {

  }

  void operator () (const Object & obj) const
  {
    const std::string name = obj->name ();
    const std::string impl = name + "_Impl";

    this->hfile_
      << std::endl
      << "// Forward declarations for " << name << std::endl
      << "class " << impl << ";"
      << "typedef " << impl << " * " << name << "_in;"
      << "typedef ::GAME::Mga::Smart_Ptr <" << impl << "> " << name << ";";
  }

private:
  /// Target forward declaration file.
  std::ofstream & hfile_;
};

//
// Fwd_Decl_Generator
//
Fwd_Decl_Generator::Fwd_Decl_Generator (void)
{

}

//
// ~Fwd_Decl_Generator
//
Fwd_Decl_Generator::~Fwd_Decl_Generator (void)
{

}

//
// generate
//
bool Fwd_Decl_Generator::
generate (const std::string & location,
          const Project & proj,
          const std::set <Object> & items)
{
  // Open the .mpc file for writing.
  const std::string name = proj.name ();
  const std::string root_name = proj.root_folder ()->name ();

  const std::string filename = location + "/" + root_name + "/" + name + "_fwd.h";

  std::string macro_name = name;
  std::transform (macro_name.begin (),
                  macro_name.end (),
                  macro_name.begin (),
                  &::toupper);

  std::ofstream hfile;
  hfile.open (filename.c_str ());

  if (!hfile.is_open ())
    return false;

  do
  {
    Indentation::Implanter <Indentation::Cxx, char> header_indent (hfile);

    // Generate the contents of the .mpc file.
    hfile
      << "// -*- C++ -*-" << std::endl
      << "// $" << "Id" << "$" << std::endl
      << std::endl
      << "#ifndef _" << macro_name << "_FWD_H_" << std::endl
      << "#define _" << macro_name << "_FWD_H_" << std::endl
      << std::endl
      << "namespace " << name
      << "{";

    std::for_each (items.begin (),
                   items.end (),
                   generate_forward_decl (hfile));

    hfile
      << "}"
      << "#endif" << std::endl;

  } while (0);

  // Close the .mpc file.
  hfile.close ();
  return true;
}

}
}
