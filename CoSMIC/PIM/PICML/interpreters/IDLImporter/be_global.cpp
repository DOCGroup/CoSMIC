// $Id$

#include "be_global.h"
#include "be_extern.h"

#include "ast_generator.h"
#include "ast_module.h"
#include "ast_component.h"
#include "ast_sequence.h"
#include "ast_typedef.h"

#include "utl_identifier.h"
#include "utl_string.h"

#include "fe_extern.h"
#include "global_extern.h"
#include "nr_extern.h"
#include "idl_defines.h"

#include "Type_Trait.h"

#include "game/xml/Error_Handler.h"
#include "game/xml/Entity_Resolver.h"
#include "game/xme/Configuration.h"

#include "xercesc/parsers/XercesDOMParser.hpp"
#include "PIM/PICML/interpreters/PICML/PICML_GUID.h"


#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_sys_stat.h"
#include "ace/streams.h"

#include <fstream>
#include <sstream>
#include <string>

#include "boost/bind.hpp"

// Some magic strings.
const char *FILE_EXT = ".xme";

IDL_TO_PICML_BE_Export BE_GlobalData *be_global = 0;

BE_GlobalData::BE_GlobalData (void)
  : output_file_ ("PICML_default_xme_file"),
    files_ (proj_),
    overwrite_ (false)
{

}

//
// ~BE_GlobalData
//
BE_GlobalData::~BE_GlobalData (void)
{
}

//
// output_dir
//
const char * BE_GlobalData::output_dir (void) const
{
  return this->output_dir_.c_str ();
}

//
// output_dir
//
void BE_GlobalData::output_dir (const char* s)
{
  this->output_dir_ = s;
}

//
// overwrite
//
bool BE_GlobalData::overwrite (void) const
{
  return this->overwrite_;
}

//
// output_file
//
ACE_CString BE_GlobalData::output_file (void) const
{
  return this->output_file_;
}

//
// output_file
//
void BE_GlobalData::output_file (const char *val)
{
  this->output_file_ = val;
}

//
// spawn_options
//
ACE_CString BE_GlobalData::spawn_options (void)
{
  return idl_global->idl_flags ();
}

//
// parse_args
//
void BE_GlobalData::parse_args (long &i, char **av)
{
  switch (av[i][1])
    {
      case 'x':
        if (av[i][2] == '\0')
        {
          this->output_file_ = av[i + 1];
          ++i;
        }
        else
          this->output_file_ = av[i] + 2;
        break;

      case 'o':
        if (av[i][2] == '\0')
        {
          this->output_dir_ = av[i + 1];
          ++i;
        }
        else
          this->output_dir_ = av[i] + 2;
        break;

      case 'r':
        if (av[i][2] == '\0')
        {
          idl_global->recursion_start (av [i + 1]);
          i++;
        }
        else
          idl_global->recursion_start (av[i] + 2);
        break;

      case 'm':
        if (av[i][2] == '\0')
        {
          GAME::XME::GLOBAL_CONFIG::instance ()->schema_path_ = av [i + 1];
          i++;
        }
        else
        {
          GAME::XME::GLOBAL_CONFIG::instance ()->schema_path_ = av[i] + 2;
        }

        // In case it isn't at the end of the command line option,
        // otherwise idempotent.
        GAME::XME::GLOBAL_CONFIG::instance ()->schema_path_.append (GAME::Xml::String ("/"));
        break;

      case 'l':
        // Load the specified library.
        if (av[i][2] == '\0')
        {
          this->libs_.push_back(av [i + 1]);
          i++;
        }
        else
        {
          this->libs_.push_back (av[i] + 2);
        }
        break;

      case '-':
        if (ACE_OS::strcmp (av[i], "--overwrite") == 0)
          this->overwrite_ = true;

        break;

      default:
        ACE_ERROR ((
            LM_ERROR,
            ACE_TEXT ("IDL: I don't understand ")
            ACE_TEXT ("the '%s' option\n"),
            av[i]
          ));

        idl_global->set_compile_flags (idl_global->compile_flags ()
                                       | IDL_CF_ONLY_USAGE);
        break;
    }
}

