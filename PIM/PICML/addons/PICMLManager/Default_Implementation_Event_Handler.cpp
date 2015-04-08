#include "StdAfx.h"
#include "Dialogs.h"
#include "Default_Implementation_Event_Handler.h"
#include "Validation.h"
#include "Import_Dialog.h"

#include "game/mga/MetaModel.h"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;

//
// Default_Implementation_Event_Handler
//
Default_Implementation_Event_Handler::Default_Implementation_Event_Handler (void)
: ::GAME::Mga::Object_Event_Handler (mask)
{

}

//
// Default_Implementation_Event_Handler
//
Default_Implementation_Event_Handler::~Default_Implementation_Event_Handler (void)
{

}

//
// handle_object_created
//
int Default_Implementation_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_ && !this->generate_on_import_)
    return 0;

  if (obj->is_lib_object ())
    return 0;

  return this->generate_default_implementation (PICML::Component::_narrow (obj));
}

//
// handle_xml_import_begin
//
int Default_Implementation_Event_Handler::handle_xml_import_begin (void)
{
  GAME::Mga::Object_Event_Handler::handle_xml_import_begin ();

  // TODO We should update GAME such that different handlers use this
  // method to update an import configuration. This configuration is
  // then displayed to the user where they can update it accordingly.
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  Import_Dialog dialog (this->config_, ::AfxGetMainWnd ());
  this->generate_on_import_ = dialog.DoModal () == IDOK ? true : false;

  return 0;
}

//
// generate_default_implementation
//
int Default_Implementation_Event_Handler::
  generate_default_implementation (PICML::Component_in type)
{
  if (is_in_template_module (type))
    return 0;

  // Locate the object's type in the map.
  const std::string metaname = type->meta ()->name ();
  auto iter = this->meta_info_.find (metaname);

  if (iter == this->meta_info_.end ())
    return 0;

  const std::string name (type->name ());
  const std::string new_name ("New" + metaname);

  if (name == metaname || name == new_name)
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    // Get the configuration information for the new element.
    Default_Implementation_Dialog dialog (this->config_, ::AfxGetMainWnd ());

    if (dialog.DoModal () == IDCANCEL)
      return 0;

    // Set the name of the object.
    type->name (this->config_.type_name_);
  }

  // Generate the default implementation.
  Default_Implementation_Generator dig (type->project (), iter->second);
  return dig.generate (this->config_, type) ? 0 : -1;
}

//
// insert
//
bool Default_Implementation_Event_Handler::
insert (std::string meta, const meta_info_t & info)
{
  return this->meta_info_.insert (std::make_pair (meta, info)).second;
}

}
}
