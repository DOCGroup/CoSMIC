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

#include "Utils/xercesc/XercesString.h"
#include "Utils/xercesc/XML_Error_Handler.h"
#include "Utils/xercesc/EntityResolver.h"
#include "xercesc/parsers/XercesDOMParser.hpp"

#include "game/xme/Configuration.h"

#include "ace/OS_NS_stdio.h"
#include "ace/streams.h"

#include <fstream>
#include <sstream>
#include <string>

#include "boost/bind.hpp"

// Some magic strings.
const char *FILE_EXT = ".xme";

IDL_TO_PICML_BE_Export BE_GlobalData *be_global = 0;

BE_GlobalData::BE_GlobalData (void)
  : output_dir_ (0),
    input_xme_ (0),
    output_file_ ("PICML_default_xme_file"),
    files_ (proj_)
{

}

//
// ~BE_GlobalData
//
BE_GlobalData::~BE_GlobalData (void)
{
}

const char*
BE_GlobalData::output_dir (void) const
{
  return this->output_dir_;
}

void
BE_GlobalData::output_dir (const char* s)
{
  delete [] this->output_dir_;
  this->output_dir_ = ACE::strnew (s);
}

const char*
BE_GlobalData::input_xme (void) const
{
  return this->input_xme_;
}

void
BE_GlobalData::input_xme (const char* s)
{
  delete [] this->input_xme_;
  this->input_xme_ = ACE::strnew (s);
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
            be_global->output_file (av[i + 1]);
            ++i;
          }
        else
          {
            be_global->output_file (av[i] + 2);
          }
        break;

      // Directory where the generated file is to
      // be kept. Default is the current directory from which
      // <idl_to_picml> is called.
      case 'o':
        if (av[i][2] == '\0')
          {
            be_global->output_dir (av [i + 1]);
            i++;
          }
        else
          {
            be_global->output_dir (av[i] + 2);
          }
        break;

      case 'i':
        if (av[i][2] == '\0')
          {
            be_global->input_xme (av [i + 1]);
            i++;
          }
        else
          {
            be_global->input_xme (av[i] + 2);
          }
        break;

      case 'r':
        if (av[i][2] == '\0')
          {
            idl_global->recursion_start (av [i + 1]);
            i++;
          }
        else
          {
            idl_global->recursion_start (av[i] + 2);
          }
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
        GAME::XME::GLOBAL_CONFIG::instance ()->schema_path_.append (::Utils::XStr ("/"));
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

      //case 'S':
      //  if (av[i][2] == 'p')
      //    {
      //      this->do_removal_ = false;
      //    }
      //  else
      //    {
      //      ACE_ERROR ((
      //          LM_ERROR,
      //          ACE_TEXT ("IDL: I don't understand ")
      //          ACE_TEXT ("the '%s' option\n"),
      //          av[i]
      //        ));
      //    }
      //  break;

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
// prep_be_arg
//
void BE_GlobalData::prep_be_arg (char *)
{
}

//
// arg_post_proc
//
void BE_GlobalData::arg_post_proc (void)
{
}

//
// usage
//
void BE_GlobalData::usage (void) const
{
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -x <filename>\t\tName of the generated file.")
      ACE_TEXT (" Default is \"PICML_default_xme_file.xme\".\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -r <pathname>\t\tPath of the directory to iterate")
      ACE_TEXT (" over recursively, processing each IDL file found.\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -o <dir>\t\tOutput directory for the generated file.")
      ACE_TEXT (" Default is current directory\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -i <filepath>\t\tPath to XME input file.")
      ACE_TEXT (" Default is no XME input file\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -l <filepath>\t\tAttach specified file as a ")
      ACE_TEXT ("library")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -m <filepath>\t\tPath to GME's mga.dtd file.")
      ACE_TEXT (" Default is c:\\Program Files\\GME\n")
    ));

  //ACE_DEBUG ((
  //    LM_DEBUG,
  //    ACE_TEXT (" -Sp \t\t\tSuppress pruning of elements removed")
  //    ACE_TEXT (" in modified IDL.")
  //    ACE_TEXT (" Default is to do pruning\n")
  //  ));
}

//
// generator_init
//
AST_Generator * BE_GlobalData::generator_init (void)
{
  AST_Generator *gen = 0;
  ACE_NEW_RETURN (gen,
                  AST_Generator,
                  0);
  return gen;
}

//
// xerces_init
//
void BE_GlobalData::initialize (void)
{
  using GAME::XME::Project;

  try
  {
    const char *xme = this->input_xme ();

    // If we are inputting an existing XME file, use that to create
    // the DOM tree, else create an empty one.
    if (0 == xme)
    {
      ACE_CString target_name;
      const char *path = be_global->output_dir ();

      if (path != 0)
      {
        target_name += path;
        target_name += "/";
      }

      target_name += be_global->output_file ();
      target_name += FILE_EXT;

      // Create the project and set its name.
      static const ::Utils::XStr PICML ("PICML");
      static const ::Utils::XStr GUID ("94FCA7F1-9017-4BFD-B557-F738FC54B103");
      const ::Utils::XStr name (be_global->output_file ().c_str ());

      this->proj_ = Project::_create (target_name.c_str (), PICML, GUID);

      this->proj_.name (name);
      this->proj_.root_folder ().name (name);
    }
    else
    {
      this->proj_ = Project::_open (xme);
    }

    // Next, attach the specified libraries.
    std::for_each (this->libs_.begin (),
                   this->libs_.end (),
                   boost::bind (&Project::attach_library, 
                                boost::ref (this->proj_),
                                _1));
  }
  catch (const xercesc::DOMException & e)
  {
    ::Utils::XStr msg (e.getMessage (), false);

    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("xerces_init - ")
                ACE_TEXT ("DOMException message is :  %s\n"),
                msg.to_string ().c_str ()));

    BE_abort ();
  }
  catch (const xercesc::SAXParseException &e)
  {
    ::Utils::XStr msg (e.getMessage (), false);

    ACE_ERROR ((LM_DEBUG,
                ACE_TEXT ("xerces_init - ")
                ACE_TEXT ("SAXParseException message is: %s\n"),
                msg.to_string ().c_str ()));

    BE_abort ();
  }
  catch (const xercesc::XMLException &e)
  {
    ::Utils::XStr msg (e.getMessage (), false);

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
