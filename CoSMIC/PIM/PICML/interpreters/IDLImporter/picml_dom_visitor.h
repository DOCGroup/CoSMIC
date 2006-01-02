// $Id$

/* -*- c++ -*- */
// ============================================================================
//
// = LIBRARY
//    IDL_TO_PICML_BE_DLL
//
// = FILENAME
//    picml_dom_visitor.h
//
// = DESCRIPTION
//    The DOM tree visitor.
//
// = AUTHOR
//    Jeff Parsons <j.parsons@vanderbilt.edu>
//
// ============================================================================

#ifndef IDL_TO_PICML_PICML_DOM_VISITOR_H
#define IDL_TO_PICML_PICML_DOM_VISITOR_H

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include <xercesc/dom/DOM.hpp>

using namespace xercesc;

class picml_dom_visitor
{
  //
  // = TITLE
  //    picml_dom_visitor.
  //
  // = DESCRIPTION
  //    PICML IDL importer DOM visitor. This visitor traverses
  //    the DOM tree (after picml_visitor is finished adding
  //    to or modifying it) and either removes an element that
  //    does not have a counterpart in the AST, modifies attributes
  //    or children as necessary, or leaves the element unchanged.
  //
public:
  bool visit_children (DOMNode *node);
  bool visit_dom_element (DOMElement *node);
};

 #endif /* IDL_TO_PICML_PICML_DOM_VISITOR_H */
