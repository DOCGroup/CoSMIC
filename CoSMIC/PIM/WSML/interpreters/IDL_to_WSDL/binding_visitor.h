// $Id: binding_visitor.h,v 1.3 2006/02/09 16:51:07 parsons Exp $

/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    IDL_TO_WSDL_BE_DLL
//
// = FILENAME
//    binding_visitor.h
//
// = DESCRIPTION
//    Generates binding elements in the WSDL document.
//
// = AUTHOR
//    Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#ifndef BINDING_VISITOR_H
#define BINDING_VISITOR_H

#include "idl_to_wsdl_visitor.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class binding_visitor : public idl_to_wsdl_visitor
{
  //
  // = TITLE
  //    binding_visitor
  //
  // = DESCRIPTION
  //    Generates binding elements in the WSDL document.
  //
public:
  binding_visitor (DOMElement *sub_tree);
  virtual ~binding_visitor (void);

  virtual int visit_component (AST_Component *node);
  
private:
  void fill_binding_op (DOMElement *binding_op,
                        DOMElement *port_type_op);
  void gen_binding (DOMElement *port_type,
                    AST_Component *node,
                    AST_Type *port_impl = 0,
                    const char *port_name = 0);
  
private:
  DOMElement *current_binding_;
};

#endif /* BINDING_VISITOR_H */
