// $Id$

#include "StdAfx.h"
#include "IDL_Generator_Visitor.h"
#include "IDL_Generator_File.h"

#include "Utils/Utils.h"
#include "boost/bind.hpp"

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
// Visit_RootFolder
//
void IDL_Generator_Visitor::
Visit_RootFolder (const PICML::RootFolder & folder)
{
  std::vector <PICML::InterfaceDefinitions> folders = folder.InterfaceDefinitions_children ();

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&PICML::InterfaceDefinitions::Accept, 
                              _1,
                              boost::ref (*this)));
}

//
// Visit_InterfaceDefinitions
//
void IDL_Generator_Visitor::
Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & folder)
{
  std::vector <PICML::File> files = folder.File_children ();
  std::for_each (files.begin (),
                 files.end (),
                 boost::bind (&PICML::File::Accept, 
                              _1, 
                              boost::ref (*this)));
}

//
// Visit_File
//
void IDL_Generator_Visitor::Visit_File (const PICML::File & file)
{
  // Construct the name of the IDL file. Make sure to include the
  // path of the IDL file.
  std::string filename (this->outdir_);
  const std::string path (file.Path ());

  if (!path.empty ())
  {
    // Make sure the path existing before creating the file.
    filename += "/" + path;
    ::Utils::CreatePath (filename);
  }

  // Make sure the path exists.
  filename += "/" + std::string (file.name ()) + ".idl";

  // Open the target file for writing.
  std::ofstream outfile (filename.c_str ());
  if (!outfile.is_open ())
    return;

  IDL_Generator_File idl_file (outfile);
  idl_file.generate (file);
}
