// $Id$

#include "StdAfx.h"
#include "ConnectorInstance_Decorator.h"
#include "ConnectorInstance_Decorator_Impl.h"

#include "game/MetaFCO.h"
#include "game/MetaModel.h"
#include "game/Model.h"
#include "game/Reference.h"

#include "game/graphics/Image_Resolver.h"
#include "game/utils/Registrar.h"

#include "boost/bind.hpp"

DECLARE_DECORATOR (ConnectorInstance_Decorator, ConnectorInstance_Decorator_Impl);

//
// ConnectorInstance_Decorator_Impl
//
ConnectorInstance_Decorator_Impl::ConnectorInstance_Decorator_Impl (void)
{

}

//
// ~ConnectorInstance_Decorator_Impl
//
ConnectorInstance_Decorator_Impl::~ConnectorInstance_Decorator_Impl (void)
{

}

//
// initialize
//
int ConnectorInstance_Decorator_Impl::
initialize_ex (const GAME::Project & proj,
               const GAME::Meta::Part & part,
               const GAME::FCO & fco,
               IMgaCommonDecoratorEvents * eventSink,
               ULONGLONG parentWnd)
{
  return this->initialize (proj, part, fco);
}

//
// initialize
//
int ConnectorInstance_Decorator_Impl::
initialize (const GAME::Project & project,
            const GAME::Meta::Part & part,
            const GAME::FCO & fco)
{
  using GAME::FCO;
  using GAME::Reference;
  using GAME::Model;

  using GAME::utils::GLOBAL_REGISTRAR;
  using GAME::utils::Registrar;

  using GAME::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::graphics::Image_Resolver;

  if (!this->impl_label_.empty ())
    this->impl_label_.clear ();

  if (fco.is_nil ())
  {
    // We can only initialize the label for this element since we
    // are in the part's browser.
    GAME::Meta::FCO metafco = part.role ().kind ();
    this->label_ = metafco.display_name ();
  }
  else
  {
    // The label is the name of the object. We also can initialize
    // the implementation label for this element since we are in the
    // active window.
    this->label_ = fco.name ();

    Model model = Model::_narrow (fco);

    std::vector <Reference> typerefs;
    if (model.children ("ConnectorImplementationType", typerefs))
    {
      Reference typeref = typerefs.front ();
      FCO refers_to = typeref.refers_to ();

      if (!refers_to.is_nil ())
        this->impl_label_ = refers_to.name ();
    }

    // Since there is no implementation label, we should set it
    // to undefined. This will help the modeler know that it is
    // missing its implementation.
    if (this->impl_label_.empty ())
      this->impl_label_ = "<undefined>";
  }

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  // Get the icon for the element in the parts browser.
  GAME::Meta::FCO metafco = part.role ().kind ();
  std::string icon_filename = metafco.registry_value ("icon");

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
int ConnectorInstance_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  sx = this->bitmap_->GetWidth ();
  sy = this->bitmap_->GetHeight ();

  return 0;
}

//
// draw
//
int ConnectorInstance_Decorator_Impl::draw (Gdiplus::Graphics & g)
{
  g.DrawImage (this->bitmap_.get (),
               this->location_.x_,
               this->location_.y_,
               this->location_.cx_ - this->location_.x_,
               this->location_.cy_ - this->location_.y_);

  float height = (float)this->location_.height ();
  float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);
  float py = static_cast <float> (this->location_.y_) + (height + 15.0f);

  static const Gdiplus::Font font (L"Arial", 10);
  static const Gdiplus::Font inst_font (L"Arial", 8);
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

  if (this->impl_label_.empty ())
    return 0;

  std::string inst_label ("[");
  inst_label += this->impl_label_ + "]";

  CComBSTR inst_bstr (inst_label.length (), inst_label.c_str ());
  g.DrawString (inst_bstr,
                inst_label.length (),
                &inst_font,
                Gdiplus::PointF (px, py + 15),
                &format,
                &brush);

  return 0;
}
