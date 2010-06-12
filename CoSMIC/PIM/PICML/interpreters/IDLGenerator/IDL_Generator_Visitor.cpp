// $Id$

#include "StdAfx.h"
#include "IDL_Generator_Visitor.h"
#include "IDL_File_Generator.h"
#include "File_Processor.h"
#include "IDLStream.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>

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
  typedef std::vector <PICML::InterfaceDefinitions> vector_t;
  vector_t folders = folder.InterfaceDefinitions_children ();

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&vector_t::value_type::Accept, _1, boost::ref (*this)));
}

//
// Visit_InterfaceDefinitions
// 
void IDL_Generator_Visitor::
Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & folder)
{
  typedef std::vector <PICML::File> vector_t;
  vector_t files = folder.File_children ();

  std::for_each (files.begin (),
                 files.end (),
                 boost::bind (&vector_t::value_type::Accept, _1, boost::ref (*this)));
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

  // First, preprocess the file. This will help sort out any
  // dependency issues between objects and files.
  IDLStream idl (outfile);

  // Construct the hash definition for this file.
  std::string hashdef ("_");
  hashdef += std::string (file.name ()) + "_IDL_";

  std::transform (hashdef.begin (),
                  hashdef.end (),
                  hashdef.begin (),
                  &::toupper);

  idl << "#ifndef " << hashdef << nl
      << "#define " << hashdef << nl
      << nl;

  // Preprocess the file. This will genenerate the necessary
  // forward declarations for any object at the top of the 
  // target output file.
  IDL_File_Processor idl_proc (idl);
  PICML::File (file).Accept (idl_proc);

  // Visit the file and generate its contents.
  IDL_File_Generator generator (idl);
  PICML::File (file).Accept (generator);

  idl << nl
      << "#endif    // !defined " << hashdef << nl
      << nl;

  // Close the output file.
  outfile.close ();
}
