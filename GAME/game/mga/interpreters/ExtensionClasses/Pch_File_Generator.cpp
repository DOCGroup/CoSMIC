// $Id$

#include "StdAfx.h"
#include "Pch_File_Generator.h"
#include "Functors.h"

#include "game/mga/Folder.h"
#include "game/mga/Project.h"
#include "game/mga/Utils.h"

#include <fstream>

namespace GAME
{
namespace Mga
{

//
// Pch_File_Generator
//
Pch_File_Generator::Pch_File_Generator (void)
{

}

//
// ~Pch_File_Generator
//
Pch_File_Generator::~Pch_File_Generator (void)
{

}

//
// generate
//
bool Pch_File_Generator::
generate (const std::string & location,
          const Project & proj,
          const std::string & basename)
{
  // Open the .mpc file for writing.
  Folder root = proj.root_folder ();
  const std::string name = GAME::Utils::normalize (root->name ());
  const std::string pch_header = location + "/" + name + "/" + basename + ".h";
  const std::string pch_source = location + "/" + name + "/" + basename + ".cpp";

  return
    this->generate_pch_header (pch_header) &&
    this->generate_pch_source (pch_source, basename);
}

//
// generate_pch_header
//
bool Pch_File_Generator::generate_pch_header (const std::string & filename)
{
  std::ofstream pch_file;
  pch_file.open (filename.c_str ());

  if (!pch_file.is_open ())
    return false;

  pch_file
    << "// -*- C++ -*-" << std::endl
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << "#ifndef _STDAFX_H_" << std::endl
    << "#define _STDAFX_H_" << std::endl
    << std::endl
    << include_t ("game/config.h")
    << std::endl
    << include_t ("atlcomcli.h", true)
    << include_t ("game/mga/Mga.h")
    << std::endl
    << "#endif" << std::endl;

  // Close this precompiled header file and start the next one.
  pch_file.close ();
  return true;
}

//
// generate_pch_source
//
bool Pch_File_Generator::
generate_pch_source (const std::string & filename,
                     const std::string & basename)
{
  std::ofstream pch_file;
  pch_file.open (filename.c_str ());

  if (!pch_file.is_open ())
    return false;

  pch_file
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (basename + ".h");

  // Close this precompiled header file and start the next one.
  pch_file.close ();
  return true;
}

}
}
