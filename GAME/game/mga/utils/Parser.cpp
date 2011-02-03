// $Id$

#include "stdafx.h"
#include "Parser.hpp"
#include "Project.h"
#include "Registrar.h"

namespace GAME
{
namespace Mga
{

//
// PathParserConfig
//
PathParserConfig::PathParserConfig (const Project & project)
{
  this->get_connstr_path (this->project_dir_, project.connstr ());
  this->get_connstr_path (this->paradigm_dir_, project.paradigm_connstr ());
}

//
// get_connstr_path
//
void PathParserConfig::
get_connstr_path (std::string & out, const std::string & connstr)
{
  std::string filename = connstr.substr (connstr.find_first_of ('=') + 1);
  out = filename.substr (0, filename.find_last_of ('\\'));
}

}
}
