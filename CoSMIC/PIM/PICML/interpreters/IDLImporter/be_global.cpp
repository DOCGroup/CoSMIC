// $Id$

// ============================================================================
//
//
// = LIBRARY
//    TAO_PICML_BE_DLL
//
// = FILENAME
//    be_global.cpp
//
// = DESCRIPTION
//    Stores global data specific to the compiler back end.
//
// = AUTHOR
//    Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#include "be_global.h"
#include "ast_generator.h"
#include "global_extern.h"
#include "idl_defines.h"
#include "picml_visitor.h"
#include "ace/OS_NS_stdio.h"
#include "XercesString.h"

// Some magic strings.
const char *VERSION = "1.0";
const char *ENCODING = "UTF-8";
const char *DOCTYPE = "project";
const char *SYS_ID = "mga.dtd";
const char *FILE_EXT = ".xme";

TAO_PICML_BE_Export BE_GlobalData *be_global = 0;

BE_GlobalData::BE_GlobalData (void)
  : filename_ (0),
    output_dir_ (0),
    models_seen_ (1UL),
    atoms_seen_ (1UL),
    refs_seen_ (1UL),
    conns_seen_ (1UL),
    folders_seen_ (1UL),
    npredefined_ (11UL),
    nfiles_ (0L),
    first_file_ (I_TRUE),
    output_file_ ("PICML_default_xme_file"),
    doc_ (0),
    writer_ (0),
    target_ (0),
    basic_seq_suffix_ ("Seq_from_IDL_include")
{
}

BE_GlobalData::~BE_GlobalData (void)
{
}

const char *
BE_GlobalData::filename (void) const
{
  return this->filename_;
}

void
BE_GlobalData::filename (char *fname)
{
  this->filename_ = fname;
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

unsigned long
BE_GlobalData::models_seen (void) const
{
  return this->models_seen_;
}

unsigned long
BE_GlobalData::atoms_seen (void) const
{
  return this->atoms_seen_;
}

unsigned long
BE_GlobalData::refs_seen (void) const
{
  return this->refs_seen_;
}

unsigned long
BE_GlobalData::conns_seen (void) const
{
  return this->conns_seen_;
}

unsigned long
BE_GlobalData::folders_seen (void) const
{
  return this->folders_seen_;
}

void
BE_GlobalData::incr_models_seen (void)
{
  ++this->models_seen_;
}

void
BE_GlobalData::incr_atoms_seen (void)
{
  ++this->atoms_seen_;
}

void
BE_GlobalData::incr_refs_seen (void)
{
  ++this->refs_seen_;
}

void
BE_GlobalData::incr_conns_seen (void)
{
  ++this->conns_seen_;
}

void
BE_GlobalData::incr_folders_seen (void)
{
  ++this->folders_seen_;
}

unsigned long
BE_GlobalData::npredefined (void) const
{
  return this->npredefined_;
}
  
const char**
BE_GlobalData::pdt_names (void) const
{
  static const char *list[] = {
                                "TypeKind",
                                "TypeEncoding",
                                "String",
                                "Boolean",
                                "ShortInteger",
                                "RealNumber",
                                "LongInteger",
                                "GenericValueObject",
                                "GenericValue",
                                "GenericObject",
                                "Byte"
                              };
  return list;
}

long
BE_GlobalData::nfiles (void) const
{
  return this->nfiles_;
}

void
BE_GlobalData::nfiles (long val)
{
  this->nfiles_ = val;
}

idl_bool
BE_GlobalData::first_file (void) const
{
  return this->first_file_;
}

void
BE_GlobalData::first_file (idl_bool val)
{
  this->first_file_ = val;
}

ACE_CString
BE_GlobalData::output_file (void) const
{
  return this->output_file_;
}

void
BE_GlobalData::output_file (const char *val)
{
  this->output_file_ = val;
}

xercesc::DOMDocument *
BE_GlobalData::doc (void) const
{
  return this->doc_;
}

BE_GlobalData::DECL_ID_TABLE &
BE_GlobalData::decl_id_table (void)
{
  return this->decl_id_table_;
}

BE_GlobalData::DECL_ELEM_TABLE &
BE_GlobalData::decl_elem_table (void)
{
  return this->decl_elem_table_;
}

ACE_CString
BE_GlobalData::spawn_options (void)
{
  return idl_global->idl_flags ();
}

void
BE_GlobalData::parse_args (long &i, char **av)
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
      // <tao_picml> is called.
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
      default:
        ACE_ERROR ((
            LM_ERROR,
            ACE_TEXT ("IDL: I don't understand the '%s' option\n"),
            av[i]
          ));

        idl_global->set_compile_flags (idl_global->compile_flags ()
                                       | IDL_CF_ONLY_USAGE);
        break;
    }
}

