// -*- C++ -*-

//=============================================================================
/**
 * @file      PlanLocalityVisitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_PLAN_LOCALITY_VISITOR_H_
#define _PICML_PLAN_LOCALITY_VISITOR_H_

#include "PICML/PICML.h"
#include "xercesc/dom/DOM.hpp"

/**
 * @class PlanLocalityVisitor
 */
class PlanLocalityVisitor : public PICML::Visitor
{
public:
  PlanLocalityVisitor (xercesc::DOMElement * root);

  virtual ~PlanLocalityVisitor (void);

  virtual void Visit_DeploymentPlan (const PICML::DeploymentPlan & );

  virtual void Visit_NodeReference (const PICML::NodeReference &);

  virtual void Visit_InstanceMapping (const PICML::InstanceMapping &);

  virtual void Visit_CollocationGroup (const PICML::CollocationGroup &);

  virtual void Visit_ComponentRef (const PICML::ComponentRef &);

  virtual void Visit_Component (const PICML::Component &);

private:

  virtual void Visit_CollocationGroupMember (const PICML::CollocationGroupMember &);

  xercesc::DOMElement * root_;

  xercesc::DOMDocument * doc_;
};

#endif  // !defined _PICML_PLAN_LOCALITY_VISITOR_H_
