// -*- C++ -*-

//=============================================================================
/**
 * @file      External_Reference_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_EXTERNAL_REFERENCE_VISITOR_H_
#define _PICML_EXTERNAL_REFERENCE_VISITOR_H_

#include "PICML/PICML.h"
#include "XML_Document.h"

/**
 * @class PICML_External_Reference_Visitor
 *
 * Visitor that is responsible for generating external reference
 * connections to a deployment plan.
 */
class PICML_External_Reference_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  /// Default constructor.
  PICML_External_Reference_Visitor (xercesc::DOMElement * parent);

  /// Destructor
  virtual ~PICML_External_Reference_Visitor (void);

  // Visit a Component
  virtual void Visit_Component (const PICML::Component & c);

  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort & receptacle);

  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & facet);

  virtual void Visit_InEventPort (const PICML::InEventPort & in_event);

  virtual void Visit_OutEventPort (const PICML::OutEventPort & out_event);

  virtual void Visit_ExternalDelegate (const PICML::ExternalDelegate & ed);

  virtual void Visit_ExternalPort (const PICML::ExternalPort & port);

protected:
  void Visit_Port (const PICML::Port & port,
                   const std::string & type,
                   const PICML::ExternalDelegate & ed);
};

#include "External_Reference_Visitor.inl"

#endif  // !defined _PICML_EXTERNAL_REFERENCE_VISITOR_H_
