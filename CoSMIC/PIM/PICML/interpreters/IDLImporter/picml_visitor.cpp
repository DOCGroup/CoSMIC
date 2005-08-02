/* -*- c++ -*- */
// $Id$

#include "picml_visitor.h"
#include "ast_argument.h"
#include "ast_array.h"
#include "ast_attribute.h"
#include "ast_component_fwd.h"
#include "ast_enum.h"
#include "ast_enum_val.h"
#include "ast_eventtype.h"
#include "ast_eventtype_fwd.h"
#include "ast_exception.h"
#include "ast_factory.h"
#include "ast_field.h"
#include "ast_home.h"
#include "ast_operation.h"
#include "ast_root.h"
#include "ast_sequence.h"
#include "ast_structure_fwd.h"
#include "ast_union.h"
#include "ast_union_branch.h"
#include "ast_union_fwd.h"
#include "ast_union_label.h"
#include "ast_valuetype_fwd.h"
#include "utl_exceptlist.h"
#include "utl_identifier.h"
#include "utl_idlist.h"
#include "utl_string.h"
#include "global_extern.h"
#include "nr_extern.h"
#include "XercesString.h"
#include "ace/OS_NS_stdio.h"



// The XMAX_ and YMAX_ values below work well for a screen size
// of 1600 x 1200, giving a likely size for the IDML Model Editor
// window.
picml_visitor::picml_visitor (DOMElement *sub_tree,
                              unsigned long rel_id)
  : sub_tree_ (sub_tree),
    doc_ (sub_tree->getOwnerDocument ()),
    rel_id_ (rel_id),
    XMAX_ (1100UL),
    YMAX_ (700UL),
    ICON_SIZE_ (64UL),
    private_relid_offset_ (0UL),
    manages_relid_offset_ (0UL),
    n_basic_seqs_ (0UL)
{
}

picml_visitor::~picml_visitor (void)
{
}

int 
picml_visitor::visit_decl (AST_Decl *)
{
  return 0;
}

int 
picml_visitor::visit_scope (UTL_Scope *node)
{
  for (UTL_ScopeActiveIterator si (node, UTL_Scope::IK_decls);
       !si.is_done ();
       si.next ())
    {
      AST_Decl *d = si.item ();
      
      if (d->node_type () == AST_Decl::NT_pre_defined)
        {
          continue;
        }
        
      // Want to skip the uses_xxxConnection structs added by uses
      // multiple ports.
      if (ScopeAsDecl (node)->node_type () == AST_Decl::NT_component
          && d->node_type () != AST_Decl::NT_attr)
        {
          continue;
        }
      
      if (d->ast_accept (this) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "picml_visitor::visit_scope - "
                             "codegen for scope failed\n"),
                            -1);
        }
    }
       
  return 0;
}

int 
picml_visitor::visit_type (AST_Type *)
{
  return 0;
}

int 
picml_visitor::visit_predefined_type (AST_PredefinedType *)
{
  return 0;
}

int 
picml_visitor::visit_module (AST_Module *node)
{
  // Checks scope recursively. If only nested modules and forward
  // decls are found, we can skip importing this node.
  if (this->can_skip_import (node))
    {
      return 0;
    }
    
  // Since modules can be reopened in IDL, we create a new DOMElement
  // without checking for previous existence. Since a module cannot
  // be referenced by any other AST node, there's no need to store
  // anything in either of the tables we use in the backend.

  DOMElement *elem = this->doc_->createElement (X ("model"));
  int result = 0;
  unsigned long holder = 0;
  
  if (!node->imported ())
    {
      // Homes can be declared at global scope or in (possibly nested)
      // modules, so we need to preserve the value of the offset for
      // the outer scope, and reset it for the inner scope.
      holder = this->manages_relid_offset_;
      this->manages_relid_offset_ = 0UL;
        
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      elem->setAttribute (X ("kind"), X ("Package"));
      elem->setAttribute (X ("role"), X ("Package"));
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_prefix_element (elem, node);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  picml_visitor scope_visitor (elem);
  if (scope_visitor.visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_module - "
                         "codegen for scope failed\n"),
                        -1);
    }
  
  if (!node->imported ())
    {
      // Restore the offset value for the outer scope.
      this->manages_relid_offset_ = holder;
    }
  
  return 0;
}

int 
picml_visitor::visit_interface (AST_Interface *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      elem->setAttribute (X ("kind"), X ("Object"));
      elem->setAttribute (X ("role"), X ("Object"));
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_prefix_element (elem, node);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      this->add_abstract_element (elem, node);
      this->add_local_element (elem, node);
      this->add_inherited_elements (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  picml_visitor scope_visitor (elem, node->n_inherits () + 1);
  if (scope_visitor.visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_interface - "
                         "codegen for scope failed\n"),
                        -1);
    }
  
  return 0;
}

int 
picml_visitor::visit_interface_fwd (AST_InterfaceFwd *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);
  
  // If there is an entry in the table, there has been a
  // previous declaration or definition, and we can just return.
  if (result == 0)
    {
      return 0;
    }
    
  // Create a DOMElement and a GME id and store them in their
  // respective tables. These actions are idempotent.
  elem = this->doc_->createElement (X ("model"));
  (void) be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                             elem);
  this->set_id_attr (elem, BE_GlobalData::MODEL);
  (void) be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                           elem->getAttribute (X ("id")));
  return 0;
}

int 
picml_visitor::visit_valuetype (AST_ValueType *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      AST_Decl::NodeType nt = node->node_type ();
      const char *kind =
        nt == AST_Decl::NT_valuetype ? "ValueObject" : "Event";
      elem->setAttribute (X ("kind"), X (kind));
      elem->setAttribute (X ("role"), X (kind));
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_prefix_element (elem, node);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      this->add_abstract_element (elem, node);
      this->add_inherited_elements (elem, node);
      this->add_supported_elements (elem,
                                    node,
                                    node->supports (),
                                    node->n_supports ());
      
      this->sub_tree_->appendChild (elem);
    }
    
  unsigned long start_id = static_cast<unsigned long> (node->n_inherits ()
                                                       + node->n_supports ()
                                                       + 1);
  
  picml_visitor scope_visitor (elem, start_id);
  if (scope_visitor.visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_valuetype - "
                         "code generation for scope failed\n"),
                        -1);
    }
  
  return 0;
}

int 
picml_visitor::visit_valuetype_fwd (AST_ValueTypeFwd *node)
{
  return this->visit_interface_fwd (node);
}

int
picml_visitor::visit_component (AST_Component *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      elem->setAttribute (X ("kind"), X ("Component"));
      elem->setAttribute (X ("role"), X ("Component"));
      this->add_base_component (elem, node);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      this->add_supported_elements (elem,
                                    node,
                                    node->supports (),
                                    node->n_supports ());
      this->add_ports (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  unsigned long start_id = (node->base_component () == 0 ? 0UL : 1UL)
                           + static_cast<unsigned long> (node->n_supports ())
                           + node->provides ().size ()
                           + node->uses ().size ()
                           + node->publishes ().size ()
                           + node->emits ().size ()
                           + node->consumes ().size ()
                           + 1;
  picml_visitor scope_visitor (elem, start_id);
  if (scope_visitor.visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_component - "
                         "code generation for scope failed\n"),
                        -1);
    }
  
  return 0;
}

int 
picml_visitor::visit_component_fwd (AST_ComponentFwd *node)
{
  return this->visit_interface_fwd (node);
}

int 
picml_visitor::visit_eventtype (AST_EventType *node)
{
  return this->visit_valuetype (node);
}

int 
picml_visitor::visit_eventtype_fwd (AST_EventTypeFwd *node)
{
  return this->visit_interface_fwd (node);
}

int
picml_visitor::visit_home (AST_Home *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      elem->setAttribute (X ("kind"), X ("ComponentFactory"));
      elem->setAttribute (X ("role"), X ("ComponentFactory"));
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      this->add_base_home (elem, node);
      this->add_supported_elements (elem,
                                    node,
                                    node->supports (),
                                    node->n_supports ());
      this->add_manages (node);
      this->add_lookup_key (elem, node);
      this->add_home_factories (elem, node);
      this->add_finders (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  unsigned long start_id = (node->base_home () == 0 ? 0UL : 1UL)
                           + static_cast<unsigned long> (node->n_supports ())
                           + (node->primary_key () == 0 ? 0UL : 1UL)
                           + node->factories ().size ()
                           + node->finders ().size ()
                           + 1;
  picml_visitor scope_visitor (elem, start_id);
  if (scope_visitor.visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_home - "
                         "code generation for scope failed\n"),
                        -1);
    }
  
  return 0;
}

int 
picml_visitor::visit_factory (AST_Factory *node)
{
  if (node->imported ())
    {
      return 0;
    }
    
  DOMElement *elem = this->doc_->createElement (X ("model"));
  this->set_id_attr (elem, BE_GlobalData::MODEL);
  elem->setAttribute (X ("kind"), X ("FactoryOperation"));
  elem->setAttribute (X ("role"), X ("FactoryOperation"));
  this->set_relid_attr (elem);
  this->set_childrelidcntr_attr (elem, node);
  this->add_name_element (elem, node->local_name ()->get_string ());
  this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
  this->add_replace_id_element (elem, node);
  this->add_version_element (elem, node);
  
  picml_visitor scope_visitor (elem);
  if (scope_visitor.visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_factory - "
                         "code generation for scope failed\n"),
                        -1);
    }   
  
  this->add_exception_elements (elem,
                                node,
                                0,
                                node->exceptions (),
                                "ExceptionRef",
                                scope_visitor.rel_id_);
  this->sub_tree_->appendChild (elem);
  
  return 0;
}

int 
picml_visitor::visit_structure (AST_Structure *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      elem->setAttribute (X ("kind"), X ("Aggregate"));
      elem->setAttribute (X ("role"), X ("Aggregate"));
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }

  // If in_recursion() returns TRUE and this node is already in the
  // decl id table, we are in the first level of recursion and do
  // not need to visit the scope.    
  ACE_Unbounded_Queue<AST_Type *> list;
  if (result != 0 && node->in_recursion (list))
    {
      return 0;
    }

  picml_visitor scope_visitor (elem);
  if (scope_visitor.visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_structure - "
                         "codegen for scope failed\n"),
                        -1);
    }
    
  return 0;
}

int 
picml_visitor::visit_structure_fwd (AST_StructureFwd *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);
  
  // If there is an entry in the table, there has been a
  // previous declaration or definition, and we can just return.
  if (result == 0)
    {
      return 0;
    }
    
  // Create a DOMElement and a GME id and store them in their
  // respective tables. These actions are idempotent.
  elem = this->doc_->createElement (X ("model"));
  (void) be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                            elem);
  this->set_id_attr (elem, BE_GlobalData::MODEL);
  (void) be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                           elem->getAttribute (X ("id")));
  return 0;
}