// Does nothing in this backend.
void
BE_GlobalData::prep_be_arg (char *s)
{
}

// Does nothing in this backend.
void
BE_GlobalData::arg_post_proc (void)
{
}

void
BE_GlobalData::usage (void) const
{
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -x <filename>\t\tName of the generated file.")
      ACE_TEXT (" Default is \"PICML_default_xme_file.xme\"\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -o <dir>\t\tOutput directory for the generated file.")
      ACE_TEXT (" Default is current directory\n")
    ));
}

AST_Generator *
BE_GlobalData::generator_init (void)
{
  AST_Generator *gen = 0;
  ACE_NEW_RETURN (gen,
                  AST_Generator,
                  0);             
  return gen;
}

void
BE_GlobalData::xerces_init (void)
{
  // Initialize the Xerces run-time
  try
    {
      xercesc::XMLPlatformUtils::Initialize();
    }
  catch (const xercesc::XMLException& e)
    {
      char* message = xercesc::XMLString::transcode (e.getMessage ());
      ACE_Auto_Basic_Array_Ptr<char> cleanup_message (message);
      ACE_ERROR ((LM_DEBUG,
                  "Error during initialization : %s\n",
                  message));
      ACE_OS::exit (99);
    }

  xercesc::DOMImplementation *impl = 
    xercesc::DOMImplementationRegistry::getDOMImplementation (XStr ("LS"));

  if (impl == 0)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("Null DOMImplementation returned\n")));
      ACE_OS::exit (99);
    }

  try
    {
      xercesc::DOMDocumentType *doc_type = 
        impl->createDocumentType (X (DOCTYPE),
                                  0,
                                  X (SYS_ID));  
      this->doc_ = impl->createDocument (0,
                                         X (DOCTYPE),
                                         doc_type);
                                               
      this->doc_->setEncoding (X (ENCODING));
      this->doc_->setVersion (X (VERSION));

      this->writer_ =
        ((xercesc::DOMImplementationLS *)impl)->createDOMWriter ();  
      this->writer_->setNewLine (XStr ("\n"));
      bool can_pretty_print =
        this->writer_->canSetFeature (
            xercesc::XMLUni::fgDOMWRTFormatPrettyPrint,
            true
          );
      
      if (can_pretty_print)
        {
          this->writer_->setFeature (
              xercesc::XMLUni::fgDOMWRTFormatPrettyPrint,
              true
            );
        }
        
      ACE_CString target_name;
      const char *path = be_global->output_dir ();
      
      if (path != 0)
        {
          target_name += path;
          target_name += "/";
        }
        
      target_name += be_global->output_file ();
      target_name += FILE_EXT;
      
      // Create a target for the output:
      ACE_NEW (this->target_,
               xercesc::LocalFileFormatTarget (
                  XStr (target_name.c_str ()))
                );
    }
  catch (const xercesc::DOMException &e)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("DOMException code is:  %d\n"),
                  e.code));
    }
  catch (...)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("Unknown exception while creating")
                  ACE_TEXT (" output document\n")));
    }
}

void
BE_GlobalData::cache_files (const char *files[], long nfiles)
{
  for (long i = 0; i < nfiles; ++i)
    {
      this->allfiles_[i] = files[i];
    }
    
  this->nfiles_ = nfiles;
}

void
BE_GlobalData::destroy (void)
{
  // Write out the file last, just before cleanup.
  this->writer_->writeNode (this->target_, *this->doc_);
      
  this->writer_->release ();                 
  this->doc_->release ();
  
  delete this->target_;
  this->target_ = 0;
  
  xercesc::XMLPlatformUtils::Terminate ();
  
  DECL_ID_TABLE_ENTRY *id_entry = 0;
  for (DECL_ID_TABLE_ITERATOR id_iter (this->decl_id_table_);
       id_iter.next (id_entry) != 0;
       id_iter.advance ())
    {
      delete const_cast<char *> (id_entry->ext_id_);
    }
  
  DECL_ELEM_TABLE_ENTRY *fwd_entry = 0;
  for (DECL_ELEM_TABLE_ITERATOR fwd_iter (this->decl_elem_table_);
       fwd_iter.next (fwd_entry) != 0;
       fwd_iter.advance ())
    {
      delete const_cast<char *> (fwd_entry->ext_id_);
    }
}

char *
BE_GlobalData::hex_string (unsigned long number)
{
  static char holder[9];
  ACE_OS::memset (holder,
                  '\0',
                  9);
  ACE_OS::sprintf (holder,
                   "0x%x",
                   number);
  return holder;
}

ACE_CString
BE_GlobalData::basic_seq_suffix (void) const
{
  return this->basic_seq_suffix_;
}
