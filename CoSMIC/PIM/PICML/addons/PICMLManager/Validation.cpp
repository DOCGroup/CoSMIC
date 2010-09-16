// $Id$

#include "StdAfx.h"
#include "Validation.h"
#include "game/Model.h"
#include "game/MetaAspect.h"
#include "game/MetaModel.h"

namespace PICML
{
namespace MI
{
//
// is_in_template_module
//
bool is_in_template_module (const GAME::FCO & fco)
{
  GAME::Model parent = fco.parent_model ();
  static const std::string meta_File ("File");

  while (!parent.is_nil () && parent.meta () != meta_File)
  {
    // See if this package contains any template parameters.
    static const std::string aspect_TemplateParameters ("TemplateParameters");
    GAME::Meta::Aspect aspect = parent.meta ().aspect (aspect_TemplateParameters);

    std::vector <GAME::FCO> parameters;
    if (0 != parent.children (aspect, parameters) && parent.meta () == "Package")
      return true;

    // Move to the next parent model.
    parent = parent.parent_model ();
  }

  return false;
}

//
// is_in_template_module
//
bool is_in_template_module_instance (const GAME::FCO & fco)
{
  GAME::Model parent = fco.parent_model ();
  static const std::string meta_File ("File");

  while (!parent.is_nil () && parent.meta () != meta_File)
  {
    // See if this package contains any template parameters.
    static const std::string aspect_TemplateParameters ("TemplateParameters");
    GAME::Meta::Aspect aspect = parent.meta ().aspect (aspect_TemplateParameters);

    std::vector <GAME::FCO> parameters;
    if (0 != parent.children (aspect, parameters) && parent.meta () == "TemplatePackageInstance")
      return true;

    // Move to the next parent model.
    parent = parent.parent_model ();
  }

  return false;
}

}
}
