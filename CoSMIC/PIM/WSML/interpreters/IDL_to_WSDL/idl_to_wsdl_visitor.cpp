/* -*- c++ -*- */
// $Id: idl_to_wsdl_visitor.cpp,v 1.9 2006/02/09 16:51:07 parsons Exp $

#include "idl_to_wsdl_visitor.h"
#include "XercesString.h"
#include "be_extern.h"

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
#include "ast_string.h"
#include "ast_structure_fwd.h"
#include "ast_union.h"
#include "ast_union_branch.h"
#include "ast_union_fwd.h"
#include "ast_union_label.h"
#include "ast_valuebox.h"
#include "ast_valuetype_fwd.h"
#include "ast_native.h"
#include "utl_exceptlist.h"
#include "utl_identifier.h"
#include "utl_idlist.h"
#include "utl_string.h"
#include "global_extern.h"
#include "nr_extern.h"

#include "ace/OS_NS_stdio.h"

idl_to_wsdl_visitor::idl_to_wsdl_visitor (DOMElement *sub_tree)
  : sub_tree_ (sub_tree),
    doc_ (sub_tree->getOwnerDocument ()),
    current_union_ (0),
    alias_ (0),
    current_port_type_ (0),
    current_binding_ (0),
    response_op_ (0)
{
}

idl_to_wsdl_visitor::~idl_to_wsdl_visitor (void)
{
}

int
idl_to_wsdl_visitor::visit_decl (AST_Decl *)
{
  return 0;
}

int
idl_to_wsdl_visitor::visit_scope (UTL_Scope *node)
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
      // @@@ (JP) This will go away when the visitor is finished, since
      // those uses_xxxConnection structs will not be added to the AST.
      if (ScopeAsDecl (node)->node_type () == AST_Decl::NT_component
          && d->node_type () != AST_Decl::NT_attr)
        {
          continue;
        }

      if (d->ast_accept (this) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "idl_to_wsdl_visitor::visit_scope - "
                             "codegen for scope failed\n"),
                            -1);
        }
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_type (AST_Type *)
{
  return 0;
}

int
idl_to_wsdl_visitor::visit_predefined_type (AST_PredefinedType *)
{
  return 0;
}

int
idl_to_wsdl_visitor::visit_module (AST_Module *node)
{
  if (node->imported ())
    {
      return 0;
    }

  if (this->visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "idl_to_wsdl_visitor::visit_module - "
                          "codegen for scope failed\n"),
                        -1);
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_interface (AST_Interface *node)
{
  // portType elements go under <definitions></definitions>.
  DOMElement *sub_tree_holder = this->sub_tree_;
  this->sub_tree_ = be_global->root_element ();

  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (node, "portType");
  
  if (NOT_SEEN == this->node_status_)
    {  
      ACE_CString name (node->full_name ());
      be_global->to_wsdl_name (name);
      elem->setAttribute (X ("name"), X (name.c_str ()));
      
      this->current_binding_ = this->doc_->createElement (X ("binding"));
      be_global->root_element ()->appendChild (this->current_binding_);
      ACE_CString bname (node->full_name ());
      be_global->to_wsdl_name (bname);
      bname = ACE_CString ("_SE_") + bname + ACE_CString ("Binding");
      this->current_binding_->setAttribute (X ("name"), X (bname.c_str ()));
      
      DOMElement *soap_binding =
        this->doc_->createElement (X ("soap:binding"));
      soap_binding->setAttribute (X ("style"), X ("rpc"));
      soap_binding->setAttribute (X ("transport"),
                                  X ("http://schemas.xmlsoap.org/soap/http"));
      this->current_binding_->appendChild (soap_binding);
    }
  
  if (DONE != this->node_status_)
    { 
      // Reset the sub_tree_ to the usual element.
      // Decls in the interface's scope that are no operations or
      // attributes go there. Elements with the 'operation' tag
      // go under the portType element, so we use
      // current_port_type_ for that.
      this->sub_tree_ = be_global->types_schema ();
      this->current_port_type_ = elem;
      
      if (this->visit_scope (node) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                              "idl_to_wsdl_visitor::visit_interface - "
                              "codegen for scope failed\n"),
                            -1);
        }
    }
    
  this->sub_tree_ = this->current_port_type_;
  this->gen_inherited_operations (node);
  
  // The 'portType' element needs to follow all the 'message' elements
  // (created from operations in our scope) that it refers to. Likewise
  // the 'binding' element needed to be created above so the inherited
  // operations could be appended to it, but also needs to be moved here.
  (void) be_global->root_element ()->removeChild (elem);
  be_global->root_element ()->appendChild (elem);
  (void) be_global->root_element ()->removeChild (this->current_binding_);
  be_global->root_element ()->appendChild (this->current_binding_);
  
  // Restore the original sub_tree_ value.
  this->sub_tree_ = sub_tree_holder;
  return 0;
}

