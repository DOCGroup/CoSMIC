/* -*- c++ -*- */
// $Id: binding_visitor.cpp,v 1.9 2006/02/09 16:51:07 parsons Exp $

#include "binding_visitor.h"
#include "XercesString.h"
#include "be_extern.h"

#include "ast_argument.h"
#include "ast_attribute.h"
#include "ast_component.h"
#include "ast_operation.h"
#include "ast_root.h"
#include "utl_identifier.h"
#include "utl_idlist.h"
#include "utl_string.h"
#include "global_extern.h"
#include "nr_extern.h"

#include "ace/OS_NS_stdio.h"

#include <xercesc/dom/DOM.hpp>

extern const char *SOAP_ENC;
extern const char *CORBA_NS;

binding_visitor::binding_visitor (DOMElement *sub_tree)
  : idl_to_wsdl_visitor (sub_tree),
    current_binding_ (0)
{
}

binding_visitor::~binding_visitor (void)
{
}

int
binding_visitor::visit_component (AST_Component *node)
{
  DOMElement *port_type = 0;
  be_global->decl_elem_table ().find (node->repoID (), port_type);
  
  this->gen_binding (port_type, node);
  
  for (ACE_Unbounded_Queue_Iterator<AST_Component::port_description> i (
         node->provides ());
       !i.done ();
       i.advance ())
    {
      AST_Component::port_description *desc = 0;
      i.next (desc);
      
      be_global->decl_elem_table ().find (desc->impl->repoID (), port_type);
      this->gen_binding (port_type, node, desc->impl, desc->id->get_string ());
    }
  
  return 0;
}

void
binding_visitor::fill_binding_op (DOMElement *binding_op,
                                  DOMElement *port_type_op)
{
  DOMElement *binding_input = this->doc_->createElement (X ("input"));
  binding_op->appendChild (binding_input);
  
  DOMElement *binding_output = this->doc_->createElement (X ("output"));
  binding_op->appendChild (binding_output);
  
  DOMElement *soap_body = this->doc_->createElement (X ("soap:body"));
  soap_body->setAttribute (X ("use"), X ("encoded"));
  soap_body->setAttribute (X ("encodingStyle"),
                           X ("http://schemas.xmlsoap.org/soap/encoding/"));
  
  ACE_CString target_name_space ("urn:");
  target_name_space += be_global->output_file ();
  
  soap_body->setAttribute (X ("namespace"),
                           X (target_name_space.c_str ()));
  
  binding_input->appendChild (soap_body);
  
  DOMElement *soap_body_clone =
    dynamic_cast<DOMElement *> (soap_body->cloneNode (false));
  binding_output->appendChild (soap_body_clone);
  
  DOMElement *op_fault =
    dynamic_cast<DOMElement *> (port_type_op->getLastChild ());
  const XMLCh *tag = op_fault->getTagName ();
  DOMNode *ref_child = 0;
  
  while (X ("fault") == tag)
    {
      const XMLCh *fault_name = op_fault->getAttribute (X ("name"));
      
      DOMElement *binding_op_fault = 
        this->doc_->createElement (X ("fault"));
      binding_op_fault->setAttribute (X ("name"), fault_name);
      
      DOMElement *soap_fault =
        this->doc_->createElement (X ("soap:fault"));
      soap_fault->setAttribute (X ("name"), fault_name);
      soap_fault->setAttribute (X ("use"), X ("encoded"));
      soap_fault->setAttribute (X ("encodingStyle"), X (SOAP_ENC));
      soap_fault->setAttribute (X ("namespace"), X (CORBA_NS));
      binding_op_fault->appendChild (soap_fault);
      
      // Preserves the order of fault elements from portType to
      // corresponding binding element.
      binding_op->insertBefore (binding_op_fault, ref_child);
      ref_child = binding_op_fault;
      
      op_fault =
        dynamic_cast<DOMElement *> (op_fault->getPreviousSibling ());
      tag = op_fault->getTagName ();
    }
}

void
binding_visitor::gen_binding (DOMElement *port_type,
                              AST_Component *node,
                              AST_Type *port_impl,
                              const char *port_name)
{
  DOMElement *binding = this->doc_->createElement (X ("binding"));
  
  be_global->root_element ()->insertBefore (
    binding,
    be_global->binding_insert_point ());
    
  if (0 == be_global->port_type_insert_point ())
    {
      be_global->port_type_insert_point (binding);
    }
  
  ACE_CString scope_name;
  AST_Decl *p = ScopeAsDecl (node->defined_in ());
  
  if (AST_Decl::NT_root != p->node_type ())
    {
      this->type_name (scope_name, p, false);
      scope_name += ".";
    }
    
  const char *lname = 0;
  const char *node_name = node->local_name ()->get_string ();
    
  if (0 == port_name)
    {
      lname = node_name;
    }
  else
    {
      scope_name += node_name;
      scope_name += ".";
      lname = port_name; 
    }
    
  scope_name += "_SE_";
  scope_name += lname;
  
  binding->setAttribute (X ("name"), X (scope_name.c_str ()));
  ACE_CString tname (0 == port_impl
                       ? node->full_name ()
                       : port_impl->full_name ());
  be_global->to_wsdl_name (tname);
  tname = ACE_CString ("tns:") + tname;
  binding->setAttribute (X ("type"), X (tname.c_str ()));
  
  DOMElement *soap_binding =
    this->doc_->createElement (X ("soap:binding"));
  soap_binding->setAttribute (X ("style"), X ("rpc"));
  soap_binding->setAttribute (X ("transport"),
                              X ("http://schemas.xmlsoap.org/soap/http"));
  binding->appendChild (soap_binding);
  
  DOMElement *op =
    dynamic_cast<DOMElement *> (port_type->getFirstChild ());
    
  while (0 != op)
    {
      DOMElement *binding_op =
        dynamic_cast<DOMElement *> (op->cloneNode (false));
      binding->appendChild (binding_op);
      
      // An example WSDL file I saw left this attribute value empty,
      // so I'm doing the same since it's a pain to retrieve the full
      // operation name if we'r dealing with a port.
      DOMElement *soap_operation =
        this->doc_->createElement (X ("soap:operation"));
      soap_operation->setAttribute (X ("style"), X ("rpc"));
      
      // Removed for now, but it may come back.
//      soap_operation->setAttribute (X ("soapAction"), X (""));

      binding_op->appendChild (soap_operation);

      this->fill_binding_op (binding_op, op);
      op = dynamic_cast<DOMElement *> (op->getNextSibling ());
    }
}