int 
picml_visitor::visit_exception (AST_Exception *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      elem->setAttribute (X ("kind"), X ("Exception"));
      elem->setAttribute (X ("role"), X ("Exception"));
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  picml_visitor scope_visitor (elem);
  if (scope_visitor.visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_exception - "
                         "codegen for scope failed\n"),
                        -1);
    }
    
  return 0;
}

int 
picml_visitor::visit_expression (AST_Expression *)
{
  return 0;
}

int 
picml_visitor::visit_enum (AST_Enum *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      elem->setAttribute (X ("kind"), X ("Enum"));
      elem->setAttribute (X ("role"), X ("Enum"));
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  picml_visitor scope_visitor (elem);
  if (scope_visitor.visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_enum - "
                         "codegen for scope failed\n"),
                        -1);
    }
    
  return 0;
}

int 
picml_visitor::visit_operation (AST_Operation *node)
{
  if (node->imported ())
    {
      return 0;
    }
    
  DOMElement *elem = this->doc_->createElement (X ("model"));
  this->set_id_attr (elem, BE_GlobalData::MODEL);
  ACE_CString kind =
    node->flags () == AST_Operation::OP_oneway ? "Oneway" : "Twoway";
  kind += "Operation";
  elem->setAttribute (X ("kind"), X (kind.c_str ()));
  elem->setAttribute (X ("role"), X (kind.c_str ()));
  this->set_relid_attr (elem);
  this->set_childrelidcntr_attr (elem, node);
  this->add_name_element (elem, node->local_name ()->get_string ());
  this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
  this->add_replace_id_element (elem, node);
  this->add_version_element (elem, node);
  
  idl_bool vrt = (node->void_return_type () != 0);
  
  if (!vrt)
    {
      AST_Type *rt = node->return_type ();
      DOMElement *return_type = this->doc_->createElement (X ("reference"));
      this->set_id_attr (return_type, BE_GlobalData::REF);
      return_type->setAttribute (X ("kind"), X ("ReturnType"));
      return_type->setAttribute (X ("role"), X ("ReturnType"));
      return_type->setAttribute (X ("relid"),
                                 X (be_global->hex_string (1UL)));
      return_type->setAttribute (X ("referred"), this->lookup_id (rt));
      this->add_name_element (return_type, "ReturnType");
      this->add_regnodes (node, return_type, 1UL);
      elem->appendChild (return_type);
    }
    
  picml_visitor scope_visitor (elem, vrt ? 1 : 2);
  if (scope_visitor.visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_operation - "
                         "code generation for scope failed\n"),
                        -1);
    }   
  
  this->add_exception_elements (elem,
                                node,
                                0,
                                node->exceptions (),
                                "ExceptionRef",
                                scope_visitor.rel_id_);
  this->sub_tree_->appendChild (elem);
  
  return 0;
}

int 
picml_visitor::visit_field (AST_Field *node)
{
  if (node->imported ())
    {
      return 0;
    }
    
  AST_Type *ft = node->field_type ();
  AST_Decl::NodeType nt = ft->node_type ();
  
  if (nt == AST_Decl::NT_array || nt == AST_Decl::NT_sequence)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_field - "
                         "anonymous types not supported: %s\n",
                         ft->full_name ()),
                        -1);
    }
    
  DOMElement *elem = this->doc_->createElement (X ("reference"));
  ACE_CString id = this->set_id_attr (elem, BE_GlobalData::REF);
  elem->setAttribute (X ("kind"), X ("Member"));
  elem->setAttribute (X ("role"), X ("Member"));
  this->set_relid_attr (elem);
  elem->setAttribute (X ("referred"), this->lookup_id (ft));
  this->add_name_element (elem, node->local_name ()->get_string ());
  unsigned long slot = this->rel_id_ - 1;
  this->add_regnodes (node->defined_in (), elem, slot);
  
  this->sub_tree_->appendChild (elem);
  
  if (node->visibility () == AST_Field::vis_PRIVATE)
    {
      this->add_private (node, id, slot);
    }
  
  return 0;
}

int 
picml_visitor::visit_argument (AST_Argument *node)
{
  DOMElement *arg = this->doc_->createElement (X ("reference"));
  this->set_id_attr (arg, BE_GlobalData::REF);
  ACE_CString kind;
  
  switch (node->direction ())
    {
      case AST_Argument::dir_IN:
        kind = "In";
        break;
      case AST_Argument::dir_INOUT:
        kind = "Inout";
        break;
      case AST_Argument::dir_OUT:
        kind = "Out";
        break;
      default:
        break;
    }
    
  kind += "Parameter";
  arg->setAttribute (X ("kind"), X (kind.c_str ()));
  arg->setAttribute (X ("role"), X (kind.c_str ()));
  this->set_relid_attr (arg);
  arg->setAttribute (X ("referred"), this->lookup_id (node->field_type ()));
  this->add_name_element (arg, node->local_name ()->get_string ());
  this->add_regnodes (node->defined_in (), arg, this->rel_id_ - 1);
  
  this->sub_tree_->appendChild (arg);
    
  return 0;
}

int 
picml_visitor::visit_attribute (AST_Attribute *node)
{
  if (node->imported ())
    {
      return 0;
    }
    
  DOMElement *elem = this->doc_->createElement (X ("model"));
  this->set_id_attr (elem, BE_GlobalData::MODEL);
  idl_bool read_only = node->readonly ();
  const char *kind = read_only ? "ReadonlyAttribute" : "Attribute";
  elem->setAttribute (X ("kind"), X (kind));
  elem->setAttribute (X ("role"), X (kind));
  this->set_relid_attr (elem);
  this->set_childrelidcntr_attr (elem, 0, node);
  this->add_name_element (elem, node->local_name ()->get_string ());
  this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
  this->add_replace_id_element (elem, node);
  this->add_version_element (elem, node);
  
  AST_Type *ft = node->field_type ();
  DOMElement *member = this->doc_->createElement (X ("reference"));
  this->set_id_attr (member, BE_GlobalData::REF);
  member->setAttribute (X ("kind"), X ("AttributeMember"));
  member->setAttribute (X ("role"), X ("AttributeMember"));
  member->setAttribute (X ("relid"), X (be_global->hex_string (1UL)));
  this->add_name_element (member, "AttributeMember");
  this->add_regnodes (0, member, 1UL, node);
  member->setAttribute (X ("referred"), this->lookup_id (ft));
  elem->appendChild (member);
  
  UTL_ExceptList *get_ex = node->get_get_exceptions ();
  this->add_exception_elements (elem,
                                0,
                                node,
                                node->get_get_exceptions (),
                                "GetException",
                                2UL);
   
  if (!node->readonly ())
    {
      unsigned long slot =
        (get_ex != 0 ? get_ex->length () : 0) + 2UL;                         
      this->add_exception_elements (
                elem,
                0,
                node,
                node->get_set_exceptions (),
                "SetException",
                slot
              );
    }
  
  this->sub_tree_->appendChild (elem);
  
  return 0;
}

int 
picml_visitor::visit_union (AST_Union *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("model"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::MODEL);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {    
      elem->setAttribute (X ("kind"), X ("SwitchedAggregate"));
      elem->setAttribute (X ("role"), X ("SwitchedAggregate"));
      this->set_relid_attr (elem);
      this->set_childrelidcntr_attr (elem, node);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      this->add_discriminator (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  // If in_recursion() returns TRUE and this node is already in the
  // decl id table, we are in the first level of recursion and do
  // not need to visit the scope.    
  ACE_Unbounded_Queue<AST_Type *> list;
  if (result != 0 && node->in_recursion (list))
    {
      return 0;
    }

  // Bump the rel_id by 1 since we've already added the discriminator.
  picml_visitor scope_visitor (elem, 2UL);
  if (scope_visitor.visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_union - "
                         "codegen for scope failed\n"),
                        -1);
    }
    
  return 0;
}

int 
picml_visitor::visit_union_fwd (AST_UnionFwd *node)
{
  return this->visit_structure_fwd (node);
}

int 
picml_visitor::visit_union_branch (AST_UnionBranch *node)
{
  if (node->imported ())
    {
      return 0;
    }
    
  AST_Type *ft = node->field_type ();
  AST_Decl::NodeType nt = ft->node_type ();
  
  if (nt == AST_Decl::NT_array || nt == AST_Decl::NT_sequence)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_union_branch - "
                         "anonymous types not supported: %s\n",
                         ft->full_name ()),
                        -1);
    }
    
  DOMElement *elem = this->doc_->createElement (X ("reference"));
  ACE_CString id = this->set_id_attr (elem, BE_GlobalData::REF);
  elem->setAttribute (X ("kind"), X ("Member"));
  elem->setAttribute (X ("role"), X ("Member"));
  this->set_relid_attr (elem);
  elem->setAttribute (X ("referred"), this->lookup_id (ft));
  this->add_name_element (elem, node->local_name ()->get_string ());
  unsigned long slot = this->rel_id_ - 1;
  this->add_regnodes (node->defined_in (), elem, slot);
  
  this->sub_tree_->appendChild (elem);
  this->add_labels (node, id, slot);
  
  return 0;
}

int 
picml_visitor::visit_union_label (AST_UnionLabel *)
{
  return 0;
}

int 
picml_visitor::visit_constant (AST_Constant *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("reference"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::REF);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      elem->setAttribute (X ("kind"), X ("Constant"));
      elem->setAttribute (X ("role"), X ("Constant"));
      this->set_relid_attr (elem);
      
      XMLCh *const_type_id = this->lookup_constant_type (node);
      
      if (const_type_id == 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                            "picml_visitor::visit_constant - "
                            "constant type id lookup failed\n"),
                            -1);
        }
        
      elem->setAttribute (X ("referred"), const_type_id);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      this->add_constant_value (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  return 0;
}

int 
picml_visitor::visit_enum_val (AST_EnumVal *node)
{
  // Enum values are also added to the enum's enclosing scope.
  // We don't want to generate anything for these nodes.
  const XMLCh *kind = this->sub_tree_->getAttribute (X ("kind"));
  if (X (kind) != X ("Enum"))
    {
      return 0;
    }
    
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("atom"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::ATOM);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      elem->setAttribute (X ("kind"), X ("EnumValue"));
      elem->setAttribute (X ("role"), X ("EnumValue"));
      this->set_relid_attr (elem);
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      
      this->sub_tree_->appendChild (elem);
    }
    
  return 0;
}

// These next three are all handled elsewhere, if legal
// anonymous sequences and arrays are not supported in
// this visitor.

int 
picml_visitor::visit_array (AST_Array *)
{
  return 0;
}

int 
picml_visitor::visit_sequence (AST_Sequence *)
{
  return 0;
}

int 
picml_visitor::visit_string (AST_String *)
{
  return 0;
}