int
idl_to_wsdl_visitor::visit_interface_fwd (AST_InterfaceFwd *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_valuebox (AST_ValueBox *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_valuetype (AST_ValueType *node)
{
  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (node, "xsd:complexType");
  
  // Fetch from DOM tree if imported.
  DOMElement *seq = 0;
  
  if (NOT_SEEN == this->node_status_)
    {  
      ACE_CString name (node->full_name ());
      be_global->to_wsdl_name (name);
      elem->setAttribute (X ("name"), X (name.c_str ()));
      
      seq = this->doc_->createElement (X ("xsd:sequence"));
      elem->appendChild (seq);
    
      DOMElement *attr = this->doc_->createElement (X ("xsd:attribute"));
      attr->setAttribute (X ("name"), X ("id"));
      attr->setAttribute (X ("type"), X ("xsd:ID"));
      attr->setAttribute (X ("use"), X ("optional"));
      elem->appendChild (attr);
    }
  
  if (DONE != this->node_status_)
    {
      seq = dynamic_cast<DOMElement *> (elem->getFirstChild ());
      idl_to_wsdl_visitor scope_visitor (seq);
      
      if (scope_visitor.visit_scope (node) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                              "idl_to_wsdl_visitor::visit_structure - "
                              "codegen for scope failed\n"),
                            -1);
        }
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_valuetype_fwd (AST_ValueTypeFwd *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_component (AST_Component *node)
{
  if (node->imported ())
    {
      return 0;
    }

  AST_Component *base = node->base_component ();
  long nsupports = node->n_supports ();

  for (long i = 0; i < nsupports; ++i)
    {
    }

  if (this->visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "idl_to_wsdl_visitor::visit_component - "
                          "codegen for scope failed\n"),
                        -1);
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_component_fwd (AST_ComponentFwd *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_eventtype (AST_EventType *node)
{
  if (node->imported ())
    {
      return 0;
    }

  if (this->visit_valuetype (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "idl_to_wsdl_visitor::visit_eventtype - "
                          "codegen for valuetype failed\n"),
                        -1);
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_eventtype_fwd (AST_EventTypeFwd *node)
{
  if (this->visit_valuetype_fwd (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "idl_to_wsdl_visitor::visit_eventtype_fwd - "
                          "codegen for valuetype_fwd failed\n"),
                        -1);
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_home (AST_Home *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}


int
idl_to_wsdl_visitor::visit_factory  (AST_Factory *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_structure (AST_Structure *node)
{
  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (node, "xsd:complexType");
  
  // Fetch from DOM tree if imported.
  DOMElement *seq = 0;
  
  if (NOT_SEEN == this->node_status_)
    {  
      ACE_CString name (node->full_name ());
      be_global->to_wsdl_name (name);
      elem->setAttribute (X ("name"), X (name.c_str ()));
      
      seq = this->doc_->createElement (X ("xsd:sequence"));
      elem->appendChild (seq);
    }
  
  if (DONE != this->node_status_)
    {
      seq = dynamic_cast<DOMElement *> (elem->getFirstChild ());
      idl_to_wsdl_visitor scope_visitor (seq);
      
      if (scope_visitor.visit_scope (node) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                              "idl_to_wsdl_visitor::visit_structure - "
                              "codegen for scope failed\n"),
                            -1);
        }
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_structure_fwd (AST_StructureFwd *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_exception (AST_Exception *node)
{
  if (0 != this->visit_structure (node))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "idl_to_wsdl_visitor::visit_exception - "
                          "codegen for exception failed\n"),
                        -1);
    }
    
  DOMElement *msg = this->doc_->createElement (X ("message"));
  
  ACE_CString fname ("_exception.");
  ACE_CString tname;
  this->type_name (tname, node, false);
  fname += tname;
  
  msg->setAttribute (X ("name"), X (fname.c_str ()));
  be_global->root_element ()->appendChild (msg);
  
  DOMElement *part = this->doc_->createElement (X ("part"));
  part->setAttribute (X ("name"), X ("exception"));
  tname = ACE_CString ("tns:") + tname;
  part->setAttribute (X ("type"), X (tname.c_str ()));
  
  msg->appendChild (part);
    
  return 0;
}

int
idl_to_wsdl_visitor::visit_expression (AST_Expression *)
{
  return 0;
}

int
idl_to_wsdl_visitor::visit_enum (AST_Enum *node)
{
  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (node, "xsd:simpleType");
  DOMElement *restriction = 0;
  
  if (NOT_SEEN == this->node_status_)
    {
      ACE_CString name (node->full_name ());
      be_global->to_wsdl_name (name);
      elem->setAttribute (X ("name"), X (name.c_str ()));
      
      // Enum values go inside this.
      restriction =
        this->doc_->createElement (X ("xsd:restriction"));
      restriction->setAttribute (X ("base"), X ("xsd:string"));
      elem->appendChild (restriction);
    }

  if (DONE != this->node_status_)
    {
      restriction = dynamic_cast<DOMElement *> (elem->getFirstChild ());
      idl_to_wsdl_visitor scope_visitor (restriction);
      
      if (scope_visitor.visit_scope (node) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "idl_to_wsdl_visitor::visit_enum - "
                             "codegen for scope failed\n"),
                            -1);
        }
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_operation (AST_Operation *node)
{
  DOMElement *sub_tree_holder = this->sub_tree_;
  this->sub_tree_ = this->current_port_type_;

  // Fetch from DOM tree, from table, or create.
  DOMElement *operation = this->process_node (node, "operation");
  DOMElement *message = 0;

  if (NOT_SEEN == this->node_status_)
    {
      this->finish_operation (node, operation, 0);                              
      this->gen_messages (node, message, 0);
    }
    
  if (DONE != this->node_status_)
    {
      // WARNING!! 'message' could be zero until generation from updated
      // IDL is supported.
      idl_to_wsdl_visitor visitor (message);
      visitor.response_op_ =
        dynamic_cast<DOMElement *> (message->getNextSibling ());
      
      if (visitor.visit_scope (node) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "idl_to_wsdl_visitor::visit_operation - "
                             "codegen for message scope failed\n"),
                            -1);
        }
    }
    
  this->sub_tree_ = sub_tree_holder;
  return 0;
}

int
idl_to_wsdl_visitor::visit_field (AST_Field *node)
{
  AST_Type *ft = node->field_type ();
  AST_Decl::NodeType nt = ft->node_type ();
  bool vt_member =
    AST_Decl::NT_valuetype == nt || AST_Decl::NT_eventtype == nt;
  DOMElement *sub_tree_holder = this->sub_tree_;
  
  if (vt_member)
    {
      DOMElement *choice = this->doc_->createElement (X ("xsd:choice"));
      this->sub_tree_->appendChild (choice);
      this->sub_tree_ = choice;
    }
  
  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (node, "xsd:element");
  
  if (NOT_SEEN == this->node_status_)
    {
      elem->setAttribute (X ("name"),
                          X (node->local_name ()->get_string ()));
      elem->setAttribute (X ("minOccurs"), X ("1"));
      elem->setAttribute (X ("maxOccurs"), X ("1"));
      
      ACE_CString ft_name;
      this->type_name (ft_name, ft, true);
      elem->setAttribute (X ("type"), X (ft_name.c_str ()));
          
      // Not sure if this is the only case where 'nillable' appears.          
      if (AST_Decl::NT_string == nt)
        {
          elem->setAttribute (X ("nillable"), X ("true"));
        }
        
      if (vt_member)
        {
          DOMElement *vt_ref =
            this->doc_->createElement (X ("xsd:element"));
          ACE_CString name ("_REF_");
          name += node->local_name ()->get_string ();
          vt_ref->setAttribute (X ("name"), X (name.c_str ()));
          vt_ref->setAttribute (X ("type"), X ("corba:_VALUEREF"));
          this->sub_tree_->appendChild (vt_ref);
        }
    }
  
  this->sub_tree_ = sub_tree_holder;
  return 0;
}

int
idl_to_wsdl_visitor::visit_argument (AST_Argument *node)
{
  // TODO - support for updating IDL.

  AST_Argument::Direction dir = node->direction ();
  const char *lname = node->local_name ()->get_string ();
  ACE_CString tname;
  this->type_name (tname, node->field_type ());
  
  if (AST_Argument::dir_OUT != dir)
    {
      DOMElement *arg = this->doc_->createElement (X ("part"));
      arg->setAttribute (X ("name"), X (lname));
      arg->setAttribute (X ("type"), X (tname.c_str ()));
      this->sub_tree_->appendChild (arg);
    }
  
  if (AST_Argument::dir_IN != dir)
    {
      DOMElement *response_arg = this->doc_->createElement (X ("part"));
      response_arg->setAttribute (X ("name"), X (lname));
      response_arg->setAttribute (X ("type"), X (tname.c_str ()));
      this->response_op_->appendChild (response_arg);
    }
    
  return 0;
}

int
idl_to_wsdl_visitor::visit_attribute (AST_Attribute *node)
{
  bool read_only = node->readonly ();
  DOMElement *sub_tree_holder = this->sub_tree_;
  this->sub_tree_ = this->current_port_type_;

  // Fetch from DOM tree, from table, or create.
  DOMElement *get_attr = this->process_node (node, "operation");
  DOMElement *message = 0;

  if (NOT_SEEN == this->node_status_)
    {
      this->finish_operation (node, get_attr, "_get_");
      this->gen_messages (node, message, "_get_");
      
      if (!read_only)
        {
          DOMElement *set_attr =
            this->doc_->createElement (X ("operation"));
          this->finish_operation (node, set_attr, "_set_");          
          this->gen_messages (node, message, "_set_");
          
          DOMElement *value = this->doc_->createElement (X ("part"));
          ACE_CString name;
          this->type_name (name, node->field_type ());
          value->setAttribute (X ("name"), X ("value"));
          value->setAttribute (X ("type"), X (name.c_str ()));
          message->appendChild (value);
          
          this->sub_tree_->appendChild (set_attr);
        }
    }
   
  this->sub_tree_ = sub_tree_holder;  
  return 0;
}

int
idl_to_wsdl_visitor::visit_union (AST_Union *node)
{
  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (node, "xsd:complexType");
  
  // Fetch from DOM tree if imported.
  DOMElement *seq = 0;
  DOMElement *choice = 0;
  
  if (NOT_SEEN == this->node_status_)
    {  
      ACE_CString name (node->full_name ());
      be_global->to_wsdl_name (name);
      elem->setAttribute (X ("name"), X (name.c_str ()));
      
      seq = this->doc_->createElement (X ("xsd:sequence"));
      elem->appendChild (seq);
      
      DOMElement *disc = this->doc_->createElement (X ("xsd:element"));
      disc->setAttribute (X ("name"), X ("discriminator"));
      AST_Type *dt = node->disc_type ();
      ACE_CString disc_name = dt->full_name ();
      this->type_name (disc_name, dt);
      disc->setAttribute (X ("type"), X (disc_name.c_str ()));
      seq->appendChild (disc);
      
      choice = this->doc_->createElement (X ("xsd:choice"));
      seq->appendChild (choice);
    }
  
  if (DONE != this->node_status_)
    {
      seq = dynamic_cast<DOMElement *> (elem->getFirstChild ());
      choice = dynamic_cast<DOMElement *> (seq->getLastChild ());
      
      idl_to_wsdl_visitor scope_visitor (choice);
      scope_visitor.current_union_ = node;
      
      if (scope_visitor.visit_scope (node) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                              "idl_to_wsdl_visitor::visit_structure - "
                              "codegen for scope failed\n"),
                            -1);
        }
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_union_fwd (AST_UnionFwd *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_union_branch (AST_UnionBranch *node)
{
  this->label_list_ = "";

  for (unsigned long i = 0; i < node->label_list_length (); ++i)
    {
      this->label_list_ += (0 == i ? "" : ", ");
      AST_UnionLabel *ul = node->label (i);
    
      if (ul->label_kind () == AST_UnionLabel::UL_default)
        {
          this->label_list_ += "default case";
          break;
        }
      else
        {
          this->label_list_ += (0 == i ? "case " : "");
        }

      if (this->visit_union_label (ul) != 0)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                              "idl_to_wsdl_visitor::visit_union_branch - "
                              "codegen for label failed\n"),
                            -1);
        }
    }
    
  DOMComment *comment =
    this->doc_->createComment (X (this->label_list_.c_str ()));
  this->sub_tree_->appendChild (comment);
  
  DOMElement *member = this->doc_->createElement (X ("xsd:element"));
  member->setAttribute (X ("name"), X (node->local_name ()->get_string ()));
  
  ACE_CString tname;
  AST_Type *ft = node->field_type ();
  this->type_name (tname, ft);
  member->setAttribute (X ("type"), X (tname.c_str ()));
  
  member->setAttribute (X ("minOccurs"), X ("0"));
  member->setAttribute (X ("maxOccurs"), X ("1"));
                
  if (AST_Type::VARIABLE == ft->size_type ())
    {
      member->setAttribute (X ("nillable"), X ("true"));
    }
  
  this->sub_tree_->appendChild (member);

  return 0;
}

int
idl_to_wsdl_visitor::visit_union_label (AST_UnionLabel *node)
{
  ACE_CString name_holder;
  AST_Expression *e = node->label_val ();
  AST_Decl::NodeType nt =
    this->current_union_->disc_type ()->node_type ();

  if (AST_Decl::NT_enum == nt)
    {
      UTL_Scope *parent =
        this->current_union_->disc_type ()->defined_in ();

      if (0 == parent)
        {
          name_holder = this->print_scoped_name (e->n ());
          be_global->to_wsdl_name (name_holder);
          this->label_list_ += name_holder;
        }
      else
        {
          if (ScopeAsDecl (parent)->node_type () != AST_Decl::NT_root)
            {
              name_holder = ScopeAsDecl (parent)->full_name ();
              be_global->to_wsdl_name (name_holder);
              this->label_list_ += name_holder;
              this->label_list_ += ".";
            }

          this->label_list_ += e->n ()->last_component ()->get_string ();
        }
    }
  else
    {
      this->label_list_ +=
        this->expr_val_to_string (node->label_val ()->ev ());
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_constant (AST_Constant *node)
{
  if (node->imported ())
    {
      return 0;
    }

  switch (node->et ())
    {
      case AST_Expression::EV_short:
        break;
      case AST_Expression::EV_ushort:
        break;
      case AST_Expression::EV_long:
        break;
      case AST_Expression::EV_ulong:
        break;
      case AST_Expression::EV_longlong:
        break;
      case AST_Expression::EV_ulonglong:
        break;
      case AST_Expression::EV_char:
        break;
      case AST_Expression::EV_wchar:
        break;
      case AST_Expression::EV_bool:
        break;
      case AST_Expression::EV_octet:
        break;
      case AST_Expression::EV_float:
        break;
      case AST_Expression::EV_double:
        break;
      case AST_Expression::EV_longdouble:
        break;
      case AST_Expression::EV_string:
        break;
      case AST_Expression::EV_wstring:
        break;
      case AST_Expression::EV_enum:
        break;
      default:
        break;
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_enum_val (AST_EnumVal *node)
{
  // Enum values are also added to the enum's enclosing scope.
  // We don't want to generate anything for these nodes.
  if (X ("xsd:restriction") == this->sub_tree_->getTagName ())
    {
      DOMElement *elem = this->process_node (node, "xsd:enumeration");
      
      if (NOT_SEEN == this->node_status_)
        {
          elem->setAttribute (X ("value"),
                              X (node->local_name ()->get_string ()));
        }
    }
    
  return 0;
}

int
idl_to_wsdl_visitor::visit_array (AST_Array *node)
{
  // TODO

  for (unsigned long i = 0; i < node->n_dims (); ++i)
    {
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_sequence (AST_Sequence *node)
{
  // Fetch from DOM tree, from table, or create.
  DOMElement *elem = this->process_node (this->alias_, "xsd:complexType");
  
  if (NOT_SEEN == this->node_status_)
    {
      this->gen_seq_array_common (elem,
                                  node->base_type (),
                                  node->max_size (),
                                  false,
                                  0);
    }
    
  return 0;
}

int
idl_to_wsdl_visitor::visit_string (AST_String *node)
{
  return 0;
}

int
idl_to_wsdl_visitor::visit_typedef (AST_Typedef *node)
{
  // TODO - typedefs of complex types.
  AST_Type *bt = node->base_type ();
  AST_Decl::NodeType nt = bt->node_type ();
  DOMElement *elem = 0;
  DOMElement *td_elem = 0;
  DOMElement *restriction = 0;
      
  ACE_CString name (node->full_name ());
  be_global->to_wsdl_name (name);
  
  ACE_CString bt_name;
  this->type_name (bt_name, bt);
  bool complex_type = false;

  switch (nt)
    {
      case AST_Decl::NT_sequence:
        {
          AST_Sequence *seq = AST_Sequence::narrow_from_decl (bt);
          this->alias_ = node;
          return this->visit_sequence (seq);
        }
      case AST_Decl::NT_pre_defined:
      case AST_Decl::NT_string:
      case AST_Decl::NT_typedef:
        // Fetch from DOM tree, from table, or create.
        elem = this->process_node (node, "xsd:simpleType");
        td_elem = elem;
        break;
      default:
        break;
    }
  
  if (NOT_SEEN == this->node_status_)
    {
      elem->setAttribute (X ("name"), X (name.c_str ()));
      restriction = this->doc_->createElement (X ("xsd:restriction"));
      restriction->setAttribute (X ("base"), X (bt_name.c_str ()));
      td_elem->appendChild (restriction);
    }
    
  if (DONE != this->node_status_ && complex_type)
    {
      // TODO
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_root (AST_Root *node)
{
  DOMElement *root = be_global->root_element ();
  
  if (this->visit_scope (node) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "idl_to_wsdl_visitor::visit_root - "
                          "codegen for scope failed\n"),
                        -1);
    }

  return 0;
}

int
idl_to_wsdl_visitor::visit_native (AST_Native *node)
{
  if (node->imported ())
    {
      return 0;
    }

  return 0;
}

void
idl_to_wsdl_visitor::check_prefix (AST_Decl *d)
{
  if (d->typeid_set ())
    {
      return;
    }
}

void
idl_to_wsdl_visitor::check_id_and_version (AST_Decl *d)
{
  if (d->typeid_set ())
    {
      return;
    }

  const char *the_version = d->version ();
  AST_Decl *p = ScopeAsDecl (d->defined_in ());

  if (ACE_OS::strcmp (the_version, p->version ()) != 0)
    {
    }
}

void
idl_to_wsdl_visitor::type_name (ACE_CString &name, AST_Decl *d, bool as_ref)
{
  AST_PredefinedType *pdt = 0;

  switch (d->node_type ())
    {
      case AST_Decl::NT_wstring:
      case AST_Decl::NT_string:
        name = "xsd:string";
        break;
      case AST_Decl::NT_pre_defined:
        pdt = AST_PredefinedType::narrow_from_decl (d);

        switch (pdt->pt ())
          {
            case AST_PredefinedType::PT_pseudo:
              name = "CORBA.TypeCode";
              break;
            case AST_PredefinedType::PT_object:
              name = "CORBA.Object";
              break;
            case AST_PredefinedType::PT_any:
              name = "CORBA.Any";
              break;
            case AST_PredefinedType::PT_long:
              name = "xsd:int";
              break;
            case AST_PredefinedType::PT_ulong:
              name = "xsd:unsignedInt";
              break;
            case AST_PredefinedType::PT_longlong:
              name = "xsd:long";
              break;
            case AST_PredefinedType::PT_ulonglong:
              name = "xsd:unsignedLong";
              break;
            case AST_PredefinedType::PT_short:
              name = "xsd:short";
              break;
            case AST_PredefinedType::PT_ushort:
              name = "xsd:unsignedShort";
              break;
            case AST_PredefinedType::PT_float:
              name = "xsd:float";
              break;
            case AST_PredefinedType::PT_double:
              name = "xsd:double";
              break;
            case AST_PredefinedType::PT_longdouble:
              // Mapping for this not found in CORBAi spec.
              name = "xsd:double";
              break;
            case AST_PredefinedType::PT_char:
              name = "xsd:string";
              break;
            case AST_PredefinedType::PT_wchar:
              name = "xsd:string";
              break;
            case AST_PredefinedType::PT_boolean:
              name = "xsd:boolean";
              break;
            case AST_PredefinedType::PT_octet:
              name = "xsd:unsignedByte";
              break;
            case AST_PredefinedType::PT_void:
              name = "CORBA.Any";
              break;
            default:
              break;
          }
          
        break;
      default:
        name += d->full_name ();
        be_global->to_wsdl_name (name);
        
        if (as_ref)
          {
            name = ACE_CString ("tns:") + name;
          }
          
        break;
    }
}

void
idl_to_wsdl_visitor::gen_anonymous_array (AST_Type *a,
                                          AST_Decl *wrapper)
{
  AST_Array *array = AST_Array::narrow_from_decl (a);
  AST_Type *bt = array->base_type ();

  for (unsigned long i = 0; i < array->n_dims (); ++i)
    {
    }
}

void
idl_to_wsdl_visitor::gen_label_value (AST_UnionLabel *node)
{
  AST_Expression *val = node->label_val ();
  AST_Expression::AST_ExprValue *ev = val->ev ();

  switch (ev->et)
    {
      case AST_Expression::EV_short:
        break;
      case AST_Expression::EV_ushort:
        break;
      case AST_Expression::EV_long:
        break;
      case AST_Expression::EV_ulong:
        break;
      case AST_Expression::EV_longlong:
#if ! defined (ACE_LACKS_LONGLONG_T)
#endif /* ! defined (ACE_LACKS_LONGLONG_T) */
        break;
      case AST_Expression::EV_ulonglong:
#if ! defined (ACE_LACKS_LONGLONG_T)
#endif /* ! defined (ACE_LACKS_LONGLONG_T) */
        break;
      case AST_Expression::EV_char:
        break;
      case AST_Expression::EV_wchar:
        break;
      case AST_Expression::EV_bool:
        break;
      case AST_Expression::EV_enum:
        break;
      default:
        break;
    }
}

void
idl_to_wsdl_visitor::gen_provides (AST_Component *node)
{
  ACE_Unbounded_Queue<AST_Component::port_description> &s =
    node->provides ();
  AST_Component::port_description *pd = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Component::port_description> iter (s);
       ! iter.done ();
       iter.advance ())
    {
      iter.next (pd);
    }
}

void
idl_to_wsdl_visitor::gen_uses (AST_Component *node)
{
  ACE_Unbounded_Queue<AST_Component::port_description> &s =
    node->uses ();
  AST_Component::port_description *pd = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Component::port_description> iter (s);
       ! iter.done ();
       iter.advance ())
    {
      iter.next (pd);

      if (pd->is_multiple)
        {
        }
      else
        {
        }
    }
}

void
idl_to_wsdl_visitor::gen_publishes (AST_Component *node)
{
  ACE_Unbounded_Queue<AST_Component::port_description> &s =
    node->publishes ();
  AST_Component::port_description *pd = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Component::port_description> iter (s);
       ! iter.done ();
       iter.advance ())
    {
      iter.next (pd);
    }
}

void
idl_to_wsdl_visitor::gen_emits (AST_Component *node)
{
  ACE_Unbounded_Queue<AST_Component::port_description> &s =
    node->emits ();
  AST_Component::port_description *pd = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Component::port_description> iter (s);
       ! iter.done ();
       iter.advance ())
    {
      iter.next (pd);
    }
}

void
idl_to_wsdl_visitor::gen_consumes (AST_Component *node)
{
  ACE_Unbounded_Queue<AST_Component::port_description> &s =
    node->consumes ();
  AST_Component::port_description *pd = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Component::port_description> iter (s);
       ! iter.done ();
       iter.advance ())
    {
      iter.next (pd);
    }
}

void
idl_to_wsdl_visitor::gen_factories (AST_Home *node,
                                    AST_Interface &)
{
  AST_Operation **item = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Operation *> i (node->factories ());
       ! i.done ();
       i.advance ())
    {
      i.next (item);

      this->gen_params (*item, (*item)->argument_count ());

      UTL_ExceptList *exceps = (*item)->exceptions ();

      if (exceps != 0 && exceps->length () > 0)
        {
          this->gen_exception_list (exceps, "", false);
        }
      else
        {
        }
    }
}

void
idl_to_wsdl_visitor::gen_finders (AST_Home *node,
                                  AST_Interface &)
{
  AST_Operation **item = 0;

  for (ACE_Unbounded_Queue_Iterator<AST_Operation *> i (node->finders ());
       ! i.done ();
       i.advance ())
    {
      i.next (item);

      this->gen_params (*item, (*item)->argument_count ());

      UTL_ExceptList *exceps = (*item)->exceptions ();

      if (exceps != 0 && exceps->length () > 0)
        {
          this->gen_exception_list (exceps, "", false);
        }
      else
        {
        }
    }
}

void
idl_to_wsdl_visitor::gen_params (UTL_Scope *s, int arg_count)
{
  if (arg_count > 0)
    {
      for (UTL_ScopeActiveIterator si (s, UTL_Scope::IK_decls);
           !si.is_done ();)
        {
          if (si.item ()->ast_accept (this) != 0)
            {
              ACE_ERROR ((LM_ERROR,
                          "idl_to_wsdl_visitor::gen_params - "
                          "codegen for parameters failed\n"));
            }

          si.next ();

          if (!si.is_done ())
            {
            }
        }
    }
}

void
idl_to_wsdl_visitor::gen_exception_list (UTL_ExceptList *exceptions,
                                         const char *prefix,
                                         bool closed)
{
  if (exceptions != 0 && exceptions->length () > 0)
    {
      for (UTL_ExceptlistActiveIterator ei (exceptions);
           !ei.is_done ();)
        {
          ei.next ();

          if (!ei.is_done () || !closed)
            {
            }
        }

      if (closed)
        {
        }
    }
}

void
idl_to_wsdl_visitor::gen_seq_array_common (DOMElement *elem,
                                           AST_Type *base_type,
                                           AST_Expression *size,
                                           bool is_array,
                                           const char *insert)
{
  ACE_CString scope_name;
  AST_Decl *p = ScopeAsDecl (this->alias_->defined_in ());
  
  if (AST_Decl::NT_root != p->node_type ())
    {
      this->type_name (scope_name, p, false);
      scope_name += ".";
    }
    
  scope_name += "_SE_";
  scope_name += this->alias_->local_name ()->get_string ();
  elem->setAttribute (X ("name"), X (scope_name.c_str ()));
  
  DOMElement *content =
    this->doc_->createElement (X ("complexContent"));
  elem->appendChild (content);
  
  DOMElement *restriction =
    this->doc_->createElement (X ("xsd:restriction"));
  restriction->setAttribute (X ("base"), X ("SOAP-ENC:Array"));
  content->appendChild (restriction);
  
  DOMElement *seq = this->doc_->createElement (X ("xsd:sequence"));
  restriction->appendChild (seq);
  
  DOMElement *item = this->doc_->createElement (X ("xsd:element"));
  item->setAttribute (X ("name"), X ("item"));
  
  // Can't be 0 for an array, parser would catch it.
  unsigned long max_size = size->ev ()->u.ulval;
  ACE_CString bound (
      0 == max_size
        ? "unbounded"
        : this->expr_val_to_string (size->ev ()));
         
  item->setAttribute (X ("minOccurs"), X (is_array ? bound.c_str () : "0"));
  item->setAttribute (X ("maxOccurs"), X (bound.c_str ()));
  
  ACE_CString tname;
  this->type_name (tname, base_type);
  item->setAttribute (X ("type"), X (tname.c_str ()));
  
  seq->appendChild (item);
  
  DOMElement *attr = this->doc_->createElement (X ("xsd:attribute"));
  attr->setAttribute (X ("ref"), X ("SOAP-ENC:arrayType"));
  tname += "[]";
  attr->setAttribute (X ("wsdl:arrayType"), X (tname.c_str ()));
  
  restriction->appendChild (attr);
}

DOMElement *
idl_to_wsdl_visitor::process_node (AST_Decl *node, const char *tag_name)
{
  // First see if it's been imported with an XME file.
  DOMElement *elem =
    be_global->imported_dom_element (
        this->sub_tree_,
        node->local_name ()->get_string ()
      );

  // Also see if it's been put in the decl table.
  DOMElement *table_elem = 0;
  int result =
    be_global->decl_elem_table ().find (node->repoID (), table_elem);

  if (0 == elem)
    {
      if (0 == result)
        {
          elem = table_elem;
        }
      else
        {
          this->node_status_ = NOT_SEEN;
          elem = this->doc_->createElement (X (tag_name));
        }

      // We add the elem to the table the first time the node is
      // seen, but we don't add the stuff below unless the elem
      // has not been imported, and we're in
      // the IDL file where the node is defined.
      if (!node->imported ())
        {
          this->sub_tree_->appendChild (elem);
        }
    }
  else
    {
      if (0 == result)
        {
          this->node_status_ = DONE;
        }
      else
        {
          this->node_status_ = IN_DOM_TREE;
        }
    }

  if (0 != result)
    {
      // Store the DOMElement.
      be_global->decl_elem_table ().bind (ACE::strnew (node->repoID ()),
                                          elem);
    }
  
  return elem;
}

ACE_CString
idl_to_wsdl_visitor::print_scoped_name (UTL_IdList *sn)
{
  long first = true;
  long second = false;
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
          first = second = false;
        }

      // Print the identifier.
      id = i.item ();
      retval += id->get_string ();

      if (first)
        {
          if (ACE_OS::strcmp (id->get_string (), "") != 0)
            {
              // Does not start with a "".
              first = false;
            }
          else
            {
              second = true;
            }
        }
    }

  return retval;
}

