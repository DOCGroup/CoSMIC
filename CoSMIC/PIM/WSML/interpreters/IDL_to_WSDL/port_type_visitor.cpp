/* -*- c++ -*- */
// $Id: port_type_visitor.cpp,v 1.9 2006/02/09 16:51:07 parsons Exp $

#include "port_type_visitor.h"
#include "XercesString.h"

#include "be_extern.h"

#include "ast_argument.h"
#include "ast_attribute.h"
#include "ast_component.h"
#include "ast_exception.h"
#include "ast_operation.h"
#include "utl_identifier.h"
#include "utl_idlist.h"
#include "utl_exceptlist.h"
#include "utl_string.h"
#include "global_extern.h"
#include "nr_extern.h"

#include "ace/OS_NS_stdio.h"

#include <xercesc/dom/DOM.hpp>

port_type_visitor::port_type_visitor (DOMElement *sub_tree)
  : idl_to_wsdl_visitor (sub_tree),
    current_port_type_ (0),
    current_response_op_ (0)
{
}

port_type_visitor::~port_type_visitor (void)
{
}

int
port_type_visitor::visit_interface (AST_Interface *node)
{
  DOMElement *elem =
    this->doc_->createElement (X ("portType"));
    
  be_global->root_element ()->insertBefore (
    elem,
    be_global->port_type_insert_point ());
  
  be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                      elem); 
  
  if (0 == be_global->msg_insert_point ())
    {
      be_global->msg_insert_point (elem);
    }
  
  ACE_CString name (node->full_name ());
  be_global->to_wsdl_name (name);
  elem->setAttribute (X ("name"), X (name.c_str ()));
  
  this->current_port_type_ = elem;
  
  if (this->visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "port_type_visitor::visit_interface - "
                          "codegen for scope failed\n"),
                        -1);
    }
    
  this->gen_inherited_operations (node);
  return 0;
}

int
port_type_visitor::visit_component (AST_Component *node)
{
  if  (0 != this->visit_interface (node))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "port_type_visitor::visit_component - "
                          "codegen for visit_interface failed\n"),
                        -1);
    }
    
  this->gen_inherited_comp (node);
  return 0;
}

int
port_type_visitor::visit_operation (AST_Operation *node)
{
  AST_Decl::NodeType nt = ScopeAsDecl (node->defined_in ())->node_type ();
  
  // We don't want to generate anything for valuetype operations.
  if (AST_Decl::NT_eventtype == nt || AST_Decl::NT_valuetype == nt)
    {
      return 0;
    }
    
  DOMElement *sub_tree_holder = this->sub_tree_;
  this->sub_tree_ = this->current_port_type_;

  // Fetch from DOM tree, from table, or create.
  DOMElement *operation = this->process_node (node, "operation");

  if (NOT_SEEN == this->node_status_)
    {
      this->finish_operation (node, operation, 0);                              
    }
    
  this->sub_tree_ = sub_tree_holder;
  return 0;
}

int
port_type_visitor::visit_attribute (AST_Attribute *node)
{
  bool read_only = node->readonly ();
  DOMElement *sub_tree_holder = this->sub_tree_;
  this->sub_tree_ = this->current_port_type_;

  // Fetch from DOM tree, from table, or create.
  DOMElement *get_attr = this->process_node (node, "operation");

  if (NOT_SEEN == this->node_status_)
    {
      this->finish_operation (node, get_attr, "_get_");
      
      if (!read_only)
        {
          DOMElement *set_attr =
            this->doc_->createElement (X ("operation"));
          this->finish_operation (node, set_attr, "_set_");          
          this->sub_tree_->appendChild (set_attr);
        }
    }
   
  this->sub_tree_ = sub_tree_holder;  
  return 0;
}

void
port_type_visitor::finish_operation (AST_Decl *node,
                                     DOMElement *elem,
                                     const char *prefix)
{
  ACE_CString lname (0 != prefix ? prefix : "");
  lname += node->local_name ()->get_string ();
  elem->setAttribute (X ("name"), X (lname.c_str ()));
  
  ACE_CString op_name ("tns:");
  ACE_CString parent_name (ScopeAsDecl (node->defined_in ())->full_name ());
  be_global->to_wsdl_name (parent_name);
  op_name += parent_name;
  op_name += ".";
  op_name += lname;
  
  DOMElement *input_msg = this->doc_->createElement (X ("input"));
  input_msg->setAttribute (X ("message"), X (op_name.c_str ()));
  elem->appendChild (input_msg);
  
  AST_Operation *op = AST_Operation::narrow_from_decl (node);
  
  if (0 == op || AST_Operation::OP_oneway != op->flags ())
    {
      op_name += "Response";
      DOMElement *output_msg = this->doc_->createElement (X ("output"));
      output_msg->setAttribute (X ("message"), X (op_name.c_str ()));
      elem->appendChild (output_msg);
    }
    
  // TODO - attribute exceptions.  
  if (0 != op)
    {
      for (UTL_ExceptlistActiveIterator i (op->exceptions ());
           !i.is_done ();
           i.next ())
        {
          DOMElement *except_msg =
            this->doc_->createElement (X ("fault"));
          ACE_CString fname (i.item ()->full_name ());
          be_global->to_wsdl_name (fname);
          except_msg->setAttribute (X ("name"), X (fname.c_str ()));
          fname = ACE_CString ("tns:_exception.") + fname;
          except_msg->setAttribute (X ("message"), X (fname.c_str ()));
          elem->appendChild (except_msg);
        }
    }

  DOMElement *sys_except_msg = this->doc_->createElement (X ("fault"));
  sys_except_msg->setAttribute (X ("name"), X ("CORBA.SystemException"));
  sys_except_msg->setAttribute (X ("message"),
                                X ("corba:CORBA.SystemExceptionMessage"));
  elem->appendChild (sys_except_msg);
}

void
port_type_visitor::gen_inherited_operations (AST_Interface *node)
{
  // Not compatible with 'updating IDL' feature.
  for (long i = 0; i < node->n_inherits_flat (); ++i)
    {
      this->append_ops_and_attrs (node->inherits_flat ()[i]);
    }
}

void
port_type_visitor::gen_inherited_comp (AST_Component *node)
{
  AST_Component *parent = node->base_component ();
  
  if (0 != parent)
    {
      this->gen_inherited_operations (parent);
      this->append_ops_and_attrs (parent);
      this->gen_inherited_comp (parent);
    }
}

void
port_type_visitor::append_ops_and_attrs (AST_Interface *ancestor)
{
  for (UTL_ScopeActiveIterator i (ancestor, UTL_Scope::IK_decls);
       !i.is_done ();
       i.next ())
    {
      AST_Decl *d = i.item ();
      AST_Operation *op = AST_Operation::narrow_from_decl (d);
      AST_Attribute *attr = AST_Attribute::narrow_from_decl (d);
      
      if (0 != op)
        {
          DOMElement *op_elem =
            this->doc_->createElement (X ("operation"));
          this->current_port_type_->appendChild (op_elem);
          this->finish_operation (op, op_elem, 0);
        }
      else if (0 != attr)
        {
          DOMElement *attr_elem =
            this->doc_->createElement (X ("operation"));
          this->current_port_type_->appendChild (attr_elem);
          this->finish_operation (attr, attr_elem, "_get_");
          
          if (!attr->readonly ())
            {
              DOMElement *attr_set_elem =
                this->doc_->createElement (X ("operation"));
              this->current_port_type_->appendChild (attr_set_elem);
              this->finish_operation (attr, attr_set_elem, "_set_");
            }
        }
    }
}