int 
picml_visitor::visit_typedef (AST_Typedef *node)
{
  DOMElement *elem = 0;
  int result = be_global->decl_elem_table ().find (node->repoID (), elem);

  if (result != 0)
    {
      // Create a DOMElement and a GME id and store them in their
      // respective tables. These actions are idempotent, so we
      // don't care about the return values of bind().
      elem = this->doc_->createElement (X ("reference"));
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
      this->set_id_attr (elem, BE_GlobalData::REF);
      be_global->decl_id_table ().bind (ACE::strnew (node->repoID ()),
                                        elem->getAttribute (X ("id")));
    }
    
  if (!node->imported ())
    {
      AST_Type *bt = node->base_type ();
      const char *role = "Alias";
      
      // Collection types in IDML are generated as IDL typedefs, so we
      // want the reverse of that as the behavior here.
      switch (bt->node_type ())
        {
          case AST_Decl::NT_array:
            role = "Collection";
            bt = AST_Array::narrow_from_decl (bt)->base_type ();
            break;
          case AST_Decl::NT_sequence:
            role = "Collection";
            bt = AST_Sequence::narrow_from_decl (bt)->base_type ();
            break;
          default:
            break;
        }
      
      elem->setAttribute (X ("kind"), X (role));
      elem->setAttribute (X ("role"), X (role));      
      this->set_relid_attr (elem);
      elem->setAttribute (X ("referred"), this->lookup_id (bt));
      this->add_name_element (elem, node->local_name ()->get_string ());
      this->add_regnodes (node->defined_in (), elem, this->rel_id_ - 1);
      this->add_replace_id_element (elem, node);
      this->add_version_element (elem, node);
      
      this->sub_tree_->appendChild (elem);
    }
    
  return 0;
}

int 
picml_visitor::visit_root (AST_Root *node)
{
  static DOMElement *interface_definitions;

  if (be_global->first_file ())
    {
      sub_tree_->setAttribute (X ("guid"),
                               X ("{00000000-0000-0000-0000-000000000000}"));
      
      ACE_TCHAR day_and_time[27];
      ACE_TCHAR *s = this->timestamp (day_and_time, sizeof day_and_time);
      
      sub_tree_->setAttribute (X ("cdate"), X (s));
      sub_tree_->setAttribute (X ("mdate"), X (s));
      sub_tree_->setAttribute (X ("metaguid"), 
                               X ("{1D244777-DEAD-BEEF-FEED-DAD000000001}"));
      sub_tree_->setAttribute (X ("metaname"), X ("PICML"));
      
      ACE_CString project_name = be_global->output_file ();
      this->add_name_element (sub_tree_, project_name.c_str ());
      
      DOMElement *comment = doc_->createElement (X ("comment"));
      DOMText *comment_val = doc_->createTextNode (X (""));
      comment->appendChild (comment_val);
      sub_tree_->appendChild (comment);
      
      DOMElement *author = doc_->createElement (X ("author"));
      DOMText *author_val = doc_->createTextNode (X (""));
      author->appendChild (author_val);
      sub_tree_->appendChild (author);
      
      DOMElement *root_folder = doc_->createElement (X ("folder"));
      this->set_id_attr (root_folder, BE_GlobalData::FOLDER);
      this->set_relid_attr (root_folder);
      root_folder->setAttribute (X ("childrelidcntr"), X ("0x2"));
      root_folder->setAttribute (X ("kind"), X ("RootFolder"));
      sub_tree_->appendChild (root_folder);      
      this->add_name_element (root_folder, project_name.c_str ());     
      this->add_predefined_types (root_folder);   
         
      interface_definitions =
        doc_->createElement (X ("folder"));
      this->set_id_attr (interface_definitions, BE_GlobalData::FOLDER);
      this->set_relid_attr (interface_definitions);
      interface_definitions->setAttribute (
          X ("childrelidcntr"), 
          X (be_global->hex_string (be_global->nfiles ()))
        );
      interface_definitions->setAttribute (X ("kind"), 
                                           X ("InterfaceDefinitions"));
      this->add_name_element (interface_definitions, 
                              "InterfaceDefinitions");
      root_folder->appendChild (interface_definitions);
      
      be_global->first_file (I_FALSE);
    }
    
  // The pass for the first file creates DOM elements at several levels
  // so we have to reset the relative id counter here to get correct
  // values for the File models under InterfaceDefinitions.
  static unsigned long pass = 1UL;
  this->rel_id_ = pass++;
  
  DOMElement *file = this->add_file_element (interface_definitions, node);
  unsigned long start_relid =
    this->user_includes () + this->n_basic_seqs_ + 1UL;
  picml_visitor scope_visitor (file, start_relid);
  
  // Affects the offset when drawing the scope elements.
  scope_visitor.n_basic_seqs_ = this->n_basic_seqs_;
 
  if (scope_visitor.visit_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::visit_root - "
                         "codegen for scope failed\n"),
                        -1);
    }
    
  // Reset this, in case it was modified.  
  this->n_basic_seqs_ = 0UL;

  return 0;
}

int 
picml_visitor::visit_native (AST_Native *)
{
  return 0;
}

int
picml_visitor::visit_valuebox (AST_ValueBox *)
{
  return 0;
}

ACE_CString
picml_visitor::set_id_attr (DOMElement *elem, BE_GlobalData::kind_id kind)
{
  ACE_CString val = be_global->make_gme_id (kind);
  elem->setAttribute (X ("id"), X (val.c_str ()));
  return val;
}

void
picml_visitor::set_relid_attr (DOMElement *elem)
{
  char *hex_relid = be_global->hex_string (this->rel_id_++);
  elem->setAttribute (X ("relid"), X (hex_relid));
}

void
picml_visitor::set_childrelidcntr_attr (DOMElement *elem,
                                       UTL_Scope *s,
                                       AST_Attribute *a)
{
  unsigned long nkids = this->nmembers_gme (s, a);
  
  if (s != 0)
    {
      AST_Decl::NodeType nt = ScopeAsDecl (s)->node_type ();
      AST_Decl *d = 0;
      
      for (UTL_ScopeActiveIterator i (s, UTL_Scope::IK_decls);
          !i.is_done ();
          i.next ())
        {
          d = i.item ();
        
          if (nt == AST_Decl::NT_union)
            {
              // Add 2 (atom & connection) for each label of each union member.
              // Increment for the discriminator is made in nmembers_gme().
              AST_UnionBranch *ub =
                AST_UnionBranch::narrow_from_decl (d);
                
              nkids += 2 * ub->label_list_length ();
            }
          else if (nt == AST_Decl::NT_valuetype || nt == AST_Decl::NT_eventtype)
            {
              AST_Field *f = AST_Field::narrow_from_decl (d);
              
              // One for the private flag and one for the connection.
              if (f != 0 && f->visibility () == AST_Field::vis_PRIVATE)
                {
                  nkids += 2;
                }
            }
          else if (nt == AST_Decl::NT_root || nt == AST_Decl::NT_module)
            {
              if (d->node_type () == AST_Decl::NT_home)
                {
                  // One for the connection to the managed component.
                  ++nkids;
                  AST_Home *h = AST_Home::narrow_from_decl (d);
                  AST_Component *c = h->managed_component ();
                  
                  if (h->defined_in () != c->defined_in ())
                    {
                      // One for the ComponentRef we create if the managed
                      // component is not in the same scope as the home.
                      ++nkids;
                    }
                }
            }
        }
    }
     
  char *hex_nkids = be_global->hex_string (nkids);   
  elem->setAttribute (X ("childrelidcntr"), X (hex_nkids));
}

void
picml_visitor::add_name_element (DOMElement *elem, const char *name)
{
  DOMElement *elem_name = doc_->createElement (X ("name"));
  DOMText *elem_name_val = doc_->createTextNode (X (name));
  elem_name->appendChild (elem_name_val);
  elem->appendChild (elem_name);
}

void
picml_visitor::add_predefined_types (DOMElement *root_folder)
{
  DOMElement *pdt_folder = doc_->createElement (X ("folder"));
  this->set_id_attr (pdt_folder, BE_GlobalData::FOLDER);
  pdt_folder->setAttribute (X ("relid"), X ("0x1"));
  
  unsigned long npdt = be_global->npredefined ();
  pdt_folder->setAttribute (X ("childrelidcntr"),
                            X (be_global->hex_string (npdt)));
                            
  pdt_folder->setAttribute (X ("kind"), X ("PredefinedTypes"));
  this->add_name_element (pdt_folder, "PredefinedTypes");
  
  for (unsigned long i = 0; i < npdt; ++i)
    {
      DOMElement *pdt = doc_->createElement (X ("atom"));
      this->set_id_attr (pdt, BE_GlobalData::ATOM);
      pdt->setAttribute (X ("kind"), X (be_global->pdt_names ()[i]));
      
      // Store the GME id for possible rererence by other XML elements.
      be_global->decl_id_table ().bind (ACE::strnew (be_global->pdt_names ()[i]),
                                        pdt->getAttribute (X ("id")));
                                        
      // The relid attributes are numbered in reverse order in all sample
      // files - don't know if it's true for all attached libraries or not.
      char *relid_str = be_global->hex_string (npdt - i);
      pdt->setAttribute (X ("relid"), X (relid_str));
      
      this->add_name_element (pdt, be_global->pdt_names ()[i]);
      
      pdt_folder->appendChild (pdt);
    }
  
  root_folder->appendChild (pdt_folder);
}

void
picml_visitor::add_predefined_sequences (DOMElement *parent, 
                                         AST_Root *node)
{
  this->set_n_basic_seqs ();
  unsigned long slot = 1UL;
    
  if (idl_global->string_seq_seen_
      || idl_global->wstring_seq_seen_)
    {
      this->add_one_predefined_sequence (parent, node, 
                                         "String",
                                         slot,
                                         2UL);
    }
    
  if (idl_global->long_seq_seen_
      || idl_global->ulong_seq_seen_
      || idl_global->longlong_seq_seen_
      || idl_global->ulonglong_seq_seen_)
    {
      this->add_one_predefined_sequence (parent,
                                         node,
                                         "LongInteger",
                                         slot,
                                         6UL);
    }
    
  if (idl_global->float_seq_seen_
      || idl_global->double_seq_seen_
      || idl_global->longdouble_seq_seen_)
    {
      this->add_one_predefined_sequence (parent,
                                         node,
                                         "RealNumber",
                                         slot,
                                         5UL);
    }
    
  if (idl_global->short_seq_seen_
      || idl_global->ushort_seq_seen_)
    {
      this->add_one_predefined_sequence (parent,
                                         node,
                                         "ShortInteger",
                                         slot,
                                         4UL);
    }  
    
  if (idl_global->char_seq_seen_
      || idl_global->wchar_seq_seen_
      || idl_global->octet_seq_seen_)
    {
      this->add_one_predefined_sequence (parent,
                                         node,
                                         "Byte",
                                         slot,
                                         10UL);
    }
    
  if (idl_global->boolean_seq_seen_)
    {
      this->add_one_predefined_sequence (parent,
                                         node,
                                         "Boolean",
                                         slot,
                                         3UL);
    }  
    
  if (idl_global->any_seq_seen_)
    {
      this->add_one_predefined_sequence (parent,
                                         node,
                                         "GenericValue",
                                         slot,
                                         8UL);
    }  
}

