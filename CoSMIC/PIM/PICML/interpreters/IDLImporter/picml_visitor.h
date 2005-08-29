// $Id$

/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    TAO_PICML_BE_DLL
//
// = FILENAME
//    picml_visitor.h
//
// = DESCRIPTION
//    The IDML importer visitor base class.
//
// = AUTHOR
//    Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#ifndef TAO_PICML_VISITOR_H
#define TAO_PICML_VISITOR_H

#include "ast_visitor.h"
#include "ast_expression.h"
#include "ast_component.h"
#include "be_extern.h"

#include "ace/Unbounded_Queue.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include <xercesc/dom/DOM.hpp>

using namespace xercesc;

class UTL_ExceptList;
class UTL_IdList;

class picml_visitor : public ast_visitor
{
  //
  // = TITLE
  //    picml_visitor.
  //
  // = DESCRIPTION
  //    Base class for the IDML importer visitors. The methods are
  //    not pure virtual to facilitate the implementation of some
  //    derived visitors that override only a few.
  //
public:
  picml_visitor (DOMElement *sub_tree,
                unsigned long relid = 1UL);
  virtual ~picml_visitor (void);

  virtual int visit_decl (AST_Decl *d);
  virtual int visit_scope (UTL_Scope *node);
  virtual int visit_type (AST_Type *node);
  virtual int visit_predefined_type (AST_PredefinedType *node);
  virtual int visit_module (AST_Module *node);
  virtual int visit_interface (AST_Interface *node);
  virtual int visit_interface_fwd (AST_InterfaceFwd *node);
  virtual int visit_valuetype (AST_ValueType *node);
  virtual int visit_valuetype_fwd (AST_ValueTypeFwd *node);
  virtual int visit_component (AST_Component *node);
  virtual int visit_component_fwd (AST_ComponentFwd *node);
  virtual int visit_eventtype (AST_EventType *node);
  virtual int visit_eventtype_fwd (AST_EventTypeFwd *node);
  virtual int visit_home (AST_Home *node);
  virtual int visit_factory (AST_Factory *node);
  virtual int visit_structure (AST_Structure *node);
  virtual int visit_structure_fwd (AST_StructureFwd *node);
  virtual int visit_exception (AST_Exception *node);
  virtual int visit_expression (AST_Expression *node);
  virtual int visit_enum (AST_Enum *node);
  virtual int visit_operation (AST_Operation *node);
  virtual int visit_field (AST_Field *node);
  virtual int visit_argument (AST_Argument *node);
  virtual int visit_attribute (AST_Attribute *node);
  virtual int visit_union (AST_Union *node);
  virtual int visit_union_fwd (AST_UnionFwd *node);
  virtual int visit_union_branch (AST_UnionBranch *node);
  virtual int visit_union_label (AST_UnionLabel *node);
  virtual int visit_constant (AST_Constant *node);
  virtual int visit_enum_val (AST_EnumVal *node);
  virtual int visit_array (AST_Array *node);
  virtual int visit_sequence (AST_Sequence *node);
  virtual int visit_string (AST_String *node);
  virtual int visit_typedef (AST_Typedef *node);
  virtual int visit_root (AST_Root *node);
  virtual int visit_native (AST_Native *node);
  virtual int visit_valuebox (AST_ValueBox *node);
  
private:
  typedef ACE_Unbounded_Queue_Iterator<AST_Component::port_description>
    PORT_ITER;
  
private:
  ACE_CString set_id_attr (DOMElement *elem, BE_GlobalData::kind_id kind);
  void set_relid_attr (DOMElement *elem);
  void set_childrelidcntr_attr (DOMElement *elem,
                                UTL_Scope *s,
                                AST_Attribute *a = 0);
                                
