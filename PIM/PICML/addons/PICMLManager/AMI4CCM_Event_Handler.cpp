// $Id$

#include "StdAfx.h"
#include "AMI4CCM_Event_Handler.h"

#include "game/mga/Attribute.h"
#include "game/mga/Model.h"
#include "game/mga/Folder.h"
#include "game/mga/Filter.h"
#include "game/mga/Reference.h"
#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"
#include "game/mga/Project.h"

#include <stack>
#include <functional>

#include "Utils/Utils.h"
#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_ATTR | OBJEVENT_CREATED;

/**
 * @struct is_ami4ccm_template_connector
 *
 * Functor that determines if a object is the AMI4CCM_Connector that
 * is located in the template module.
 */
struct is_ami4ccm_template_connector
{
  bool operator () (const GAME::Mga::FCO & fco) const
  {
    GAME::Mga::Model parent = fco->parent ();
    return parent->name () == "Connector_T";
  }
};

//
// AMI4CCM_Event_Handler
//
AMI4CCM_Event_Handler::AMI4CCM_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (mask)
{

}

//
// ~AMI4CCM_Event_Handler
//
AMI4CCM_Event_Handler::~AMI4CCM_Event_Handler (void)
{

}

//
// handle_object_created
//
int AMI4CCM_Event_Handler::handle_object_created (GAME::Mga::Object_in obj)
{
  if (!this->is_importing_)
    return 0;

  GAME::Mga::Model model = GAME::Mga::Model::_narrow (obj);
  GAME::Mga::Attribute attr = model->attribute ("SupportsAsync");
  bool supports_async = attr->bool_value ();

  return supports_async ? this->instantiate_connector (obj) : 0;
}


//
// handle_object_attribute
//
int AMI4CCM_Event_Handler::handle_object_attribute (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  // Get the support async attribute for the interface.
  GAME::Mga::Model model = GAME::Mga::Model::_narrow (obj);
  GAME::Mga::Attribute attr = model->attribute ("SupportsAsync");

  if (attr->has_changed () && attr->bool_value ())
    return this->instantiate_connector (obj);

  return 0;
}

