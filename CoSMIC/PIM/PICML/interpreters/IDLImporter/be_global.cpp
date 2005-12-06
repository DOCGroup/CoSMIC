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

#include "picml_visitor.h"
#include "XercesString.h"
#include "XML_Error_Handler.h"
#include "be_global.h"
#include "ast_generator.h"
#include "ast_module.h"
#include "utl_identifier.h"
#include "global_extern.h"
#include "idl_defines.h"
#include "ace/OS_NS_stdio.h"

// Some magic strings.
const char *VERSION = "1.0";
const char *ENCODING = "UTF-8";
const char *DOCTYPE = "project";
const char *SYS_ID = "mga.dtd";
const char *FILE_EXT = ".xme";

IDL_TO_PICML_BE_Export BE_GlobalData *be_global = 0;

BE_GlobalData::BE_GlobalData (void)
  : filename_ (0),
    output_dir_ (0),
    input_xme_ (0),
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
    root_folder_ (0),
    component_types_folder_ (0),
    implementation_artifacts_folder_ (0),
    implementations_folder_ (0),
    interface_definitions_folder_ (0),
    component_types_rel_id_ (1UL),
    implementation_artifacts_rel_id_ (1UL),
    implementations_rel_id_ (1UL),
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

DOMDocument *
BE_GlobalData::doc (void) const
{
  return this->doc_;
}

DOMElement *
BE_GlobalData::root_folder (void) const
{
  return this->root_folder_;
}

void
BE_GlobalData::root_folder (DOMElement *elem)
{
  this->root_folder_ = elem;
}

DOMElement *
BE_GlobalData::component_types_folder (void) const
{
  return this->component_types_folder_;
}

void
BE_GlobalData::component_types_folder (DOMElement *elem)
{
  this->component_types_folder_ = elem;
}

DOMElement *
BE_GlobalData::implementation_artifacts_folder (void) const
{
  return this->implementation_artifacts_folder_;
}

void
BE_GlobalData::implementation_artifacts_folder (DOMElement *elem)
{
  this->implementation_artifacts_folder_ = elem;
}

DOMElement *
BE_GlobalData::implementations_folder (void) const
{
  return this->implementations_folder_;
}

void
BE_GlobalData::implementations_folder (DOMElement *elem)
{
  this->implementations_folder_ = elem;
}

DOMElement *
BE_GlobalData::interface_definitions_folder (void) const
{
  return this->interface_definitions_folder_;
}

void
BE_GlobalData::interface_definitions_folder (DOMElement *elem)
{
  this->interface_definitions_folder_ = elem;
}

unsigned long
BE_GlobalData::component_types_rel_id (void) const
{
  return this->component_types_rel_id_;
}

void
BE_GlobalData::incr_component_types_rel_id (void)
{
  ++this->component_types_rel_id_;
}

unsigned long
BE_GlobalData::implementation_artifacts_rel_id (void) const
{
  return this->implementation_artifacts_rel_id_;
}

void
BE_GlobalData::incr_implementation_artifacts_rel_id (void)
{
  ++this->implementation_artifacts_rel_id_;
}

unsigned long
BE_GlobalData::implementations_rel_id (void) const
{
  return this->implementations_rel_id_;
}

