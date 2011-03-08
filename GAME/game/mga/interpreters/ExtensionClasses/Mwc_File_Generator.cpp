// $Id$

#include "StdAfx.h"
#include "Mwc_File_Generator.h"
#include "game/mga/Project.h"
#include <fstream>

namespace GAME
{
namespace Mga
{

//
// Mwc_File_Generator
//
Mwc_File_Generator::Mwc_File_Generator (void)
{

}

//
// ~Mwc_File_Generator
//
Mwc_File_Generator::~Mwc_File_Generator (void)
{

}

//
// generate
//
bool Mwc_File_Generator::
generate (const std::string & location, const Project & proj)
{
  // Open the .mpc file for writing.
  const std::string project_name = proj.name ();
  const std::string mwc_filename = location + "/" + project_name + "_GAME_Mga.mwc";

  std::ofstream mwc_file;
  mwc_file.open (mwc_filename.c_str ());

  if (!mwc_file.is_open ())
    return false;

  const std::string mpc_filename = project_name + "_GAME_Mga.mpc";

  // Generate the contents of the .mpc file.
  mwc_file
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << "workspace (" << project_name << "_GAME_Mga) {" << std::endl
    << "  cmdline += -include $GAME_ROOT/MPC/config" << std::endl
    << std::endl
    << "  " << mpc_filename << std::endl
    << "}" << std::endl;

  // Close the .mpc file.
  mwc_file.close ();
  return true;
}

}
}