void
picml_visitor::add_one_predefined_sequence (DOMElement *parent,
                                            AST_Root *node,
                                            const char *type,
                                            unsigned long &model_slot,
                                            unsigned long pdt_slot)
{
  // Can't create a basic type sequence more than once in a project.
  // A processed basic type sequence is stored by its GME id.
  XMLCh *gme_id = 0;
  ACE_CString name (type);
  name += be_global->basic_seq_suffix ();
  int result = be_global->decl_id_table ().find (name.c_str (), gme_id);
  
  if (result == 0)
    {
      return;
    }
  
  DOMElement *seq = 0;
  result = be_global->decl_elem_table ().find (name.c_str (), seq);
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "picml_visitor::add_one_predefined_sequence - "
                  "lookup of sequence DOCElement %s failed\n",
                  name.c_str ()));
      return;
    }
    
  this->set_id_attr (seq, BE_GlobalData::REF);
  seq->setAttribute (X ("relid"), X (be_global->hex_string (model_slot)));
  seq->setAttribute (X ("kind"), X ("Collection"));
  seq->setAttribute (X ("role"), X ("Collection"));
  
  const char **pdts = be_global->pdt_names ();
  XMLCh *pdt_id = 0;
  result = be_global->decl_id_table ().find (pdts[pdt_slot], pdt_id);
  
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "picml_visitor::add_one_predefined_sequence - "
                  "lookup of base type id %s failed\n",
                  type));
      return;
    }
    
  seq->setAttribute (X ("referred"), pdt_id);
  
  this->add_name_element (seq, name.c_str ());
  this->add_regnodes (node, seq, model_slot);
  ++model_slot;
  
  be_global->decl_id_table ().bind (ACE::strnew (name.c_str ()),
                                                 seq->getAttribute (X ("id")));
  
  parent->appendChild (seq);
}

DOMElement *
picml_visitor::add_file_element (DOMElement *parent, AST_Root *node)
{
  ACE_CString tmp (idl_global->stripped_filename ()->get_string ());
  tmp = tmp.substr (0, tmp.rfind ('.'));
  const char *tmp_cstr = tmp.c_str ();
  
  DOMElement *file = 0;
  int result = be_global->decl_elem_table ().find (tmp_cstr, file);

  // All files should have been stored as part of BE_init(). If 
  // this lookup fails, we will crash if we continue.
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Error: file %s not found in decl table\n",
                  tmp_cstr));
                        
      exit (99);
    }
    
  this->set_relid_attr (file);
  file->setAttribute (X ("kind"), X ("File"));
  
  XMLCh *file_id = 0;
  result = be_global->decl_id_table ().find (tmp_cstr, file_id);
  
  // All files should have been stored as part of BE_init(). If 
  // this lookup fails, we will crash if we continue.
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "Error: file %s id not found in id table\n",
                  tmp_cstr));
                        
      exit (99);
    }
    
  file->setAttribute (X ("id"), file_id);
  this->add_name_element (file, tmp_cstr);
  this->add_prefix_element (file, node);
  
  // This has to come before add_include_elements, because it adjusts
  // the number of members, but only for the first file processed.
  this->add_predefined_sequences (file, node);
  
  // This has to come after add_predefined_sequences, to get the possibly
  // updated number of members.
  this->set_childrelidcntr_attr (file, node);
  
  this->add_include_elements (node, file);
  
  parent->appendChild (file);
  
  return file;
}

void
picml_visitor::add_prefix_element (DOMElement *parent, AST_Decl *node)
{
  const char *prefix = node->prefix ();
  
  if (node->typeid_set ())
    {
      // SpecifyIdTag will handle it.
      prefix = "";
    }
  else
    {
      UTL_Scope *s = node->defined_in ();
      
      // If our prefix was set in an outer scope (or not set at all), we
      // should set it to the empty string here.
      if (s != 0)
        {
          if (ACE_OS::strcmp (prefix, ScopeAsDecl (s)->prefix ()) == 0)
            {
              prefix = "";
            }
        }
    }
    
  this->add_tag_common (prefix, "PrefixTag", parent);  
}

void
picml_visitor::add_replace_id_element (DOMElement *parent, AST_Decl *node)
{
  const char *id = 0;
  
  if (node == 0 || !node->typeid_set ())
    {
      id = "";
    }
  else
    {
      id = node->prefix ();
    }
    
  this->add_tag_common (id, "SpecifyIdTag", parent);  
}

void
picml_visitor::add_version_element (DOMElement *parent, AST_Decl *node)
{
  const char *version = 0;
  
  if (node == 0)
    {
      version = "";
    }
  else
    {
      version = node->version ();
   
      // If it's the default version, set the attribute to the empty string.
      if (ACE_OS::strcmp (version, "1.0") == 0)
        {
          version = "";
        }
   }
    
  this->add_tag_common (version, "VersionTag", parent);  
}

void
picml_visitor::add_tag_common (const char *value,
                              const char *name,
                              DOMElement *parent,
                              idl_bool is_meta)
{
  DOMElement *tag_elem = this->doc_->createElement (X ("attribute"));
  tag_elem->setAttribute (X ("kind"), X (name));
  
  if (is_meta)
    {
      tag_elem->setAttribute (X ("status"), X("meta"));
    }
    
  DOMElement *value_elem = this->doc_->createElement (X ("value"));
  DOMText *tag_value = this->doc_->createTextNode (X (value));
  
  value_elem->appendChild (tag_value);
  tag_elem->appendChild (value_elem);
  parent->appendChild (tag_elem);  
}

void
picml_visitor::add_local_element (DOMElement *parent, AST_Decl *node)
{
  const char *value = (node->is_local () ? "true" : "false");
  this->add_tag_common (value, "local", parent);
}

void
picml_visitor::add_abstract_element (DOMElement *parent, AST_Decl *node)
{
  const char *value = (node->is_abstract () ? "true" : "false");
  this->add_tag_common (value, "abstract", parent);
}

void
picml_visitor::add_include_elements (UTL_Scope *container, DOMElement *parent)
{
  idl_global->validate_included_idl_files ();
  unsigned long slot = this->n_basic_seqs_ + 1UL;
  
  for (size_t i = 0; i < idl_global->n_included_idl_files (); ++i)
    {
      ACE_CString fname (idl_global->included_idl_files ()[i]);
      int pos = fname.rfind ('/');
      ACE_CString lname =
        (pos == ACE_CString::npos ? fname : fname.substr (pos + 1));
        
      // Types in these files should never be referenced in application
      // IDL files, so we don't included references to the files in the
      // PICML model.  
      if (lname == "Components.idl" || lname == "orb.idl")
        {
          continue;
        }
       
      // The only types from these files that are referenced directly are
      // the sequences of basic types, which will probably be added to
      // the basic types library in PICML.  
      if (lname.find (".pidl") != ACE_CString::npos)
        {
          continue;
        }
        
      DOMElement *fileref = this->doc_->createElement (X ("reference"));
      this->set_id_attr (fileref, BE_GlobalData::REF);
      const char *hex_rel_id = be_global->hex_string (slot);
      fileref->setAttribute (X ("relid"), X (hex_rel_id));
      ++this->rel_id_;
      fileref->setAttribute (X ("kind"), X ("FileRef"));
      fileref->setAttribute (X ("role"), X ("FileRef"));
      
      ACE_CString lname_noext = lname.substr (0, lname.rfind ('.'));
      const char *tmp = lname_noext.c_str ();
      XMLCh *id = 0;
      
      int result =
        be_global->decl_id_table ().find (tmp, id);
        
      if (result != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "Error: Filename %s, included in %s, not found "
                      "in id table. %s was omitted from command line "
                      "or spelling differs in case.\n",
                      lname.c_str (),
                      idl_global->filename ()->get_string (),
                      lname.c_str ()));
          
          exit (99);
        }
      
      fileref->setAttribute (X ("referred"), id);
      this->add_name_element (fileref, "FileRef");
      this->add_regnodes (container, fileref, slot++);
      
      parent->appendChild (fileref);
    }
}

void
picml_visitor::add_regnodes (UTL_Scope *container,
                            DOMElement *parent,
                            size_t slot,
                            AST_Attribute *a,
                            idl_bool is_connected)
{
  DOMElement *outer = this->doc_->createElement (X ("regnode"));
  outer->setAttribute (X ("name"), X ("PartRegs"));
  outer->setAttribute (X ("isopaque"), X ("yes"));
  DOMElement *ovalue = this->doc_->createElement (X ("value"));
  DOMText *oval = this->doc_->createTextNode (X (""));
  ovalue->appendChild (oval);
  outer->appendChild (ovalue);
  
  DOMElement *middle = this->doc_->createElement (X ("regnode"));
  middle->setAttribute (X ("name"), X ("InterfaceDefinition"));
  middle->setAttribute (X ("isopaque"), X ("yes"));
  DOMElement *mvalue = this->doc_->createElement (X ("value"));
  DOMText *mval = this->doc_->createTextNode (X (""));
  mvalue->appendChild (mval);
  middle->appendChild (mvalue);
  
  DOMElement *inner = this->doc_->createElement (X ("regnode"));
  inner->setAttribute (X ("name"), X ("Position"));
  inner->setAttribute (X ("isopaque"), X ("yes"));
  DOMElement *ivalue = this->doc_->createElement (X ("value"));
  
  this->add_pos_element (container, ivalue, slot, a, is_connected);

  inner->appendChild (ivalue);
  middle->appendChild (inner);

  outer->appendChild (middle);
  parent->appendChild (outer);
}

void
picml_visitor::add_pos_element (UTL_Scope *container, 
                               DOMElement *parent,
                               size_t slot,
                               AST_Attribute *a,
                               idl_bool is_connected)
{
  static char holder[9];
  ACE_OS::memset (holder,
                  '\0',
                  9);
  
  unsigned long nslices = this->nmembers_gme (container, a) + 1;
    
  unsigned long slice_width = XMAX_ / nslices;
  unsigned long slice_height = YMAX_ / nslices;
  
  // Icons are positioned according to their upper left corners,
  // so we subtract half the size in each dimention.
  unsigned long xpos = slot * slice_width - ICON_SIZE_ / 2;
  unsigned long ypos = slot * slice_height - ICON_SIZE_ / 2;
  
  // If we are connected to the first element in the scope, we draw ourselves
  // 200 pixels to the right of the element, otherwise we draw ourselves one
  // slice width to the left.
  if (is_connected)
    {
      if (this->rel_id_ == 2UL)
        {
          xpos += 200;
        }
      else
        {
          xpos -= slice_width;
        }
    }
  
  ACE_OS::sprintf (holder, "%d,%d", xpos, ypos);
  DOMText *coordinates = this->doc_->createTextNode (X (holder));
  parent->appendChild (coordinates);
}

void
picml_visitor::add_inherited_elements (DOMElement *parent, AST_Interface *node)
{
  for (long i = 0; i < node->n_inherits (); ++i)
    {
      AST_Interface *p = node->inherits ()[i];
      unsigned long slot = static_cast<unsigned long> (i + 1);
      this->add_one_inherited (parent, node, p, slot);
    }
}

