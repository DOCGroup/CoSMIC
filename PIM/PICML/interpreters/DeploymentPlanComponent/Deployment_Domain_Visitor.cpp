#include "StdAfx.h"
#include "Deployment_Domain_Visitor.h"

#include "Data_Type_Visitor.h"
#include "Data_Value_Visitor.h"
#include "External_Reference_Visitor.h"

#include "Utils/UDM/Position_Sort_T.h"
#include "Utils/udm/visit.h"

#include "game/xml/String.h"

#include "UmlExt.h"
#include "boost/bind.hpp"

#include <algorithm>
#include <functional>
#include <sstream>

using GAME::Xml::String;

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;
using xercesc::DOMElement;


//
// Deployment_Domain_Visitor
//
Deployment_Domain_Visitor::
Deployment_Domain_Visitor (const std::string & outputPath)
: impl_ (0),
  doc_ (0),
  output_ (0),
  serializer_ (0),
  outputPath_ (outputPath)
{
  this->init ();
}


//
// ~Deployment_Domain_Visitor
//
Deployment_Domain_Visitor::~Deployment_Domain_Visitor (void)
{
  if (this->output_)
    this->output_->release ();

  if (this->serializer_)
    this->serializer_->release ();
}


//
// init
//
void Deployment_Domain_Visitor::
init (void)
{
  this->impl_ = DOMImplementationRegistry::getDOMImplementation (L"LS");

  this->serializer_ = ((DOMImplementationLS*)impl_)->createLSSerializer ();
  this->output_ = ((DOMImplementationLS*)this->impl_)->createLSOutput ();

  // Set features if the serializer supports the feature/mode
  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  if (this->serializer_->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
    this->serializer_->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);
}


//
// init_document
//
void Deployment_Domain_Visitor::
init_document (const std::string& rootName)
{

  if (this->doc_)
    this->doc_->release ();

  // Create the document
  this->doc_ = this->impl_->createDocument (String ("http://www.omg.org/Deployment"),
                                            String (rootName.c_str ()),
                                            0);

  this->doc_->setXmlVersion (String ("1.0"));
}


//
// Visit_DeploymentPlan
//
void Deployment_Domain_Visitor::
Visit_DeploymentPlan (const PICML::DeploymentPlan & plan)
{
  // Start a new XML document for this deployment plan.
  this->init_document ("Deployment:domain");

  // Prepare the XML document for writing.
  this->curr_root_ = this->doc_->getDocumentElement ();

  this->curr_root_->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                                    String ("xmlns:Deployment"),
                                    String ("http://www.omg.org/Deployment"));

  this->curr_root_->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                                    String ("xmlns:xsi"),
                                    String ("http://www.w3.org/2001/XMLSchema-instance"));

  this->curr_root_->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                                    String ("xmlns:xmi"),
                                    String ("http://www.omg.org/XMI"));

  this->curr_root_->setAttribute (String ("xsi:schemaLocation"),
                      String ("http://www.omg.org/Deployment Deployment.xsd"));

  this->create_simple_content (this->curr_root_, "UUID", plan.UUID ());
  this->create_simple_content (this->curr_root_, "label", plan.label ());

  // Visit all the nodes in the deployment plan. This will gather all
  // the necessary parts of the XML document. We do not process the
  // connections at this point because we want to wait until we have
  // all the deployed instances. This will make a life a little less
  // hectic in the long run.


  std::vector <PICML::NodeReference> nodes = plan.NodeReference_children ();

  std::for_each (nodes.begin (),
                 nodes.end (),
                 boost::bind (&PICML::NodeReference::Accept,
                              _1,
                              boost::ref (*this)));

  // Open the XML file for writing.
  std::ostringstream filename;
  filename << this->outputPath_ << "/" << plan.name () << ".cdd";
  LocalFileFormatTarget target (filename.str ().c_str ());

  // Write the document.
  this->output_->setByteStream (&target);
  this->serializer_->write (this->doc_, this->output_);
  this->output_->setByteStream (0);

  // Release the document.
  this->doc_->release ();
}


//
// Visit_NodeReference
//
void Deployment_Domain_Visitor::
Visit_NodeReference (const PICML::NodeReference & noderef)
{
  PICML::Node parent_noderef = noderef.ref ();

  std::set <PICML::PropertyMapping> mapping = noderef.dstPropertyMapping ();

  this->curr_node_ = this->create_element (this->curr_root_, "node");
  this->create_simple_content (this->curr_node_, "name", noderef.name ());
  this->create_simple_content (this->curr_node_, "label", parent_noderef.label ());

  this->curr_resource_ = this->create_element (this->curr_node_, "resource");
  this->create_simple_content (this->curr_resource_, "name", "Node Address");
  this->create_simple_content (this->curr_resource_, "resourceType", "edu.vanderbilt.dre.DAnCE.NodeAddress");

  for(auto m:mapping)
	  m.Accept(*this);
}


//
// Visit_PropertyMapping
//
void Deployment_Domain_Visitor::
Visit_PropertyMapping (const PICML::PropertyMapping & pmapping)
{
  PICML::Property prop = pmapping.dstPropertyMapping_end ();

  if (Udm::IsDerivedFrom (prop.type (), PICML::SimpleProperty::meta))
    PICML::SimpleProperty::Cast (prop).Accept (*this);
}


//
// Visit_SimpleProperty
//
void Deployment_Domain_Visitor::
Visit_SimpleProperty (const PICML::SimpleProperty & prop)
{
  std::string prop_name = prop.name ();
  std::string pname_full;

  if (prop_name == "StringIOR")
  {
    pname_full = "edu.vanderbilt.dre.DAnCE.StringIOR";
  }

  else if (prop_name == "CORBAName")
  {
    pname_full = "edu.vanderbilt.dre.DAnCE.CORBAName";
  }

  if (!pname_full.empty ())
  {
    this->curr_property_ = this->create_element (this->curr_resource_, "property");
    this->create_simple_content (this->curr_property_, "name", pname_full);
    this->create_simple_content (this->curr_property_, "kind", "Attribute");
    this->create_simple_content (this->curr_property_, "dynamic", "false");

    this->curr_value_ = this->create_element (this->curr_property_, "value");
    this->curr_type_ = this->create_element (this->curr_value_, "type");
    this->create_simple_content (this->curr_type_, "kind", "tk_string");

    this->curr_value_inner_ = this->create_element (this->curr_value_, "value");

    this->create_simple_content (this->curr_value_inner_, "string", prop.Value ());
  }
}