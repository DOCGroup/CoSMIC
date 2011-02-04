// $Id$

#include "StdAfx.h"

#include "NoShowRefersTo_Decorator_Impl.h"
#include "NoShowRefersTo_Decorator.h"
#include "game/mga/be/Decorator_T.h"

#include "game/mga/MetaFCO.h"
#include "game/mga/graphics/Image_Resolver.h"
#include "game/mga/utils/Registrar.h"

DECLARE_DECORATOR (NoShowRefersTo_Decorator, NoShowRefersTo_Decorator_Impl);

//
// NoShowRefersTo_Decorator_Impl
//
NoShowRefersTo_Decorator_Impl::NoShowRefersTo_Decorator_Impl (void)
{

}

//
// ~NoShowRefersTo_Decorator_Impl
//
NoShowRefersTo_Decorator_Impl::~NoShowRefersTo_Decorator_Impl (void)
{

}

//
// destroy
//
void NoShowRefersTo_Decorator_Impl::destroy (void)
{
  this->bitmap_.release ();
}

//
// initialize
//
int NoShowRefersTo_Decorator_Impl::
initialize_ex (const GAME::Mga::Project & project,
               const GAME::Mga::Meta::Part_in part,
               const GAME::Mga::FCO_in fco,
               IMgaCommonDecoratorEvents * eventSink,
               ULONGLONG parentWnd)
{
  using GAME::Mga::GLOBAL_REGISTRAR;
  using GAME::Mga::Registrar;

  using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::Mga::graphics::Image_Manager_T;
  using GAME::Mga::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  // Get the icon for the element in the parts browser.
  GAME::Mga::Meta::FCO metafco = part->role ()->kind ();
  std::string icon_filename = metafco->registry_value ("icon");

  if (0 == fco)
    this->label_ = metafco->display_name ();

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
int NoShowRefersTo_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  sx = this->bitmap_->GetWidth ();
  sy = this->bitmap_->GetHeight ();

  return 0;
}

//
// draw
//
int NoShowRefersTo_Decorator_Impl::draw (Gdiplus::Graphics * g)
{
  g->DrawImage (this->bitmap_.get (),
                this->location_.x_,
                this->location_.y_,
                this->location_.cx_ - this->location_.x_,
                this->location_.cy_ - this->location_.y_);

  if (this->label_.empty ())
    return 0;

  float height = static_cast <float> (this->location_.height ());
  float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);
  float py = static_cast <float> (this->location_.y_) + (height + 15.0f);

  static const Gdiplus::Font font (L"Arial", 10);
  static const Gdiplus::SolidBrush brush (Gdiplus::Color (0, 0, 0));

  Gdiplus::StringFormat format;
  format.SetAlignment (Gdiplus::StringAlignmentCenter);
  format.SetLineAlignment (Gdiplus::StringAlignmentCenter);

  CComBSTR bstr (this->label_.length (), this->label_.c_str ());

  // Draw the label for the element.
  g->DrawString (bstr,
                 this->label_.length (),
                 &font,
                 Gdiplus::PointF (px, py),
                 &format,
                 &brush);

  return 0;
}
