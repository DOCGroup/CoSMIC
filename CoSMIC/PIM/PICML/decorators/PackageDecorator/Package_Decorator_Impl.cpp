// $Id$

#include "StdAfx.h"
#include "Package_Decorator.h"
#include "Package_Decorator_Impl.h"

#include "game/MetaFCO.h"
#include "game/Model.h"
#include "game/MetaAspect.h"
#include "game/MetaModel.h"

#include "game/graphics/Image_Resolver.h"
#include "game/utils/Registrar.h"

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
// destroy
//
void Package_Decorator_Impl::destroy (void)
{
  this->bitmap_.reset ();
}

//
// initialize
//
int Package_Decorator_Impl::
initialize_ex (const GAME::Project & project,
               const GAME::Meta::Part & part,
               const GAME::FCO & fco,
               IMgaCommonDecoratorEvents * eventSink,
               ULONGLONG parentWnd)
{
  using GAME::Model;

  using GAME::utils::GLOBAL_REGISTRAR;
  using GAME::utils::Registrar;

  using GAME::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::graphics::Image_Manager_T;
  using GAME::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  // Let's initialize the icon file to the default one.
  GAME::Meta::FCO metafco = part.role ().kind ();
  std::string icon_filename = metafco.registry_value ("icon");

  if (!fco.is_nil ())
  {
    // The label is the name of the FCO.
    this->label_ = fco.name ();

    if (fco.meta () == "Package")
    {
      // Determine if this is a package, or a template package. A template
      // package will have one or more template parameters as a child.
      Model package = Model::_narrow (fco);
      GAME::Meta::Aspect aspect = package.meta ().aspect ("TemplateParameters");

      std::vector <GAME::FCO> children;

      if (package.children (aspect, children))
        icon_filename = TEMPLATEPACKAGE_BITMAP;
    }
  }
  else
  {
    // We are in the part browser. The label is just the display name
    // for the FCO's type (i.e., the MetaFCO).
    this->label_ = metafco.display_name ();
  }

  // Load the file for later usage.
  std::string abs_filename;
  if (!resolver->lookup_icon (icon_filename, abs_filename))
    return -1;

  CA2W temp (abs_filename.c_str ());
  this->bitmap_.reset (Gdiplus::Bitmap::FromFile (temp));

  return this->bitmap_.get () != 0 ? 0 : -1;
}

//
// get_preferred_size
//
int Package_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  sx = this->bitmap_->GetWidth ();
  sy = this->bitmap_->GetHeight ();

  return 0;
}

//
// draw
//
int Package_Decorator_Impl::draw (Gdiplus::Graphics & g)
{
  g.DrawImage (this->bitmap_.get (),
               this->location_.x_,
               this->location_.y_,
               this->location_.cx_ - this->location_.x_,
               this->location_.cy_ - this->location_.y_);

  if (this->label_.empty ())
    return 0;

  float height = this->location_.height ();
  float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0);
  float py = static_cast <float> (this->location_.y_) + (height + 10.0);

  const Gdiplus::Font font (L"Arial", 10);
  const Gdiplus::SolidBrush brush (Gdiplus::Color (0, 0, 0));

  Gdiplus::StringFormat format;
  format.SetAlignment (Gdiplus::StringAlignmentCenter);
  format.SetLineAlignment (Gdiplus::StringAlignmentCenter);

  CComBSTR bstr (this->label_.length (), this->label_.c_str ());

  // Draw the label for the element.
  g.DrawString (bstr,
                this->label_.length (),
                &font,
                Gdiplus::PointF (px, py),
                &format,
                &brush);

  return 0;
}
