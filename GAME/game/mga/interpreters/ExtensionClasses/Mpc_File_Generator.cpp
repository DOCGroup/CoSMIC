// $Id$

#include "StdAfx.h"
#include "Mpc_File_Generator.h"

#include "game/mga/Object.h"
#include "game/mga/Project.h"
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
struct include_source_file
{
  include_source_file (std::ofstream & mpc_file)
    : mpc_file_ (mpc_file)
  {

  }

  void operator () (const Object & obj) const
  {
    this->mpc_file_ << "    " << obj->path ("/", false) << ".cpp" << std::endl;
  }

private:
  /// Target MPC project file.
  std::ofstream & mpc_file_;
};

//
// Mpc_File_Generator
//
Mpc_File_Generator::Mpc_File_Generator (void)
{

}

//
// ~Mpc_File_Generator
//
Mpc_File_Generator::~Mpc_File_Generator (void)
{

}

//
// generate
//
bool Mpc_File_Generator::
generate (const std::string & location,
          const Project & proj,
          const std::string & pch_basename,
          const std::set <Object> & items)
{
  // Open the .mpc file for writing.
  const std::string name = proj.name ();
  const std::string project_name = name + "_Mga";
  const std::string mpc_filename = location + "/" + project_name + ".mpc";

  std::string export_name = name;
  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);

  std::ofstream mpc_file;
  mpc_file.open (mpc_filename.c_str ());

  if (!mpc_file.is_open ())
    return false;

  // Generate the contents of the .mpc file.
  mpc_file
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << "project (" << project_name << ") : game_mga {" << std::endl
    << "  sharedname = " << project_name << std::endl
    << std::endl
    << "  includes += ." << std::endl

    // @note We should allow the client to customize the output location for
    //       both the .lib and .dll files.

    << "  libout = ./lib" << std::endl
    << "  dllout = ./lib" << std::endl
    << std::endl
    << "  pch_header = " << pch_basename << ".h" << std::endl
    << "  pch_source = " << pch_basename << ".cpp" << std::endl
    << std::endl
    << "  dynamicflags += " << export_name << "_BUILD_DLL" << std::endl
    << "  prebuild     += $(ACE_ROOT)/bin/generate_export_file.pl "
    << export_name << " > " << name << "_export.h" << std::endl
    << std::endl
    << "  Source_Files {" << std::endl
    << "    " << proj.root_folder ()->name () << "/Visitor.cpp" << std::endl;

  // Write the extension class source files.
  std::for_each (items.begin (),
                 items.end (),
                 include_source_file (mpc_file));

  mpc_file
    << "  }" << std::endl
    << "}" << std::endl;

  // Close the .mpc file.
  mpc_file.close ();
  return true;
}

}
}
