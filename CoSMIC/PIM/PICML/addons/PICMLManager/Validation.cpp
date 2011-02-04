// $Id$

#include "StdAfx.h"
#include "Validation.h"
#include "game/mga/Model.h"
#include "game/mga/MetaAspect.h"
#include "game/mga/MetaModel.h"

namespace PICML
{
namespace MI
{
//
// is_in_template_module
//
bool is_in_template_module (const GAME::Mga::FCO_in fco)
{
  GAME::Mga::Model parent = fco->parent_model ();
  static const std::string meta_File ("File");
  std::string metaname = parent->meta ()->name ();

  while (!parent.is_nil () && metaname != meta_File)
  {
    // See if this package contains any template parameters.
    static const std::string aspect_TemplateParameters ("TemplateParameters");
    GAME::Mga::Meta::Aspect aspect = parent->meta ()->aspect (aspect_TemplateParameters);

    std::vector <GAME::Mga::FCO> parameters;
    if (0 != parent->children (aspect, parameters) && metaname == "Package")
      return true;

    // Move to the next parent model.
    parent = parent->parent_model ();
    metaname = parent->meta ()->name ();
  }

  return false;
}

//
// is_in_template_module
//
bool is_in_template_module_instance (const GAME::Mga::FCO_in fco)
{
  GAME::Mga::Model parent = fco->parent_model ();
  static const std::string meta_File ("File");
  std::string metaname = parent->meta ()->name ();

  while (!parent.is_nil () && metaname != meta_File)
  {
    // See if this package contains any template parameters.
    static const std::string aspect_TemplateParameters ("TemplateParameters");
    GAME::Mga::Meta::Aspect aspect = parent->meta ()->aspect (aspect_TemplateParameters);

    std::vector <GAME::Mga::FCO> parameters;
    if (0 != parent->children (aspect, parameters) && metaname == "TemplatePackageInstance")
      return true;

    // Move to the next parent model.
    parent = parent->parent_model ();
    metaname = parent->meta ()->name ();
  }

  return false;
}

}
}
