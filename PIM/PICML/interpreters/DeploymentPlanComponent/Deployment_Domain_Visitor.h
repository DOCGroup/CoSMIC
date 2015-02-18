// -*- C++ -*-

#ifndef DEPLOYMENT_DOMAIN_VISITOR_H
#define DEPLOYMENT_DOMAIN_VISITOR_H

#include "../DomainComponent/Domain_Visitor.h"

/**
 * @class Deployment_Domain_Visitor
 */
class Deployment_Domain_Visitor : public Domain_Visitor
{
public:
  Deployment_Domain_Visitor (const std::string & outpath);
  virtual ~Deployment_Domain_Visitor (void);

  virtual void Visit_DeploymentPlan (PICML::DeploymentPlan_in);
  virtual void Visit_NodeReference (PICML::NodeReference_in);
  virtual void Visit_PropertyMapping (PICML::PropertyMapping_in);
};

#endif