void
picml_visitor::add_one_inherited (DOMElement *parent,
                                 AST_Interface *node,
                                 AST_Interface *base,
                                 unsigned long slot)
{
  DOMElement *elem = this->doc_->createElement (X ("reference"));
  this->set_id_attr (elem, BE_GlobalData::REF);
  elem->setAttribute (X ("kind"), X ("Inherits"));
  elem->setAttribute (X ("role"), X ("Inherits"));
  const char *hex_rel_id = be_global->hex_string (slot);
  elem->setAttribute (X ("relid"), X (hex_rel_id));
  
  XMLCh *id = 0;
  int result = be_global->decl_id_table ().find (base->repoID (), id);
                                      
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "picml_visitor::add_one_inherited - "
                  "lookup of parent %s failed\n",
                  base->full_name ()));
    }
    
  elem->setAttribute (X ("referred"), id);
  this->add_name_element (elem, "Inherits");
  
  // We'll let the parent interfaces be in the upper left of the
  // Model Editor so we can just pass the index as the slot.
  this->add_regnodes (node, elem, slot);
  
  parent->appendChild (elem);
}

void
picml_visitor::add_supported_elements (DOMElement *parent,
                                      AST_Interface *node,
                                      AST_Interface **supports,
                                      long n_supports)
{
  unsigned long nparents = 0;
  
  switch (node->node_type ())
    {
      case AST_Decl::NT_interface:
      case AST_Decl::NT_valuetype:
      case AST_Decl::NT_eventtype:
        nparents = static_cast<unsigned long> (node->n_inherits ());
        break;
      case AST_Decl::NT_component:
        {
          AST_Component *c = AST_Component::narrow_from_decl (node);
          nparents = (c->base_component () == 0 ? 0 : 1);
          break;
        }
      case AST_Decl::NT_home:
        {
          AST_Home *h = AST_Home::narrow_from_decl (node);
          nparents = (h->base_home () == 0 ? 0 : 1);
          break;
        }
      default:
        break;
    }
    
  for (unsigned long i = 0; i < static_cast<unsigned long> (n_supports); ++i)
    {
      DOMElement *supported = this->doc_->createElement (X ("reference"));
      this->set_id_attr (supported, BE_GlobalData::REF);
      supported->setAttribute (X ("kind"), X ("Supports"));
      supported->setAttribute (X ("role"), X ("Supports"));
      supported->setAttribute (X ("relid"),
                               X (be_global->hex_string (nparents + i + 1)));
      supported->setAttribute (X ("referred"),
                               this->lookup_id (supports[i]));
      this->add_name_element (supported, "Supports");
      this->add_regnodes (node, supported, nparents + i + 1);
      parent->appendChild (supported);
    }
}

void
picml_visitor::add_exception_elements (DOMElement *parent,
                                      UTL_Scope *s,
                                      AST_Attribute *a,
                                      UTL_ExceptList *el,
                                      const char *name,
                                      unsigned long start_slot)
{
  for (UTL_ExceptlistActiveIterator ei (el);
       !ei.is_done ();
       ei.next ())
    {
      DOMElement *elem = this->doc_->createElement (X ("reference"));
      this->set_id_attr (elem, BE_GlobalData::REF);
      elem->setAttribute (X ("kind"), X (name));
      elem->setAttribute (X ("role"), X (name));
      elem->setAttribute (X ("relid"), 
                          X (be_global->hex_string (start_slot)));
      elem->setAttribute (X ("referred"), this->lookup_id (ei.item ()));
      this->add_name_element (elem, name);
      this->add_regnodes (s, elem, start_slot++, a);
      parent->appendChild (elem);
    }
}

void
picml_visitor::add_constant_value (DOMElement *parent, AST_Constant *c)
{
  AST_Expression *cv = c->constant_value ();
  ACE_CString value = (c->et () == AST_Expression::EV_enum
                       ? this->print_scoped_name (cv->n ())
                       : this->expr_val_to_string (cv->ev ()));
  this->add_tag_common (value.c_str (), "value", parent, I_FALSE);
}

void
picml_visitor::add_discriminator (DOMElement *parent, AST_Union *u)
{
  DOMElement *elem = this->doc_->createElement (X ("reference"));
  this->set_id_attr (elem, BE_GlobalData::REF);
  elem->setAttribute (X ("kind"), X ("Discriminator"));
  elem->setAttribute (X ("role"), X ("Discriminator"));
  elem->setAttribute (X ("relid"), 
                      X (be_global->hex_string (1UL)));
  elem->setAttribute (X ("referred"), this->lookup_id (u->disc_type ()));
  this->add_name_element (elem, "Discriminator");
  this->add_regnodes (u, elem, 1UL);
  parent->appendChild (elem);
}

void
picml_visitor::add_labels (AST_UnionBranch *ub,
                          ACE_CString &ub_id,
                          unsigned long member_slot)
{
  UTL_Scope *u = ub->defined_in ();
  unsigned long label_base = this->nmembers_gme (u) + member_slot - 1;

  for (unsigned long i = 0; i < ub->label_list_length (); ++i)
    {
      DOMElement *label = this->doc_->createElement (X ("atom"));
      ACE_CString label_id = this->set_id_attr (label, BE_GlobalData::ATOM);
      label->setAttribute (X ("kind"), X ("Label"));
      label->setAttribute (X ("role"), X ("Label"));
      label->setAttribute(X ("relid"),
                          X (be_global->hex_string (label_base + 2 * i)));
      this->add_label_name (label, ub->label (i), u);
      this->add_regnodes (u, label, member_slot, 0, I_TRUE);
      this->sub_tree_->appendChild (label);
      
      DOMElement *connection = this->doc_->createElement (X ("connection"));
      this->set_id_attr (connection, BE_GlobalData::CONN);
      connection->setAttribute (X ("kind"), X ("LabelConnection"));
      connection->setAttribute (X ("role"), X ("LabelConnection"));
      connection->setAttribute(X ("relid"),
                               X (be_global->hex_string (label_base + 2 * i + 1)));
      this->add_name_element (connection, "LabelConnection");
      
      DOMElement *conn_reg = this->doc_->createElement (X ("regnode"));
      conn_reg->setAttribute (X ("name"), X ("autorouterPref"));
      conn_reg->setAttribute (X ("isopaque"), X ("yes"));
      DOMElement *conn_value = this->doc_->createElement (X ("value"));
      DOMText *val = this->doc_->createTextNode (X ("We"));
      conn_value->appendChild (val);
      conn_reg->appendChild (conn_value);
      connection->appendChild (conn_reg);
      
      DOMElement *dst = this->doc_->createElement (X ("connpoint"));
      dst->setAttribute (X ("role"), X ("dst"));
      dst->setAttribute (X ("target"), X (label_id.c_str ()));
      connection->appendChild (dst);
      
      DOMElement *src = this->doc_->createElement (X ("connpoint"));
      src->setAttribute (X ("role"), X ("src"));
      src->setAttribute (X ("target"), X (ub_id.c_str ()));
      connection->appendChild (src);
      
      this->sub_tree_->appendChild (connection);
    }
}

void
picml_visitor::add_label_name (DOMElement *label, AST_UnionLabel *ul, UTL_Scope *s)
{
  ACE_CString name;
  AST_Expression *e = ul->label_val ();
  AST_Union *u = AST_Union::narrow_from_scope (s);
  
  if (ul->label_kind () == AST_UnionLabel::UL_default)
    {
      name = "default";
    }
  else
    {
      if (u->disc_type ()->node_type () == AST_Decl::NT_enum)
        {
          UTL_Scope *parent = u->disc_type ()->defined_in ();
          
          if (parent == 0)
            {
              name = this->print_scoped_name (e->n ());
            }
          else
            {
              if (ScopeAsDecl (parent)->node_type () != AST_Decl::NT_root)
                {
                  name = 
                    this->print_scoped_name (ScopeAsDecl (parent)->name ());
                  name += "::";
                }
                
              name += e->n ()->last_component ()->get_string ();
            }
        }
      else
        {
          name = this->expr_val_to_string (ul->label_val ()->ev ());
        }
    }
    
  this->add_name_element (label, name.c_str ());
}

void
picml_visitor::add_private (AST_Field *f,
                           ACE_CString &id,
                           unsigned long member_slot)
{
  unsigned long base = this->nmembers_gme (f->defined_in ())
                       + this->private_relid_offset_
                       + 1;

  DOMElement *pflag = this->doc_->createElement (X ("atom"));
  ACE_CString flag_id = this->set_id_attr (pflag, BE_GlobalData::ATOM);
  pflag->setAttribute (X ("kind"), X ("PrivateFlag"));
  pflag->setAttribute (X ("role"), X ("PrivateFlag"));
  pflag->setAttribute (X ("relid"),
                       X (be_global->hex_string (base++)));
  ++this->private_relid_offset_;
  this->add_name_element (pflag, "PrivateFlag");
  this->add_regnodes (f->defined_in (), pflag, this->rel_id_ - 1, 0, I_TRUE);
  
  DOMElement *connection = this->doc_->createElement (X ("connection"));
  this->set_id_attr (connection, BE_GlobalData::CONN);
  connection->setAttribute (X ("kind"), X ("MakeMemberPrivate"));
  connection->setAttribute (X ("role"), X ("MakeMemberPrivate"));
  connection->setAttribute (X ("relid"),
                            X (be_global->hex_string (base)));
  ++this->private_relid_offset_;
  this->add_name_element (connection, "MakeMemberPrivate");
  
  DOMElement *conn_reg = this->doc_->createElement (X ("regnode"));
  conn_reg->setAttribute (X ("name"), X ("autorouterPref"));
  conn_reg->setAttribute (X ("isopaque"), X ("yes"));
  DOMElement *conn_value = this->doc_->createElement (X ("value"));
  DOMText *val = this->doc_->createTextNode (X ("We"));
  conn_value->appendChild (val);
  conn_reg->appendChild (conn_value);
  connection->appendChild (conn_reg);
  
  DOMElement *dst = this->doc_->createElement (X ("connpoint"));
  dst->setAttribute (X ("role"), X ("dst"));
  dst->setAttribute (X ("target"), X (flag_id.c_str ()));
  connection->appendChild (dst);
  
  DOMElement *src = this->doc_->createElement (X ("connpoint"));
  src->setAttribute (X ("role"), X ("src"));
  src->setAttribute (X ("target"), X (id.c_str ()));
  connection->appendChild (src);
  
  this->sub_tree_->appendChild (pflag);
  this->sub_tree_->appendChild (connection);
}

void
picml_visitor::add_base_component (DOMElement *elem, AST_Component *node)
{
  AST_Component *base = node->base_component ();
  if (base == 0)
    {
      return;
    }

  XMLCh *id = 0;
  int result = be_global->decl_id_table ().find (base->repoID (), id);
                                      
  if (result != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "picml_visitor::add_base_component - "
                  "lookup of parent %s failed\n",
                  base->full_name ()));
    }
    
  // XML generated from GEM models has these attributes also for
  // derived ports, but it seems we don't need all that for
  // correct importing, so we just generate the attributes for
  // the derived component.  
  elem->setAttribute (X ("derivedfrom"), id);
  elem->setAttribute (X ("isinstance"), X ("no"));
  elem->setAttribute (X ("isprimary"), X ("yes"));
}

