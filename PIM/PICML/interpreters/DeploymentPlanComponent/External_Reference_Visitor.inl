// -*- C++ -*-
// $Id$

//
// PICML_External_Reference_Visitor
//
inline
PICML_External_Reference_Visitor::
PICML_External_Reference_Visitor (xercesc::DOMDocument * doc,
                                  std::vector <xercesc::DOMElement *> & conns)
: doc_ (doc),
  conns_ (conns)
{

}

//
// ~PICML_External_Reference_Visitor
//
inline
PICML_External_Reference_Visitor::~PICML_External_Reference_Visitor (void)
{

}
