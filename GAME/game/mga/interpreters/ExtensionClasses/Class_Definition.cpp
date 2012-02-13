// $Id$

#include "StdAfx.h"
#include "Class_Definition.h"

#include "boost/bind.hpp"

//
// build
//
void Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // First, we need to gather all connections from this FCO that could
  // lead to another FCO that must be included in the header file.
  fco->in_connections ("SourceToConnector", this->src_to_connector_);
  fco->in_connections ("ConnectorToDestination", this->connector_to_dst_);
  fco->in_connections ("Containment", this->containment_);
  fco->in_connections ("FolderContainment", this->containment_);
  fco->in_connections ("ReferTo", this->refers_to_);
  fco->in_connections ("HasAttribute", this->has_attributes_);
  fco->in_connections ("AssociationClass", this->association_class_);

  // There could be proxy elements in the metamodel. We therefore
  // need to gather all of them and continue building the class
  // definition as if they are this FCO object.
  std::vector <GAME::Mga::Reference> referenced_by;
  fco->referenced_by (referenced_by);

  std::for_each (referenced_by.begin (),
                 referenced_by.end (),
                 boost::bind (&Class_Definition::build,
                              this,
                              boost::bind (&GAME::Mga::Reference::get, _1)));
}