void
picml_visitor::add_base_home (DOMElement *parent, AST_Home *node)
{
  AST_Home *base = node->base_home ();
  if (base == 0)
    {
      return;
    }
    
  this->add_one_inherited (parent, node, base, 1UL);
}

void
picml_visitor::add_ports (DOMElement *parent, AST_Component *node)
{
  AST_Component::port_description *pd = 0;
  unsigned long slot = (node->base_component () == 0 ? 0 : 1)
                       + node->n_supports ()
                       + 1;

  // Provides ports.
  for (PORT_ITER provides_iter (node->provides ());
       ! provides_iter.done ();
       provides_iter.advance ())
    {
      provides_iter.next (pd);
      DOMElement *provides_port =
        this->doc_->createElement (X ("reference"));
      this->set_id_attr (provides_port, BE_GlobalData::REF);
      provides_port->setAttribute (X ("kind"), X ("ProvidedRequestPort"));
      provides_port->setAttribute (X ("role"), X ("ProvidedRequestPort"));
      provides_port->setAttribute (X ("relid"),
                                   X (be_global->hex_string (slot)));
      provides_port->setAttribute (X ("referred"),
                                   this->lookup_id (pd->impl));
      this->add_name_element (provides_port, pd->id->get_string ());
      this->add_regnodes (node, provides_port, slot++);
      this->add_replace_id_element (provides_port, 0);
      this->add_version_element (provides_port, 0);
      parent->appendChild (provides_port);
    }

  // Uses ports.
  for (PORT_ITER uses_iter (node->uses ());
       ! uses_iter.done ();
       uses_iter.advance ())
    {
      uses_iter.next (pd);
      DOMElement *uses_port =
        this->doc_->createElement (X ("reference"));
      this->set_id_attr (uses_port, BE_GlobalData::REF);
      uses_port->setAttribute (X ("kind"), X ("RequiredRequestPort"));
      uses_port->setAttribute (X ("role"), X ("RequiredRequestPort"));
      uses_port->setAttribute (X ("relid"),
                               X (be_global->hex_string (slot)));
      uses_port->setAttribute (X ("referred"),
                               this->lookup_id (pd->impl));
      this->add_name_element (uses_port, pd->id->get_string ());
      this->add_regnodes (node, uses_port, slot++);
      this->add_replace_id_element (uses_port, 0);
      this->add_version_element (uses_port, 0);
      DOMElement *mult_attr = this->doc_->createElement (X ("attribute"));
      mult_attr->setAttribute (X ("kind"), X ("multiple_connections"));
      DOMElement *value_elem = this->doc_->createElement (X ("value"));
      DOMText *value =
        this->doc_->createTextNode (X (pd->is_multiple ? "true" : "false"));
      value_elem->appendChild (value);
      mult_attr->appendChild (value_elem);
      uses_port->appendChild (mult_attr);
      parent->appendChild (uses_port);
    }

  // Emits ports.
  for (PORT_ITER emits_iter (node->emits ());
       ! emits_iter.done ();
       emits_iter.advance ())
    {
      emits_iter.next (pd);
      DOMElement *emits_port =
        this->doc_->createElement (X ("reference"));
      this->set_id_attr (emits_port, BE_GlobalData::REF);
      emits_port->setAttribute (X ("kind"), X ("OutEventPort"));
      emits_port->setAttribute (X ("role"), X ("OutEventPort"));
      emits_port->setAttribute (X ("relid"),
                                X (be_global->hex_string (slot)));
      emits_port->setAttribute (X ("referred"),
                                this->lookup_id (pd->impl));
      this->add_name_element (emits_port, pd->id->get_string ());
      this->add_regnodes (node, emits_port, slot++);
      this->add_replace_id_element (emits_port, 0);
      this->add_version_element (emits_port, 0);
      DOMElement *single_attr = this->doc_->createElement (X ("attribute"));
      single_attr->setAttribute (X ("kind"), X ("single_destination"));
      DOMElement *value_elem = this->doc_->createElement (X ("value"));
      DOMText *value = this->doc_->createTextNode (X ("true"));
      value_elem->appendChild (value);
      single_attr->appendChild (value_elem);
      emits_port->appendChild (single_attr);
      parent->appendChild (emits_port);
    }

  // Publishes ports.
  for (PORT_ITER publishes_iter (node->publishes ());
       ! publishes_iter.done ();
       publishes_iter.advance ())
    {
      publishes_iter.next (pd);
      DOMElement *publishes_port =
        this->doc_->createElement (X ("reference"));
      this->set_id_attr (publishes_port, BE_GlobalData::REF);
      publishes_port->setAttribute (X ("kind"), X ("OutEventPort"));
      publishes_port->setAttribute (X ("role"), X ("OutEventPort"));
      publishes_port->setAttribute (X ("relid"),
                                    X (be_global->hex_string (slot)));
      publishes_port->setAttribute (X ("referred"),
                                    this->lookup_id (pd->impl));
      this->add_name_element (publishes_port, pd->id->get_string ());
      this->add_regnodes (node, publishes_port, slot++);
      this->add_replace_id_element (publishes_port, 0);
      this->add_version_element (publishes_port, 0);
      DOMElement *single_attr = this->doc_->createElement (X ("attribute"));
      single_attr->setAttribute (X ("kind"), X ("single_destination"));
      DOMElement *value_elem = this->doc_->createElement (X ("value"));
      DOMText *value = this->doc_->createTextNode (X ("false"));
      value_elem->appendChild (value);
      single_attr->appendChild (value_elem);
      publishes_port->appendChild (single_attr);
      parent->appendChild (publishes_port);
    }

  // Consumes ports.
  for (PORT_ITER consumes_iter (node->consumes ());
       ! consumes_iter.done ();
       consumes_iter.advance ())
    {
      consumes_iter.next (pd);
      DOMElement *consumes_port =
        this->doc_->createElement (X ("reference"));
      this->set_id_attr (consumes_port, BE_GlobalData::REF);
      consumes_port->setAttribute (X ("kind"), X ("InEventPort"));
      consumes_port->setAttribute (X ("role"), X ("InEventPort"));
      consumes_port->setAttribute (X ("relid"),
                                   X (be_global->hex_string (slot)));
      consumes_port->setAttribute (X ("referred"),
                                   this->lookup_id (pd->impl));
      this->add_name_element (consumes_port, pd->id->get_string ());
      this->add_regnodes (node, consumes_port, slot++);
      this->add_replace_id_element (consumes_port, 0);
      this->add_version_element (consumes_port, 0);
      parent->appendChild (consumes_port);
    }
}

void
picml_visitor::add_manages (AST_Home *node)
{
  UTL_Scope *s = node->defined_in ();
  unsigned long base = this->nmembers_gme (s)
                       + this->manages_relid_offset_
                       + 1;

  DOMElement *connection = this->doc_->createElement (X ("connection"));
  this->set_id_attr (connection, BE_GlobalData::CONN);
  connection->setAttribute (X ("kind"), X ("ManagesComponent"));
  connection->setAttribute (X ("role"), X ("ManagesComponent"));
  connection->setAttribute (X ("relid"),
                            X (be_global->hex_string (base++)));
  ++this->manages_relid_offset_;
  this->add_name_element (connection, "ManagesComponent");
  
  DOMElement *conn_reg = this->doc_->createElement (X ("regnode"));
  conn_reg->setAttribute (X ("name"), X ("autorouterPref"));
  conn_reg->setAttribute (X ("isopaque"), X ("yes"));
  DOMElement *conn_value = this->doc_->createElement (X ("value"));
  DOMText *val = this->doc_->createTextNode (X ("Ws"));
  conn_value->appendChild (val);
  conn_reg->appendChild (conn_value);
  connection->appendChild (conn_reg);
  
  AST_Component *c = node->managed_component ();
  const XMLCh *comp_id = this->lookup_id (c);
  idl_bool same_scope = (c->defined_in () == s);
  ACE_CString comp_ref_id;
  
  if (!same_scope)
    {
      // Create a ComponentRef node and make that the dst end of the
      // ManagesComponent connection.
      DOMElement *comp_ref = this->doc_->createElement (X ("reference"));
      comp_ref_id = this->set_id_attr (comp_ref, BE_GlobalData::REF);
      comp_ref->setAttribute (X ("kind"), X ("ComponentRef"));
      comp_ref->setAttribute (X ("role"), X ("ComponentRef"));
      comp_ref->setAttribute (X ("relid"),
                              X (be_global->hex_string (base)));
      ++this->manages_relid_offset_;
      comp_ref->setAttribute (X ("referred"), comp_id);
      this->add_name_element (comp_ref, "ComponentRef");
      this->add_regnodes (s, comp_ref, this->rel_id_ - 1, 0, I_TRUE);
      this->sub_tree_->appendChild (comp_ref);
    }
  
  DOMElement *dst = this->doc_->createElement (X ("connpoint"));
  dst->setAttribute (X ("role"), X ("dst"));
  dst->setAttribute (X ("target"),
                     same_scope ? comp_id : X (comp_ref_id.c_str ()));
  connection->appendChild (dst);
  
  DOMElement *src = this->doc_->createElement (X ("connpoint"));
  src->setAttribute (X ("role"), X ("src"));
  src->setAttribute (X ("target"), this->lookup_id (node));
  connection->appendChild (src);
  
  this->sub_tree_->appendChild (connection);
}

void
picml_visitor::add_lookup_key (DOMElement *parent, AST_Home *node)
{
  AST_ValueType *pk = node->primary_key ();
  if (pk == 0)
    {
      return;
    }
    
  unsigned long slot = (node->base_home () == 0 ? 0UL : 1UL)
                       + static_cast<unsigned long> (node->n_supports ())
                       + 1;
                       
  DOMElement *lookup_key = this->doc_->createElement (X ("reference"));
  this->set_id_attr (lookup_key, BE_GlobalData::REF);
  lookup_key->setAttribute (X ("kind"), X ("LookupKey"));
  lookup_key->setAttribute (X ("role"), X ("LookupKey"));
  lookup_key->setAttribute (X ("relid"), X (be_global->hex_string (slot)));
  lookup_key->setAttribute (X ("referred"), this->lookup_id (pk ));
  this->add_name_element (lookup_key, "LookupKey");
  this->add_regnodes (node, lookup_key, slot);
  parent->appendChild (lookup_key);
}