ACE_CString
idl_to_wsdl_visitor::expr_val_to_string (AST_Expression::AST_ExprValue *ev)
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

void
idl_to_wsdl_visitor::tranfer_scope_elements (AST_Home *src,
                                             AST_Interface &dst)
{
  // Transfer the elements of the home's scope to the temporary
  // explicit home interface.
  for (UTL_ScopeActiveIterator src_iter (src, UTL_Scope::IK_decls);
       ! src_iter.is_done ();
       src_iter.next ())
    {
      AST_Decl *d = src_iter.item ();
      d->set_defined_in (&dst);
      UTL_ScopedName *new_name =
        this->create_scoped_name (0,
                                  d->local_name ()->get_string (),
                                  0,
                                  &dst);
      d->set_name (new_name);
      dst.add_to_scope (d);
    }

  // Visit the transferred scope elements normally to generate the IDL.
  // This way referenced items will have the interface's name in the
  // scoped name instead of the home's name.
  for (UTL_ScopeActiveIterator dst_iter (&dst, UTL_Scope::IK_decls);
       ! dst_iter.is_done ();
       dst_iter.next ())
    {
      if (dst_iter.item ()->ast_accept (this) != 0)
        {
          ACE_ERROR ((LM_ERROR,
                      "idl_to_wsdl_visitor::tranfer_scope_elements - "
                      "codegen for destination scope failed\n"));
        }
    }
}