  void add_name_element (DOMElement *elem, const char *name);
  void add_predefined_types (DOMElement *root_folder);
  void add_predefined_sequences (DOMElement *parent, AST_Root *node);
  void add_one_predefined_sequence (DOMElement *parent,
                                    AST_Root *node,
                                    const char *type,
                                    unsigned long &model_slot,
                                    unsigned long pdt_slot);
  DOMElement *add_file_element (DOMElement *parent,
                                AST_Root *node,
                                unsigned long rel_id);
  void add_prefix_element (DOMElement *parent, AST_Decl *node);
  void add_replace_id_element (DOMElement *parent, AST_Decl *node);
  void add_version_element (DOMElement *parent, AST_Decl *node);
  void add_tag_common (const char *value,
                       const char *name,
                       DOMElement *parent,
                       idl_bool is_meta = I_TRUE);
  void add_local_element (DOMElement *parent, AST_Decl *node);
  void add_abstract_element (DOMElement *parent, AST_Decl *node);
  void add_include_elements (UTL_Scope *container, DOMElement *parent);
  void add_regnodes (UTL_Scope *container,
                     DOMElement *parent,
                     size_t slot,
                     AST_Attribute *a = 0,
                     idl_bool is_connected = I_FALSE,
                     const char *aspect = "InterfaceDefinition",
                     unsigned long num_slices = 0UL);
  void add_pos_element (UTL_Scope *container,
                        DOMElement *parent,
                        size_t slot,
                        AST_Attribute *a = 0,
                        idl_bool is_connected = I_FALSE,
                        unsigned long num_slices = 0UL);
  void add_inherited_elements (DOMElement *parent, AST_Interface *node);
  void add_one_inherited (DOMElement *parent,
                          AST_Interface *node,
                          AST_Interface *base,
                          unsigned long slot);
  void add_supported_elements (DOMElement *parent,
                               AST_Interface *node,
                               AST_Interface **supports,
                               long n_supports);
  void add_exception_elements (DOMElement *parent,
                               UTL_Scope *s,
                               AST_Attribute *a,
                               UTL_ExceptList *el,
                               const char *name,
                               unsigned long start_slot);
  void add_constant_value (DOMElement *parent, AST_Constant *node);
  void add_discriminator (DOMElement *parent, AST_Union *u);
  void add_labels (AST_UnionBranch *ub,
                   ACE_CString &ub_id,
                   unsigned long member_slot);
  void add_label_name (DOMElement *label, AST_UnionLabel *ul, UTL_Scope *u);
  void add_private (AST_Field *f,
                    ACE_CString &id,
                    unsigned long member_slot);
  void add_base_component (DOMElement *parent, AST_Component *node);
  void add_base_home (DOMElement *parent, AST_Home *node);
  void add_ports (DOMElement *parent, AST_Component *node);
  void add_manages (AST_Home *node);
  void add_lookup_key (DOMElement *parent, AST_Home *node);
  void add_home_factories (DOMElement *parent, AST_Home *node);
  void add_finders (DOMElement *parent, AST_Home *node);
  
  ACE_TCHAR *timestamp (ACE_TCHAR date_and_time[], int length);
  unsigned long nmembers_gme (UTL_Scope *s, AST_Attribute *a = 0);
  XMLCh *lookup_id (AST_Decl *d);
  XMLCh *lookup_constant_type (AST_Constant *c);
  ACE_CString print_scoped_name (UTL_IdList *sn);
  ACE_CString expr_val_to_string (AST_Expression::AST_ExprValue *ev);
  unsigned long user_includes (void);
  void set_n_basic_seqs (void);
  void set_one_basic_seq (const char *base_type);
  void check_for_basic_seq (AST_Decl *d, ACE_CString &str);
  void check_for_basic_type (AST_Decl *d, ACE_CString &str);
  bool can_skip_import (AST_Module *m);
  DOMElement *imported_dom_element (AST_Decl *d);
  
  void add_picml_boilerplate (void);
  void add_ComponentImplementations (void);
  void add_ImplementationArtifacts (void);
  void add_ComponentTypes (void);
  void add_PackageConfigurations (void);
  void add_ComponentPackages (void);
  void add_DeploymentPlans (void);
  void add_Targets (void);
  void add_TopLevelPackages (void);
  void add_ComponentBuild (void);
  
  void add_defalt_container (AST_Component *node);
  void add_implementation_artifacts (AST_Component *node);
  DOMElement *add_one_impl_artifact (DOMElement *container,
                                     AST_Component *node,
                                     unsigned long index);
  void add_entrypoint (DOMElement *container,
                       DOMElement *artifact,
                       AST_Component *node,
                       unsigned long index);
                       
  void add_artifact_depends (DOMElement *container,
                             DOMElement *src,
                             DOMElement *dst,
                             unsigned long index);

private:
  DOMElement *sub_tree_;
  DOMDocument *doc_;
  unsigned long rel_id_;
  const unsigned long XMAX_;
  const unsigned long YMAX_;
  const unsigned long ICON_SIZE_;
  unsigned long private_relid_offset_;
  unsigned long manages_relid_offset_;
  unsigned long n_basic_seqs_;
};

#endif /* TAO_PICML_VISITOR_H */
