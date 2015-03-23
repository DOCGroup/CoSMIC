#include "StdAfx.h"
#include "Deployment_Domain_Visitor.h"

#include "External_Reference_Visitor.h"
#include "game/xml/String.h"

#include <algorithm>
#include <functional>
#include <sstream>

using GAME::Xml::String;

Deployment_Domain_Visitor::
Deployment_Domain_Visitor (const std::string & outpath)
: Domain_Visitor (outpath)
{
  this->add_shortname ("StringIOR", "edu.vanderbilt.dre.DAnCE.StringIOR");
  this->add_shortname ("CORBAName", "edu.vanderbilt.dre.DAnCE.CORBAName"); 
}

Deployment_Domain_Visitor::~Deployment_Domain_Visitor (void)
{

}

void Deployment_Domain_Visitor::
Visit_DeploymentPlan (PICML::DeploymentPlan_in plan)
{
  // Start a new XML document for this deployment plan.
  this->begin_document (plan->UUID (), plan->label ());

  // Visit all the nodes in the deployment plan. This will gather all
  // the necessary parts of the XML document. We do not process the
  // connections at this point because we want to wait until we have
  // all the deployed instances. This will make a life a little less
  // hectic in the long run.
  for (PICML::NodeReference noderef : plan->get_NodeReferences ())
    noderef->accept (this);

  // Write the XML document to file.
  this->write_document (plan->name ());
}

void Deployment_Domain_Visitor::
Visit_NodeReference (PICML::NodeReference_in noderef)
{
  PICML::Node node = noderef->refers_to_Node ();
  this->fragment_ = this->fragment_.append_element ("node");
  this->fragment_.append_simple_content ("name", noderef->name ());   
  this->fragment_.append_simple_content ("label", node->label ());

  this->fragment_ = this->fragment_.append_element ("resource");
  this->fragment_.append_simple_content ("name", "Node Address");
  this->fragment_.append_simple_content ("resourceType", "edu.vanderbilt.dre.DAnCE.NodeAddress");

  for (PICML::PropertyMapping mapping : noderef->src_of_PropertyMapping ())
    mapping->accept (this);
}

void Deployment_Domain_Visitor::
Visit_PropertyMapping (PICML::PropertyMapping_in mapping)
{
  PICML::Property prop = mapping->dst_Property ();
  prop->accept (this);
}
