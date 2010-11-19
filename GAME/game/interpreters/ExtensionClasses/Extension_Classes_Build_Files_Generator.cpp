#include "StdAfx.h"
#include "StdAfx.cpp"

#include "Extension_Classes_Build_Files_Generator.h"

namespace GAME
{

//
// Extension_Classes_Build_Files_Generator
//
Extension_Classes_Build_Files_Generator::Extension_Classes_Build_Files_Generator
                                          (const GAME::Folder & root,
                                           std::set <GAME::Object> objects,
                                           std::string output,
                                           std::string filename,
                                           std::string uc_paradigm_name):
  root_ (root),
  objects_ (objects),
  output_ (output),
  filename_ (filename),
  uc_paradigm_name_ (uc_paradigm_name)
{

}

//
// ~Extension_Classes_Build_Files_Generator
//
Extension_Classes_Build_Files_Generator::~Extension_Classes_Build_Files_Generator ()
{

}

//
// generate_mwc_file
//
void Extension_Classes_Build_Files_Generator::generate_mwc_file ()
{
  std::stringstream filename;
  
  filename << this->output_ << "/" << this->filename_ << ".mwc";

  this->out_.open (filename.str ().c_str ());

  // generate the code for mwc file
  this->out_ << "workspace (" << this->filename_ << ") {" <<std::endl
             << "  cmdline += -features boost=1,xerces3=1,xsc=1,mfc=1"
             << std::endl << "  cmdline += -include $GAME_ROOT/MPC/config"
             << std::endl << std::endl << "  " << this->filename_ << ".mpc"
             << std::endl << "}";

  this->out_.close ();
}

//
// generate_mpc_file
//
void Extension_Classes_Build_Files_Generator::generate_mpc_file ()
{
  std::stringstream filename, includes, source_files;
  std::set <GAME::Object> parents;
  
  filename << this->output_ << "/" << this->filename_ << ".mpc";

  std::set <GAME::Object>::iterator
    obj_iter = this->objects_.begin (),
    obj_iter_end = this->objects_.end ();

  // create a string that lists all the .cpp files
  for (; obj_iter != obj_iter_end; ++ obj_iter)
  {
    parents.insert (obj_iter->parent ());
    source_files << "  ./";

    if (obj_iter->parent ().parent () != this->root_)
      source_files << obj_iter->parent ().parent ().name () << "/";
    
    source_files << obj_iter->parent ().name () << "/"
                 << obj_iter->name () << ".cpp" << std::endl;
  }

  std::set <GAME::Object>::iterator
    parent_iter = parents.begin (),
    parent_iter_end = parents.end ();

  // collect all the folders in a string
  for (; parent_iter != parent_iter_end; ++ parent_iter)
  {
    includes << ", ./";

    if (parent_iter->parent () != this->root_)
      includes << parent_iter->parent ().name () << "/";

    includes << parent_iter->name ();
  }

  includes << std::endl;

  this->out_.open (filename.str ().c_str ());

  // generate the code for mpc file
  this->out_ << "project(" << this->filename_ << "): game {" << std::endl
             << "  sharedname = " << this->filename_ << std::endl << std::endl
             << "  includes += $(GAME_ROOT)" << std::endl
             << "  includes += ./" << includes.str () << std::endl
             << "  dynamicflags += " << this->uc_paradigm_name_ << "_BUILD_DLL"
             << std::endl << "  staticflags  += " << this->uc_paradigm_name_
             << "_AS_STATIC_LIBS" << std::endl << std::endl
             << "  prebuild += $(ACE_ROOT)/bin/generate_export_file.pl "
             << this->uc_paradigm_name_ << " > " << this->output_
             << "\\" << this->uc_paradigm_name_ << "_export.h"
             << std::endl << std::endl << "  pch_header = stdafx.h"
             << std::endl << "  pch_source = stdafx.cpp" << std::endl
             << std::endl << "  Source_Files {"
             << std::endl << source_files.str () << "  }"
             << std::endl << std::endl << "  Header_Files {"
             << std::endl << "    " << this->uc_paradigm_name_
             << "_export.h" << std::endl << "  }"
             << std::endl << "}";

  this->out_.close ();
}

//
// generate_stdafx_files
//
void Extension_Classes_Build_Files_Generator::generate_stdafx_files ()
{
  std::stringstream filename;
  filename << this->output_ << "/stdafx.h";

  this->out_.open (filename.str ().c_str ());

  // generate the code for stdafx.h file
  this->out_ << "#ifndef _STDAFX_H_" << std::endl
             << "#define _STDAFX_H_" << std::endl << std::endl
             << "#include \"" << this->uc_paradigm_name_ << "_export.h\""
             << std::endl << "#include \"Mga.h\""
             << std::endl << "#include <atlcomcli.h>" << std::endl
             << std::endl << "#endif";

  this->out_.close ();

  filename.str ("");
  filename << this->output_ << "/stdafx.cpp";

  this->out_.open (filename.str ().c_str ());

  // generate the code for stdafx.cpp file
  this->out_ << "#include \"stdafx.h\"" << std::endl
             << "#include \"ace/Functor_T.h\"" << std::endl
             << "#include \"ace/ACE.h\"";

  this->out_.close ();
}

}