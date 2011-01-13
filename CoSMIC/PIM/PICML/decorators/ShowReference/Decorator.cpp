// $Id$

#include "StdAfx.h"
#include "Decorator.h"
#include "resource.h"
#include "DecoratorLib_i.c"

#include "game/be/Decorator_Module.h"
#include "game/MetaFCO.h"
#include "game/graphics/Image_Resolver.h"
#include "game/utils/Registrar.h"
#include "game/Reference.h"

DECLARE_DECORATOR_MODULE (LIBID_ShowReferenceDecoratorLibrary, IDR_DECORATOR, "{CDD72C3A-3340-4225-83D6-46B10E9A763E}")

//
// Show_Reference_Decorator_Impl
//
Show_Reference_Decorator_Impl::Show_Reference_Decorator_Impl (void)
{

}

//
// ~Show_Reference_Decorator_Impl
//
Show_Reference_Decorator_Impl::~Show_Reference_Decorator_Impl (void)
{

}

//
// initialize
//
int Show_Reference_Decorator_Impl::
initialize_ex (const GAME::Project & project,
               const GAME::Meta::Part_in part,
               const GAME::FCO_in fco,
               IMgaCommonDecoratorEvents * eventSink,
               ULONGLONG parentWnd)
{
  using GAME::utils::GLOBAL_REGISTRAR;
  using GAME::utils::Registrar;

  using GAME::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  std::string icon_filename;

  if (0 == fco)
  {
    // Get the icon for the element in the parts browser.
    GAME::Meta::FCO metafco = part->role ()->kind ();

    icon_filename = metafco->registry_value ("icon");
    this->label_ = metafco->display_name ().c_str ();
  }
  else
  {
    // Get the icon filename for the referenced element. If no
    // element is referenced, then display the reference's icon.
    GAME::Reference ref = GAME::Reference::_narrow (fco);
    GAME::FCO refers_to = ref->refers_to ();

    if (!refers_to.is_nil ())
      icon_filename = refers_to->registry_value ("icon");
    else
      icon_filename = ref->registry_value ("icon");

    // Determine if we need to show the label for the element.
    std::string show_name = ref->registry_value ("isNameEnabled");

    if (show_name.empty () || show_name == "true")
      this->label_ = ref->name ().c_str ();
  }

  // Load the file for later usage.
  std::string abs_filename;
  if (!resolver->lookup_icon (icon_filename, abs_filename))
    return -1;

  CA2W temp (abs_filename.c_str ());
  this->bitmap_.reset (Gdiplus::Bitmap::FromFile (temp));

  return 0;
}

//
// GetPreferredSize
//
int Show_Reference_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  sx = this->bitmap_->GetWidth ();
  sy = this->bitmap_->GetHeight ();

  return 0;
}

//
// draw
//
int Show_Reference_Decorator_Impl::draw (Gdiplus::Graphics * g)
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