//
// xerces_init
//
void BE_GlobalData::initialize (void)
{
  using GAME::XME::Project;
  using GAME::Xml::String;

  try
  {
    ACE_CString filename;

    if (!this->output_dir_.empty ())
    {
      // Add the directory to the filename,
      filename += this->output_dir_;

      // Make sure there is a ending slash on the filename.
      char ending = this->output_dir_[this->output_dir_.length () - 1];

      if (ending != '/' && ending != '\\')
        filename += "/";
    }

    // Append the name of the file to the filename.
    filename += this->output_file_;
    String project_name;

    if (this->output_file_.find (FILE_EXT) == ACE_CString::npos)
    {
      // Make sure there is a .xme appended to the filename.
      filename += FILE_EXT;

      // Set the name of the project.
      project_name = this->output_file_.c_str ();
    }
    else
      project_name = this->output_file_.substr (0, this->output_file_.length () - 4).c_str ();

    // Create the project and set its name.
    static const String PICML ("PICML");
    static const String GUID (PICML_PARADIGM_GUID);
    const String xmefile (filename.c_str ());

    ACE_stat stats;
    bool exists = ACE_OS::stat (filename.c_str (), &stats) == 0;

    if (this->overwrite_ || !exists)
      this->proj_ = Project::_create (xmefile, PICML, GUID);
    else
      this->proj_ = Project::_open (xmefile);

    this->proj_.name (project_name);
    this->proj_.root_folder ().name (project_name);

    // Finally, attach all the specified libraries.
    std::for_each (this->libs_.begin (),
                   this->libs_.end (),
                   boost::bind (&Project::attach_library,
                                boost::ref (this->proj_),
                                _1));
  }
  catch (const xercesc::DOMException & e)
  {
    String msg (e.getMessage (), false);

    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("xerces_init - ")
                ACE_TEXT ("DOMException message is :  %s\n"),
                msg.to_string ().c_str ()));

    BE_abort ();
  }
  catch (const xercesc::SAXParseException &e)
  {
    String msg (e.getMessage (), false);

    ACE_ERROR ((LM_DEBUG,
                ACE_TEXT ("xerces_init - ")
                ACE_TEXT ("SAXParseException message is: %s\n"),
                msg.to_string ().c_str ()));

    BE_abort ();
  }
  catch (const xercesc::XMLException &e)
  {
    String msg (e.getMessage (), false);

    ACE_ERROR ((LM_DEBUG,
                ACE_TEXT ("xerces_init - ")
                ACE_TEXT ("XMLException message is: %s\n"),
                msg.to_string ().c_str ()));

    BE_abort ();
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("Unknown exception in xerces_init\n")));
    BE_abort ();
  }
}

//
// destroy
//
void BE_GlobalData::destroy (void)
{

}

//
// project
//
GAME::XME::Project & BE_GlobalData::project (void)
{
  return this->proj_;
}

//
// get_GME_version
//
std::string BE_GlobalData::get_GME_version (std::string path)
{
  path += "\\Interfaces\\GMEVersion.h";
  std::ifstream infile (path.c_str ());

  if (infile)
    {
      std::string token;
      int major = 0, minor = 0, plevel = 0;

      while (infile >> token)
        {
          if (token == "GME_VERSION_MAJOR")
            {
              infile >> major;
            }
          else if (token == "GME_VERSION_MINOR")
            {
              infile >> minor;
            }
          else if (token == "GME_VERSION_PLEVEL")
            {
              infile >> plevel;
              break;
            }
        }

      std::ostringstream ostr;
      ostr << major << "." << minor << "." << plevel;

      return ostr.str ();
    }

  return ""; // Empty string
}

//
// files
//
PICML_File_Creator & BE_GlobalData::files (void)
{
  return this->files_;
}

//
// files
//
const PICML_File_Creator & BE_GlobalData::files (void) const
{
  return this->files_;
}
