// $Id$

#include "StdAfx.h"
#include "NoShowRefersTo_Decorator.h"
#include "NoShowRefersTo_Decorator_Impl.h"

#include "game/MetaFCO.h"
#include "game/graphics/Image_Resolver.h"
#include "game/utils/Registrar.h"

#define GME_PORT_HEIGHT         11
#define GME_PORT_WIDTH          11

#define GME_PORT_PADDING_Y      4

#define GME_PORT_MARGIN_X       8
#define GME_PORT_MARGIN_Y       8

#define COMPONENT_DEFUALT_WIDTH     143
#define COMPONENT_DEFAULT_HEIGHT    70
#define COMPONENT_LINE_WIDTH        3

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
initialize_ex (const GAME::Project & project, 
               const GAME::Meta::Part & part, 
               const GAME::FCO & fco,
               IMgaCommonDecoratorEvents * eventSink, 
               ULONGLONG parentWnd)
{
  using GAME::utils::GLOBAL_REGISTRAR;
  using GAME::utils::Registrar;

  using GAME::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::graphics::Image_Manager_T;
  using GAME::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();
  
  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  // Get the icon for the element in the parts browser.
  GAME::Meta::FCO metafco = part.role ().kind ();
  std::string icon_filename = metafco.registry_value ("icon");

  if (fco.is_nil ())
    this->label_ = metafco.display_name ();

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
int NoShowRefersTo_Decorator_Impl::draw (Gdiplus::Graphics & g)
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
  float py = static_cast <float> (this->location_.y_) + (height + 15.0);

  static const Gdiplus::Font font (L"Arial", 10);
  static const Gdiplus::SolidBrush brush (Gdiplus::Color (0, 0, 0));

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
