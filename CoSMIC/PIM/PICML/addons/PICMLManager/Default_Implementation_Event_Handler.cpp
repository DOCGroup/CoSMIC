// $Id$

#include "StdAfx.h"
#include "Dialogs.h"
#include "Default_Implementation_Event_Handler.h"
#include "Implementation_Configuration.h"
#include "Validation.h"

#include "game/mga/Model.h"

#include "boost/bind.hpp"
#include <algorithm>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;

//
// Default_Implementation_Event_Handler
//
Default_Implementation_Event_Handler::Default_Implementation_Event_Handler (void)
: ::GAME::Mga::Event_Handler_Impl (mask)
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

  return this->generate_default_implementation (obj);
}

//
// handle_notification_ready
//
int Default_Implementation_Event_Handler::handle_xml_import_begin (void)
{
  GAME::Mga::Event_Handler_Impl::handle_xml_import_begin ();

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  const char * question = "Generate default implementation for imported models?";
  int answer = ::AfxMessageBox (question, MB_YESNO);
  this->generate_on_import_ = answer == IDYES;

  return 0;
}

//
// generate_default_implementation
//
int Default_Implementation_Event_Handler::
generate_default_implementation (const GAME::Mga::Object_in obj)
{
  ::GAME::Mga::Model model = ::GAME::Mga::Model::_narrow (obj);
  if (is_in_template_module (model))
    return 0;

  // Locate the object's type in the map.
  map_t::const_iterator iter = this->meta_info_.find (obj->meta ()->name ());

  if (iter == this->meta_info_.end ())
    return 0;

  Implementation_Configuration config;
  const std::string name (obj->name ());

  if (name == obj->meta ()->name ())
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    // Get the configuration information for the new element.
    Default_Implementation_Dialog dialog (config, ::AfxGetMainWnd ());

    if (dialog.DoModal () == IDCANCEL)
      return 0;

    // Set the name of the object.
    model->name (config.type_name_);
  }

  // Generate the default implementation.
  Default_Implementation_Generator dig (obj->project (), iter->second);
  return dig.generate (config, model) ? 0 : -1;
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
