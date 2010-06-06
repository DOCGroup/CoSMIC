// $Id$

#include "StdAfx.h"
#include "resource.h"
#include "ComponentRef_Decorator.h"
#include "ComponentRef_Decorator_Impl.h"
#include "../ComponentDecorator/Component_Decorator_Impl.h"

#include "game/graphics/Image_Resolver.h"
#include "game/utils/Registrar.h"

#include "game/Model.h"
#include "game/Reference.h"

DECLARE_DECORATOR (ComponentRef_Decorator, ComponentRef_Decorator_Impl);

namespace icons
{
  static const std::string component ("component.bmp");
};

//
// ComponentRef_Decorator_Impl
//
ComponentRef_Decorator_Impl::ComponentRef_Decorator_Impl (void)
{

}

//
// ~ComponentRef_Decorator_Impl
//
ComponentRef_Decorator_Impl::~ComponentRef_Decorator_Impl (void)
{

}

//
// initialize
//
int ComponentRef_Decorator_Impl::
initialize_ex (const GAME::Project & project, 
               const GAME::Meta::Part & part, 
               const GAME::FCO & fco,
               IMgaCommonDecoratorEvents * eventSink, 
               ULONGLONG parentWnd)
{
  AFX_MANAGE_STATE (AfxGetStaticModuleState ());

  using GAME::utils::GLOBAL_REGISTRAR;
  using GAME::utils::Registrar;

  using GAME::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();

  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  // Load the reference arrow into memory.
  HINSTANCE hinst = ::AfxFindResourceHandle (MAKEINTRESOURCEA (IDB_REFARROW), 
                                             RT_BITMAP);

  Gdiplus::Bitmap * bitmap = 
    Gdiplus::Bitmap::FromResource (hinst, 
                                   MAKEINTRESOURCEW (IDB_REFARROW));

  std::string filename;
  this->refarrow_.reset (bitmap);

  if (fco.is_nil ())
  {
    // We are in the part browser. So, let's just load the 
    // component bitmap ourselves.
    if (!resolver->lookup_icon (icons::component, filename))
      return E_DECORATOR_INIT_WITH_NULL;

    CA2W tempstr (filename.c_str ());
    this->component_.reset (Gdiplus::Bitmap::FromFile (tempstr));
  }
  else
  {
    GAME::Reference ref = GAME::Reference::_narrow (fco);
    GAME::FCO refers_to = ref.refers_to ();

    if (refers_to.is_nil ())
    {
      // The component reference is null. So, let's just load the 
      // component bitmap ourselves.
      if (!resolver->lookup_icon (icons::component, filename))
        return E_DECORATOR_INIT_WITH_NULL;

      CA2W tempstr (filename.c_str ());
      this->component_.reset (Gdiplus::Bitmap::FromFile (tempstr));
    }
    else
    {
      GAME::Model model = GAME::Model::_narrow (refers_to);
      this->delegate_.reset (new Component_Decorator_Impl ());

      // Let's delegate the work to the component decorator.
      this->delegate_->initialize (project, GAME::Meta::Part (), model);
    }
  }

  return 0;
}

//
// destroy
//
void ComponentRef_Decorator_Impl::destroy (void)
{
  if (0 != this->delegate_.get ())
    this->delegate_->destroy ();
}

//
// set_location
//
void ComponentRef_Decorator_Impl::
set_location (const GAME::utils::Rect & location)
{
  if (this->delegate_.get () != 0)
    this->delegate_->set_location (location);

  GAME::Decorator_Impl::set_location (location);
}

//
// get_preferred_size
//
int ComponentRef_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  if (this->delegate_.get () != 0)
    return this->delegate_->get_preferred_size (sx, sy);

  sx = this->component_->GetWidth ();
  sy = this->component_->GetHeight ();
  return 0;
}

//
// draw
//
int ComponentRef_Decorator_Impl::draw (Gdiplus::Graphics & g)
{
  if (0 != this->delegate_.get ())
  {
    // We need to draw the component and its ports.
    this->delegate_->draw_component (g);
    this->delegate_->draw_ports (g);
  }
  else
  {
    // Draw an blank component.
    g.DrawImage (this->component_.get (),
                 this->location_.x_,
                 this->location_.y_,
                 this->location_.cx_ - this->location_.x_,
                 this->location_.cy_ - this->location_.y_);
  }

  const long py = (this->location_.y_ + this->location_.height ()) - this->refarrow_->GetHeight ();

  // Draw the overlay image.
  g.DrawImage (this->refarrow_.get (),
               this->location_.x_,
               py, 
               this->refarrow_->GetWidth (),
               this->refarrow_->GetHeight ());

  return 0;
}