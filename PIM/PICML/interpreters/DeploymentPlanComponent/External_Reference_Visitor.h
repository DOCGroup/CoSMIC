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
#include "PICML/Visitor.h"

#include "game/xml/Fragment.h"

namespace PICML
{

namespace Deployment
{

/**
 * @class External_Reference_Visitor
 *
 * Visitor that is responsible for generating external reference
 * connections to a deployment plan.
 */
class External_Reference_Visitor : public Visitor
{
public:
  /// Default constructor.
  External_Reference_Visitor (GAME::Xml::Fragment document, std::vector <GAME::Xml::Fragment> & conns);

  /// Destructor
  virtual ~External_Reference_Visitor (void);

  // Visit a Component
  virtual void Visit_ComponentInstance (ComponentInstance_in);
  virtual void Visit_RequiredRequestPortInstance (RequiredRequestPortInstance_in);
  virtual void Visit_ProvidedRequestPortInstance (ProvidedRequestPortInstance_in);
  virtual void Visit_InEventPortInstance (InEventPortInstance_in);
  virtual void Visit_OutEventPortInstance (OutEventPortInstance_in);

  const std::vector <GAME::Xml::Fragment> & connections (void) const;

private:
  void Visit_Port (GAME::Mga::FCO_in port,
                   GAME::Mga::FCO_in porttype,
                   const std::string & provider_type,
                   bool provider,
                   ExternalDelegate_in ed);

  GAME::Xml::Fragment document_;

  std::vector <GAME::Xml::Fragment> & conns_;
};

}
}

#include "External_Reference_Visitor.inl"

#endif  // !defined _PICML_EXTERNAL_REFERENCE_VISITOR_H_