UTL_ScopedName *
idl_to_wsdl_visitor::create_scoped_name (const char *prefix,
                                         const char *local_name,
                                         const char *suffix,
                                         AST_Decl *parent)
{
  ACE_CString local_string (prefix,
                            0,
                            0);
  local_string += local_name;
  local_string += suffix;
  Identifier *local_id = 0;
  ACE_NEW_RETURN (local_id,
                  Identifier (local_string.fast_rep ()),
                  0);
  UTL_ScopedName *last_segment = 0;
  ACE_NEW_RETURN (last_segment,
                  UTL_ScopedName (local_id,
                                  0),
                  0);
  UTL_ScopedName *full_name =
    static_cast<UTL_ScopedName *> (parent->name ()->copy ());
  full_name->nconc (last_segment);
  return full_name;
}

void
idl_to_wsdl_visitor::finish_operation (AST_Decl *node,
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
    
  // Create and populate the 'operation' element under 'binding'.
    
  DOMElement *binding_op = this->doc_->createElement (X ("operation"));
  binding_op->setAttribute (X ("name"), X (lname.c_str ()));
  this->current_binding_->appendChild (binding_op);
  
  DOMElement *soap_op = this->doc_->createElement (X ("soap:operation"));
  ACE_CString sname (ScopeAsDecl (node->defined_in ())->full_name ());
  be_global->to_wsdl_name (sname);
  sname += "#";
  sname += lname;
  soap_op->setAttribute (X ("soapAction"), X (sname.c_str ()));
  binding_op->appendChild (soap_op);
  
  this->fill_binding_op (binding_op);
    
  // TODO - attribute exceptions (no OMG mapping yet).  
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
          binding_op->appendChild (except_msg);
          
          DOMElement *except_msg_clone =
            dynamic_cast<DOMElement *> (except_msg->cloneNode (false));
          except_msg_clone->setAttribute (X ("message"), X (fname.c_str ()));
          elem->appendChild (except_msg_clone);
        }
    }

  DOMElement *sys_except_msg = this->doc_->createElement (X ("fault"));
  sys_except_msg->setAttribute (X ("name"), X ("CORBA.SystemException"));
  
  DOMElement *binding_sys_except =
    dynamic_cast<DOMElement *> (sys_except_msg->cloneNode (false));
  binding_op->appendChild (binding_sys_except);
  
  sys_except_msg->setAttribute (X ("message"),
                                X ("corba:CORBA.SystemExceptionMessage"));
  elem->appendChild (sys_except_msg);
}

