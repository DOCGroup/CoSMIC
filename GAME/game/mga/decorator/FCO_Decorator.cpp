// $Id$

#include "stdafx.h"
#include "FCO_Decorator.h"

#if !defined (__GAME_INLINE__)
#include "FCO_Decorator.inl"
#endif

#include "game/mga/utils/Registrar.h"
#include "game/mga/graphics/Image_Resolver.h"
#include "game/mga/graphics/Stock_Objects.h"
#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/MetaPart.h"

namespace GAME
{
namespace Mga
{

//
// initialize
//
int FCO_Decorator::
initialize (const Project & proj,
            const Meta::Part_in part,
            IMgaCommonDecoratorEvents * eventSink,
            ULONGLONG parentWnd)
{
  // Initialize the project's image resolver.
  if (0 != this->init_image_resolver (proj))
    return -1;

  // Load the default bitmap.
  GAME::Mga::Meta::FCO metafco = part->role ()->kind ();

  if (this->use_default_bitmap_ && 0 != this->init_default_bitmap (proj, metafco))
    return -1;

  // Initialize the display label.
  this->label_ = metafco->display_name ();
  return 0;
}

//
// initialize
//
int FCO_Decorator::
initialize (const Project & proj,
            const Meta::Part_in part,
            const FCO_in fco,
            IMgaCommonDecoratorEvents * sink,
            ULONGLONG window)
{
  // Initialize the project's image resolver.
  if (0 != this->init_image_resolver (proj))
    return -1;

  // Load the default bitmap.
  if (this->use_default_bitmap_ && 0 != this->init_default_bitmap (proj, part->role ()->kind ()))
    return -1;

  // Initialize the display label.
  this->label_ = fco->name ();
  return 0;
}

//
// init_image_resolver
//
int FCO_Decorator::init_image_resolver (const Project & proj)
{
  using GAME::Mga::GLOBAL_REGISTRAR;
  using GAME::Mga::Registrar;

  using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::Mga::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  if (!resolver->is_init ())
    resolver->init (proj, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  return 0;
}

//
// init_default_bitmap
//
int FCO_Decorator::
init_default_bitmap (const Project & proj, Meta::FCO_in metafco)
{
  // Load the icon for this element and store it.
  std::string icon_filename = metafco->registry_value ("icon");

  if (!icon_filename.empty ())
  {
    using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
    using GAME::Mga::graphics::Image_Resolver;
    Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

    std::string abs_filename;
    if (!resolver->lookup_icon (icon_filename, abs_filename))
      return -1;

    CA2W temp (abs_filename.c_str ());
    this->bitmap_.reset (Gdiplus::Bitmap::FromFile (temp));
  }

  return 0;
}

//
// get_preferred_size
//
int FCO_Decorator::get_preferred_size (long & sx, long & sy)
{
  if (0 != this->bitmap_.get ())
  {
    sx = this->bitmap_->GetWidth ();
    sy = this->bitmap_->GetHeight ();
  }

  return 0;
}

//
// draw
//
int FCO_Decorator::draw (Gdiplus::Graphics * g)
{
  if (0 != this->bitmap_.get ())
    this->draw_bitmap (g);

  if (!this->label_.empty ())
    this->draw_label (g);

  return 0;
}

//
// draw_bitmap
//
void FCO_Decorator::draw_bitmap (Gdiplus::Graphics * g) const
{
  g->DrawImage (this->bitmap_.get (),
                this->location_.x_,
                this->location_.y_,
                this->location_.cx_ - this->location_.x_,
                this->location_.cy_ - this->location_.y_);
}

//
// draw_label
//
void FCO_Decorator::draw_label (Gdiplus::Graphics * g) const
{
  // Since we have been given the go ahead, let's draw the label
  // for this element. Right now, we have our own layout as to where
  // the label should appear. We also will use the Stock_Objects to
  // draw the label. This will ensure consistent look and feel with
  // the rest of GME, or the custom decorator library.
  const float height = static_cast <float> (this->location_.height ());
  const float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);
  float py = static_cast <float> (this->location_.y_) + (height + 15.0f);

  using GAME::Mga::graphics::GLOBAL_STOCK_OBJECTS;
  using GAME::Mga::graphics::Stock_Objects;
  Stock_Objects * sos = GLOBAL_STOCK_OBJECTS::instance ();

  CComBSTR bstr (this->label_.length (), this->label_.c_str ());

  // Draw the label for the element.
  g->DrawString (bstr,
                 this->label_.length (),
                 sos->label_font (),
                 Gdiplus::PointF (px, py),
                 sos->label_string_format (),
                 sos->label_brush ());
}

}
}
