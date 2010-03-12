//  -*- C++ -*-
// $Id$

//
// XML_Document
//
inline
XML_Document::XML_Document (xercesc::DOMElement * parent)
: curr_ (parent)
{

}

//
// XML_Document
//
inline
XML_Document::~XML_Document (void)
{

}

//
// create_element
//
inline
xercesc::DOMElement *
XML_Document::create_element (const std::string & name)
{
  return XML_Document::create_element (this->curr_, name);
}

