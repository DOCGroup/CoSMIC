// $Id$

#include "StdAfx.h"
#include "Top_Level_File_Generator.h"
#include "Functors.h"
#include "Object_Class_Definition.h"
#include "Object_Manager.h"

#include "game/mga/Utils.h"

#include <fstream>

namespace GAME
{
namespace Mga
{

/**
 * @struct include_header_file
 *
 * Functor that generates an extension classes source file to the
 * provided MPC project file.
 */
struct include_header_file
{
  include_header_file (std::ofstream & hfile)
    : hfile_ (hfile)
  {

  }

  void operator () (const Object_Manager::map_type::ENTRY & entry) const
  {
    this->hfile_ << include_t (entry.item ()->compute_path ("/", false) + ".h");
  }

private:
  /// Reference to header file.
  std::ofstream & hfile_;
};

//
// Top_Level_File_Generator
//
Top_Level_File_Generator::Top_Level_File_Generator (void)
{

}

//
// Top_Level_File_Generator
//
Top_Level_File_Generator::~Top_Level_File_Generator (void)
{

}

//
// generate
//
void Top_Level_File_Generator::
generate (const std::string & location,
          const Project & proj,
          const Object_Manager * obj_mgr)
{
  // Open the .mpc file for writing.
  Folder root = proj.root_folder ();
  const std::string name = GAME::Utils::normalize (root->name ());
  const std::string filename = location + "/" + name + "/" + name + ".h";

  std::string macro_guard = "_" + name + "_H_";
  std::transform (macro_guard.begin (),
                  macro_guard.end (),
                  macro_guard.begin (),
                  &::toupper);

  std::ofstream hfile;
  hfile.open (filename.c_str ());

  if (hfile.is_open ())
  {
    // Generate the contents of the .mpc file.
    hfile
      << "// -*- C++ -*-" << std::endl
      << std::endl
      << "#ifndef " << macro_guard << std::endl
      << "#define " << macro_guard << std::endl
      << std::endl;

    // Write the extension class source files.
    std::for_each (obj_mgr->objects ().begin (),
                   obj_mgr->objects ().end (),
                   include_header_file (hfile));

    hfile
      << std::endl
      << "#endif  // !defined " << macro_guard << std::endl;

    hfile.close ();
  }
}


}
}
