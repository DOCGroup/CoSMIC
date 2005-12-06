/* -*- c++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    TAO_IFR_BE_DLL
//
// = FILENAME
//    be_global.h
//
// = DESCRIPTION
//    Header file for class containing compiler back end global data.
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#ifndef TAO_PICML_BE_GLOBAL_H
#define TAO_PICML_BE_GLOBAL_H

#include "IDL_TO_PICML_BE_Export.h"
#include "ast_type.h"
#include "ace/SString.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "idl_defines.h"
#include "idl_bool.h"

#include "xercesc/dom/DOM.hpp"
#include "xercesc/dom/DOMElement.hpp"
#include "xercesc/framework/LocalFileFormatTarget.hpp"

using namespace xercesc;

#define X(str) XStr (ACE_TEXT (str))
class AST_Generator;
class AST_Module;

// Defines a class containing all back end global data.

class IDL_TO_PICML_BE_Export BE_GlobalData
{
public:
  // = TITLE
  //    BE_GlobalData
  //
  // = DESCRIPTION
  //    Storage of global data specific to the compiler back end
  //
  BE_GlobalData (void);
  // Constructor.

  virtual ~BE_GlobalData (void);
  // Destructor.

  // Typedefs for hash table that holds GME ids for processed
  // AST nodes. GME references use these ids.

  typedef ACE_Hash_Map_Entry<const char *,
                             const XMLCh *>
    DECL_ID_TABLE_ENTRY;
    
  typedef ACE_Hash_Map_Manager_Ex<const char *,
                                  const XMLCh *,
                                  ACE_Hash<const char *>,
                                  ACE_Equal_To<const char *>,
                                  ACE_Null_Mutex>
    DECL_ID_TABLE;

  typedef ACE_Hash_Map_Iterator_Ex<const char *,
                                   const XMLCh *,
                                   ACE_Hash<const char *>,
                                   ACE_Equal_To<const char *>,
                                   ACE_Null_Mutex>
    DECL_ID_TABLE_ITERATOR;

  // Empty DOMElements are created for forward declarations, then
  // looked up and completed when the full definition is seen.
  
  typedef ACE_Hash_Map_Entry<const char *,
                             DOMElement *>
    DECL_ELEM_TABLE_ENTRY;
    
  typedef ACE_Hash_Map_Manager_Ex<const char *,
                                  DOMElement *,
                                  ACE_Hash<const char *>,
                                  ACE_Equal_To<const char *>,
                                  ACE_Null_Mutex>
    DECL_ELEM_TABLE;

  typedef ACE_Hash_Map_Iterator_Ex<const char *,
                                   DOMElement *,
                                   ACE_Hash<const char *>,
                                   ACE_Equal_To<const char *>,
                                   ACE_Null_Mutex>
    DECL_ELEM_TABLE_ITERATOR;
    
  typedef ACE_Hash_Map_Entry<const char *,
                             AST_Type *>
    REF_DECL_TABLE_ENTRY;
    
  typedef ACE_Hash_Map_Iterator_Ex<const char *,
                                   AST_Type *,
                                   ACE_Hash<const char *>,
                                   ACE_Equal_To<const char *>,
                                   ACE_Null_Mutex>
    REF_DECL_TABLE_ITERATOR;
    
  typedef ACE_Hash_Map_Manager_Ex<const char *,
                                  AST_Type *,
                                  ACE_Hash<const char *>,
                                  ACE_Equal_To<const char *>,
                                  ACE_Null_Mutex>
    REF_DECL_TABLE;

  // Maps GME model element type to hex string used in GME id.
  enum kind_id
    {
      MODEL  = 0x65,
      ATOM   = 0x66,
      REF    = 0x67,
      CONN   = 0x68,
      FOLDER = 0x6a
    };
    
  // Data accessors.

  const char *filename (void) const;
  void filename (char *fname);

  const char* output_dir (void) const;
  void output_dir (const char* s);
  
  const char* input_xme (void) const;
  void input_xme (const char* s);
  
  // Access or increment these project-wide values.
  
  unsigned long models_seen (void) const;
  unsigned long atoms_seen (void) const;
  unsigned long refs_seen (void) const;
  unsigned long conns_seen (void) const;
  unsigned long folders_seen (void) const;
  
  void incr_models_seen (void);
  void incr_atoms_seen (void);
  void incr_refs_seen (void);
  void incr_conns_seen (void);
  void incr_folders_seen (void);
  
  unsigned long npredefined (void) const;
  // Accessor for the readonly member.
  
  const char** pdt_names (void) const;
  // Access a singleton list of IDML predefined type names.
  
  long nfiles (void) const;
  void nfiles (long val);
  // Accessors for the member.
  
  idl_bool first_file (void) const;
  void first_file (idl_bool val);
  // Accessors for the member.
  
  ACE_CString output_file (void) const;
  void output_file (const char *val);
  // Accessors for the member.
  
  DOMDocument *doc (void) const;
  // Readonly accessor for the member.
  
  DOMElement *root_folder (void) const;
  void root_folder (DOMElement *elem);
  // Accessors for the member.
  
  DOMElement *component_types_folder (void) const;
  void component_types_folder (DOMElement *elem);
  // Accessors for the member.
  
  DOMElement *implementation_artifacts_folder (void) const;
  void implementation_artifacts_folder (DOMElement *elem);
  // Accessors for the member.
  
  DOMElement *implementations_folder (void) const;
  void implementations_folder (DOMElement *elem);
  
  DOMElement *interface_definitions_folder (void) const;
  void interface_definitions_folder (DOMElement *elem);
  
  unsigned long component_types_rel_id (void) const;
  void incr_component_types_rel_id (void);
  // Read and increment the rel_id index for ComponentTypes.
  
  unsigned long implementation_artifacts_rel_id (void) const;
  void incr_implementation_artifacts_rel_id (void);
  // Read and increment the rel_id index for ImplementationArtifacts.
  
  unsigned long implementations_rel_id (void) const;
  void incr_implementations_rel_id (void);
  // Read and increment the rel_id index for ComponentImplementations.
  
  DECL_ID_TABLE &decl_id_table (void);
  DECL_ELEM_TABLE &decl_elem_table (void);
  REF_DECL_TABLE &ref_decl_table (void);
  // Read/write accessors for the members.
  
  // Utility methods.
  
  ACE_CString spawn_options (void);
  // Command line passed to ACE_Process::spawn. Different
  // implementations in different backends.

  void parse_args (long &i, char **av);
  // Parse args that affect the backend.
  
  void prep_be_arg (char *s);
  // Special BE arg call factored out of DRV_args.
  
  void arg_post_proc (void);
  // Checks made after parsing args.
  
  void usage (void) const;
  // Display usage of BE-specific options.
  
  AST_Generator *generator_init (void);
  // Create an AST node generator.
  
  void xerces_init (void);
  // Initialize all the Xerces stuff.
  
  void cache_files (const char *files[], long nfiles);
  // Cache the list of files from the command line.
  
  void destroy (void);
  // Cleanup.
  
  char *hex_string (unsigned long number);
  // Conversion utility.
  
  ACE_CString basic_seq_suffix (void) const;
  // Accessor for the member.

  ACE_CString make_gme_id (kind_id kind);
  // Create a unique GME id based on the model element type.
  
  DOMElement *imported_dom_element (DOMElement *sub_tree,
                                    const char *local_name,
                                    kind_id elem_kind = MODEL,
                                    bool by_referred = false);
  // Have we already imported <local_name> in scope <sub_tree>?
  
  DOMElement *imported_module_dom_elem (DOMElement *sub_tree,
                                        AST_Module *node);
  // Specialization for IDL modules of above method.
  
  void set_working_folders (void);
  // If we are importing an XME file, set root folder and
  // interface definitions folder from it.
  
  DOMElement *lookup_by_tag_and_kind (DOMElement *scope,
                                      const char *tag_name,
                                      const char *kind_name);
  // Utility operation.
  
  void init_ids (DOMElement *sub_tree);
  // Recursive functions that traverses the imported DOM tree and
  // initializes models_seen_, atoms_seen_, etc. so IDs added from
  // IDL files will be not clash.

private:
  char *filename_;
  // Name of the IDL file we are processing.

  char *output_dir_;
  // Directory where the generated file is to be
  // kept. Default value is 0 for this string which means the current
  // directory from which the <idl_to_picml> is called.
  
  char *input_xme_;
  // URL of the XME file to input, if any.

  unsigned long models_seen_;
  unsigned long atoms_seen_;
  unsigned long refs_seen_;
  unsigned long conns_seen_;
  unsigned long folders_seen_;
  // Ids for these are project-wide and use these numbers to be unique.
  
  unsigned long npredefined_;
  // Number of predefined types in IDML.
  
  const char *allfiles_[NFILES];
  // All files in the command line.
  
  long nfiles_;
  // Actual length of the above list.
  
  idl_bool first_file_;
  // Are we processing the first file on the command line?
  
  ACE_CString output_file_;
  // Set from command line or had default value.
  
  DOMDocument *doc_;
  DOMWriter *writer_;
  XMLFormatTarget *target_;
  DOMElement *root_folder_;
  DOMElement *component_types_folder_;
  DOMElement *implementation_artifacts_folder_;
  DOMElement *implementations_folder_;
  DOMElement *interface_definitions_folder_;
  // DOM items we need to cache.
  
  unsigned long component_types_rel_id_;
  unsigned long implementation_artifacts_rel_id_;
  unsigned long implementations_rel_id_;
  // Cache of rel_id indices for the extra folders.
  
  DECL_ID_TABLE decl_id_table_;
  // Hash map of GME ids, keyed by repository id.
  
  DECL_ELEM_TABLE decl_elem_table_;
  // Hash map of DOMElements, keyed by repository id.
  
  REF_DECL_TABLE ref_decl_table_;
  // Hash map of AST nodes, keyed by GME id, used to look up
  // referenced elements in the DOM tree.
  
  ACE_CString basic_seq_suffix_;
  // Appended to name of basic type to get corresponding sequence.
};

#endif /* TAO_PICML_BE_GLOBAL_H */
