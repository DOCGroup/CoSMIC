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
  PICML_External_Reference_Visitor (xercesc::DOMDocument * doc);

  /// Destructor
  virtual ~PICML_External_Reference_Visitor (void);

  // Visit a Component
  virtual void Visit_ComponentInstance (const PICML::ComponentInstance & c);

  virtual void Visit_RequiredRequestPortInstance (const PICML::RequiredRequestPortInstance & );

  virtual void Visit_ProvidedRequestPortInstance (const PICML::ProvidedRequestPortInstance & );

  virtual void Visit_InEventPortInstance (const PICML::InEventPortInstance & );

  virtual void Visit_OutEventPortInstance (const PICML::OutEventPortInstance & );

  const std::vector <xercesc::DOMElement *> & connections (void) const;

private:
  void Visit_Port (const PICML::MgaObject & port,
                   const PICML::MgaObject & porttype,
                   const std::string & provider_type,
                   bool provider,
                   const PICML::ExternalDelegate & ed);

  xercesc::DOMDocument * doc_;

  std::vector <xercesc::DOMElement *> conns_;
};

#include "External_Reference_Visitor.inl"

#endif  // !defined _PICML_EXTERNAL_REFERENCE_VISITOR_H_
