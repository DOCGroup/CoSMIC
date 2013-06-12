// $Id$

#include "stdafx.h"
#include "Reference_Decorator.h"

#if !defined (__GAME_INLINE__)
#include "Reference_Decorator.inl"
#endif

#include "game/mga/FCO.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/MetaPart.h"
#include "game/mga/Reference.h"
#include "game/mga/Project.h"
#include "game/mga/utils/Registrar.h"

#include "game/mga/component/Console_Service.h"
#include "game/mga/graphics/Image_Resolver.h"

namespace GAME
{
namespace Mga
{

//
// initialize
//
int Reference_Decorator::
initialize (const Project & proj,
            const Meta::Part_in part,
            const FCO_in fco,
            IMgaCommonDecoratorEvents * sink,
            ULONGLONG window)
{
  if (0 != FCO_Decorator::initialize (proj, part, fco, sink, window))
    return -1;

  using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::Mga::graphics::Image_Resolver;
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  std::string icon_filename;

  GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (fco);
  GAME::Mga::FCO target = ref->refers_to ();

  if (!this->show_refers_to_)
    icon_filename = fco->meta ()->registry_value ("icon");
  else if (!target.is_nil ())
    icon_filename = target->meta ()->registry_value ("icon");

  if (!icon_filename.empty ())
  {
    std::string abs_filename;
    if (!resolver->lookup_icon (icon_filename, abs_filename))
      return -1;

    CA2W temp (abs_filename.c_str ());
    this->bitmap_.reset (Gdiplus::Bitmap::FromFile (temp));
  }

  // Check for a decorator. If one is specified, then we should go
  // ahead a load it into memory as well.
  std::string target_decorator;

  if (!target.is_nil () && this->show_refers_to_)
    target_decorator = target->meta ()->registry_value ("decorator");

  if (!target_decorator.empty ())
  {
    // Load the decorator, and initialize it.
    CA2W tempstr (target_decorator.c_str ());
    VERIFY_HRESULT (this->delegate_.CoCreateInstance (tempstr));
    VERIFY_HRESULT (this->delegate_->InitializeEx (proj.impl (),
                                                   part->impl (),
                                                   target->impl (),
                                                   sink,
                                                   window));
  }

  return 0;
}

//
// destroy
//
void Reference_Decorator::destroy (void)
{
  if (0 == this->delegate_)
    return;

  // Destroy the delegate and release its resources.
  this->delegate_->Destroy ();
  this->delegate_.Release ();
}

//
// set_active
//
void Reference_Decorator::set_active (bool state)
{
  if (this->delegate_)
    this->delegate_->SetActive (state ? VARIANT_TRUE : VARIANT_FALSE);

  // Pass control to the base class.
  FCO_Decorator::set_active (state);
}

//
// set_active
//
void Reference_Decorator::set_selected (bool state)
{
  if (this->delegate_)
    this->delegate_->SetSelected (state ? VARIANT_TRUE : VARIANT_FALSE);

  FCO_Decorator::set_active (state);
}

//
// preferred_size
//
int Reference_Decorator::get_preferred_size (long & sx, long & sy)
{
  if (0 == this->delegate_)
    return FCO_Decorator::get_preferred_size (sx, sy);
  else
    return this->delegate_->GetPreferredSize (&sx, &sy);
}

//
// set_location
//
void Reference_Decorator::set_location (const GAME::Mga::Rect & location)
{
  if (this->delegate_)
    VERIFY_HRESULT (this->delegate_->SetLocation (location.x_,
                                                  location.y_,
                                                  location.cx_,
                                                  location.cy_));

  FCO_Decorator::set_location (location);
}

//
// draw
//
int Reference_Decorator::draw (Gdiplus::Graphics * g)
{
  if (0 == this->delegate_)
    return FCO_Decorator::draw (g);

  HDC hdc = g->GetHDC ();

  try
  {
    // Pass control to the delegate. We have to make sure we release
    // the device context before continuing. Otherwise, all subsequent
    // drawing operations fail.
    VERIFY_HRESULT (this->delegate_->Draw ((ULONG)hdc));
    g->ReleaseHDC (hdc);

    // Draw out label.
    //this->draw_label (g);

    return 0;
  }
  catch (...)
  {
    // Make sure we release the device context.
    g->ReleaseHDC (hdc);
    throw;
  }
}

//
// get_ports
//
int Reference_Decorator::get_ports (std::vector <FCO> & v)
{
  if (this->delegate_)
  {
    CComPtr <IMgaFCOs> ports;
    VERIFY_HRESULT (this->delegate_->GetPorts (&ports));

    iter_to_collection (ports.p, v);
  }

  return 0;
}

//
// get_port_location
//
int Reference_Decorator::
get_port_location (const FCO_in fco,
                   long & sx,
                   long & sy,
                   long & ex,
                   long & ey)
{
  if (this->delegate_)
    VERIFY_HRESULT (this->delegate_->GetPortLocation (fco->impl (), &sx, &sy, &ex, &ey));

  return 0;
}

}
}