void
idl_to_wsdl_visitor::gen_messages (AST_Decl *node,
                                   DOMElement *&message,
                                   const char *prefix)
{
  message = this->doc_->createElement (X ("message"));
  ACE_CString name (ScopeAsDecl (node->defined_in ())->full_name ());
  be_global->to_wsdl_name (name);
  name += ".";
  name += (0 != prefix ? prefix : "");
  name += node->local_name ()->get_string ();
  message->setAttribute (X ("name"), X (name.c_str ()));
  be_global->root_element ()->appendChild (message);
  
  DOMElement *response = this->doc_->createElement (X ("message"));
  name += "Response";
  response->setAttribute (X ("name"), X (name.c_str ()));
  be_global->root_element ()->appendChild (response);
  
  AST_Operation *op = AST_Operation::narrow_from_decl (node);
  AST_Attribute *attr = AST_Attribute::narrow_from_decl (node);
  
  if (0 != op && !op->void_return_type () || ACE_CString (prefix) == "_get_")
    {
      AST_Type *rt = (0 != op ? op->return_type () : attr->field_type ());
      ACE_CString rname;
      this->type_name (rname, rt);
      
      DOMElement *return_elem = this->doc_->createElement (X ("part"));
      return_elem->setAttribute (X ("name"), X ("_return"));
      return_elem->setAttribute (X ("type"), X (rname.c_str ()));
      
      response->appendChild (return_elem);
    }
}

