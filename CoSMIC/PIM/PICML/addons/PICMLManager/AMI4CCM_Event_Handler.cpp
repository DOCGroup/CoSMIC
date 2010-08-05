// $Id$

#include "StdAfx.h"
#include "AMI4CCM_Event_Handler.h"

#include "game/Attribute.h"
#include "game/Model.h"
#include "game/Folder.h"
#include "game/Filter.h"
#include "game/Reference.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "game/Project.h"

#include <stack>
#include <functional>

#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{
//
// AMI4CCM_Event_Handler
//
AMI4CCM_Event_Handler::AMI4CCM_Event_Handler (void)
: GAME::Event_Handler_Impl (OBJEVENT_ATTR),
  is_importing_ (false)
{

}

//
// ~AMI4CCM_Event_Handler
//
AMI4CCM_Event_Handler::~AMI4CCM_Event_Handler (void)
{

}

//
// handle_xml_import_begin
//
int AMI4CCM_Event_Handler::handle_xml_import_begin (void)
{
  this->is_importing_ = true;
  return 0;
}

//
// handle_xml_import_end
//
int AMI4CCM_Event_Handler::handle_xml_import_end (void)
{
  this->is_importing_ = false;
  return 0;
}

//
// handle_object_attribute
//
int AMI4CCM_Event_Handler::handle_object_attribute (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  // Get the support async attribute for the interface.
  GAME::Model model = GAME::Model::_narrow (obj);
  GAME::Attribute attr = model.attribute ("SupportsAsync");

  if (!attr.has_changed () || !attr.bool_value ())
    return 0;

  // Generate the header file that will define the ami4ccm connector
  // for this interface. This file will be in the same folder and
  // location as this interface, but it will have 'A' appended to the
  // file name.
  const std::string name (obj.name ());
  GAME::Object file = obj.parent ();

  std::stack <GAME::Object> scope;
  while (file.meta () != "File")
  {
    // Save the current scope for later usage.
    scope.push (file);
    file = file.parent ();
  }

  GAME::Model connector_file;
  const std::string connector_filename = file.name () + "A";
  GAME::Folder idl_folder = GAME::Folder::_narrow (file.parent ());

  if (GAME::create_if_not (idl_folder, "File", connector_file,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      connector_filename,
                      boost::bind (&GAME::Model::name, _1)))))
  {
    connector_file.name (connector_filename);
  }

  // Make sure the location (or path) are the same.
  model = GAME::Model::_narrow (file);
  const std::string location = model.attribute ("Path").string_value ();
  connector_file.attribute ("Path").string_value (location);

  // Reconstruct the scope for the connector in the newly
  // created file.
  while (!scope.empty ())
  {
    // Get the next element in the scope.
    const std::string package_name (scope.top ().name ());
    // Make sure the package exists in the model.
    if (GAME::create_if_not (connector_file, "Package", connector_file,
        GAME::contains (boost::bind (std::equal_to <std::string> (),
                        package_name,
                        boost::bind (&GAME::Model::name, _1)))))
    {
      connector_file.name (package_name);
    }

    // Remove the top element on the stack.
    scope.pop ();
  }

  // Create the standard ami4ccm interface.
  const std::string ami4ccm_interface_name = "AMI4CCM_" + name;
  const std::string ami4ccm_replyhandler_name = "AMI4CCM_" + name + "ReplyHandler";

  GAME::Model ami4ccm_interface;
  if (GAME::create_if_not (connector_file, "Object", ami4ccm_interface,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      ami4ccm_interface_name,
                      boost::bind (&GAME::Model::name, _1)))))
  {
    ami4ccm_interface.name (ami4ccm_interface_name);
  }

  ami4ccm_interface.attribute ("InterfaceSemantics").string_value ("local");

  // Create the standard ami4ccm replyhandler interface.
  GAME::Model ami4ccm_replyhandler;
  if (GAME::create_if_not (connector_file, "Object", ami4ccm_replyhandler,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      ami4ccm_replyhandler_name,
                      boost::bind (&GAME::Model::name, _1)))))
  {
    ami4ccm_replyhandler.name (ami4ccm_replyhandler_name);
  }

  ami4ccm_replyhandler.attribute ("InterfaceSemantics").string_value ("local");

  // Locate the ami4ccm connector element.
  GAME::Filter search (obj.project ());
  search.kind ("ConnectorObject");
  search.name ("AMI4CCM_Connector");

  std::vector <GAME::FCO> results;

  if (search.apply (results) == 1)
  {
    GAME::Model connector_object = GAME::Model::_narrow (results.front ());

    // Create the template package instance for the connector.
    GAME::Model tpi;
    const std::string tpi_name = "AMI4CCM_" + name + "_Connector";

    if (GAME::create_if_not (connector_file, "TemplatePackageInstance", tpi,
        GAME::contains (boost::bind (std::equal_to <std::string> (),
                        tpi_name,
                        boost::bind (&GAME::Model::name, _1)))))
    {
      tpi.name (tpi_name);
    }

    // Insert the parameters into the template. First, we must define
    // the package type for the template package instance.
    GAME::Model template_package =
      GAME::Model::_narrow (connector_object.parent ());


    GAME::Reference package_type;
    if (GAME::create_if_not (tpi, "PackageType", package_type,
        GAME::contains (boost::bind (std::equal_to <GAME::FCO> (),
                        template_package,
                        boost::bind (&GAME::Reference::refers_to, _1)))))
    {
      package_type.refers_to (template_package);
    }

    GAME::utils::Point pt (50, 50);
    GAME::utils::position ("TemplateParameters", pt, package_type);

    // Create the template parameter value for interface.
    GAME::Reference tpv_interface;
    model = GAME::Model::_narrow (obj);

    if (GAME::create_if_not (tpi, "TemplateParameterValue", tpv_interface,
        GAME::contains (boost::bind (std::equal_to <GAME::FCO> (),
                        model,
                        boost::bind (&GAME::Reference::refers_to, _1)))))
    {
      tpv_interface.refers_to (model);
    }

    pt.shift (100, 0);
    GAME::utils::position ("TemplateParameters", pt, tpv_interface);

    // Create the template parameter value for the reply handler.
    GAME::Reference tpv_replyhandler;

    if (GAME::create_if_not (tpi, "TemplateParameterValue", tpv_replyhandler,
        GAME::contains (boost::bind (std::equal_to <GAME::FCO> (),
                        ami4ccm_replyhandler,
                        boost::bind (&GAME::Reference::refers_to, _1)))))
    {
      tpv_replyhandler.refers_to (ami4ccm_replyhandler);
    }

    pt.shift (100, 0);
    GAME::utils::position ("TemplateParameters", pt, tpv_replyhandler);
  }
  else
  {
    ::AfxMessageBox ("AMI4CCM_Connector connector not found. Please attach the "
                     "ami4ccm library and try again",
                     MB_ICONWARNING);
  }

  return 0;
}

}
}