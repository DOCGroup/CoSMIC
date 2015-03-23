#include "StdAfx.h"
#include "Domain_Visitor.h"

#include "PIM/PICML/xml/Data_Type_Visitor.h"
#include "PIM/PICML/xml/Data_Value_Visitor.h"

#include "PICML/RootFolder.h"
#include "PICML/Domain/Targets.h"
#include "PICML/Domain/Domain.h"

#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/Interconnect.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/NodeReference.h"
#include "PICML/TargetElements/Resource.h"
#include "PICML/TargetElements/SharedResource.h"
#include "PICML/DeploymentPlan/InstanceMapping.h"

#include "PICML/Common/DataType.h"
#include "PICML/Common/SatisfierProperty.h"

#include "game/xml/String.h"
#include "game/xml/Swap_Fragment.h"

#include "game/mga/Utils.h"

#include <sstream>

Domain_Visitor::Domain_Visitor (const std::string & output_path)
: output_path_ (output_path)
{
}

Domain_Visitor::~Domain_Visitor (void)
{

}

void Domain_Visitor::visit_RootFolder (PICML::RootFolder_in root)
{
  for (PICML::Targets targets : root->get_Targets ())
    targets->accept (this);
}

void Domain_Visitor::visit_Targets (PICML::Targets_in targets)
{
  for (PICML::Domain domain : targets->get_Domains ())
    domain->accept (this);
}

void Domain_Visitor::visit_Domain (PICML::Domain_in domain)
{
  // Begin a new document.
  this->begin_document (domain->UUID (), domain->label ());

  // Visit the remaining elments in the domain.
  for (PICML::Node node : domain->get_Nodes ())
    node->accept (this);

  for (PICML::Interconnect interconnect : domain->get_Interconnects ())
    interconnect->accept (this);

  for (PICML::Bridge bridge : domain->get_Bridges ())
    bridge->accept (this);

  for (PICML::SharedResource shared : domain->get_SharedResources ())
    shared->accept (this);

  // Write the document.
  this->write_document (domain->name ());
}

void Domain_Visitor::
begin_document (const std::string & uuid, const std::string & label)
{
  using namespace GAME::Xml;
  using namespace xercesc;

  // Create a new document for the domain. This also requires initializing
  // its attributes.
  if (this->xml_doc_)
    this->xml_doc_->close ();

  this->xml_doc_.reset (new LS_Document ("http://www.omg.org/Deployment", "Deployment:domain"));
  Fragment root = this->fragment_ = this->xml_doc_->root ();

  root->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                        String ("xmlns:Deployment"),
                        String ("http://www.omg.org/Deployment"));

  root->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                        String ("xmlns:xsi"),
                        String ("http://www.w3.org/2001/XMLSchema-instance"));

  root->setAttributeNS (String ("http://www.w3.org/2000/xmlns/"),
                        String ("xmlns:xmi"),
                        String ("http://www.omg.org/XMI"));

  root->setAttribute (String ("xsi:schemaLocation"),
                      String ("http://www.omg.org/Deployment Deployment.xsd"));

  // Attach the <label> to the root element.
  if (!label.empty ())
    root.append_simple_content ("label", label);

  // Attach the <UUID> to the root element. We generate a UUID if
  // one is not present.
  if (uuid.empty ())
    root.append_simple_content ("UUID", uuid);
}

void Domain_Visitor::write_document (const std::string & basename)
{
  std::ostringstream filename;
  filename << this->output_path_ << "\\" << basename << ".cdd";

  using namespace GAME::Xml;
  using namespace xercesc;

  // Write the XML document to a file.  
  DOMLSSerializer * serializer = this->xml_doc_->impl ()->createLSSerializer ();

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTBOM, false))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTBOM, false);

  serializer->writeToURI (this->fragment_, String (filename.str ()));
  serializer->release ();
}

#include "game/mga/component/Console_Service.h"

