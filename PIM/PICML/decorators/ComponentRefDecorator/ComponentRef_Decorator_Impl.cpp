#include "StdAfx.h"
#include "resource.h"

#include "ComponentRef_Decorator.h"
#include "ComponentRef_Decorator_Impl.h"
#include "game/mga/decorator/Decorator_T.h"

//#include "../ComponentDecorator/Component_Decorator_Impl.h"

#include "game/mga/graphics/Image_Resolver.h"
#include "game/mga/utils/Registrar.h"

#include "game/mga/Model.h"
#include "game/mga/Reference.h"

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

////
//// initialize
////
//int ComponentRef_Decorator_Impl::
//initialize (const GAME::Mga::Project & project,
//            const GAME::Mga::Meta::Part_in part,
//            const GAME::Mga::FCO_in fco,
//            IMgaCommonDecoratorEvents * sink,
//            ULONGLONG window)
//{
//  AFX_MANAGE_STATE (AfxGetStaticModuleState ());
//
//  using GAME::Mga::GLOBAL_REGISTRAR;
//  using GAME::Mga::Registrar;
//
//  using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
//  using GAME::Mga::graphics::Image_Resolver;
//
//  // Initialize the icon manager.
//  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();
//
//  if (!resolver->is_init ())
//    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);
//
//  // Load the reference arrow into memory.
//  HINSTANCE hinst = ::AfxFindResourceHandle (MAKEINTRESOURCEA (IDB_REFARROW),
//                                             RT_BITMAP);
//
//  Gdiplus::Bitmap * bitmap =
//    Gdiplus::Bitmap::FromResource (hinst,
//                                   MAKEINTRESOURCEW (IDB_REFARROW));
//
//  std::string filename;
//  this->refarrow_.reset (bitmap);
//
//  if (0 == fco)
//  {
//    // We are in the part browser. So, let's just load the
//    // component bitmap ourselves.
//    if (!resolver->lookup_icon (icons::component, filename))
//      return E_DECORATOR_INIT_WITH_NULL;
//
//    CA2W tempstr (filename.c_str ());
//    this->component_.reset (Gdiplus::Bitmap::FromFile (tempstr));
//  }
//  else
//  {
//    GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (fco);
//    GAME::Mga::FCO refers_to = ref->refers_to ();
//
//    if (refers_to.is_nil ())
//    {
//      // The component reference is null. So, let's just load the
//      // component bitmap ourselves.
//      if (!resolver->lookup_icon (icons::component, filename))
//        return E_DECORATOR_INIT_WITH_NULL;
//
//      CA2W tempstr (filename.c_str ());
//      this->component_.reset (Gdiplus::Bitmap::FromFile (tempstr));
//    }
//    else
//    {
//      GAME::Mga::Model model = GAME::Mga::Model::_narrow (refers_to);
//      this->delegate_.reset (new Component_Decorator_Impl ());
//
//      // Let's delegate the work to the component decorator.
//      this->delegate_->initialize (project, 0, model);
//    }
//  }
//
//  return 0;
//}

////
//// draw
////
//int ComponentRef_Decorator_Impl::draw (Gdiplus::Graphics * g)
//{
//  if (0 != this->delegate_.get ())
//  {
//    // We need to draw the component and its ports.
//    this->delegate_->draw_component (g);
//    this->delegate_->draw_ports (g);
//  }
//  else
//  {
//    // Draw an blank component.
//    g->DrawImage (this->component_.get (),
//                  this->location_.x_,
//                  this->location_.y_,
//                  this->location_.cx_ - this->location_.x_,
//                  this->location_.cy_ - this->location_.y_);
//  }
//
//  const long py = (this->location_.y_ + this->location_.height ()) - this->refarrow_->GetHeight ();
//
//  // Draw the overlay image.
//  g->DrawImage (this->refarrow_.get (),
//                this->location_.x_,
//                py,
//                this->refarrow_->GetWidth (),
//                this->refarrow_->GetHeight ());
//
//  return 0;
//}