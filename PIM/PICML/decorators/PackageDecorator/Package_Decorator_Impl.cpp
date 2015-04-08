#include "StdAfx.h"
#include "Package_Decorator.h"
#include "Package_Decorator_Impl.h"
#include "game/mga/decorator/Decorator_T.h"

#include "game/mga/MetaFCO.h"
#include "game/mga/Model.h"
#include "game/mga/MetaAspect.h"
#include "game/mga/MetaModel.h"

#include "game/mga/graphics/Image_Resolver.h"
#include "game/mga/utils/Registrar.h"

DECLARE_DECORATOR (Package_Decorator, Package_Decorator_Impl);

const std::string Package_Decorator_Impl::TEMPLATEPACKAGE_BITMAP ("TemplatePackage.gif");

//
// Package_Decorator_Impl
//
Package_Decorator_Impl::Package_Decorator_Impl (void)
{

}

//
// ~Package_Decorator_Impl
//
Package_Decorator_Impl::~Package_Decorator_Impl (void)
{

}

//
// initialize
//
int Package_Decorator_Impl::
initialize (const GAME::Mga::Project & project,
            const GAME::Mga::Meta::Part_in part,
            const GAME::Mga::FCO_in fco,
            IMgaCommonDecoratorEvents * sink,
            ULONGLONG window)
{
  if (0 != FCO_Decorator::initialize (project, part, fco, sink, window))
    return -1;

  static const std::string meta_Package ("Package");

  if (fco->meta ()->name () == meta_Package)
  {
    using GAME::Mga::Model;
    using GAME::Mga::FCO;
    using GAME::Mga::Meta::Aspect;

    // Determine if this is a package, or a template package. A template
    // package will have one or more template parameters as a child.
    Model package = Model::_narrow (fco);
    Aspect aspect = package->meta ()->aspect ("TemplateParameters");

    std::vector <FCO> fcos;
    if (package->children <FCO> (aspect, fcos))
    {
      using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
      using GAME::Mga::graphics::Image_Resolver;

      Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

      std::string abs_filename;
      resolver->lookup_icon (TEMPLATEPACKAGE_BITMAP, abs_filename);

      CA2W temp (abs_filename.c_str ());
      this->bitmap_.reset (Gdiplus::Bitmap::FromFile (temp));
    }
  }

  return 0;
}