void
BE_GlobalData::incr_implementations_rel_id (void)
{
  ++this->implementations_rel_id_;
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

BE_GlobalData::REF_DECL_TABLE &
BE_GlobalData::ref_decl_table (void)
{
  return this->ref_decl_table_;
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
      XMLPlatformUtils::Initialize();
    }
  catch (const XMLException& e)
    {
      char* message = XMLString::transcode (e.getMessage ());
      ACE_Auto_Basic_Array_Ptr<char> cleanup_message (message);
      ACE_ERROR ((LM_DEBUG,
                  "Error during initialization : %s\n",
                  message));
      ACE_OS::exit (99);
    }

  XMLCh tempStr[100];
  XMLString::transcode("LS", tempStr, 99);
  DOMImplementation *impl =
    DOMImplementationRegistry::getDOMImplementation (tempStr);

  if (0 == impl)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("Null DOMImplementation returned\n")));
      ACE_OS::exit (99);
    }

  this->writer_ =
    ((DOMImplementationLS *)impl)->createDOMWriter ();
  this->writer_->setNewLine (XStr ("\n"));
  bool can_pretty_print =
    this->writer_->canSetFeature (
        XMLUni::fgDOMWRTFormatPrettyPrint,
        true
      );

  if (can_pretty_print)
    {
      this->writer_->setFeature (
          XMLUni::fgDOMWRTFormatPrettyPrint,
          true
        );
    }

  try
    {
      const char *xme = this->input_xme ();

      // If we are inputting an existing XME file, use that to create
      // the DOM tree, else create an empty one.
      if (0 == xme)
        {
          DOMDocumentType *doc_type =
            impl->createDocumentType (X (DOCTYPE),
                                      0,
                                      X (SYS_ID));
          this->doc_ = impl->createDocument (0,
                                             X (DOCTYPE),
                                             doc_type);

          this->doc_->setEncoding (X (ENCODING));
          this->doc_->setVersion (X (VERSION));
        }
      else
        {
          DOMBuilder *parser =
            ((DOMImplementationLS*)impl)->createDOMBuilder (
                DOMImplementationLS::MODE_SYNCHRONOUS,
                0
              );

          if (parser->canSetFeature(XMLUni::fgDOMValidation, true))
            {
              parser->setFeature(XMLUni::fgDOMValidation, true);
            }

          if (parser->canSetFeature(XMLUni::fgDOMNamespaces, true))
            {
              parser->setFeature(XMLUni::fgDOMNamespaces, true);
            }

          if (parser->canSetFeature(XMLUni::fgDOMDatatypeNormalization, true))
            {
              parser->setFeature(XMLUni::fgDOMDatatypeNormalization, true);
            }


          parser->setFeature (XMLUni::fgDOMComments, false);
          parser->setFeature (XMLUni::fgDOMEntities, false);
          parser->setFeature (XMLUni::fgDOMNamespaces, true);
          parser->setFeature (XMLUni::fgDOMValidation, true);
          parser->setFeature (XMLUni::fgDOMWhitespaceInElementContent, false);
          parser->setFeature (XMLUni::fgXercesSchema, true);

          XML_Error_Handler handler;
          parser->setErrorHandler (&handler);

          this->doc_ = parser->parseURI (xme);
//          parser->release ();

          if (handler.getErrors ())
            {
              throw;
            }
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

      // (@@@ JP) All of a sudden (2/7/05) there was an exception when
      // XMLCh* was passed, but not when char* was passed (the constructor
      // for LocalFileFormatTarget has two variants).
      XStr target_xstr (target_name.c_str ());
      const XMLCh * target_arg = target_xstr.begin ();

      ACE_NEW (this->target_,
               LocalFileFormatTarget (target_name.c_str ()));
    }
  catch (const DOMException &e)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("DOMException code is:  %d\n"),
                  e.code));
    }
  catch (const XMLException&)
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("XML exception while creating")
                  ACE_TEXT (" output document\n")));
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
  // Get root folder and interface definitions folder from the
  // input and cache them.
  if (be_global->input_xme () != 0)
    {
      this->set_working_folders ();
    }

  for (long i = 0; i < nfiles; ++i)
    {
      // Cache the file names in be_global.
      this->allfiles_[i] = files[i];

      // Store DOM element and GME id for each file now, so we
      // won't have to be concerned that a lookup failure later
      // might be due to a mistake or that the filename just
      // appears further down the command line.

      ACE_CString fname (files[i]);
      int fpos = fname.rfind ('/');
      int pos = (fpos == ACE_CString::npos ? fname.rfind ('\\') : fpos);
      ACE_CString lname =
        (pos == ACE_CString::npos ? fname : fname.substr (pos + 1));
      lname = lname.substr (0, lname.rfind ('.'));
      const char *lname_cstr = lname.c_str ();

      DOMElement *file = 0;

      if (be_global->input_xme () != 0)
        {
          file =
            this->lookup_by_tag_and_kind (this->interface_definitions_folder_,
                                          "model",
                                          "File");
        }

      if (0 == file)
        {
          // Create a DOM element and store in the table under the
          // local filename. This may lead to name clashes, but it is
          // too much of a bottomless pit to deal with full pathnames
          // portably.
          file = this->doc_->createElement (X ("model"));

          // Create a new GME id and store it as well.
          ACE_CString new_id = this->make_gme_id (MODEL);
          file->setAttribute (X ("id"), X (new_id.c_str ()));
        }

      this->decl_elem_table_.bind (ACE::strnew (lname_cstr),
                                   file);

      this->decl_id_table_.bind (ACE::strnew (lname_cstr),
                                 file->getAttribute (X ("id")));
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

  XMLPlatformUtils::Terminate ();

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

  REF_DECL_TABLE_ENTRY *ref_entry = 0;
  for (REF_DECL_TABLE_ITERATOR ref_iter (this->ref_decl_table_);
       ref_iter.next (ref_entry) != 0;
       ref_iter.advance ())
    {
      delete const_cast<char *> (ref_entry->ext_id_);
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

ACE_CString
BE_GlobalData::make_gme_id (kind_id kind)
{
  ACE_CString val ("id-");
  static char short_str[5];
  ACE_OS::sprintf (short_str, "%4.4x", kind);
  short_str[4] = '\0';
  val += short_str;
  val += "-";
  unsigned long tmp = 0;

  switch (kind)
    {
      case MODEL:
        tmp = this->models_seen_++;
        break;
      case ATOM:
        tmp = this->atoms_seen_++;
        break;
      case REF:
        tmp = this->refs_seen_++;
        break;
      case CONN:
        tmp = this->conns_seen_++;
        break;
      case FOLDER:
        tmp = this->folders_seen_++;
        break;
      default:
        break;
    }

  static char long_str[9];
  ACE_OS::sprintf (long_str, "%8.8x", tmp);
  long_str[8] = '\0';
  val += long_str;
  return val;
}

DOMElement *
BE_GlobalData::imported_dom_element (DOMElement *sub_tree,
                                     const char *local_name,
                                     kind_id elem_kind,
                                     bool by_referred)
{
  // Can't already be in the DOM tree if we didn't read in an XME file.
  if (0 == this->input_xme_)
    {
      return 0;
    }

  DOMNodeList *children = 0;

  switch (elem_kind)
    {
      default:
        children = sub_tree->getElementsByTagName (X ("model"));
        break;
      case REF:
        children = sub_tree->getElementsByTagName (X ("reference"));
        break;
      case ATOM:
        children = sub_tree->getElementsByTagName (X ("atom"));
        break;
      case CONN:
        children = sub_tree->getElementsByTagName (X ("connection"));
        break;
    }

  for (XMLSize_t index = 0; index < children->getLength (); ++index)
    {
      DOMElement *child =
        (DOMElement *) children->item (index);

      // Elements of an exception list have no names, so we have to
      // look up the referenced exception by name and return its
      // DOMElement, if any, to see if this local_name represents a
      // new member of the exception list.
      if (by_referred)
        {
          const XMLCh *referred = child->getAttribute (X ("referred"));
          child = this->doc_->getElementById (referred);
        }

      // There should be only one "name" node.
      DOMNodeList *namelist =
        child->getElementsByTagName (X ("name"));

      DOMNode *name_elem = namelist->item (0);
      DOMNode *name_item = name_elem->getFirstChild ();
      DOMText *name = (DOMText *) name_item;
      const XMLCh *text = name->getData ();

      if (X (local_name) == text)
        {
          return child;
        }
    }

  return 0;
}

DOMElement *
BE_GlobalData::imported_module_dom_elem (DOMElement *sub_tree,
                                         AST_Module *node)
{
  // Can't already be in the DOM tree if we didn't read in an XME file.
  if (0 == this->input_xme_)
    {
      return 0;
    }

  DOMNodeList *children = sub_tree->getChildNodes ();
  const char *local_name = node->local_name ()->get_string ();
  AST_Decl *d = 0;

  for (XMLSize_t i = 0; i < children->getLength (); ++i)
    {
      DOMElement *child = (DOMElement *) children->item (i);

      if (0 == child)
        {
          continue;
        }

      const XMLCh *tag = child->getTagName ();

      if (X ("model") != X (tag))
        {
          continue;
        }

      const XMLCh *kind = child->getAttribute (X ("kind"));

      if (X ("Package") != X (kind))
        {
          continue;
        }

      // There should be only one "name" node.
      DOMNode *name_elem = child->getFirstChild ();
      DOMNode *name_node = name_elem->getFirstChild ();
      DOMText *name_text = (DOMText *) name_node;
      const XMLCh *name = name_text->getData ();

      if (X (local_name) != X (name))
        {
          continue;
        }

      DOMNodeList *grandkids = child->getChildNodes ();

      for (XMLSize_t j = 0; j < grandkids->getLength (); ++j)
        {
          DOMElement *kid = (DOMElement *) grandkids->item (j);

          if (0 == kid)
            {
              continue;
            }

          tag = kid->getTagName ();

          // We just need to find the first child that's either an
          // XME reference (Alias) or an XME model.
          if (X ("model") != X (tag) && X ("reference") != X (tag))
            {
              continue;
            }

          // There should be only one "name" node.
          name_elem = kid->getFirstChild ();
          name_node = name_elem->getFirstChild ();
          name_text = (DOMText *) name_node;
          name = name_text->getData ();
          bool child_name_match = false;

          // New decls in this IDL module may have been added at the
          // top, but the name we're trying to match has to be in
          // here somewhere.
          for (UTL_ScopeActiveIterator iter (node, UTL_Scope::IK_decls);
               !iter.is_done ();
               iter.next ())
            {
              d = iter.item ();

              const char *node_child_name =
                d->local_name ()->get_string ();

              if (X (node_child_name) == name)
                {
                  child_name_match = true;
                  break;
                }
            }

          if (!child_name_match)
            {
              break;
            }

          AST_Module *m = AST_Module::narrow_from_decl (d);
          kind = kid->getAttribute (X ("kind"));

          // If we've matched things that aren't nested modules,
          // we're done. If they are, we recurse. If one is and
          // one isn't, break and increment the outer loop.
          if (0 == m && X ("Package") != X (kind))
            {
              return child;
            }
          else if (0 != m && X ("Package") == kind)
            {
              DOMElement *rec_val =
                this->imported_module_dom_elem (child, m);

              if (0 != rec_val)
                {
                  return child;
                }
              else
                {
                  break;
                }
            }
          else
            {
              break;
            }
        }
    }

  return 0;
}

void
BE_GlobalData::set_working_folders (void)
{
  DOMElement *root = doc_->getDocumentElement ();

  DOMNodeList *folders =
    root->getElementsByTagName (X ("folder"));

  DOMElement *root_folder = (DOMElement *) folders->item (0);
  this->root_folder_ = root_folder;

  this->interface_definitions_folder_ =
    this->lookup_by_tag_and_kind (root_folder,
                                  "folder",
                                  "InterfaceDefinitions");
}

DOMElement *
BE_GlobalData::lookup_by_tag_and_kind (DOMElement *scope,
                                       const char *tag_name,
                                       const char *kind_name)
{
  DOMNodeList *children = scope->getElementsByTagName (X (tag_name));

  for (XMLSize_t i = 0; i < children->getLength (); ++i)
    {
      DOMElement *child = (DOMElement *) children->item (i);
      const XMLCh *kind = child->getAttribute (X ("kind"));

      if (X (kind_name) == kind)
        {
          return child;
        }
    }

  return 0;
}

void
BE_GlobalData::init_ids (DOMElement *sub_tree)
{
  static const XStr model ("model");
  static const XStr reference ("reference");
  static const XStr atom ("atom");
  static const XStr connection ("connection");
  static const XStr folder ("folder");

  if (sub_tree == 0)
    {
      return;
    }

  const XMLCh *tag = sub_tree->getTagName ();

  if (model == tag)
    {
      ++this->models_seen_;
    }
  else if (reference == tag)
    {
      ++this->refs_seen_;
    }
  else if (connection == tag)
    {
      ++this->conns_seen_;
    }
  else if (atom == tag)
    {
      ++this->atoms_seen_;
    }
  else if (folder == tag)
    {
      ++this->folders_seen_;
    }

  DOMNodeList *children = sub_tree->getChildNodes ();

  for (XMLSize_t index = 0; index < children->getLength (); ++index)
    {
      this->init_ids ((DOMElement *) children->item (index));
    }
}
