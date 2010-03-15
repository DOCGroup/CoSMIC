// -*- C++ -*-

//=============================================================================
/**
 * @file      XML_Document.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_XML_DOCUMENT_H_
#define _PICML_XML_DOCUMENT_H_

#include "xercesc/dom/DOM.hpp"
#include <string>

/**
 * @class XML_Document
 *
 * Base class for all XML documents in CoSMIC/PICML. Right now,
 * we are building up this class in this interpreter. When the
 * directory structure of CoSMIC is flushed out more, this class
 * will be moved elsewhere.
 */
class XML_Document
{
public:
  /// Default constructor
  XML_Document (xercesc::DOMElement * curr);

  /// Destructor.
  virtual ~XML_Document (void);

  /**
   * Helper class for creating a DOM element that has simple
   * content. Simple content is defined as <name>value</name>.
   */
  static
    xercesc::DOMElement *
    create_simple_content (xercesc::DOMNode * parent,
                           const std::string & name,
                           const std::string & value);

  static
    xercesc::DOMElement *
    create_element (xercesc::DOMNode * parent,
                    const std::string & name);

protected:
  xercesc::DOMElement * create_element (const std::string & name);

  xercesc::DOMElement *
    create_simple_content (const std::string & name,
                           const std::string & value);

  /// The current parent element.
  xercesc::DOMElement * curr_;
};

#include "XML_Document.inl"

#endif  // !define _PICML_XML_DOCUMENT_H_