void
idl_to_wsdl_visitor::gen_inherited_operations (AST_Interface *node)
{
  // Not compatible with 'updating IDL' feature.
  for (long i = 0; i < node->n_inherits_flat (); ++i)
    {
      AST_Interface *parent = node->inherits_flat ()[i];
      
      for (UTL_ScopeActiveIterator iter (parent, UTL_Scope::IK_decls);
           !iter.is_done ();
           iter.next ())
        {
          AST_Decl *d = iter.item ();
          AST_Operation *op = AST_Operation::narrow_from_decl (d);
          AST_Attribute *attr = AST_Attribute::narrow_from_decl (d);
          
          if (0 != op)
            {
              DOMElement *operation =
                this->doc_->createElement (X ("operation"));
              this->current_port_type_->appendChild (operation);
              this->finish_operation (op, operation, 0);
            }
          else if (0 != attr)
            {
              DOMElement *get_operation =
                this->doc_->createElement (X ("operation"));
              this->current_port_type_->appendChild (get_operation);
              this->finish_operation (attr, get_operation, "_get_");
              this->current_port_type_->appendChild (get_operation);
              
              if (!attr->readonly ())
                {
                  DOMElement *set_operation =
                    this->doc_->createElement (X ("operation"));
                  this->finish_operation (attr, set_operation, "_set_");
                  this->current_port_type_->appendChild (set_operation);
                }
            }
          else
            {
              continue;
            }
        }
    }
}

void
idl_to_wsdl_visitor::fill_binding_op (DOMElement *binding_op)
{
  DOMElement *binding_input = this->doc_->createElement (X ("input"));
  binding_op->appendChild (binding_input);
  
  DOMElement *binding_output = this->doc_->createElement (X ("output"));
  binding_op->appendChild (binding_output);
  
  DOMElement *soap_body = this->doc_->createElement (X ("soap:body"));
  soap_body->setAttribute (X ("use"), X ("encoded"));
  soap_body->setAttribute (X ("encodingStyle"),
                           X ("http://schemas.xmlsoap.org/soap/encoding/"));
  soap_body->setAttribute (X ("namespace"),
                           X ("http://www.omg.org/IDL-WSDL/1.0/"));
  
  binding_input->appendChild (soap_body);
  
  DOMElement *soap_body_clone =
    dynamic_cast<DOMElement *> (soap_body->cloneNode (false));
  binding_output->appendChild (soap_body_clone);
}