void Domain_Visitor::visit_Node (PICML::Node_in node)
{
  using namespace GAME::Xml;

  Swap_Fragment fragment (this->fragment_, this->fragment_.append_element ("node"));
  fragment.append_simple_content ("name", this->expand_shortname (node->name ()));

  // Testing
  fragment.set_attribute ("test", String ("5"));
  String test = fragment[String ("test")];
  String foo = "5";
    std::ostringstream ostr;
    ostr << "Testing read attribute (asdf): " << test.to_string ().c_str () << " objects...";
    GME_CONSOLE_SERVICE->info (ostr.str ().c_str ());

  fragment.set_attribute ("test", "qwer");
    std::ostringstream ostr2;
    ostr2 << "Testing read attribute (qwer): " << test.to_string ().c_str () << " objects...";
    GME_CONSOLE_SERVICE->info (ostr2.str ().c_str ());

  std::string label = node->label ();
  if (!label.empty ())
    fragment.append_simple_content ("label", label);

  for (PICML::Resource res : node->get_Resources ())
    res->accept (this);
}

void Domain_Visitor::visit_Interconnect (PICML::Interconnect_in ic)
{
  using namespace GAME::Xml;

  Swap_Fragment fragment (this->fragment_, this->fragment_.append_element ("interconnect"));
  fragment.append_simple_content ("name", this->expand_shortname (ic->name ()));

  std::string label = ic->label ();
  if (!label.empty ())
    fragment.append_simple_content ("label", label);

  for (PICML::Resource res : ic->get_Resources ())
  {
    Fragment res_fragment = fragment.append_element ("resource");
    res_fragment.append_simple_content ("name", this->expand_shortname (res->name ()));
  }
}

void Domain_Visitor::visit_Bridge (PICML::Bridge_in bridge)
{
  using namespace GAME::Xml;

  Swap_Fragment fragment (this->fragment_, this->fragment_.append_element ("bridge"));
  fragment.append_simple_content ("name", this->expand_shortname (bridge->name ()));

  for (PICML::Resource res : bridge->get_Resources ())
    res->accept (this);
}

void Domain_Visitor::visit_SharedResource (PICML::SharedResource_in sr)
{
  using namespace GAME::Xml;

  Swap_Fragment fragment (this->fragment_, this->fragment_.append_element ("sharedResource"));
  fragment.append_simple_content ("name", this->expand_shortname (sr->name ()));
  fragment.append_simple_content ("resourceType", sr->resourceType ());

  for (PICML::SatisfierProperty prop : sr->get_SatisfierPropertys ())
    prop->accept (this);
}

void Domain_Visitor::visit_InstanceMapping (PICML::InstanceMapping_in ins_map)
{
  ins_map->dst_NodeReference ()->accept (this);
}

void Domain_Visitor::visit_Resource (PICML::Resource_in res)
{
  using namespace GAME::Xml;

  Swap_Fragment fragment (this->fragment_, this->fragment_.append_element ("resource"));
  fragment.append_simple_content ("name", this->expand_shortname (res->name ()));
  fragment.append_simple_content ("resourceType", res->resourceType ());

  for (PICML::SatisfierProperty prop : res->get_SatisfierPropertys ())
    prop->accept (this);
}

void Domain_Visitor::visit_SatisfierProperty (PICML::SatisfierProperty_in prop)
{
  using namespace GAME::Xml;

  Swap_Fragment fragment (this->fragment_, this->fragment_.append_element ("property"));
  fragment.append_simple_content ("name", this->expand_shortname (prop->name ()));
  fragment.append_simple_content ("kind", prop->SatisfierPropertyKind ());
  fragment.append_simple_content ("dynamic", prop->dynamic () ? "true" : "false");

  // Write the type and value of the property.
  PICML::DataType data_type = prop->get_DataType ();
  Fragment value = fragment.append_element ("value");
  PICML::Xml::Data_Type_Visitor data_type_visitor (value);
  data_type->accept (&data_type_visitor);

  PICML::Xml::Data_Value_Visitor data_value_visitor (value, prop->DataValue ());
  data_type->accept (&data_value_visitor);
}

void Domain_Visitor::add_shortname (const std::string & name, const std::string & value)
{
  this->short_names_.insert (std::make_pair (name, value));
}

void Domain_Visitor::remove_shortname (const std::string & name)
{
  this->short_names_.erase (name);
}

std::string Domain_Visitor::expand_shortname (const std::string & shortname)
{
  auto item = this->short_names_.find (shortname);
  return item != this->short_names_.end () ? item->second : shortname;
}
