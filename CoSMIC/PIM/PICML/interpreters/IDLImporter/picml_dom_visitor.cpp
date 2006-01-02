/* -*- c++ -*- */
// $Id$

#include "picml_dom_visitor.h"
#include "be_extern.h"

bool
picml_dom_visitor::visit_children (DOMNode *node)
{
  return true;
}

bool
picml_dom_visitor::visit_dom_element (DOMElement *node)
{
  return true;
}