//
// instantiate_connector
//
int AMI4CCM_Event_Handler::instantiate_connector (GAME::Mga::Object_in obj)
{
  using GAME::Mga_t;

  // Generate the header file that will define the ami4ccm connector
  // for this interface. This file will be in the same folder and
  // location as this interface, but it will have 'A' appended to the
  // file name.
  const std::string name = obj->name ();
  GAME::Mga::Object file = obj->parent ();

  std::stack <GAME::Mga::Object> scope;
  static const std::string meta_File ("File");
  while (file->meta ()->name () != meta_File)
  {
    // Save the current scope for later usage.
    scope.push (file);
    file = file->parent ();
  }

  GAME::Mga::Model connector_file;
  const std::string connector_filename = file->name () + "A";
  GAME::Mga::Folder idl_folder = GAME::Mga::Folder::_narrow (file->parent ());

  if (GAME::create_if_not <Mga_t> (idl_folder, "File", connector_file,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                              connector_filename,
                              boost::bind (&GAME::Mga::Model::impl_type::name,
                                           boost::bind (&GAME::Mga::Model::get, _1))))))
  {
    connector_file->name (connector_filename);
  }

  // Make sure the location (or path) are the same.
  GAME::Mga::Model model = GAME::Mga::Model::_narrow (file);
  const std::string location = model->attribute ("Path")->string_value ();
  connector_file->attribute ("Path")->string_value (location);

  // Reconstruct the scope for the connector in the newly
  // created file.
  while (!scope.empty ())
  {
    // Get the next element in the scope.
    const std::string package_name (scope.top ()->name ());

    // Make sure the package exists in the model.
    if (GAME::create_if_not <Mga_t> (connector_file, "Package", connector_file,
        GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                package_name,
                                boost::bind (&GAME::Mga::Model::impl_type::name,
                                             boost::bind (&GAME::Mga::Model::get, _1))))))
    {
      connector_file->name (package_name);
    }

    // Remove the top element on the stack.
    scope.pop ();
  }

  // Create the standard ami4ccm interface.
  const std::string ami4ccm_interface_name = "AMI4CCM_" + name;
  const std::string ami4ccm_replyhandler_name = "AMI4CCM_" + name + "ReplyHandler";

  GAME::Mga::Model ami4ccm_interface;
  if (GAME::create_if_not <Mga_t> (connector_file, "Object", ami4ccm_interface,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                              ami4ccm_interface_name,
                              boost::bind (&GAME::Mga::Model::impl_type::name,
                                           boost::bind (&GAME::Mga::Model::get, _1))))))
  {
    ami4ccm_interface->name (ami4ccm_interface_name);
  }

  ami4ccm_interface->attribute ("InterfaceSemantics")->string_value ("local");

  // Create the standard ami4ccm replyhandler interface.
  GAME::Mga::Model ami4ccm_replyhandler;
  if (GAME::create_if_not <Mga_t> (connector_file, "Object", ami4ccm_replyhandler,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                              ami4ccm_replyhandler_name,
                              boost::bind (&GAME::Mga::Model::impl_type::name,
                                           boost::bind (&GAME::Mga::Model::get, _1))))))
  {
    ami4ccm_replyhandler->name (ami4ccm_replyhandler_name);
  }

  ami4ccm_replyhandler->attribute ("InterfaceSemantics")->string_value ("local");

  // Locate the ami4ccm connector element. There is a chance that more than
  // one may be returned. In that case, we need to locate the first one that
  // is from the ami4ccm library.
  GAME::Mga::Filter search (obj->project ());
  search.kind ("ConnectorObject");
  search.name ("AMI4CCM_Connector");

  std::vector <GAME::Mga::FCO> results;

  if (0 == search.apply (results))
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    ::AfxMessageBox ("AMI4CCM_Connector connector not found. Please attach the "
                     "ami4ccm library and try again.",
                     MB_ICONWARNING);

    return 0;
  }

  std::vector <GAME::Mga::FCO>::const_iterator iter =
    std::find_if (results.begin (),
                  results.end (),
                  is_ami4ccm_template_connector ());

  if (iter == results.end ())
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    ::AfxMessageBox ("AMI4CCM_Connector connector not found. Please attach the "
                     "ami4ccm library and try again.",
                     MB_ICONWARNING);

    return 0;
  }

  // Create the template package instance for the connector.
  GAME::Mga::Model tpi;

  GAME::Mga::Model connector_object = GAME::Mga::Model::_narrow (*iter);
  const std::string tpi_name = "AMI4CCM_" + name + "_Connector";

  if (GAME::create_if_not <Mga_t> (connector_file, "TemplatePackageInstance", tpi,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                              tpi_name,
                              boost::bind (&GAME::Mga::Model::impl_type::name,
                                           boost::bind (&GAME::Mga::Model::get, _1))))))
  {
    tpi->name (tpi_name);
  }

  // Insert the parameters into the template. First, we must define
  // the package type for the template package instance.
  GAME::Mga::Model template_package = GAME::Mga::Model::_narrow (connector_object->parent ());

  GAME::Mga::Reference package_type;
  if (GAME::create_if_not <Mga_t> (tpi, "PackageType", package_type,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <GAME::Mga::FCO> (),
                              template_package,
                              boost::bind (&GAME::Mga::Reference::impl_type::refers_to,
                                           boost::bind (&GAME::Mga::Reference::get, _1))))))
  {
    package_type->refers_to (template_package);
  }

  GAME::Mga::Point pt (50, 50);
  GAME::Mga::set_position ("TemplateParameters", pt, package_type);

  // Create the template parameter value for interface.
  GAME::Mga::Reference tpv_interface;
  model = GAME::Mga::Model::_narrow (obj);

  if (GAME::create_if_not <Mga_t> (tpi, "TemplateParameterValue", tpv_interface,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <GAME::Mga::FCO> (),
                              model,
                              boost::bind (&GAME::Mga::Reference::impl_type::refers_to,
                                           boost::bind (&GAME::Mga::Reference::get, _1 ))))))
  {
    tpv_interface->refers_to (model);
  }

  pt.shift (100, 0);
  GAME::Mga::set_position ("TemplateParameters", pt, tpv_interface);

  // Create the template parameter value for the reply handler.
  GAME::Mga::Reference ami4ccm_param;

  if (GAME::create_if_not <Mga_t> (tpi, "TemplateParameterValue", ami4ccm_param,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <GAME::Mga::FCO> (),
                              ami4ccm_replyhandler,
                              boost::bind (&GAME::Mga::Reference::impl_type::refers_to,
                                           boost::bind (&GAME::Mga::Reference::get, _1))))))
  {
    ami4ccm_param->refers_to (ami4ccm_interface);
  }

  pt.shift (100, 0);
  GAME::Mga::set_position ("TemplateParameters", pt, ami4ccm_param);

  return 0;
}

}
}
