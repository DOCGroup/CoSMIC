// $Id$

#include "StdAfx.h"
#include "Mpc_File_Generator.h"
#include "Object_Manager.h"
#include "Object_Class_Definition.h"

#include "game/mga/Object.h"
#include "game/mga/Project.h"
#include "game/mga/Utils.h"

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

  void operator () (const Object_Manager::map_type::ENTRY & entry) const
  {
    this->mpc_file_
      << "    "
      << entry.item ()->compute_path ("/", false) << ".cpp" << std::endl;
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
          const Object_Manager * obj_mgr)
{
  // Open the .mpc file for writing.
  const std::string name = proj.name ();
  const std::string project_name = name + "_GAME_Mga";
  const std::string mpc_filename = location + "/" + project_name + ".mpc";
  const std::string root_name = GAME::Utils::normalize (proj.root_folder ()->name ());

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
    << "project (" << project_name << ") : game_extension_classes {" << std::endl
    << "  sharedname = " << project_name << std::endl
    << std::endl
    << "  includes += . " << proj.root_folder ()->name () << std::endl
    << std::endl
    << "  pch_header = " << pch_basename << ".h" << std::endl
    << "  pch_source = " << root_name << "/" << pch_basename << ".cpp" << std::endl
    << std::endl
    << "  dynamicflags += " << export_name << "_BUILD_DLL" << std::endl
    << std::endl
    << "  Source_Files {" << std::endl
    << "    " << proj.root_folder ()->name () << "/Impl_Factory.cpp" << std::endl
    << "    " << proj.root_folder ()->name () << "/Init.cpp" << std::endl
    << "    " << proj.root_folder ()->name () << "/Visitor.cpp" << std::endl;

  // Write the extension class source files.
  std::for_each (obj_mgr->objects ().begin (),
                 obj_mgr->objects ().end (),
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