void
picml_visitor::add_home_factories (DOMElement *parent, AST_Home *node)
{
  AST_Operation **op = 0;
  unsigned long slot = (node->base_home () == 0 ? 0UL : 1UL)
                       + static_cast<unsigned long> (node->n_supports ())
                       + (node->primary_key () == 0 ? 0UL : 1UL)
                       + 1;

  for (ACE_Unbounded_Queue_Iterator<AST_Operation *> i (node->factories ());
       !i.done ();
       i.advance ())
    {
      i.next (op);
      DOMElement *factory = this->doc_->createElement (X ("model"));
      this->set_id_attr (factory, BE_GlobalData::MODEL);
      this->set_childrelidcntr_attr (factory, *op);
      factory->setAttribute (X ("relid"), X (be_global->hex_string (slot)));
      factory->setAttribute (X ("kind"), X ("FactoryOperation"));
      factory->setAttribute (X ("role"), X ("FactoryOperation"));
      this->add_name_element (factory, (*op)->local_name ()->get_string ());
      this->add_regnodes (node, factory, slot++);
      this->add_replace_id_element (factory, *op);
      this->add_version_element (factory, *op);
      
      picml_visitor scope_visitor (factory);
      if (scope_visitor.visit_scope (*op) != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "picml_visitor::add_home_factories - "
                      "code generation for scope failed\n"));
        }   
      
      this->add_exception_elements (factory,
                                    *op,
                                    0,
                                    (*op)->exceptions (),
                                    "ExceptionRef",
                                    scope_visitor.rel_id_);
      parent->appendChild (factory); 
    }
}

void
picml_visitor::add_finders (DOMElement *parent, AST_Home *node)
{
  AST_Operation **op = 0;
  unsigned long slot = (node->base_home () == 0 ? 0UL : 1UL)
                       + static_cast<unsigned long> (node->n_supports ())
                       + (node->primary_key () == 0 ? 0UL : 1UL)
                       + node->factories ().size ()
                       + 1;

  for (ACE_Unbounded_Queue_Iterator<AST_Operation *> i (node->finders ());
       !i.done ();
       i.advance ())
    {
      i.next (op);
      DOMElement *finder = this->doc_->createElement (X ("model"));
      this->set_id_attr (finder, BE_GlobalData::MODEL);
      this->set_childrelidcntr_attr (finder, *op);
      finder->setAttribute (X ("relid"), X (be_global->hex_string (slot)));
      finder->setAttribute (X ("kind"), X ("LookupOperation"));
      finder->setAttribute (X ("role"), X ("LookupOperation"));
      this->add_name_element (finder, (*op)->local_name ()->get_string ());
      this->add_regnodes (node, finder, slot++);
      this->add_replace_id_element (finder, *op);
      this->add_version_element (finder, *op);
      
      picml_visitor scope_visitor (finder);
      if (scope_visitor.visit_scope (*op) != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "picml_visitor::add_finders - "
                      "code generation for scope failed\n"));
        }   
      
      this->add_exception_elements (finder,
                                    *op,
                                    0,
                                    (*op)->exceptions (),
                                    "ExceptionRef",
                                    scope_visitor.rel_id_);
      parent->appendChild (finder); 
    }
}

ACE_TCHAR *
picml_visitor::timestamp (ACE_TCHAR date_and_time[],
                         int length)
{
  if (length < 27)
    {
      errno = EINVAL;
      return 0;
    }

#if defined (WIN32)
   // Emulate Unix.  Win32 does NOT support all the UNIX versions
   // below, so DO we need this ifdef.
  static const ACE_TCHAR *day_of_week_name[] =
  {
    ACE_LIB_TEXT ("Sun"),
    ACE_LIB_TEXT ("Mon"),
    ACE_LIB_TEXT ("Tue"),
    ACE_LIB_TEXT ("Wed"),
    ACE_LIB_TEXT ("Thu"),
    ACE_LIB_TEXT ("Fri"),
    ACE_LIB_TEXT ("Sat")
  };

  static const ACE_TCHAR *month_name[] =
  {
    ACE_LIB_TEXT ("Jan"),
    ACE_LIB_TEXT ("Feb"),
    ACE_LIB_TEXT ("Mar"),
    ACE_LIB_TEXT ("Apr"),
    ACE_LIB_TEXT ("May"),
    ACE_LIB_TEXT ("Jun"),
    ACE_LIB_TEXT ("Jul"),
    ACE_LIB_TEXT ("Aug"),
    ACE_LIB_TEXT ("Sep"),
    ACE_LIB_TEXT ("Oct"),
    ACE_LIB_TEXT ("Nov"),
    ACE_LIB_TEXT ("Dec")
  };

  SYSTEMTIME local;
  ::GetLocalTime (&local);

  ACE_OS::sprintf (date_and_time,
                   ACE_LIB_TEXT ("%3s %3s %02d% 02d:%02d:%02d %04d"),
                   day_of_week_name[local.wDayOfWeek],
                   month_name[local.wMonth - 1],
                   (int) local.wDay,
                   (int) local.wHour,
                   (int) local.wMinute,
                   (int) local.wSecond,
                   (int) local.wYear);
#else  /* UNIX */
  ACE_TCHAR timebuf[26]; // This magic number is based on the ctime(3c) man page.
  ACE_Time_Value cur_time = ACE_OS::gettimeofday ();
  time_t secs = cur_time.sec ();

  ACE_OS::ctime_r (&secs,
                   timebuf,
                   sizeof timebuf);
  // date_and_timelen > sizeof timebuf!
  ACE_OS::strsncpy (date_and_time,
                    timebuf,
                    length);
  date_and_time[26] = '\0';
#endif /* WIN32 */

  return &date_and_time[0];
}

unsigned long
picml_visitor::nmembers_gme (UTL_Scope *s, AST_Attribute *a)
{
  unsigned long retval = 0;
  
  if (a != 0)
    {
      UTL_ExceptList *get_ex = a->get_get_exceptions ();
      UTL_ExceptList *set_ex = a->get_set_exceptions ();
      
      // The exceptions plus 1 for the attribute field type.
      return (get_ex != 0 ? get_ex->length () : 0)
             + (set_ex != 0 ? set_ex->length () : 0)
             + 1;
    }
    
  AST_Decl::NodeType snt = ScopeAsDecl (s)->node_type ();

  for (UTL_ScopeActiveIterator si (s, UTL_Scope::IK_decls);
        !si.is_done ();
        si.next ())
    {
      AST_Decl *d = si.item ();
    
      if (d->imported ())
        {
          continue;
        }
        
      AST_Decl::NodeType nt = d->node_type ();
    
      // Don't count predefined types (applies only if s == root),
      // or any kind of forward declaration or enum value (the
      // latter are included in their enclosing scope by the IDL
      // compiler since enums are not a scope in C++.
      if (nt == AST_Decl::NT_pre_defined
          || nt == AST_Decl::NT_interface_fwd
          || nt == AST_Decl::NT_component_fwd
          || nt == AST_Decl::NT_valuetype_fwd
          || nt == AST_Decl::NT_eventtype_fwd
          || nt == AST_Decl::NT_struct_fwd
          || nt == AST_Decl::NT_union_fwd
          || nt == AST_Decl::NT_enum_val && snt != AST_Decl::NT_enum)
        {
          continue;
        }
        
      // Skip the Cookie-related stuff added in the front end for uses
      // multiple ports. Ports are stored in queues so all that's left
      // are attributes.
      if (snt == AST_Decl::NT_component && nt != AST_Decl::NT_attr)
        {
          continue;
        }
   
      ++retval;
    }
    
  AST_Operation *op = AST_Operation::narrow_from_scope (s);
  if (op != 0)
    {
      // The return type of a home factory and finder operations
      // are implicit in IDML.
      if (ScopeAsDecl (op->defined_in ())->node_type () != AST_Decl::NT_home)
        {
          retval += op->void_return_type () == 0 ? 1 : 0;
        }
        
      UTL_ExceptList *ex = op->exceptions ();  
      retval += (ex == 0 ? 0UL : ex->length ());
      return retval;
    }
    
  AST_Factory *f = AST_Factory::narrow_from_scope (s);
  if (f != 0)
    {
      UTL_ExceptList *ex = f->exceptions ();
      retval += (ex == 0 ? 0UL : ex->length ());
      return retval;
    }
    
  AST_Union *u = AST_Union::narrow_from_scope (s);
  if (u != 0)
    {
      // Add 1 for the discriminator.
      ++retval;
      return retval;
    }
  
  AST_Root *r = AST_Root::narrow_from_scope (s);
  if (r != 0)
    {
      retval += this->user_includes () + this->n_basic_seqs_;   
      return retval;
    }
    
  AST_Interface *i = AST_Interface::narrow_from_scope (s);
  if (i != 0)
    {
      // This covers supported interfaces for components and homes.
      retval += static_cast<unsigned long> (i->n_inherits ());
      // No 'return' here - this is a base class for all the others
      // below so we want to fall through.
    }
    
  AST_ValueType *v = AST_ValueType::narrow_from_scope (s);
  if (v != 0)
    {
      // Inherited valuetypes are in AST_Interface inheritance list.
      // This covers AST_EventType as well.
      retval += static_cast<unsigned long> (v->n_supports ());
      
      return retval;
    }
    
  AST_Component *c = AST_Component::narrow_from_scope (s);
  if (c != 0)
    {
      // Supported interfaces are in AST_Interface inheritance list.
      retval += (c->base_component () != 0 ? 1 : 0);
      
      // Add in the ports.
      retval += c->provides ().size ()
                 + c->uses ().size ()
                 + c->emits ().size ()
                 + c->publishes ().size ()
                 + c->consumes ().size ();
      return retval;
    }
    
  AST_Home *h = AST_Home::narrow_from_scope (s);
  if (h != 0)
    {
      // Supported interfaces are in AST_Interface inheritance list.
      retval += (h->base_home () != 0 ? 1 : 0)
                + (h->primary_key () != 0 ? 1: 0)
                + h->factories ().size ()
                + h->finders ().size ();
    }
    
  return retval;
}

XMLCh *
picml_visitor::lookup_id (AST_Decl *d)
{
  ACE_CString ext_id = d->repoID ();
  
  // One or the other of these, but not both, may replace ext_id.
  this->check_for_basic_type (d, ext_id);
  this->check_for_basic_seq (d, ext_id);
  
  XMLCh *retval = 0;
  int result = be_global->decl_id_table ().find (ext_id.c_str (), retval);
  
  if (result != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::lookup_id - "
                         "lookup of id %s failed\n",
                         ext_id.c_str ()),
                        0);
    }
    
  return retval;
}

XMLCh *
picml_visitor::lookup_constant_type (AST_Constant *c)
{
  const char *ext_id = 0;
  const char **namelist = be_global->pdt_names ();
  AST_Decl *enum_type = 0;

  switch (c->et ())
    {
      case AST_Expression::EV_enum:
        enum_type = 
          c->defined_in ()->lookup_by_name (c->enum_full_name (), I_TRUE);
        ext_id = enum_type->repoID ();
        break;
      case AST_Expression::EV_short:
      case AST_Expression::EV_ushort:
        ext_id = namelist[4UL];
        break;
      case AST_Expression::EV_long:
      case AST_Expression::EV_ulong:
      case AST_Expression::EV_longlong:
      case AST_Expression::EV_ulonglong:
        ext_id = namelist[6UL];
        break;
      case AST_Expression::EV_bool:
        ext_id = namelist[3UL];
        break;
      case AST_Expression::EV_float:
      case AST_Expression::EV_longdouble:
      case AST_Expression::EV_double:
        ext_id = namelist[5UL];
        break;
      case AST_Expression::EV_char:
      case AST_Expression::EV_wchar:
      case AST_Expression::EV_octet:
        ext_id = namelist[10UL];
        break;
      case AST_Expression::EV_string:
      case AST_Expression::EV_wstring:
        ext_id = namelist[2UL];
        break;
      default:
        break;
    }
   
  XMLCh *retval = 0;
  int result = be_global->decl_id_table ().find (ext_id, retval);
  
  if (result != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "picml_visitor::lookup_constant_type - "
                         "lookup of id %s failed\n",
                         ext_id),
                        0);
    }
    
  return retval;
}

