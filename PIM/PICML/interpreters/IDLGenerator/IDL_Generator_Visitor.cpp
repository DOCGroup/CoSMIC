#include "StdAfx.h"
#include "IDL_Generator_Visitor.h"
#include "IDL_Generator_File.h"

#include "game/mga/Utils.h"

#include <algorithm>
#include <fstream>

//
// IDL_Generator_Visitor
//
IDL_Generator_Visitor::IDL_Generator_Visitor (const std::string & outdir)
: outdir_ (outdir)
{

}

//
// ~IDL_Generator_Visitor
//
IDL_Generator_Visitor::~IDL_Generator_Visitor (void)
{

}

//
// visit_RootFolder
//
void IDL_Generator_Visitor::
visit_RootFolder (PICML::RootFolder_in folder)
{
  for (auto folder : folder->get_InterfaceDefinitions ())
    folder->accept (this);
}

//
// visit_InterfaceDefinitions
//
void IDL_Generator_Visitor::
visit_InterfaceDefinitions (PICML::InterfaceDefinitions_in folder)
{
  for (auto file : folder->get_Files ())
    file->accept (this);
}

//
// visit_File
//
void IDL_Generator_Visitor::visit_File (PICML::File_in file)
{
  // Construct the name of the IDL file. Make sure to include the
  // path of the IDL file.
  std::string filename (this->outdir_);
  const std::string path (file->Path ());

  if (!path.empty ())
  {
    // Make sure the path existing before creating the file.
    filename += "/" + path;
    GAME::Utils::create_path (filename);
  }

  // Make sure the path exists.
  filename += "/" + file->name () + ".idl";

  // Open the target file for writing.
  std::ofstream outfile (filename.c_str ());
  if (!outfile.is_open ())
    return;

  IDL_Generator_File idl_file (outfile);
  idl_file.generate (file);
}
