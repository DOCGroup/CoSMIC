// $Id$

#include "PlanLocalityVisitor.h"
#include "Utils/XercesString.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <algorithm>

//
// PlanLocalityVisitor
//
PlanLocalityVisitor::PlanLocalityVisitor (xercesc::DOMElement * root)
: root_ (root),
  doc_ (root->getOwnerDocument ())
{

}

//
// ~PlanLocalityVisitor
//
PlanLocalityVisitor::~PlanLocalityVisitor (void)
{

}

//
// Visit_DeploymentPlan
//
void PlanLocalityVisitor::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();
  std::for_each (nodes.begin (),
                 nodes.end (),
                 boost::bind (&PICML::NodeReference::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_NodeReference
//
void PlanLocalityVisitor::
Visit_NodeReference (const PICML::NodeReference & ref)
{
  std::set <PICML::InstanceMapping> mapping = ref.srcInstanceMapping ();
  std::for_each (mapping.begin (),
                 mapping.end (),
                 boost::bind (&PICML::InstanceMapping::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_InstanceMapping
//
void PlanLocalityVisitor::
Visit_InstanceMapping (const PICML::InstanceMapping & mapping)
{
  PICML::CollocationGroup group = mapping.srcInstanceMapping_end ();
  group.Accept (*this);
}

//
// Visit_CollocationGroup
//
void PlanLocalityVisitor::
Visit_CollocationGroup (const PICML::CollocationGroup & group)
{
  std::set <PICML::CollocationGroupMember> members = group.members ();

  if (members.empty ())
    return;

  // Begin a new locality constaint.
  xercesc::DOMElement * locality = this->doc_->createElement (Utils::XStr ("localityConstraint"));
  this->root_->appendChild (locality);

  // Right now, we assume all members in a collocation group have
  // the SameProcess constraint.
  xercesc::DOMElement* constraint = this->doc_->createElement (Utils::XStr ("constraint"));
  constraint->appendChild (this->doc_->createTextNode (Utils::XStr ("SameProcess")));
  locality->appendChild (constraint);

  std::swap (this->root_, locality);

  // Visit all the components in this constraint.
  std::for_each (members.begin (),
                 members.end (),
                 boost::bind (&PlanLocalityVisitor::Visit_CollocationGroupMember,
                              this,
                              _1));

  std::swap (this->root_, locality);
}

//
// Visit_CollocationGroupMember
//
void PlanLocalityVisitor::
Visit_CollocationGroupMember (const PICML::CollocationGroupMember & member)
{
  Uml::Class type = member.type ();

  if (type == PICML::ComponentRef::meta)
    PICML::ComponentRef::Cast (member).Accept (*this);
}

//
// Visit_ComponentRef
//
void PlanLocalityVisitor::
Visit_ComponentRef (const PICML::ComponentRef & ref)
{
  PICML::Component component = ref.ref ();

  if (Udm::null != component)
    component.Accept (*this);
}

//
// Visit_Component
//
void PlanLocalityVisitor::
Visit_Component (const PICML::Component & component)
{
  // Write this component to the locality constraint.
  xercesc::DOMElement * instance = this->doc_->createElement (Utils::XStr ("constrainedInstance"));
  this->root_->appendChild (instance);

  std::string uuid = "_" + std::string (component.UUID ());
  instance->setAttribute (Utils::XStr ("xmi:idref"), Utils::XStr (uuid));
}