ACE_CString
picml_visitor::print_scoped_name (UTL_IdList *sn)
{
  long first = I_TRUE;
  long second = I_FALSE;
  Identifier *id = 0;
  ACE_CString retval;

  for (UTL_IdListActiveIterator i (sn); !i.is_done (); i.next ())
    {
      if (!first)
        {
          retval += "::";
        }
      else if (second)
        {
          first = second = I_FALSE;
        }

      // Print the identifier.
      id = i.item ();
      retval += id->get_string ();

      if (first)
        {
          if (ACE_OS::strcmp (id->get_string (), "") != 0)
            {
              // Does not start with a "".
              first = I_FALSE;
            }
          else
            {
              second = I_TRUE;
            }
        }
    }
    
  return retval;
}

ACE_CString
picml_visitor::expr_val_to_string (AST_Expression::AST_ExprValue *ev)
{
  ACE_CString value;
  char buffer[33] = {'\0'};
  
  switch (ev->et)
    {
      case AST_Expression::EV_short:
        ACE_OS::sprintf (buffer, "%hd", ev->u.sval);
        value = buffer;
        break;
      case AST_Expression::EV_ushort:
        ACE_OS::sprintf (buffer, "%hu", ev->u.usval);
        value = buffer;
        break;
      case AST_Expression::EV_long:
        ACE_OS::sprintf (buffer, "%ld", ev->u.lval);
        value = buffer;
        break;
      case AST_Expression::EV_ulong:
        ACE_OS::sprintf (buffer, "%u", ev->u.ulval);
        value = buffer;
        break;
      case AST_Expression::EV_longlong:
#if ! defined (ACE_LACKS_LONGLONG_T)
        ACE_OS::sprintf (buffer, "%ld", ev->u.llval);
        value = buffer;
#endif /* ! defined (ACE_LACKS_LONGLONG_T) */
        break;
      case AST_Expression::EV_ulonglong:
#if ! defined (ACE_LACKS_LONGLONG_T)
        ACE_OS::sprintf (buffer, ACE_UINT64_FORMAT_SPECIFIER, ev->u.ullval);
        value = buffer;
#endif /* ! defined (ACE_LACKS_LONGLONG_T) */
        break;
      case AST_Expression::EV_bool:
        value = (ev->u.bval ? "TRUE" : "FALSE");
        break;
      case AST_Expression::EV_float:
        ACE_OS::sprintf (buffer, "%f", ev->u.fval);
        value = buffer;
        break;
      case AST_Expression::EV_double:
        ACE_OS::sprintf (buffer, "%24.16G", ev->u.dval);
        value = buffer;
        break;
      case AST_Expression::EV_char:
        ACE_OS::sprintf (buffer, "%c", ev->u.cval);
        value = buffer;
        break;
      case AST_Expression::EV_wchar:
        ACE_OS::sprintf (buffer, "%lc", ev->u.wcval);
        value = buffer;
        break;
      case AST_Expression::EV_octet:
        ACE_OS::sprintf (buffer, "%d", ev->u.oval);
        value = buffer;
        break;
      case AST_Expression::EV_wstring:
        value = ev->u.wstrval;
        break;
      case AST_Expression::EV_string:
        value = ev->u.strval->get_string ();
        break;
      case AST_Expression::EV_longdouble:
      default:
        break;
    }
    
  return value;
}

unsigned long
picml_visitor::user_includes (void)
{
  unsigned long retval = 0;

  // Included IDL files are modeled as GME references in the File model,
  // except canonical includes orb.idl and Components.idl.
  for (unsigned long i = 0; i < idl_global->n_included_idl_files (); ++i)
    {
      ACE_CString fname (idl_global->included_idl_files ()[i]);
      int pos = fname.rfind ('/');
      ACE_CString lname =
        (pos == ACE_CString::npos ? fname : fname.substr (pos + 1));
        
      // Types in these files should never be referenced in application
      // IDL files, so we don't included references to the files in the
      // PICML model.  
      if (lname == "Components.idl" || lname == "orb.idl")
        {
          continue;
        }
       
      // The only types from these files that are referenced directly are
      // the sequences of basic types, which will probably be added to
      // the basic types library in PICML.  
      if (lname.find (".pidl") != ACE_CString::npos)
        {
          continue;
        }
        
      ++retval;
    }
    
  return retval;
}

void
picml_visitor::set_n_basic_seqs (void)
{
  const char **pdts = be_global->pdt_names ();
  
  if (idl_global->string_seq_seen_
      || idl_global->wstring_seq_seen_)
    {
      this->set_one_basic_seq (pdts[2UL]);
    }
    
  if (idl_global->short_seq_seen_
      || idl_global->ushort_seq_seen_)
    {
      this->set_one_basic_seq (pdts[4UL]);
    }
    
  if (idl_global->long_seq_seen_
      || idl_global->ulong_seq_seen_
      || idl_global->longlong_seq_seen_
      || idl_global->ulonglong_seq_seen_)
    {
      this->set_one_basic_seq (pdts[6UL]);
    }
    
  if (idl_global->float_seq_seen_
      || idl_global->double_seq_seen_
      || idl_global->longdouble_seq_seen_)
    {
      this->set_one_basic_seq (pdts[5UL]);
    }
    
  if (idl_global->char_seq_seen_
      || idl_global->wchar_seq_seen_
      || idl_global->octet_seq_seen_)
    {
      this->set_one_basic_seq (pdts[10UL]);
    }
    
  if (idl_global->boolean_seq_seen_)
    {
      this->set_one_basic_seq (pdts[3UL]);
    }
    
  if (idl_global->any_seq_seen_)
    {
      this->set_one_basic_seq (pdts[8UL]);
    }
}

void
picml_visitor::set_one_basic_seq (const char *base_type)
{
  DOMElement *elem = 0;
  ACE_CString name (base_type);
  name += be_global->basic_seq_suffix ();
  int result = be_global->decl_elem_table ().find (name.c_str (), elem);
  
  if (result != 0)
    {
      elem = this->doc_->createElement (X ("reference"));
      be_global->decl_elem_table ().bind (ACE::strnew (name.c_str ()), elem);
      ++this->n_basic_seqs_;
    }
}
void
picml_visitor::check_for_basic_seq (AST_Decl *d, ACE_CString &str)
{
  if (d->node_type () != AST_Decl::NT_typedef)
    {
      return;
    }
    
  AST_Decl *p = ScopeAsDecl (d->defined_in ());  
  if (ACE_OS::strcmp (p->local_name ()->get_string (), "CORBA") != 0)
    {
      return;
    }
    
  AST_Type *bt = AST_Typedef::narrow_from_decl (d)->base_type ();
  if (bt->node_type () != AST_Decl::NT_sequence)
    {
      return;
    }
    
  bt = AST_Sequence::narrow_from_decl (bt)->base_type ();
  AST_Decl::NodeType nt = bt->node_type ();
  this->check_for_basic_type (bt, str);
  
  // If the previous call modified the string, append the sequence suffix.
  if (nt == AST_Decl::NT_string
      || nt == AST_Decl::NT_wstring
      || nt == AST_Decl::NT_pre_defined)
    {
      str += be_global->basic_seq_suffix ();
    }
}

void
picml_visitor::check_for_basic_type (AST_Decl *d, ACE_CString &str)
{
  const char **namelist = be_global->pdt_names ();
  AST_Decl::NodeType nt = d->node_type ();
  
  if (nt == AST_Decl::NT_string || nt == AST_Decl::NT_wstring)
    {
      str = namelist[2UL];
    }
  else if (d->node_type () == AST_Decl::NT_pre_defined)
    {
      AST_PredefinedType *pdt = AST_PredefinedType::narrow_from_decl (d);
      
      switch (pdt->pt ())
        {
          case AST_PredefinedType::PT_long:
          case AST_PredefinedType::PT_ulong:
          case AST_PredefinedType::PT_longlong:
          case AST_PredefinedType::PT_ulonglong:
            str = namelist[6UL];
            break;
          case AST_PredefinedType::PT_short:
          case AST_PredefinedType::PT_ushort:
            str = namelist[4UL];
            break;
          case AST_PredefinedType::PT_float:
          case AST_PredefinedType::PT_double:
          case AST_PredefinedType::PT_longdouble:
            str = namelist[5UL];
            break;
          case AST_PredefinedType::PT_char:
          case AST_PredefinedType::PT_octet:
          case AST_PredefinedType::PT_wchar:
            str = namelist[10UL];
            break;
          case AST_PredefinedType::PT_boolean:
            str = namelist[3UL];
            break;
          case AST_PredefinedType::PT_any:
            str = namelist[8UL];
            break;
          case AST_PredefinedType::PT_object:
            str = namelist[9UL];
            break;
          case AST_PredefinedType::PT_value:
            str = namelist[7UL];
            break;
          case AST_PredefinedType::PT_pseudo:
            {
              const char *pseudo_name = d->local_name ()->get_string ();
              
              if (ACE_OS::strcmp (pseudo_name, "TypeCode") == 0)
                {
                  str = namelist[1UL];
                }
              else if (ACE_OS::strcmp (pseudo_name, "TCKind") == 0)
                {
                  str = namelist[0UL];
                }
            }
            break;
          default:
            break;
        }
    }
}

// If an IDL module contains only other modules and forward decls,
// we can skip importing it, and at the same time avoid the
// 'empty package' constraint violation.
bool
picml_visitor::can_skip_import (AST_Module *m)
{
  for (UTL_ScopeActiveIterator si (m, UTL_Scope::IK_decls);
       !si.is_done ();
       si.next ())
    {
      AST_Decl *d = si.item ();
      AST_Module *nested_m = AST_Module::narrow_from_decl (d);
      
      if (nested_m != 0 && !this->can_skip_import (nested_m))
        {
          return false;
        }
        
      AST_Decl::NodeType nt = d->node_type ();
      
      if (nt == AST_Decl::NT_interface_fwd
          || nt == AST_Decl::NT_valuetype_fwd
          || nt == AST_Decl::NT_union_fwd
          || nt == AST_Decl::NT_struct_fwd
          || nt == AST_Decl::NT_component_fwd
          || nt == AST_Decl::NT_eventtype_fwd
          || nt == AST_Decl::NT_pre_defined
          || nt == AST_Decl::NT_module)
        {
          continue;
        }
      else
        {
          return false;
        }
    }
    
  return true;
}