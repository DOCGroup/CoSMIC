// $Id$

#include "StdAfx.h"
#include "Dialogs.h"
#include "Default_Implementation_Event_Handler.h"
#include "Implementation_Configuration.h"
#include "Validation.h"

#include "game/Model.h"

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;

//
// Default_Implementation_Event_Handler
//
Default_Implementation_Event_Handler::Default_Implementation_Event_Handler (void)
: ::GAME::Event_Handler_Impl (mask)
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
handle_object_created (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  ::GAME::Model model = ::GAME::Model::_narrow (obj);
  if (is_in_template_module (model))
    return 0;

  // Locate the object's type in the map.
  map_t::const_iterator iter = this->meta_info_.find (obj.meta ().name ());

  if (iter == this->meta_info_.end ())
    return 0;

  Implementation_Configuration config;

  if (obj.name () == obj.meta ().name ())
  {
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

    // Get the configuration information for the new element.
    Default_Implementation_Dialog dialog (config, ::AfxGetMainWnd ());

    if (dialog.DoModal () == IDCANCEL)
      return 0;

    // Set the name of the object.
    model.name (config.type_name_);
  }

  // Generate the default implementation.
  Default_Implementation_Generator dig (obj.project (), iter->second);
  dig.generate (config, model);

  return 0;
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
